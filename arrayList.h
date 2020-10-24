//
// Created by YilingYu on 2020/10/22.
//

#ifndef DATA_STRUCTURE_COURSE_ARRAYLIST_H
#define DATA_STRUCTURE_COURSE_ARRAYLIST_H

#include "linearList.h"
#include <iostream>

using std::ostream;

template<class T>
class arrayList : public linearList<T> {
public:
    //默认构造函数和拷贝构造函数.
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &theList);

    //析构函数
    ~arrayList();

    //返回数组的最大容量
    int capacity() { return this->arrayLength; }

    //ADT 线性表接口. 简单的方法内联实现.
    bool empty() const { return this->listSize == 0; }
    int size() const { return this->listSize; }
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);

    T & operator[](int x) { return this->get(x); }

    class iterator;
    typedef typename arrayList<T>::iterator iterator;

    //获取迭代器的公有接口.
    iterator begin() { return iterator(element); }
    iterator end() { return iterator(element + listSize); }

    class iterator {
    public:
        //构造器
        iterator(T *thePosition = nullptr) { position = thePosition; }

        //重载解引用操作符
        T &operator*() const { return *position; }

        //指向操作符 单目运算符 实现解包操作.
        T *operator->() const { return &*position; }

        //自增自减操作符的重载.
        //前缀自增. 返回自身引用.
        iterator &operator++() { ++position; return *this; }
        //用int标识后缀自增. 返回原来的拷贝.
        iterator operator++(int) { iterator old = *this; ++position; return old; }

        //自减同上
        iterator &operator--() { --position; return *this; }
        iterator operator--(int) { iterator old = *this; --position; return old; }

        //判等. 解包判等
        bool operator!=(const iterator right) const { return position != right.position; }
        bool operator==(const iterator right) const { return position == right.position; }

    protected:
        //维护本节点的元素指针.
        T *position;
    };

protected:
    //加上一个额外的索引检查.
    void checkIndex(int theIndex) const;

    //自身的打印方法.
    void output(ostream &out) const;

    //线性表头指针
    T *element;
    //线性表尺寸
    int listSize;
    //线性表容量
    int arrayLength;
};

//resize容器的方法, 以实现变长数组
template<class T>
void changeLength(T *&a, int newLength, int oldLength);

#endif //DATA_STRUCTURE_COURSE_ARRAYLIST_H
