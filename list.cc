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
    // delete head;
    // delete tail;
    // delete prev;
    // delete next;
}


// ######################################################


// void list::clear() {



// }

// void list::push_back(int a){



// }


void list::push_front(int value){
    Node *tmp = new Node(value);
    if (_head == nullptr && _tail == nullptr && _end == nullptr) {
        _head = tmp;
        _tail = tmp;
    } else {
        Node *tmp2 = tmp;
        _head = tmp;
        _head->_next = tmp2;
        _head->_prev = _end;
    }
    _end = new Node();
    _end->_next = _head;
    _end->_prev = _tail;
}

// void list::pop_back(){



// }


// void list::pop_front(){



// }


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
    std::cout << this->_head->_data << std:: endl;
}


int main() {
    list a;
    a.push_front(2);
    // a.printList();
    a.push_front(3);
    
    // a.printList();
    a.push_front(4);
    a.printList();
    int b = 2;
    // std::cout << a._next->_data << std::endl;
    // a.printList();
}