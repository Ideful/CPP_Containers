#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include <iostream>
#include <limits>


template <class T>

class list {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;
        list();
        list(size_type n); /* size_type n */
        list(std::initializer_list<value_type> const &items); // cho za items
        list(const list &l);
        list(list &&l);
        ~list();
        list& operator=(list &&l);
        list& operator=(list &l);

        void Destructor();
        void ParCons(size_type n);
        void Cpy(list &l);

        const_reference Front();	  //      access the first element
        const_reference Back();	  //      access the last element
        bool Empty(); //	checks whether the container is empty
        size_type Size();	// returns size
        size_type MaxSize();	// check node qty
        void Clear(); //	clears the contents
        void PushFront(value_type value); //	adds an element to the end
        void PushBack(value_type value); //	adds an elements to the head
        void PopFront(); //	removes the first element
        void PopBack(); //	removes the last element
        void Swap(list& other);  //	swaps the contents
        void Merge(list& other); //	merges two sorted lists
        void Reverse(); //	reverses the order of the elements
        void Unique(); //	removes consecutive duplicate elements
        void Sort(); //	sorts the elements
        void PrintList();
        
        // fields:
        struct Node{
                value_type _data;
                Node *_prev;
                Node *_next;
                Node() : _data(), _prev(nullptr), _next(nullptr){};
                Node(T value) : _data(value), _prev(nullptr), _next(nullptr){};
        };
        Node* _head;
        Node* _tail;
        Node* _end;
        int _size;

        class ListIterator {
                public:
                        ListIterator();
                        ListIterator(Node* value);
                        ListIterator(const ListIterator &value);
                        ~ListIterator(){};
                        reference operator*();
                        void operator++();
                        void operator--();
                        bool operator==(ListIterator &value);
                        bool operator!=(ListIterator &value);
                        int FindIndex(list &a);

                        Node* _current_node = nullptr;
                        int _index;
        };
        using iterator = ListIterator;

        class ListConstIterator: public ListIterator{
                public:
                        ListConstIterator():_current_node(nullptr){};
                        ListConstIterator(Node* value);
                        ListConstIterator(ListConstIterator &value); // hz
                        // ~ListConstIterator():{};
                        const_reference operator*();
                        void operator++();
                        void operator--();
                        // bool operator==(ListConstIterator &value);
                        // bool operator!=(ListConstIterator &value);                      
                        Node* _current_node = nullptr;  
                        // int _index();        // ??? a nado li eto
        };
        using const_iterator = ListConstIterator;

        public:
        void Erase(iterator pos);	//erases element at pos
        void KindOfQS(int head_iter, int tail_iter);
        int Partition(int start, int end);
        void Splice(const_iterator pos, list& other); //	transfers elements from list other starting from pos
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
#endif //  SRC_LIST_H_

// include tpp i ubrat iz tpp header

