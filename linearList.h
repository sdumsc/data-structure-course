//
// Created by YilingYu on 2020/10/22.
//

#ifndef DATA_STRUCTURE_COURSE_LINEARLIST_H
#define DATA_STRUCTURE_COURSE_LINEARLIST_H

#include <iostream>

template<class T>
class linearList {
public:
    //析构函数一定要在虚基类中实现.(虽然是空实现, 但是这样才能在面向接口的时候动态绑定)
    virtual ~linearList() {};

    //ADT(Abstract Data Type) 使用纯虚方法来确定集合类的接口.
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T &get(int theIndex) const = 0;
    virtual int indexOf(const T &theElement) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insert(int theIndex, const T &theElement) = 0;

    //重载流输出运算符, 依赖抽象方法output.
    friend std::ostream &operator<<(std::ostream &out, const linearList<T> &x) {
      x.output(out);
      return out;
    }

protected:
    //Output输出 子类各自实现自己的输出方法.
    virtual void output(std::ostream &out) const = 0;
};

#endif //DATA_STRUCTURE_COURSE_LINEARLIST_H
