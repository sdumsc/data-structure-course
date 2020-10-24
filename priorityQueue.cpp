//
// Created by YilingYu on 2020/10/24.
//

#include "priorityQueue.h"

template<class T>
priorityQueue<T>::priorityQueue(int length) : array(*new arrayList<T>(length)){
}

template<class T>
priorityQueue<T>::priorityQueue(const priorityQueue<T> & x) : array(*new arrayList<T>(x.array)){
}

template<class T>
priorityQueue<T>::~priorityQueue() {
  delete &array;
}

template<class T>
T &priorityQueue<T>::top() {
  if (array.size() == 0)
    throw std::out_of_range("No element in the queue!");
  else
    return array[0];
}

template<class T>
void priorityQueue<T>::pop() {
  int tail = array.size() - 1;
  array[0] = array[tail];
  array.erase(tail);
  int target = 0;
  int maxSon = getMaxSon(target);
  while (maxSon != -1 && array[target] > array[maxSon]) {
    T tmp = array[maxSon];
    array[maxSon] = array[target];
    array[target] = tmp;
    target = maxSon;
    maxSon = getMaxSon(target);
  }
}

template<class T>
void priorityQueue<T>::push(const T & x) {
  array.insert(array.size(), x);
  int idxs = array.size() - 1;
  int idxf = (idxs - 1) / 2;
  while (idxs > 0 && array[idxs] > array[idxf]) {
    T tmp = array[idxs];
    array[idxs] = array[idxf];
    array[idxf] = tmp;
  }
}

template<class T>
int priorityQueue<T>::getMaxSon(int father) {
  int left = father * 2 + 1;
  int right = father * 2 + 2;
  if (left > array.size()) return -1;
  if (right > array.size()) return left;
  else return (array[left] > array[right]) ? left : right;
}

int main() {
  int n = 0;
  std::cout << "****************** Heap Sort ********************" << std::endl;
  std::cout << "Please enter the size of the array to be sorted: ";
  std::cin >> n;
  int * a = new int[n];
  std::cout << "Input : " << std::endl;
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 1000;
    std::cout << a[i] << "\t";
    if (n % 5 == 0) std::cout << std::endl;
  }
  queue<int> * q = new priorityQueue<int>(n);
  for (int i = 0; i < n; i++) {
    q->push(a[i]);
  }

  for (int i = 0; i < n; i++) {
    a[n-i] = q->top();
    q->pop();
  }

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << "\t";
    if (n % 5 == 0) std::cout << std::endl;
  }
  return 0;
}


