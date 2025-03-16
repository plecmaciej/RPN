#pragma once
#include <iostream>

struct IntElement {
public:
    int data;
    IntElement* next;

    IntElement(int data) : data(data), next(nullptr) {}
};

class IntList {
private:
    IntElement* head;
    int size;

public:
    IntList() : head(nullptr), size(0) {}

    ~IntList() {

        while (head != nullptr) {
            IntElement* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    void clear() {

        while (head != nullptr) {
            IntElement* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;

    }

    void append(int value) {

        IntElement* newNode = new IntElement(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            IntElement* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void increaseLast() {

        if (head == nullptr) {
            head = nullptr;
        }
        else {
            IntElement* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->data++;
        }
    }

    void popBack() {

        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            IntElement* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }

    int getSize() const {
        return size;
    }

    int returnLastElement() {

        if (head == nullptr) {
            return 0;
        }
        IntElement* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

    char returnLastChar() {

        int integer_value;
        if (head == nullptr) {
            return 0;
        }
        IntElement* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        integer_value =  current->data;

        if (integer_value >= 0 && integer_value <= 9) {
            return '0' + integer_value; 
        }
        else {
            return '?';
        }
    }

    int returnSum() {

        int sum = 0;
        IntElement* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        sum = current->data + current->next->data;
        return sum;
    }

    int returnSub() {

        int sub = 0;
        IntElement* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        sub = current->data - current->next->data;
        return sub;
    }

    int returnDiv() {

        int div = 0;
        IntElement* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        div = current->data / current->next->data;
        return div;
    }

    int returnMul() {

        int mul = 0;
        IntElement* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        mul = current->data * current->next->data;
        return mul;
    }

    int returnNeg() {

        int neg = 0;
        IntElement* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        neg = -(current->data);
        return neg;
    }

    int returnIF() {

        IntElement* current = head;
        while (current->next->next->next != nullptr) {
            current = current->next;
        }
        if (current->data > 0) return current->next->data;
        else return current->next->next->data;
    
    }

    int returnMax(int n) {

        if (n <= 0 || head == nullptr) {
            return 0;
        }

        IntElement* current = head;

        for (int i = 0; i < size - n; ++i) {
            current = current->next;
        }

        int maxNum = current->data;

        for (int i = 0; i < n; ++i) {
            if (current->data > maxNum) {
                maxNum = current->data;
            }
            current = current->next;
        }

        return maxNum;
    }

    int returnMin(int n) {

        if (n <= 0 || head == nullptr) {
            return 0;
        }

        IntElement* current = head;

        for (int i = 0; i < size - n; ++i) {
            current = current->next;
        }

        int minNum = current->data;

        for (int i = 0; i < n; ++i) {
            if (current->data < minNum) {
                minNum = current->data;
            }
            current = current->next;
        }

        return minNum;
    }


    void printIntListReverseTail() {

        IntElement* tail = nullptr;
        IntElement* current = head;

        while (current != nullptr) {
            IntElement* next = current->next;
            current->next = tail;
            tail = current;
            current = next;
        }

        while (tail != nullptr) {

            std::cout << tail->data << " ";
            IntElement* prev = tail->next; 
            tail->next = current;
            current = tail;
            tail = prev;
        }
        std::cout << "\n";

        head = current;
    }

    void printIntList() {

        IntElement* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            std::cout << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}; 
