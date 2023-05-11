#include "list.h"

list::list() : _head(nullptr),_tail(nullptr),_end(nullptr) {
}

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

list::~list(){
    // if (_head) delete _head;
    // if (_tail) delete _tail;
    // if (_end) delete _end;
    // _head = _tail = _end = nullptr;
}


// ######################################################


// void list::clear() {



// }

void list::push_back(int value){
    // Node *tmp = new Node(value);
    // if (_head == nullptr && _tail == nullptr && _end == nullptr) {
    //     _head = tmp;
    //     _tail = tmp;
    //     _head->_data = value;
    //     _tail->_data = value;
        
    //     _end = new Node();
    //     _head->_prev = _end;
    //     _head->_next = _tail;

    //     _end->_next = _head;
    //     _end->_prev = _tail;
        
    //     _tail->_next = _end;
    //     _tail->_prev = _head;
    // } else {
    //     Node *tmp2 = _tail;
    //     _tail = tmp;
    //     _tail->_prev = tmp2;
    //     _tail->_next = _end;
    //     _end->_prev= _tail;
    //     _head->_next = tmp2;
    // }

}


void list::push_front(int value){
    if (_head == nullptr && _tail == nullptr && _end == nullptr) {
        _head = new Node();
        _end = new Node();
        _tail = new Node();

        _head->_data = value;
        _head->_next = _end;
        _head->_prev = _end;

        _flag = 1;
    } else if (_flag == 1) {
        _tail->_data = _head->_data;
        _head->_data = value;

        _head->_next = _tail;
        _tail->_next = _end;
        _end->_next = _head;

        _head->_prev = _end;
        _end->_prev = _tail;
        _tail->_prev = _head;

        _flag = 2;
    } else if (_flag == 2) { 
        Node* tmp = new Node(_head->_data);
        _head->_data = value;
        
        tmp->_prev = _head;
        tmp->_next = _tail;
        
        _head->_next = tmp;
        _tail->_prev = tmp;

        _flag = 3;
    } else if (_flag == 3) {
        Node* tmp = new Node(_head->_data);
        tmp->_next = _head->_next;
        tmp->_prev = _head;

        _head->_data = value;
        _head->_next = tmp;
    }

    // if (_head == nullptr && _tail == nullptr && _end == nullptr) {
    //     _head = tmp;
    //     _tail = tmp;
    //     _head->_data = value;
    //     _tail->_data = value;

    //     _end = new Node();
    //     _end->_next = _head;
    //     _end->_prev = _tail;

    //     _head->_prev = _end;
    //     _head->_next = _tail;

    //     _tail->_next = _end;
    //     _tail->_prev = _head;
    // } else {
    //     Node *tmp2 = new Node();
    //     tmp2 = _head;
    //     _head = tmp;
    //     _head->_prev = _end;
    //     _head->_next = tmp2;
    //     _end->_next = _head;
    //     _end->_prev = _tail;

    // }

}

void list::pop_back(){

}


void list::pop_front(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else {
        Node *tmp = _head->_next;
        _head = tmp;
        _head->_prev = _end;
        _head->_next = tmp->_next;
        _end->_next = _head;
    }
}


// void list::swap(list& other){



// }


// void list::merge(list& other){



// }


// void list::reverse(){



// }


// void list::unique(){



// }


// void list::sort(){



// }

void list::printList() {
    int k = 0;
    while(_head != _end) {
        std::cout << _head->_data << std:: endl;
        _head = _head->_next;
    }

    _head = _end->_next;
}


int main() {
    list a;
    a.push_front(2);
    a.push_front(3);
    a.push_front(4);
    a.push_front(5);
    a.push_front(6);
    a.push_front(7);
    a.pop_front();
    // a.push_back(5);
    a.printList();
    // std::cout << std:: endl;
    // a.printList();
    

    // std::cout << a._next->_data << std::endl;
    // a.printList();
}