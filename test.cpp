//
// Created by YilingYu on 2020/10/25.
//

#include <iostream>
#include <cstdlib>
#include "queue.h"
#include "priorityQueue.h"

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

