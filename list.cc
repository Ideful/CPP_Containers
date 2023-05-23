#include "list.h"
// #include <string>

template <class T>
list<T>::list() : _head(nullptr),_tail(nullptr),_end(nullptr),_size(0) {}

template <class T>
void list<T>::Par_Cons(size_type n){
    //throw throw std::out_of_range("Incorrect input");
    for(int i = 0; i < n; i++) {
        Node *tmp = new Node();
        if (_head == nullptr) {
            _head = _tail = tmp;
            _end = new Node();
            // _tail->_next = _end;
            // _end->_prev = _tail;
            tmp->_prev = _end;
            _end->_next = _head;
        } else {
            // tmp->_next = _head->_next;
            // tmp->_prev = _head;

            // _head->_next->_prev = tmp;
            // _head->_next = tmp;


            tmp->_prev = _tail;
            _tail->_next = tmp;
            _tail = tmp;
        }
        _end->_prev = _tail;
        _tail->_next = _end;
        // _end->_next = _head;
        // _head->_prev = _end;
        _size++;
    }
}


template <class T>
list<T>::list(size_type n):list() { // nado ukoroteet'
    Par_Cons(n);
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
    Par_Cons(l._size);
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
bool list <T>::empty(){
    bool ans = (_head == nullptr) ? true : false;
    return ans;
}

template <class T>
void list<T>::swapper(ListIterator a, ListIterator b){
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
    // if (_tail) delete _tail;
    if (_end && _end != _head) delete _end;
    _head = _tail = _end = nullptr;
}



template <class T>
list<T>::~list(){ 
    Destructor();
}

template <class T>
typename list<T>::size_type list<T>::max_size(){
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
typename list<T>::const_reference list<T>::front() {
    return _head->_data;
}

template <class T>
typename list<T>::const_reference list<T>::back() {
    return _tail->_data;
}


template <class T>
void list<T>::clear() {
    Node *tmp = _head;
    while(tmp != _end) {
        tmp->_data = 0; // a esli eto ne chislo???
        tmp=tmp->_next;
    }
}


template <class T>
void list<T>::push_back(T value){

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
void list<T>::push_front(T value){
    Node* tmp = new Node(value);
    if (!_head) {
        _head = _tail = tmp;
        _end = new Node();
        _tail->_next = _end;
        _end->_prev = _tail;
    } else {
        tmp->_next = _head;
        _head->_prev = tmp;
        _head = tmp;
    }
    _end->_next = _head;
    _head->_prev = _end;

    _size++;
}

template <class T>
void list<T>::pop_front(){
    if (_head == nullptr) throw std::out_of_range("nothing to pop");
    if (_size == 1) {
        delete _end;
        delete _head;
        _head = _tail = _end = nullptr;
    } 
    else {
        Node* tmp = _head->_next;
        _head = tmp;
        tmp = tmp->_prev;
        delete tmp;

        _head->_prev = _end;
        _end->_next = _head;
    }
    _size--;
}



template <class T>
void list<T>::pop_back(){
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
typename list<T>::size_type list<T>::size() { // ne rabotaet s pop'om. hz po4
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
void list<T>::swap(list& other){
    list tmp;
    tmp.Cpy(other);
    other.Destructor();
    other.Cpy(*this);
    Destructor();
    Cpy(tmp);
}


template <class T>
void list<T>::merge(list& other){
    ListIterator pos = other._head;
    splice(pos,other);
    sort();
}

template <class T>
void list<T>::splice(typename list<T>::const_iterator pos, list& other) {
    int cnt = 0;
    ListIterator tmp = pos;
    while(pos._current_node != other._end) {
        cnt++;
        ++pos;
    }
    ListIterator qwe(_tail);
    Par_Cons(cnt);
    for(int i = 0; i < cnt; i++) {
        ++qwe;
        *qwe = *tmp;
        ++tmp;
    }

}



template <class T>
void list<T>::reverse(){
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
void list<T>::erase(ListIterator pos) {
    if (_size == 0) throw std::out_of_range("list is empty");
    if (_size == 1) pop_back(); // eto ne to4no
    else {
        if (pos._current_node == _head) {
            pop_front();
        } else if (pos._current_node == _tail) {
            pop_back();
        } else if (pos._current_node == _end) {
            // throw?
        } else {
            // ListIterator tmp_iter(pos._current_node->_prev);
            pos._current_node->_prev->_next = pos._current_node->_next;
            pos._current_node->_next->_prev = pos._current_node->_prev;
            Node* tmp = pos._current_node;
            pos._current_node = pos._current_node->_prev;
            delete tmp;     
            tmp = nullptr;
            // Node* tmp = pos._current_node->_prev;
            // delete pos._current_node; //udalaet tmp nahuy
            // --pos;
            // pos = tmp;
        }
    }
    _size--;
}


template <class T>
typename list<T>::ListIterator list<T>::insert(ListIterator pos, const_reference value)
{
    // throw
    ListIterator newpos(_head);
    if (pos._current_node == _head) {
        push_front(value);
    } else if (pos._current_node == _tail) {
        push_back(value);
        --newpos;
    } else {
        int index = pos.find_index(*this);
        for (int i = 0; i < index; i++) {
            ++newpos; // tut mb kosyaque
        }
        Node* newval = new Node(value);

        newpos._current_node->_prev->_next = newval;
        newval->_next = newpos._current_node;
        newpos._current_node->_prev = newval;
        newval->_prev = newpos._current_node->_prev;
    }
    return newpos;
}


template <class T>
void list<T>::unique(){
    ListIterator end_iter(_end);
    // int c1 = 0;
    for(ListIterator iter_i(_head); iter_i != end_iter; ++iter_i) {
        // int c2 = 0;
        for(ListIterator iter_j(iter_i._current_node->_next); iter_j != end_iter; ++iter_j) {
            if (*iter_i == *iter_j){ 
                erase(iter_j);
                // c1--;
                // iter_j = Begin();
                iter_j = iter_i._current_node->_next;
                // int counter = c1+c2;
                // for(int i = 0; i < counter-1; i++) {
                //     iter_j._current_node = iter_j._current_node->_next;
                // }
            }
            // if (*iter_i == *iter_j) erase(iter_j), iter_j = Begin();
            // PrintList();
            // c2++;
        }
        // c1++;
    }

}


template <class T>
void list<T>::kind_of_qs(int start, int end) {
    if (start < end) {
        int pivot_index = partition(start,end);
        kind_of_qs(start, pivot_index - 1);
        kind_of_qs(pivot_index + 1, end);
    }
}


template <class T>
int list<T>::partition(int start, int end) {
    iterator pivot(_head);
    for(int i = 0; i < end; i++) {
        ++pivot;
    }
        //  pivot = pivot

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
            swapper(ichecker,jchecker);
        }
    }
    i++;
    iterator ichecker(_head);
    for(int k = 0; k < i; k++) {
        ++ichecker;
    }
    swapper(ichecker,pivot);
    return (i);
}

template <class T>
void list<T>::sort(){
// throw if T is not a number
    iterator head_iter(_head);
    iterator end(_tail);
    int end_iter = end.find_index(*this);
    kind_of_qs(0, end_iter);
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
list<T>::ListIterator::~ListIterator() {
    _current_node = nullptr;
}


template <class T>
T& list<T>::ListIterator::operator*() {
    return _current_node->_data;
}



template <class T>
void list<T>::ListIterator::operator++() {
    _current_node = _current_node->_next;
    // _index++;
}

template <class T>
int list<T>::ListIterator::find_index(list &a){ 
    size_type res = 0;
    while(_current_node != a._head){ 
        _current_node = _current_node->_prev;
        res++;
    }
    return res;
}


template <class T>
void list<T>::ListIterator::operator--() {
    _current_node = _current_node->_prev;
    // _index--;
}



template <class T>
bool list<T>::ListIterator::operator==(ListIterator &value) {
    bool ans = false;
    if (_current_node == value._current_node) ans = true;
    return ans;
}


template <class T>
bool list<T>::ListIterator::operator!=(ListIterator &value) {
    return !operator==(value);
}


// inerator ####################################################################






int main() {
    // list<std::string> a;
    // std::string z("qwe");
    // std::string q("zxc");
    // a.push_front(z);
    // a.push_front(q);

    // list<int> a(4);
    list<int> a;
    a.push_front(7);
    a.push_front(8);
    a.push_front(9);
    a.push_front(10);
    a.push_front(11);
    a.push_front(12);
    // a.push_front(0);
    // a.push_back(-2);
    // a.push_back(0);
    // a.Par_Cons(8);


    // list<int> b(std::move(a));
    list <int> b;
    // list <int> c;
    // c = std::move(a);
    // b = a;
    
    // c.PrintList();
    // a.push_front(6);
    // a.push_front(9);
    // a.push_front(1);
    // a.push_front(2);
    // a.push_front(1);
    // a.push_front(2);
    a.PrintList();
    // std::cout<<a._size<<"\n\n\n";
    // a.push_back(0);
    // a.push_front(6);
    // list<int>b(a);
    // b.PrintList();
    // list<int> b(3);
    // std::cout << b.max_size();
    // std::cout << ans << std::endl;
    // std::cout << ans2 << std::endl;
    b.push_front(1);
    b.push_front(2);
    b.push_front(3);
    b.push_front(4);
    b.push_front(5);
    b.push_front(6);
    
    
    b.PrintList();

    list<int>::ListIterator it(b._head->_next);
    // a.merge(b);
    a.splice(it,b);

    // a.swap(b);
    a.PrintList();
    // b.PrintList();

    // a.PrintList();
}