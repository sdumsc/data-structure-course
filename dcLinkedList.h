#ifndef DOUBLY_CIRCULAR_LINKEDLIST_H
#define DOUBLY_CIRCULAR_LINKEDLIST_H

#include "linearList.h"
#include <iostream>
#include <iterator>

using std::ostream;

template<class T>
class dcLinkedList : public linearList<T> {
public:
    //构造器部分
    dcLinkedList(int initialCapacity = 10);
    dcLinkedList(const dcLinkedList<T>&);
    ~dcLinkedList();

    //ADT中的公有接口
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    //实现迭代器
    class iterator;
    typedef typename dcLinkedList<T>::iterator iterator;
    //公开迭代器接口
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(head->prev); }

    struct node {
        T element;
        node* next;
        node* prev;

        node() {
            this->next = nullptr;
            this->prev = nullptr;
        }
        node(const T& element) {
            this->element = element;
            this->next = nullptr;
            this->prev = nullptr;
        }
        node(const T& element, node* prev, node* next) {
            this->element = element;
            this->prev = prev;
            this->next = next;
        }
    };

    class iterator {
    public:
        //构造器
        iterator(node* thisPosition = nullptr) { position = thisPosition; }

        //解引用
        T& operator*() { return position->element; }
        T* operator->() { return &(position->element); }

        //自增自减
        iterator& operator++() {
            position = position->next;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            position = position->next;
            return tmp;
        }
        iterator& operator--() {
            position = position->prev;
            return *this;
        }
        iterator operator--(int) {
            iterator tmp = *this;
            position = position->prev;
            return tmp;
        }

        //判等
        bool operator!=(const iterator right) { return position != right.position; }
        bool operator==(const iterator right) { return position == right.position; }

    private:
        node* position;
    };

protected:

    void checkIndex(int theIndex) const;
    node* head;
    int listSize;
};

#endif