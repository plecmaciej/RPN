#pragma once
#include "Stack.h"
#include "IntList.h"

int readN(){

	WordList newList;
	char sign = getchar();
	while (sign != '\n') {
		newList.append(sign);
		sign = getchar();
	}
	int N = newList.returnIfInt();
	newList.clear();
	return N;
}

int charToInt(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else {
		return -1;
	}
}

WordList readLine() {

	bool isFirst = false , isMaxMin = false;
	Stack newStack;
	WordList newList;
	IntList newIntList;
	char sign = 0;

	while (sign != '.') {

		sign = getchar();
	
		if ( sign != '\n' && sign!= '.') {

			if (sign >= '0' && sign <= '9') {

				newList.append(sign);
			}
			else if (sign == ' ') {

				if (isFirst) isFirst = false;
				else newList.append(sign);
			}
			else if (sign == 'M') {

				isMaxMin = true;
			}
			else if ((sign == 'A' || sign == 'I') && isMaxMin == true) {

				newIntList.append(1);
				newStack.push(sign);
				isFirst = true;

			}
			else if ((sign == 'N' || sign == 'X') && isMaxMin == true) {

				isMaxMin = false;
			}
			else if (sign == ')') {

				while (newStack.returnLastElement() != '(' && !newStack.isEmpty()){

					newList.append(newStack.returnAndPop());
					newList.append(' ');
				}
				newStack.popBack();

				if (newStack.returnLastElement() == 'A') {

					newList.append('M');
					newList.append(newStack.returnAndPop());
					newList.append('X');
					if (newIntList.returnLastElement() > 9) {
						int number = newIntList.returnLastElement();
						number = number - (number % 10);
						newList.append(number+'0');
						newList.append((newIntList.returnLastElement() % 10) + '0');

					}
					else newList.append(newIntList.returnLastChar());
					newIntList.popBack();
					newList.append(' ');
				}
				else if (newStack.returnLastElement() == 'I') {

					newList.append('M');
					newList.append(newStack.returnAndPop());
					newList.append('N');
					if (newIntList.returnLastElement() > 9) {

						int number = newIntList.returnLastElement();
						number = number - (number % 10);
						newList.append(number + '0');
						newList.append((newIntList.returnLastElement() % 10) + '0');
					}
					else newList.append(newIntList.returnLastChar());

					newIntList.popBack();
					newList.append(' ');
				}
				else if (newStack.returnLastElement() == 'F') {

					newList.append('I');
					newList.append(newStack.returnAndPop());
					newList.append(' ');
				}
				else if (newStack.returnLastElement() == 'N') {

					newList.append(newStack.returnAndPop());
					newList.append(' ');
				}
				isFirst = true;
			}
			else if ((sign == '+' || sign == '-') ) {

				while (!newStack.isEmpty() && newStack.returnLastElement() != '(') {

					newList.append(newStack.returnAndPop());
					newList.append(' ');
				}
				
				isFirst = true;
				newStack.push(sign);
			}
			else if ((sign == '/' || sign == '*')) {

				while (!newStack.isEmpty() && newStack.returnLastElement() != '(' && newStack.returnLastElement() != '-' && newStack.returnLastElement() != '+') {

					newList.append(newStack.returnAndPop());
					newList.append(' ');
				}
				isFirst = true;
				newStack.push(sign);
			}
			else if (sign == '(') {

				newStack.push(sign);
				isFirst = true;
			}
			else if ((sign == 'N' || sign == 'F') && isMaxMin == false) {

				isFirst = true;
				newStack.push(sign);
			}
			else if (sign == ',') {

				while (newStack.returnLastElement() != '(') {

					newList.append(newStack.returnAndPop());
					newList.append(' ');
				}
				if (newStack.returnPreLastElement() == 'A' || newStack.returnPreLastElement() == 'I') {

					newIntList.increaseLast();
				}
				isFirst = true;
			}
		}
	}

	while (!newStack.isEmpty()) {
		newList.append(newStack.returnAndPop());
		newList.append(' ');
	}
	newList.append('\n');

	return newList;
}

void convert(WordList &list) {

	WordList tmpList;
	IntList intiegers;
	int tmpInt = 0;
	char c = 'x';
	bool isMaxMin = false, isMin = false, isMax = false;

	
	while (c != '\n') {

		c = list.returnHead();

		if (c >= '0' && c <= '9') {

			if (isMax) {

				std::cout << "MAX" << charToInt(c) << " ";
				intiegers.printIntListReverseTail();
				tmpInt = intiegers.returnMax(charToInt(c));
				for (int i = 0; i < charToInt(c); i++) {

					intiegers.popBack();
				}
				intiegers.append(tmpInt);
				isMax = false;
				isMaxMin = false;
			}
			else if (isMin) {

				std::cout << "MIN" << charToInt(c) << " ";
				intiegers.printIntListReverseTail();
				tmpInt = intiegers.returnMin(charToInt(c));
				for (int i = 0; i < charToInt(c); i++) {

					intiegers.popBack();
				}
				intiegers.append(tmpInt);
				isMin = false;
				isMaxMin = false;
			}
			else tmpList.append(c);
		}
		else if (c == ' ') {

			if (tmpList.getSize() > 0) {

				intiegers.append(tmpList.returnIfInt());
				while (tmpList.getSize() > 0) tmpList.popBack();
			}
		}
		else if (c == '+') {

			std::cout << c << " ";
			intiegers.printIntListReverseTail();
			tmpInt = intiegers.returnSum();
			intiegers.popBack();
			intiegers.popBack();
			intiegers.append(tmpInt);
		}
		else if (c == '-') {

			std::cout << c << " ";
			intiegers.printIntListReverseTail();
			tmpInt = intiegers.returnSub();
			intiegers.popBack();
			intiegers.popBack();
			intiegers.append(tmpInt);
		}
		else if (c == '*') {

			std::cout << c << " ";
			intiegers.printIntListReverseTail();
			tmpInt = intiegers.returnMul();
			intiegers.popBack();
			intiegers.popBack();
			intiegers.append(tmpInt);
		}
		else if (c == '/') {

			std::cout << c << " ";
			intiegers.printIntListReverseTail();
			if (intiegers.returnLastElement() == 0) {

				std::cout << "ERROR\n\n";
				return;
			}

			tmpInt = intiegers.returnDiv();
			intiegers.popBack();
			intiegers.popBack();
			intiegers.append(tmpInt);
		}
		else if (c == 'N' && isMaxMin == false) {

			std::cout << c << " ";
			intiegers.printIntListReverseTail();
			tmpInt = intiegers.returnNeg();
			intiegers.popBack();
			intiegers.append(tmpInt);
		}
		else if (c == 'F') {

			std::cout << 'I' << c << " ";
			intiegers.printIntListReverseTail();
			tmpInt = intiegers.returnIF();
			intiegers.popBack();
			intiegers.popBack();
			intiegers.popBack();

			intiegers.append(tmpInt);
		}
		else if (c == 'M') {
			isMaxMin = true;
		}
		else if (c == 'I' && isMaxMin == true) {
			isMin = true;
		}
		else if (c == 'A' && isMaxMin == true) {
			isMax = true;
		}


		list.popHead();
	}
	
	std::cout<< tmpInt;
	std::cout << '\n';
	std::cout << '\n';
}


