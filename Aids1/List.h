#pragma once
#include <iostream>

struct CharElement {
public:
    char data;
    CharElement* next;

    CharElement(char data) : data(data), next(nullptr) {}
};

class WordList {
private:
    CharElement* head;
    int size;

public:
    WordList() : head(nullptr), size(0) {}

    //~WordList() {
    //    std::cout << '[' << size << ']';
    //    while (head != nullptr) {
    //        CharElement* temp = head;
    //        head = head->next;
    //        delete temp;
    //    }
    //    head = nullptr; 
        //std::cout << "czyszczono";
    //}

    void clear() {

        while (head != nullptr) {
            CharElement* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    void append(char c) {

        CharElement* newNode = new CharElement(c);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            CharElement* current = head;
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
            CharElement* current = head;
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

    char returnHead() {

        if (head == nullptr) {
            return 'x';
        }
        else{ 
            return head->data; 
        }
    }

    void popHead() {

        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            CharElement* current = head->next;
            delete head;
            head = current;
        }
        size--;
    }

    int returnIfInt(){
        int result = 0;
        CharElement* current = head;
        int power = size - 1;
        while (current != nullptr) {

            result += (current->data - '0') * std::pow(10, power);
            current = current->next;
            power--;
        }
        return result;
    }

    void printWordList() {
        if (head == nullptr) {
            return;
        }
        else if (head->next == nullptr) {
            std::cout << head->data;
            return;
        }

        CharElement* current = head;
        while (current != nullptr) {

            std::cout << current->data;
            current = current->next;
        }
    }
};