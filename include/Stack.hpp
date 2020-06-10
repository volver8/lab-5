// Copyright 2020 CrestoniX
#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include "MyStack.hpp"

template<class T>
class Stack: public MainStack<T> {
public:
    void push(const T &value)
    {
        auto *prevNode =  MainStack<T>::headNode;

        MainStack<T>::headNode = new StackNode<T>{
                value,
                prevNode,
        };
    }

    void pop()
    {
        if (!MainStack<T>::headNode) {
            throw std::exception();
        }

        auto *prevNode = MainStack<T>::headNode;
        MainStack<T>::headNode = MainStack<T>::headNode->previous;

        delete prevNode;
    }
};

#endif //INCLUDE_STACK_HPP_
