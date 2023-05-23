// https://github.com/Ideful/CPP_Containers
#include "list.h"

template <class T>
list<T>::list() : _head(nullptr),_tail(nullptr),_end(nullptr),_size(0) {}

template <class T>
void list<T>::ParCons(size_type n){
    if(n < 1) throw std::out_of_range("Incorrect input");
    for(int i = 0; i < n; i++) {
        Node *tmp = new Node();
        if (_head == nullptr) {
            _head = _tail = tmp;
            _end = new Node();
            tmp->_prev = _end;
            _end->_next = _head;
        } else {
            tmp->_prev = _tail;
            _tail->_next = tmp;
            _tail = tmp;
        }
        _end->_prev = _tail;
        _tail->_next = _end;
        _size++;
    }
}


template <class T>
list<T>::list(size_type n):list() { 
    ParCons(n);
}


template <class T>
list<T>::list(std::initializer_list<value_type> const &items){
    for(auto iter = items.begin(); iter != items.end(); ++ iter){
        PushBack(*iter);
    }
}


template <class T>
list<T>::list(const list &l) : list(l._size) {
    ListIterator ListIterator(l._head);
    while(_head != _end) {
        _head->_data = *ListIterator;
        _head = _head->_next;
        ++ListIterator;
    }
    _head = _end->_next; 
}


template <class T>
list<T>::list(list&& l) {
    _size = l._size;
    _head = l._head;
    _end = l._end;
    _tail = l._tail;
    l._head = l._tail = l._end = nullptr;
}


template <class T>
void list<T>::Cpy(list l) {
    Destructor();
    ParCons(l._size);
    Node *tmp(l._head);
    while(_head != _end) {
        _head->_data = tmp->_data;
        _head = _head->_next;
        tmp = tmp->_next;
    }
    _head = _end->_next;
}


template <class T>
typename list<T>::list& list<T>::operator=(list &&l)  {
    Cpy(l);
    return *this;
}


template <class T>
typename list<T>::list& list<T>::operator=(list &l)  {
    Cpy(l);
    return *this; 
}


template <class T>
bool list <T>::Empty(){
    bool ans = (_head == nullptr) ? true : false;
    return ans;
}


template <class T>
void list<T>::Swapper(iterator a, iterator b){
    value_type tmp = *a;
    *a = *b;
    *b = tmp;
}


template <class T>
void list<T>::Destructor(){
    if (_head && _head != _end) {
        while(_head->_next != _end) {
            Node *tmp = _head->_next;
            delete _head;
            _head = tmp;
        }
    }
    if (_head) delete _head;
    if (_end && _end != _head) delete _end;
    _head = _tail = _end = nullptr;
}



template <class T>
list<T>::~list(){ 
    Destructor();
}

template <class T>
typename list<T>::size_type list<T>::MaxSize(){
    size_type counter = 0;
    Node * tmp(_head);
    while(tmp != _end) {
        tmp = tmp->_next;
        counter++;
    }
    return counter;
}

// ######################################################


template <class T>
typename list<T>::const_reference list<T>::Front() {
    return _head->_data;
}


template <class T>
typename list<T>::const_reference list<T>::Back() {
    return _tail->_data;
}


template <class T>
void list<T>::Clear() {
    while(_head != _end) {
    Node *tmp = _head->_next;
        delete _head; // a esli eto ne chislo???
        _head = tmp;
    }
    if (_end) delete _end;
    _size = 0;
}


template <class T>
void list<T>::PushBack(T value){

    Node* tmp = new Node(value);
    if(_head == nullptr){
        _head = _tail = tmp;
        _end = new Node();
        tmp->_prev = _end;
        _end->_next = _head;
    } 
    else {
        tmp->_prev = _tail;
        _tail->_next = tmp;
        _tail = tmp;
    }
    _end->_prev = _tail;
    _tail->_next = _end;
    _size++;
}


template <class T>
void list<T>::PushFront(T value){
    Node* newnode = new Node(value);
    if (!_head) {
        _head = _tail = newnode;
        _end = new Node();
        _tail->_next = _end;
        _end->_prev = _tail;
    } else {
        newnode->_next = _head;
        _head->_prev = newnode;
        _head = newnode;
    }
    _end->_next = _head;
    _head->_prev = _end;

    _size++;
}


template <class T>
void list<T>::PopFront(){
    if (_head == nullptr) throw std::out_of_range("nothing to pop");
    if (_size == 1) {
        delete _end;
        delete _head;
        _head = _tail = _end = nullptr;
    } 
    else {
        Node* newnode = _head->_next;
        _head = newnode;
        newnode = newnode->_prev;
        delete newnode;
        _head->_prev = _end;
        _end->_next = _head;
    }
    _size--;
}


template <class T>
void list<T>::PopBack(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    if (_size == 1) {
        delete _end;
        delete _tail;
        _head = _tail = _end = nullptr;
    } 
    else{
        Node * tmp = _tail->_prev;
        _tail = tmp;
        tmp = tmp->_next;
        delete tmp;
        _tail->_next = _end;    
        _end->_prev = _tail;
    }
    _size--;
}


template <class T>
typename list<T>::size_type list<T>::Size() { // ne rabotaet s pop'om. hz po4
    if(_head == nullptr) throw std::out_of_range("list is empty");
    int res = 0;
    while(_head != _end) {
        _head = _head->_next;
        res++;
    }
    _head = _end->_next;

    return res;
}


template <class T>
typename list<T>::ListIterator list<T>::Begin() {
    return _head;
}


template <class T>
typename list<T>::ListIterator  list<T>::End() {
    return _end;
}


template <class T>
void list<T>::Swap(list& other){
    list tmp;
    tmp.Cpy(other);
    other.Destructor();
    other.Cpy(*this);
    Destructor();
    Cpy(tmp);
}


template <class T>
void list<T>::Merge(list& other){
    ListIterator pos = other._head;
    Splice(pos,other);
    Sort();
}

template <class T>
void list<T>::Splice(typename list<T>::const_iterator pos, list& other) {
    int cnt = 0;
    ListIterator tmp = pos;
    while(pos._current_node != other._end) {
        cnt++;
        ++pos;
    }
    ListIterator qwe(_tail);
    ParCons(cnt);
    for(int i = 0; i < cnt; i++) {
        ++qwe;
        *qwe = *tmp;
        ++tmp;
    }

}


template <class T>
void list<T>::Reverse(){
    // throw 0 elements 
    ListIterator iterator_head(_head);
    ListIterator iterator_tail(_tail);
    Node * tmp_h = _head;
    Node * tmp_t = _tail;
    T data = *iterator_head;

    for(int i = 0; i < _size / 2; i++) {
        tmp_h->_data = *iterator_tail;
        tmp_t->_data = data;

        tmp_h = tmp_h->_next;
        tmp_t = tmp_t->_prev;

        data = tmp_h->_data;
        ++iterator_head;
        --iterator_tail;
    }
}


template <class T>
void list<T>::Erase(typename list<T>::iterator pos) {
    if (_size == 0) throw std::out_of_range("list is empty");
    if (_size == 1) PopBack(); // eto ne to4no
    else {
        if (pos._current_node == _head) {
            PopFront();
        } else if (pos._current_node == _tail) {
            PopBack();
        } else if (pos._current_node == _end) {
            // throw?
        } else {
            pos._current_node->_prev->_next = pos._current_node->_next;
            pos._current_node->_next->_prev = pos._current_node->_prev;
            Node* tmp = pos._current_node;
            pos._current_node = pos._current_node->_prev;
            delete tmp;     
            tmp = nullptr;
        }
    }
    _size--;
}


template <class T>
typename list<T>::iterator list<T>::Insert(iterator pos, const_reference value) {
    // throw
    iterator newpos(_head);
    if (pos._current_node == _head) {
        PushFront(value);
    } else if (pos._current_node == _tail) {
        PushBack(value);
        --newpos;
    } else {
        int index = pos.FindIndex(*this);
        for (int i = 0; i < index; i++) {
            ++newpos; // tut mb kosyaque
        }
        Node* newval = new Node(value);

        newpos._current_node->_prev->_next = newval;
        newval->_next = newpos._current_node;

        newval->_prev = newpos._current_node->_prev;
        newpos._current_node->_prev = newval;
    }
    return newpos;
}


template <class T>
void list<T>::Unique(){
    ListIterator end_iter(_end);
    for(ListIterator iter_i(_head); iter_i != end_iter; ++iter_i) {
        for(ListIterator iter_j(iter_i._current_node->_next); iter_j != end_iter; ++iter_j) {
            if (*iter_i == *iter_j){ 
                Erase(iter_j);
                iter_j = iter_i._current_node->_next;
            }
        }
    }

}


template <class T>
void list<T>::KindOfQS(int start, int end) {
    if (start < end) {
        int pivot_index = Partition(start,end);
        KindOfQS(start, pivot_index - 1);
        KindOfQS(pivot_index + 1, end);
    }
}


template <class T>
int list<T>::Partition(int start, int end) {
    iterator pivot(_head);
    for(int i = 0; i < end; i++) {
        ++pivot;
    }
    int i = start - 1; // vse ok
    for(int j = start; j <= end - 1; j++) { // mb ne nujen -1
        iterator jchecker(_head);
        for(int k = 0; k < j; k++) {
            ++jchecker;
        }
        if (*jchecker < *pivot) {
            i++;
            iterator ichecker(_head);
            for(int z = 0; z < i; z++) {
                ++ichecker;
            }            
            Swapper(ichecker,jchecker);
        }
    }
    i++;
    iterator ichecker(_head);
    for(int k = 0; k < i; k++) {
        ++ichecker;
    }
    Swapper(ichecker,pivot);
    return (i);
}


template <class T>
void list<T>::Sort(){
// throw if T is not a number
    iterator head_iter(_head);
    iterator end(_tail);
    int end_iter = end.FindIndex(*this);
    KindOfQS(0, end_iter);
}

template <class T>
void list<T>::PrintList() {
    int k = 0;
    if (_head != nullptr) {
        while(_head != _end) {
            std::cout << _head->_data << std:: endl;
            _head = _head->_next;
        }
        _head = _end->_next;
        std::cout << std:: endl;
    }

}

// iterator ####################################################################

template <class T>
list<T>::ListIterator::ListIterator():_current_node(nullptr) { 
}


template <class T>
list<T>::ListIterator::ListIterator(Node* value):_current_node(value) { 
}


template <class T>
list<T>::ListIterator::ListIterator(const ListIterator &value){ 
    _current_node = value._current_node;
}


template <class T>
typename list<T>::reference list<T>::ListIterator::operator*() {
    return _current_node->_data;
}


template <class T>
void list<T>::ListIterator::operator++() {
    _current_node = _current_node->_next;
}


template <class T>
int list<T>::ListIterator::FindIndex(list &a){ 
    size_type res = 0;
    Node * tmp = _current_node;
    while(tmp != a._head){ 
        tmp = tmp->_prev;
        res++;
    }
    return res;
}


template <class T>
void list<T>::ListIterator::operator--() {
    _current_node = _current_node->_prev;
}


template <class T>
bool list<T>::ListIterator::operator==(ListIterator &value) {
    return (_current_node == value._current_node) ? true : false;
}


template <class T>
bool list<T>::ListIterator::operator!=(ListIterator &value) {
    return !operator==(value);
}


// const iterator ##############################################################


template <class T>
list<T>::ListConstIterator::ListConstIterator(ListConstIterator &value){
    _current_node = value._current_node;
}


template <class T>
list<T>::ListConstIterator::ListConstIterator(Node* value) {
    _current_node = value;
}


template <class T>
typename list<T>::const_reference list<T>::ListConstIterator::operator*() {
    return _current_node->_data;
}


template <class T>
void list<T>::ListConstIterator::operator--() {
    _current_node = _current_node->_prev;
}


template <class T>
void list<T>::ListConstIterator::operator++() {
    _current_node = _current_node->_next;
}


// template <class T>
// bool list<T>::ListConstIterator::operator==(ListConstIterator &value) {
//     return (_current_node == value._current_node) ? true : false;
// }


// template <class T>
// bool list<T>::ListConstIterator::operator!=(ListConstIterator &value) {
//     return !(operator==(value));
// }


// bonus          ##############################################################


template <class T>
template <typename... Args>
void list<T>::EmplaceFront(Args &&...args) {
    ([&] { PushFront(args); }(), ...);
}


template <class T>
template <typename... Args>
void list<T>::EmplaceBack(Args &&...args) {
    ([&] { PushBack(args); }(), ...);
}


template <class T>
template <typename... Args>
typename list<T>::iterator list<T>::Emplace(const_iterator pos, Args &&...args) {
    iterator iter = pos;    
    ([&] { Insert(pos, args); }(), ...);
    --iter;
    return iter;
}


int main() {
    // list<std::string> a;
    // std::string z("qwe");
    // std::string q("zxc");
    // a.PushFront(z);
    // a.PushFront(q);

    // list<int> a(4);
    // list<int> a{11, 22, 13, 434, 5};
    list<int>a;
    a.PushFront(7);
    a.PushFront(8);
    a.PushFront(9);
    a.PushFront(10);
    a.PushFront(11);
    a.PushFront(22);
    a.PushFront(12);


    a.PrintList();
    list<int>::iterator qwe(a._head->_next);
    *qwe = 12321421;
    std::cout<<"\n\n\n"<<a._head->_next->_data<<std::endl;

    list<int>::const_iterator qwew(a._head->_next);
    // *qwew = 98;
    // std::cout<<"\n\n\n"<<a._head->_next->_data<<std::endl;
    ++qwew;
    ++qwew;
    std::cout<<"\n\n\n"<<*qwew<<std::endl;
    // qwe = a.Insert(qwe,22);
    // a.Sort();
    // a.PushFront(7);
    // a.PushFront(8);
    // a.PushFront(9);
    // a.PushFront(10);
    // a.PushFront(11);
    // a.PushFront(12);
    // a.PushFront(0);
    // a.push_back(-2);
    // a.push_back(0);
    // a.ParCons(8);

    // a.erase(qwe);

    // list<int> b(std::move(a));
    // list <int> b;
    // list <int> c;
    // c = std::move(a);
    // b = a;
    
    // c.PrintList();
    // a.PushFront(6);
    // a.PushFront(9);
    // a.PushFront(1);
    // a.PushFront(2);
    // a.PushFront(1);
    // a.PushFront(2);
    // a.PrintList();
    // std::cout<<a._size<<"\n\n\n";
    // a.push_back(0);
    // a.PushFront(6);
    // list<int>b(a);
    // b.PrintList();
    // list<int> b(3);
    // std::cout << b.max_size();
    // std::cout << ans << std::endl;
    // std::cout << ans2 << std::endl;
}