//
// Created by YilingYu on 2020/10/24.
//

#ifndef DATA_STRUCTURE_COURSE_PRIORITYQUEUE_H
#define DATA_STRUCTURE_COURSE_PRIORITYQUEUE_H

#include "queue.h"
#include "arrayList.h"

template<class T>
class priorityQueue : public queue<T>{
public:
  //默认构造器
  priorityQueue(int length = 10);
  //拷贝构造器
  priorityQueue(const priorityQueue<T>&);
  //析构函数
  ~priorityQueue();

  //实现ADT
  int size() const { return array.size(); }
  bool empty() const { return array.empty(); }
  T& top();
  void pop();
  void push(const T&);

private:
  //线性表.
  arrayList<T> array;

  int getMaxSon(int father);
};

#endif //DATA_STRUCTURE_COURSE_PRIORITYQUEUE_H
