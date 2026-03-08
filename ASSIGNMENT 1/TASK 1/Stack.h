#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    T* arr;
    int topIndex;
    int capacity;

public:
    Stack(int size = 100);
    ~Stack();

    bool push(T value);
    T pop();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

#endif