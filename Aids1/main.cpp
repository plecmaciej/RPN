#include "List.h"
#include "Reading.h"

int main() {
	int n = readN();
	for (int i = 0; i < n; i++) {
		WordList list = readLine();
		list.printWordList();
		convert(list);
	}
	return 0;
}