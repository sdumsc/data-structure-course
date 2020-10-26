//
// Created by lenovo on 2020/10/8.
//

#include "linkedStack.h"
#include <iostream>

template <class T>
linkedStack<T>::linkedStack() {
    stackSize = 0;
    head = nullptr;
}

template <class T>
linkedStack<T>::linkedStack(linkedStack<T> & x) {
    stackSize = x.stackSize;
    node * src = x.head;
    node * tar = head;
    if (src != nullptr) tar = new node(src);
    src = src->next;
    while(src != nullptr) {
        node * newNode = new node(src);
        tar->next = newNode;
        tar = tar->next;
        src = src->next;
    }
}

template <class T>
linkedStack<T>::~linkedStack() {
    while (head != nullptr) {
        node * tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <class T>
T linkedStack<T>::top() const {
    return head->element;
}

template <class T>
void linkedStack<T>::pop() {
    if (empty()) //TODO 抛出空栈异常.
        ;
    if (head->next == nullptr) {
        delete head;
    } else {
        node * tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <class T>
void linkedStack<T>::push(const T & theElement) {
    node * newNode = new node(theElement, head);
    head = newNode;
}

int main() {
    stack<double> *s = new linkedStack<double>();
    for (int i = 0; i < 100; i++) {
        s->push(i);
    }
    for (int j = 0; j < 100; j++) {
        std::cout << s->top() << "  " << std::endl;
        s->pop();
    }
    return 0;
}