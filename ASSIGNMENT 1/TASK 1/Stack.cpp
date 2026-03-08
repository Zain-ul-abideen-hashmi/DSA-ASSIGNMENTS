#include "Stack.h"

template <typename T>
Stack<T>::Stack(int size) : capacity(size), topIndex(-1) {
    arr = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <typename T>
bool Stack<T>::isEmpty() const { return topIndex == -1; }

template <typename T>
bool Stack<T>::isFull() const { return topIndex == capacity - 1; }

template <typename T>
bool Stack<T>::push(T value) {
    if (isFull()) return false;
    arr[++topIndex] = value;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) return T(); 
    return arr[topIndex--];
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) return T();
    return arr[topIndex];
}

// Explicit Instantiation for Part A (char) and Part B (int)
template class Stack<char>;
template class Stack<int>;
