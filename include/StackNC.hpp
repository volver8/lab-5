// Copyright 2020 CrestoniX

#ifndef INCLUDE_STACKNC_HPP_
#define INCLUDE_STACKNC_HPP_

#include "MyStack.hpp"

template<class T>
class StackNC : public MainStack<T> {
public:
    template <typename ... Args>
    void push_emplace(Args &&... value)
    {
        auto *prevNode = MainStack<T>::headNode;

        MainStack<T>::headNode = new StackNode<T>{
                {std::forward<Args>(value)...},
                prevNode,
        };
    }

    T pop()
    {
        if (!MainStack<T>::headNode) {
            throw std::exception();
        }

        auto *prevNode = MainStack<T>::headNode;
        MainStack<T>::headNode = MainStack<T>::headNode->previous;

        T value = std::move(prevNode->value);
        delete prevNode;
        return value;
    }
};


#endif //INCLUDE_STACKNC_HPP_
