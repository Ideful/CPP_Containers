#include "list.h"

list::list() : _head(nullptr),_tail(nullptr),_end(nullptr),_flag(0) {
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
    if (_head == nullptr || _tail == nullptr || _end == nullptr) {
        _head = new Node();
        _end = new Node();
        _tail = new Node();

        _head->_data = value;
        _head->_next = _end;
        _head->_prev = _end;

        _flag = 2;
    } else if (_flag == 2) {
        _tail->_data = value;
        _head->_next = _tail;
        _tail->_next = _end;
        _end->_next = _head;

        _end->_prev = _tail;
        _tail->_prev = _head;

        _flag = 3;
    } else if (_flag == 3) { 
        Node* tmp = new Node(_tail->_data);
        _tail->_data = value;
        
        tmp->_prev = _head;
        tmp->_next = _tail;
        
        _head->_next = tmp;
        _tail->_prev = tmp;

        _flag = 4;
    } else if (_flag >= 4) {
        Node* tmp = new Node(_tail->_data);
        tmp->_next = _tail;
        tmp->_prev = _tail->_prev;

        _tail->_data = value;
        _tail->_prev = tmp;
        _tail->_prev->_prev->_next = _tail->_prev;
        _flag++;
    }

}


void list::push_front(int value){
    if (_head == nullptr || _tail == nullptr || _end == nullptr) {
        _head = new Node();
        _end = new Node();
        _tail = new Node();

        _head->_data = value;
        _head->_next = _end;
        _head->_prev = _end;

        _flag = 2;
    } else if (_flag == 2) {
        _tail->_data = _head->_data;
        _head->_data = value;

        _head->_next = _tail;
        _tail->_next = _end;
        _end->_next = _head;

        _end->_prev = _tail;
        _tail->_prev = _head;

        _flag = 3;
    } else if (_flag == 3) { 
        Node* tmp = new Node(_head->_data);
        _head->_data = value;
        
        tmp->_prev = _head;
        tmp->_next = _tail;
        
        _head->_next = tmp;
        _tail->_prev = tmp;

        _flag = 4;
    } else if (_flag >= 4) {
        Node* tmp = new Node(_head->_data);
        tmp->_next = _head->_next;
        tmp->_prev = _head;

        _head->_data = value;
        _head->_next = tmp;
        _head->_next->_next->_prev = _head->_next;
        _flag++;
    }
}

void list::pop_back(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else if (_flag >2) {
        if (_flag != 3) {
            _tail->_data = _tail->_prev->_data;
            _tail->_prev = _tail->_prev->_prev;
            _tail->_prev->_next = _tail;
        } else {
            _tail->_data = _head->_data;
            _head->_next = _end;
            _head->_prev = _end;
            _tail->_next = _end;
            _tail->_prev = _end;
        }
        _flag--;
    } else if (_flag == 2) {
        delete _head;
        delete _tail;
        delete _end;
        _head = nullptr;
        _tail = nullptr;
        _end = nullptr;
    }
}


void list::pop_front(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else if (_flag >2) {
        if (_flag != 3) {
            _head->_data = _head->_next->_data;
            _head->_next = _head->_next->_next;
            _head->_next->_prev = _head;
        } else {
            _tail->_data = _head->_data;
            _head->_next = _end;
            _head->_prev = _end;
            _tail->_next = _end;
            _tail->_prev = _end;
        }
        _flag--;
    } else if (_flag == 2) {
        delete _head;
        delete _tail;
        delete _end;
        _head = nullptr;
        _tail = nullptr;
        _end = nullptr;
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
    if (_head != nullptr) {
        while(_head != _end) {
            std::cout << _head->_data << std:: endl;
            _head = _head->_next;
        }
        _head = _end->_next;
        std::cout << std:: endl;
    }

}


int main() {
    list a;
    // a.push_front(2);
    // a.push_front(3);
    // a.push_front(4);
    // a.push_front(5);
    // a.push_front(6);
    // a.push_front(7);

    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    // a.pop_front();
    
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);

    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    // a.pop_back();

    // a.push_back(5);
    a.printList();
    // std::cout << std:: endl;
    // a.printList();
    

    // std::cout << a._next->_data << std::endl;
    // a.printList();
}