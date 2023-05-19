#include "list.h"
// #include <string>

template <class T>
list<T>::list() : _head(nullptr),_tail(nullptr),_end(nullptr),_size(0) {}

template <class T>
list<T>::list(int n):list() {
// throw n < 1     throw std::out_of_range("Incorrect input");
    for(int i = 0; i < n; i++) {
        Node *tmp = new Node();
        if (_head == nullptr) {
            _head = _tail = tmp;
            _end = new Node();

            _head->_next = tmp;
            tmp->_next = _tail;
            _tail->_next = _end;

            _end->_prev = _tail;
            _tail->_prev = tmp;
            tmp->_prev = _head;
        } else {
            tmp->_next = _head->_next;
            tmp->_prev = _head;

            _head->_next->_prev = tmp;
            _head->_next = tmp;
        }
        _end->_next = _head;
        _head->_prev = _end;
        _size++;
    }
}


template <class T>
list<T>::list(const list &l) : list(l._size) {
    iter iter(l._head);
    while(_head != _end) {
        _head->_data = *iter;
        _head = _head->_next;
        ++iter;
    }
    _head = _end->_next; 

}


template <class T>
list<T>::list(list&& l) {
    // _head = l._head;
    // _tail = l._tail;



}
template <class T>
void list<T>::operator=(list &&l)  {
    // udalit' vse soderjimoe
    // malloc
    // equalizing
}

template <class T>
bool list <T>::empty(){
    bool ans = (_head == nullptr) ? true : false;
    return ans;
}

template <class T>
list<T>::~list(){ // ne rabotaet s 1 elementom
    if (_head && _head != _end) {
        while(_head->_next != _end) {
            Node *tmp = _head->_next;
            delete _head;
            _head = tmp;
            // delete tmp;
            // _head = _head->_next;
            // delete _head->_prev;
        }
    }
    if (_head) delete _head;
    if (_tail && _tail != _head) delete _tail;
    if (_end && _end != _head) delete _end;
    _head = _tail = _end = nullptr;
}


// ######################################################

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

    Node *tmp = new Node(value);
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

    Node *tmp = new Node(value);
    if (!_head) {
        _head = _tail = tmp;
        _end = new Node();

        _head->_next = tmp;
        tmp->_next = _tail;
        _tail->_next = _end;

        _end->_prev = _tail;
        _tail->_prev = tmp;
        tmp->_prev = _head;
    } else {
        tmp->_next = _head;
        _head->_prev = tmp;
        _head = tmp;

    }
    _end->_next = _head;
    _head->_prev = _end;

    
    // Node *tmp = new Node(value);
    // if(_head == nullptr){
    //     _head = _tail = tmp;
    //     _end = new Node();
    //     tmp->_next = _end;
    //     _end->_prev = _tail;
    // } else {
    //     tmp->_next = _head;
    //     _head->_prev = tmp;
    //     _head = tmp;
    // }
    // _end->_next = _head;
    // _head->_prev = _end;
    _size++;

}

template <class T>
void list<T>::pop_front(){ // leaks 100%
    if (_head == nullptr) throw std::out_of_range("nothing to pop");
    if (_size == 1) {
        delete _end;
        delete _head;
        _head = _tail = _end = nullptr;
    } 
    else {
        Node * tmp = _head->_next;
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
int list<T>::size() { // ne rabotaet s pop'om. hz po4
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
typename list<T>::iter list<T>::Begin() {
    return _head;
}


template <class T>
typename list<T>::iter  list<T>::End() {
    return _end;
}

// void list::swap(list& other){



// }


// void list::merge(list& other){



// }

template <class T>
void list<T>::reverse(){
    // throw 0 elements 
    iter iterator_head(_head);
    iter iterator_tail(_tail);
    Node * tmp_h = _head;
    Node * tmp_t = _tail;
    T data = *iterator_head;

    for(int i = 0; i < _size / 2;i++) {
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
void list<T>::erase(iter pos) {
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
            // iter tmp_iter(pos._current_node->_prev);
            pos._current_node->_prev->_next = pos._current_node->_next;
            pos._current_node->_next->_prev = pos._current_node->_prev;
            Node* tmp = pos._current_node;
            pos._current_node = pos._current_node->_prev;
            delete tmp;     // LEAK IDK HOW TO FIX when erase, ++, erase
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
void list<T>::unique(){
    iter end_iter(_end);
    for(iter iter_i(_head); iter_i != end_iter; ++iter_i) {
        int counter = 0;
        for(iter iter_j(iter_i._current_node->_next); iter_j != end_iter; ++iter_j) {
            if (*iter_i == *iter_j){ 
                erase(iter_j);
                iter_j = Begin();
                for(int i = 0; i < counter; i++) {
                    iter_j._current_node = iter_j._current_node->_next;
                }
            }
            // if (*iter_i == *iter_j) erase(iter_j), iter_j = Begin();
            counter++;
        }
    }

}

template <class T>
void list<T>::sort(){
// throw if T is not a number


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
list<T>::iter::iter():_current_node(nullptr) { 
}


template <class T>
list<T>::iter::iter(Node* value):_current_node(value) { 
}


template <class T>
list<T>::iter::iter(const iter &value){ 
    _current_node = value._current_node;
}


template <class T>
list<T>::iter::~iter() {
    _current_node = nullptr;
}


template <class T>
T& list<T>::iter::operator*() {
    return _current_node->_data;
}



template <class T>
void list<T>::iter::operator++() {
    _current_node = _current_node->_next;
}



template <class T>
void list<T>::iter::operator--() {
    _current_node = _current_node->_prev;
}



template <class T>
bool list<T>::iter::operator==(iter &value) {
    bool ans = false;
    if (_current_node == value._current_node) ans = true;
    return ans;
}


template <class T>
bool list<T>::iter::operator!=(iter &value) {
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
    a.push_front(1);
    a.push_front(2);
    a.push_front(3);
    // a.push_front(4);
    // a.push_front(5);
    // a.push_front(1);
    // a.push_front(2);
    // a.push_front(1);
    a.PrintList();

    // a.push_back(0);
    // a.push_front(6);
    // list<int>b(a);
    // b.PrintList();


    // std::cout << ans << std::endl;
    // std::cout << ans2 << std::endl;
    // a.push_front(223);
    // a.push_front(4);
    // a.push_front(5);
    // a.push_front(6);
    // a.push_front(7);
    // a.push_front(8);


    list<int>::iter iterator(a._head);
    // list<int>::iter iterator2(a._head);
    // bool ans = iterator2==iterator;
    // bool ans2 = iterator2!=iterator;
    
    // ++iterator;
    // a.erase(iterator);
    // // std::cout << &iterator << " ";
    // ++iterator;
    // a.erase(iterator);
    // std::cout << &iterator;
    // ++iterator;
    // a.erase(iterator);
    // ++iterator;
    // a.erase(iterator);

    // ++iterator;
    // ++iterator;
    // ++iterator;
    // std::cout << *iterator << std::endl;
    // iterator--;
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    
    // std::cout << a.empty()<< '\n' << a.size()  <<  std::endl;


    // a.push_back (2);
    // a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);
    // a.push_back(6);
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();

    // a.pop_back();
    // a.pop_back();
    // a.push_front(5);


    // a.PrintList();
    a.unique();
    a.PrintList();


    // a.reverse();
    // a.PrintList();
    // a.reverse();
    // a.PrintList();
    
    // std::cout << a.size() << std::endl;
    
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_back();
    // a.pop_front();
    // a.pop_back();

    // a.push_back(5);
    // a.PrintList();
    // a.push_front(7);
    // a.printList();
    // std::cout << std:: endl;
    // a.printList();
    

    // std::cout << a._next->_data << std::endl;
    // a.printList();
}

// template class list<int>;
// template class list<double>;
// template class list<float>;
// template class list<std::string>;