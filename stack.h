//
// Created by YilingYu on 2020/10/8.
//

#ifndef TEST_STACK_H
#define TEST_STACK_H

template<class T>
class stack {
public:
    virtual ~stack() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual const T& top() = 0;
    virtual void pop() = 0;
    virtual void push(const T & theElement) = 0;
};

#endif //TEST_STACK_H
