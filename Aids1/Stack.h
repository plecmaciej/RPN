#pragma once
#include "List.h"

class StackElement {
public:
    char data;
    StackElement* next;
    StackElement* prev; 

    StackElement(char c) : data(c), next(nullptr), prev(nullptr) {}
};

class Stack {
private:
    StackElement* head;
    int size;

public:
    Stack() : head(nullptr), size(0) {}

    ~Stack() {
        while (head != nullptr) {

            StackElement* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(char c) {

        StackElement* newNode = new StackElement(c);

        if (head == nullptr) {
            head = newNode;
            
        }
        else if (head->next == nullptr) {
            head->next = newNode;
        }
        else {
            StackElement* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
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
            StackElement* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }

    char returnLastElement() const {
        if (head == nullptr) {
            return 'j';
        }
        StackElement* current = head;
        while (current->next != nullptr) {

            current = current->next;
        }
        return current->data;
    }

    char returnPreLastElement() {
        if (head == nullptr) {
            return 'j';
        }
        else if (head->next == nullptr) {
            return 'j';
        }
        StackElement* current = head;
        while (current->next->next != nullptr) {

            current = current->next;
        }
        return current->data;
    }

    char returnAndPop() {
        char tmp = 0;
        if (head == nullptr) {
            return ' ';
        }
        if (head->next == nullptr) {
            tmp = head->data;
            delete head;
            head = nullptr;
        }
        else {
            StackElement* current = head;
            while (current->next->next != nullptr) {

                current = current->next;
            }
            tmp = current->next->data;
            delete current->next;
            current->next = nullptr;
        }
        size--;
        return tmp;
    }

    int getSize() const {
        return size;
    }


    bool isEmpty() const {
        if (size > 0) return false;
        else return true;
    }
    
};