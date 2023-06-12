#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include <iostream>
#include <limits>
#include <initializer_list>

namespace s21{
template <class T>

class List {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;
        List();
        List(size_type n); /* size_type n */
        List(std::initializer_list<value_type> const &items); // cho za items
        List(const List &l);
        List(List &&l);
        ~List();
        List& operator=(List &&l);
        List& operator=(List &l);

        void ParCons(size_type n);
        void Cpy(const List &l);

        const_reference Front() const noexcept;	  //      access the first element
        const_reference Back() const noexcept;	  //      access the last element
        bool Empty() const noexcept;  //	checks whether the container is empty
        size_type Size()  noexcept;	// returns size
        size_type MaxSize() const noexcept;	// check node qty
        void Clear() noexcept; //	clears the contents
        void PushFront(value_type value); //	adds an element to the end
        void PushBack(value_type value); //	adds an elements to the head
        void PopFront(); //	removes the first element
        void PopBack(); //	removes the last element
        void Swap(List& other);  //	swaps the contents
        void Merge(List& other); //	merges two sorted lists
        void Reverse() noexcept; //	reverses the order of the elements
        void Unique()noexcept; //	removes consecutive duplicate elements
        void Sort()noexcept; //	sorts the elements
        void PrintList();
        
        // fields:
        struct Node{
                value_type _data = 0;
                Node *_prev = nullptr;
                Node *_next = nullptr;
                Node() : _data(), _prev(nullptr), _next(nullptr){};
                Node(T value) : _data(value), _prev(nullptr), _next(nullptr){};
        };
        private:
                Node* _head = nullptr;
                Node* _tail = nullptr;
                Node* _end = nullptr;
                int _size;
        
        public:

        class ListIterator {
                public:
                        ListIterator();
                        ListIterator(Node* value):_current_node(value){}
                        ListIterator(const ListIterator &value):_current_node(value._current_node){}
                        ~ListIterator(){};
                        reference operator*();
                        void operator++();
                        void operator--();
                        bool operator==(const ListIterator &value) const;
                        bool operator!=(const ListIterator &value) const;
                        ListIterator& operator=(ListIterator other) noexcept;
                        int FindIndex(List &a);
                        Node* _current_node = nullptr;
                        int _index;
        };
        using iterator = ListIterator;

        class ListConstIterator: public iterator{
                public:
                        ListConstIterator() {_current_node = nullptr;}
                        ListConstIterator(Node* value) {_current_node = value; }
                        ListConstIterator(const ListConstIterator &value): _current_node(value._current_node) {} 
                        ListConstIterator(const ListIterator value): iterator(value) {} 
                        ~ListConstIterator(){};
                        const_reference operator*();
                        ListConstIterator& operator=(ListConstIterator other);
                        Node* _current_node = nullptr;  
        };
        using const_iterator = ListConstIterator;





        public:
        void Erase(iterator pos) noexcept;	//erases element at pos
        void KindOfQS(int head_iter, int tail_iter);
        int Partition(int start, int end);
        void Splice(const_iterator pos, List& other) noexcept; //	transfers elements from List other starting from pos
        void Swapper(iterator a, iterator b);
        iterator Begin();
        iterator End();  
        iterator Insert(iterator pos, const_reference value); //	inserts elements into concrete pos and returns the iterator that points to the new element

        template <typename... Args>
        iterator Emplace(const_iterator pos, Args&&... args);
        template <typename... Args>
        void EmplaceFront(Args&&... args);
        template <typename... Args>
        void EmplaceBack(Args&&... args);
};
}
#include "list.tpp"

#endif //  SRC_LIST_H_

// include tpp i ubrat iz tpp header

