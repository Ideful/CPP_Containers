#include "list.h"
// #include <string>

template <class T>
list<T>::list() : _head(nullptr),_tail(nullptr),_end(nullptr),_size(0) {}

// list::list(int n) {
// // for(int i = 0; i < n;i++) {

// // }

// }

// list::list(const list &l) {



// }

// list::list(list&& l) {



// }

// list list::operator=(list &&l) {



// }

template <class T>
list<T>::~list(){ // ne rabotaet s 1 elementom
    if (_head && _head != _end) {
        while(_head->_next != _end) {
            Node *tmp = _head->_next;
            delete _head;
            _head = tmp;
            // _head = _head->_next;
            // delete _head->_prev;
        }
    }
    if (_head) delete _head;
    if (_end && _end != _head) delete _end;
    // _head = _tail = _end = nullptr;
}


// ######################################################


// void list::clear() {



// }
template <class T>
void list<T>::push_back(T value){
    // if (_head == nullptr || _tail == nullptr || _end == nullptr) {
    //     _head = new Node();
    //     _end = new Node();
    //     _tail = new Node();

    //     _head->_data = value;
    //     _head->_next = _end;
    //     _head->_prev = _end;

    //     _flag = 1;
    // } else if (_flag == 1) {
    //     _tail->_data = value;
    //     _head->_next = _tail;
    //     _tail->_next = _end;
    //     _end->_next = _head;

    //     _end->_prev = _tail;
    //     _tail->_prev = _head;

    //     _flag = 2;
    // } else if (_flag == 2) { 
    //     Node* tmp = new Node(_tail->_data);
    //     _tail->_data = value;
        
    //     tmp->_prev = _head;
    //     tmp->_next = _tail;
        
    //     _head->_next = tmp;
    //     _tail->_prev = tmp;

    //     _flag = 3;
    // } else if (_flag >= 3) {
    //     Node* tmp = new Node(_tail->_data);
    //     tmp->_next = _tail;
    //     tmp->_prev = _tail->_prev;

    //     _tail->_data = value;
    //     _tail->_prev = tmp;
    //     _tail->_prev->_prev->_next = _tail->_prev;
    //     _flag++;
    // }


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

    // if (_head == nullptr || _tail == nullptr || _end == nullptr) {
    //     _head = new Node();
    //     _end = new Node();
    //     _tail = new Node();

    //     _head->_data = value;
    //     _head->_next = _end;
    //     _head->_prev = _end;

    //     _flag = 1;
    // } else if (_flag == 1) {
    //     _tail->_data = _head->_data;
    //     _head->_data = value;

    //     _head->_next = _tail;
    //     _tail->_next = _end;
    //     _end->_next = _head;

    //     _end->_prev = _tail;
    //     _tail->_prev = _head;

    //     _flag = 2;
    // } else if (_flag == 2) { 
    //     Node* tmp = new Node(_head->_data);
    //     _head->_data = value;
        
    //     tmp->_prev = _head;
    //     tmp->_next = _tail;
        
    //     _head->_next = tmp;
    //     _tail->_prev = tmp;

    //     _flag = 3;
    // } else if (_flag >= 3) {
    //     Node* tmp = new Node(_head->_data);
    //     tmp->_next = _head->_next;
    //     tmp->_prev = _head;

    //     _head->_data = value;
    //     _head->_next = tmp;
    //     _head->_next->_next->_prev = _head->_next;
    //     _flag++;
    // }


    Node *tmp = new Node(value);
    if(_head == nullptr){
        _head = _tail = tmp;
        _end = new Node();
        tmp->_next = _end;
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
void list<T>::pop_back(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else {
        Node * tmp = _tail->_prev;
        _tail = tmp;
        _tail->_next = _end;    
        _end->_prev = _tail;
    }
    _size--;
}



template <class T>
void list<T>::pop_front(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else {
        Node * tmp = _head->_next;
        _head = tmp;
        _head->_prev = _end;
        _end->_next = _head;
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



// void list::swap(list& other){



// }


// void list::merge(list& other){



// }

template <class T>
void list<T>::reverse(){
    list<T>::iter iterator_head(_head);
    list<T>::iter iterator_tail(_tail);
    Node * tmp_h = _head;
    Node * tmp_t = _tail;
    T data = *iterator_head;

    for(int i = 0; i < _size/2;i++) {
        tmp_h->_data = *iterator_tail;
        tmp_t->_data = data;

        tmp_h = tmp_h->_next;
        tmp_t = tmp_t->_prev;

        data = tmp_h->_data;
        ++iterator_head;
        --iterator_tail;
    }
}


// void list::unique(){



// }

template <class T>
void list<T>::sort(){
    


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
list<T>::iter::iter():_current_node(nullptr) { // esli v skobkah _head -> hueta
}

template <class T>
list<T>::iter::iter(Node* value):_current_node(value) { // esli v skobkah _head -> hueta
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

    list<int> a;

    // a.push_front(2);
    // a.push_front(3);
    // a.push_front(4);
    // a.push_front(5);
    // a.push_front(6);




    // std::cout << ans << std::endl;
    // std::cout << ans2 << std::endl;
    a.push_front(223);
    a.push_front(4);
    a.push_front(5);
    // a.push_front(6);
    // a.push_front(7);
    // a.push_front(8);


    // list<int>::iter iterator(a._head);
    // list<int>::iter iterator2(a._head);
    // bool ans = iterator2==iterator;
    // bool ans2 = iterator2!=iterator;
    
    // ++iterator;
    // ++iterator;
    // std::cout << *iterator << std::endl;
    // iterator--;
    a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    
    a.push_back (2);
    a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);
    // a.push_back(6);
    // std::cout << a.size() << '\n' << std::endl;
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();

    // a.pop_back();
    // a.pop_back();
    // a.push_front(5);


    a.PrintList();
    a.reverse();
    a.PrintList();
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