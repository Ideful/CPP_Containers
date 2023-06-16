#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <iostream>
#include <limits>
#include <initializer_list>

namespace s21{
    template <class T>

    class Stack {
        public:
            using value_type = T;
            using reference = T &;
            using const_reference = const T &;
            using size_type = size_t;
            Stack();
            Stack(std::initializer_list<value_type> const &items);
            Stack(const Stack &n);
            Stack(Stack &&n);
            ~Stack();
            void Clear();
            void operator=(Stack &&n);
            void operator=(Stack &n);
            void Copier(const Stack &n);
            void Mover(Stack &n);
            const_reference Top();
            bool Empty();
            size_type Size();
            void Push(const_reference val);
            void Pop();
            void Swap(Stack& val);
            void PrintStack();

            template <typename... Args>
            void EmplaceFront(Args &&...args);
            struct Node{
                value_type _data;
                Node* _next = nullptr;
                Node(): _data(),_next(nullptr){};
                Node (const_reference val) : _data(val), _next(nullptr) {};
            };
            private:
            Node* _head = nullptr;
            size_type _size = 0;

    };
}


#include "stack.tpp"
#endif //  SRC_STACK_H_
