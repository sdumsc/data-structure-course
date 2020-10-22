#include <sstream>
#include "dcLinkedList.h"
#include "myException.h"

template<class T>
dcLinkedList<T>::dcLinkedList(int initialCapacity) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw myException(0, s.str());
    }
    listSize = 0;
    head = nullptr;
}

template <class T>
dcLinkedList<T>::dcLinkedList(const dcLinkedList<T>& x) {
    listSize = x.listSize;

    if(listSize == 0) {
        head = nullptr;
        return;
    } else {
        node* sourceNode = x.head;
        head = new node(sourceNode->element);
        node* prevNode = head;
        for (int i = 1; i < x.listSize; i++) {
            sourceNode = sourceNode->next;
            node* newNode = new node(sourceNode->element);
            newNode->prev = prevNode;
            prevNode->next = newNode;
            prevNode = prevNode->next;
        }
        prevNode->next = head;
        head->prev = prevNode;
    }
}

template<class T>
T& dcLinkedList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    node* tmp = head;
    for (int i = 0;  i < theIndex; i++)
        tmp = tmp->next;
    return tmp->element;
}

template<class T>
int dcLinkedList<T>::indexOf(const T& theElement) const {
    node* tmp = head;
    for (int i = 0; i < listSize; i++) {
        if (tmp->element == theElement)
            return i;
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
void dcLinkedList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    node* prevNode = head->prev;
    if(head->next == nullptr) {
        delete head;
        listSize--;
        return;
    }
    if (theIndex < listSize/2) {
        for (int i = 0; i < theIndex; i++)
            prevNode = prevNode->next;
    } else {
        for (int i = 0; i < listSize - theIndex; i++) {
            prevNode = prevNode->prev;
        }
    }
    node* tmp = prevNode->next;
    prevNode->next = prevNode->next->next;
    prevNode->next->prev = prevNode;
    delete tmp;
    listSize--;
}

template<class T>
void dcLinkedList<T>::insert(int theIndex, const T& theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "the index = " << theIndex << " the listSize = " << listSize;
        throw myException(1, s.str());
    }
    if (head == nullptr) {
        head = new node(theElement);
        listSize++;
        return;
    }
    if (head->next == nullptr) {
        node* newNode = new node(theElement, head, head);
        head->next = newNode;
        head->prev = newNode;
        if (theElement == 0)
            head = newNode;
        listSize++;
        return;
    }
    node* prevNode = head->prev;
    if (theIndex < listSize/2) {
        for (int i = 0; i < theIndex; i++)
            prevNode = prevNode->next;
    } else {
        for (int i = 0; i < listSize - theIndex; i++) {
            prevNode = prevNode->prev;
        }
    }
    node* newNode = new node(theElement, prevNode, prevNode->next);
    prevNode->next->prev = newNode;
    prevNode->next = newNode;
    listSize++;
}

template<class T>
void dcLinkedList<T>::output(std::ostream& out) const {
    node* tmp = head;
    for (int i = 0; i < listSize; i++) {
        out << tmp->element << "  ";
        tmp = tmp->next;
    }
}

template<class T>
dcLinkedList<T>::~dcLinkedList<T>() {
    while (head != nullptr) {
        node* tmp = head;
        delete head;
        head = tmp->next;
    }
}

template<class T>
void dcLinkedList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "the index = " << theIndex << " the listSize = " << listSize;
        throw myException(1, s.str());
    }
}

int main(void) {
    linearList<double>* a = new dcLinkedList<double>();

    for (int i = 0; i < 100; i++) {
        a->insert(i, i * 3.2);
    }

    std::cout << *a;

    return 0;
}