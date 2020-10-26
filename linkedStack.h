//
// Created by lenovo on 2020/10/8.
//

#ifndef TEST_LINKEDSTACK_H
#define TEST_LINKEDSTACK_H

#include "stack.h"

template <class T>
class linkedStack : public stack<T> {
public:
    //构造器
    linkedStack();
    linkedStack(linkedStack<T> &);
    //析构器
    ~linkedStack();

    //ADT中定义的接口
    bool empty() const {return stackSize == 0;}
    int size() const {return stackSize;}
    T top() const;
    void pop();
    void push(const T & theElement);

    struct node {
        T element;
        node * next;

        node(const T & theElement) {
            next = nullptr;
            element = theElement;
        }
        node(const T & theElement, node * theNext) {
            element = theElement;
            next = theNext;
        }
        node(node & theNode) {
            element = theNode.element;
            next = theNode.next;
        }
    };

protected:
    int stackSize;
    node * head;
};


#endif //TEST_LINKEDSTACK_H
