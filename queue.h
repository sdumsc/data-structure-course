//
// Created by YilingYu on 2020/10/24.
//

#ifndef DATA_STRUCTURE_COURSE_QUEUE_H
#define DATA_STRUCTURE_COURSE_QUEUE_H

#include <iostream>

template<class T>
class queue {
public:
    virtual ~queue() {}
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual const T& top() = 0;
    virtual void pop() = 0;
    virtual void push(const T& theElement) = 0;
};

#endif //DATA_STRUCTURE_COURSE_QUEUE_H
