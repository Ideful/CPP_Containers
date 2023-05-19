#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include <iostream>

template <class T>

class list {
    public:

        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        // using const_iterator = iter<T>; //???
        using size_type = size_t;

        list();
        list(size_type n); /* size_type n */
        list(const list &l);
        list(list &&l);
        ~list();
        void operator=(list &&l);




        // List Element access
// const_reference front()	access the first element
// const_reference back()	access the last element

        // List Iterators
// iterator begin()	returns an iterator to the beginning
// iterator end()	returns an iterator to the end

        // List Capacity
bool empty(); //	checks whether the container is empty

// size_type size()	returns the number of elements
int size();

size_type max_size();	
 
        // List Modifiers
void clear(); //	clears the contents
// insert(iterator pos, const_reference value)	inserts elements into concrete pos and returns the iterator that points to the new element
void push_front(T value); //	adds an element to the end
void push_back(T value); //	adds an element to the head
void pop_front(); //	removes the first element
void pop_back(); //	removes the last element
// void swap(list& other);  //	swaps the contents
// void merge(list& other); //	merges two sorted lists
// // void splice(const_iterator pos, list& other); //	transfers elements from list other starting from pos
void reverse(); //	reverses the order of the elements
void unique(); //	removes consecutive duplicate elements
void sort(); //	sorts the elements
void PrintList();


        // fields:
        struct Node{
                T _data;
                Node *_prev;
                Node *_next;
                Node() : _data(), _prev(nullptr), _next(nullptr){};
                Node(T value) : _data(value), _prev(nullptr), _next(nullptr){};
                // ~Node() {
                //         while(_head->_next != _end) {
                //                 delete _head->_data;
                //                 delete _head->_prev;
                //         }
                // };
        };
        Node* _head;
        Node* _tail;
        Node* _end;
        int _size;


        class iter {
                public:
                        iter();
                        iter(Node* value);
                        iter(const iter &value);
                        ~iter();
                        Node* _current_node = nullptr;
                        T& operator*();
                        void operator++();
                        void operator--();
                        bool operator==(iter &value);
                        bool operator!=(iter &value);

        };
        using iterator = iter;
        public:
        void erase(iter pos);	//erases element at pos
        iter Begin();
        iter End();  
};


// Каждый вид контейнеров должен предоставить пользователю следующие методы:
// -    стандартные конструкторы (конструктор по умолчанию, конструктор копирования, конструктор перемещения, 
//      конструктор со списком инициализации, см. материалы);
// -    методы доступа к элементам контейнера (например, осуществление доступа к элементу с индексом i);
// -    методы проверки наполненности контейнера (например, количество элементов в контейнере, проверка на пустоту контейнера);
// -    методы изменения контейнера (удаление и добавление новых элементов, очистка контейнера);
// -    методы для работы с итератором контейнера.

//-  Контейнеры предоставляют через методы `begin()` и `end()` итераторы, 
//   которые указывают на первый и следующий после последнего элементы контейнера соответственно.

//   Над итератором `iter` определены следующие операции:

//   - `*iter`: получение элемента, на который указывает итератор;
//   - `++iter`: перемещение итератора вперед для обращения к следующему элементу;
//   - `--iter`: перемещение итератора назад для обращения к предыдущему элементу;
//   - `iter1 == iter2`: два итератора равны, если они указывают на один и тот же элемент;
//   - `iter1 != iter2`: два итератора не равны, если они указывают на разные элементы.


//   В объекте класса контейнера хранятся указатели на "голову" и "хвост" списка, 
//   указывающие на первый и последний элементы списка. 
//   Контейнер List предоставляет прямой доступ только к "голове" и "хвосту", 
//   но позволяет добавлять и удалять элементы в любой части списка.


 #endif //  SRC_LIST_H_

// include tpp i ubrat iz tpp header

