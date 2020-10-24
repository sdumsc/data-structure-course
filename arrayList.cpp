//
// Created by YilingYu on 2020/10/22.
//

#include "arrayList.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

//更改数组长度, 实现变长数组.
template<class T>
void changeLength(T*& a, int newLength, int oldLength) {
  //debug
  cout << "resize the list from " << oldLength << " to " << newLength << endl;
  if (newLength < 1) {
    throw length_error("new length must be > 0");
  }
  T* temp = new T[newLength];
  int num = (newLength > oldLength) ? oldLength : newLength;
  copy(a, a + num, temp);
  delete[] a;
  a = temp;
}

template<class T>
arrayList<T>::arrayList(int initialCapacity) {
  //构造函数.
  if (initialCapacity < 1) {
    ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw invalid_argument(s.str());
  }
  arrayLength = initialCapacity;
  listSize = 0;
  element = new T[arrayLength];
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList) {
  //复制构造器.
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];
  copy(theList.element, theList.element + listSize, element);
}

template<class T>
arrayList<T>::~arrayList() {
  //析构函数.
  if (element != nullptr)
    delete[] element;
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const {
  //索引合法性检查.
  if (theIndex < 0 || theIndex >= listSize) {
    ostringstream s;
    s << "the index = " << theIndex << " ; the size = " << listSize;
    //索引异常.
    throw out_of_range(s.str());
  }
}

template<class T>
T& arrayList<T>::get(int theIndex) const {
  //根据索引来获取对象, 随机访问.
  checkIndex(theIndex);
  return *(element + theIndex);
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const {
  //根据元素来找到对应索引.
  int theIndex = (int)(find(element, element + listSize, theElement) - element);
  if (theIndex == listSize) return -1;
  else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex) {
  //擦除索引位置上的元素.
  checkIndex(theIndex);

  //为节省开销, 数组倍减.
  if (listSize < (arrayLength / 4)) {
    changeLength(element, arrayLength/2, arrayLength);
    arrayLength /= 2;
  }


  copy(element + theIndex + 1, element + listSize, element + theIndex);
  element[--listSize].~T();
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement) {
  //在给定的位置上插入给定的元素.
  if (theIndex < 0 || theIndex > listSize) {
    ostringstream s;
    s << "the index = " << theIndex << " the listSize = " << listSize;
    throw out_of_range(s.str());
  }

  //为节省开销, 数组倍增.
  if (listSize == arrayLength) {
    changeLength(element, arrayLength * 2, arrayLength);
    arrayLength *= 2;
  }

  copy_backward(element + theIndex, element + listSize, element + listSize + 1);
  element[theIndex] = theElement;
  ++listSize;
}

template<class T>
void arrayList<T>::output(ostream& out) const {
  copy(element, element + listSize, ostream_iterator<T>(out, "  "));
}

//int main() {
//  //arrayList类测试.
//  cout << "The test of the arrayList." << endl;
//  linearList<double> * alist = new arrayList<double>();
//  cout << "Insert" << endl;
//  for (int i = 0; i < 100; i++) {
//    alist->insert(0, 3.14*i);
//  }
//  cout << "Size(size == 100)" << endl;
//  cout << "\tsize = " << alist->size() << endl;
//  cout << "Iterator" << endl;
//  int cnt = 0;
//  for (auto x = dynamic_cast<arrayList<double>*>(alist)->begin(); x != dynamic_cast<arrayList<double>*>(alist)->end(); ++x)
//    cnt++;
//  cout << "\tcnt = " << cnt << endl;
//  cout << "Empty(empty == 0)" << endl;
//  cout << "\tempty = " << alist->empty() << endl;
//  cout << "IndexOf(index == 99)" << endl;
//  cout << "\tindex = " << alist->indexOf(0) << endl;
//  cout << "Get(element = 157)" << endl;
//  cout << "\telement = " << alist->get(49)<< endl;
//  cout << "Output" << endl;
//  cout << "\t" << *alist << endl;
//  cout << "Constructor" << endl;
//  linearList<double> * newalist = new arrayList<double>(*dynamic_cast<arrayList<double>*>(alist));
//  cout << "Destructor" << endl;
//  delete alist;
//  cout << "Erase" << endl;
//  for (int i = 0; i < 100; i++)
//    newalist->erase(99-i);
//  return 0;
//}
