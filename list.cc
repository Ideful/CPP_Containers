#include "list.h"
// #include <string>

template <class T>
list<T>::list() : _head(nullptr),_tail(nullptr),_end(nullptr),_flag(0) {}

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
    if (_end) delete _end;
    // if (_tail) delete _tail;
    // _head = _tail = _end = nullptr;
}


// ######################################################


// void list::clear() {



// }
template <class T>
void list<T>::push_back(T value){
    if (_head == nullptr || _tail == nullptr || _end == nullptr) {
        _head = new Node();
        _end = new Node();
        _tail = new Node();

        _head->_data = value;
        _head->_next = _end;
        _head->_prev = _end;

        _flag = 1;
    } else if (_flag == 1) {
        _tail->_data = value;
        _head->_next = _tail;
        _tail->_next = _end;
        _end->_next = _head;

        _end->_prev = _tail;
        _tail->_prev = _head;

        _flag = 2;
    } else if (_flag == 2) { 
        Node* tmp = new Node(_tail->_data);
        _tail->_data = value;
        
        tmp->_prev = _head;
        tmp->_next = _tail;
        
        _head->_next = tmp;
        _tail->_prev = tmp;

        _flag = 3;
    } else if (_flag >= 3) {
        Node* tmp = new Node(_tail->_data);
        tmp->_next = _tail;
        tmp->_prev = _tail->_prev;

        _tail->_data = value;
        _tail->_prev = tmp;
        _tail->_prev->_prev->_next = _tail->_prev;
        _flag++;
    }

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

    } else {
        tmp->_next = _head;
        _head->_prev = tmp;
        _head = tmp;
    }
        _end->_next = _head;
        _head->_prev = _end;



    // Node *tmp = new Node(value);
    // if (_head == nullptr ) {
    //     _head = _tail = tmp;
    //     _head->_next = tmp;
    //     _head->_prev = _end;
    //     _head->_prev = _end;

    //     _flag = 1;
    // } else if (_flag == 1) {
    //     // _tail->_data = _head->_data;
    //     // _head->_data = value;

    //     // _head->_next = _tail;
    //     // _tail->_next = _end;
    //     // _end->_next = _head;

    //     // _end->_prev = _tail;
    //     // _tail->_prev = _head;

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

}

template <class T>
void list<T>::pop_back(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else if (_flag > 1) {
        if (_flag > 2) {
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
    } else if (_flag == 1) {
        delete _head;
        delete _tail;
        delete _end;
        _head = nullptr;
        _tail = nullptr;
        _end = nullptr;
    }
}

template <class T>
void list<T>::pop_front(){
    if(_head == nullptr) throw std::out_of_range("nothing to pop");
    else if (_flag > 1) {
        if (_flag > 2) {
            _head->_data = _head->_next->_data;
            _head->_next = _head->_next->_next;
            delete _head->_next->_prev;
            _head->_next->_prev = _head;
        } else {
            _tail->_data = _head->_data;
            _head->_next = _end;
            _head->_prev = _end;
            _tail->_next = _end;
            _tail->_prev = _end;
        }
        _flag--;
    } else if (_flag == 1) {
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

    a.push_front(2);
    a.push_front(3);
    list<int>::iter iterator(a._head);
    list<int>::iter iterator2(a._head);


    bool ans = iterator2==iterator;
    bool ans2 = iterator2!=iterator;
    
    std::cout << ans << std::endl;
    std::cout << ans2 << std::endl;
    // a.push_front(4);
    // a.push_front(5);
    // a.push_front(6);
    // a.push_front(7);
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
    
    // a.push_back(2);
    // a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);
    // a.push_back(6);
    // a.PrintList();

    // a.pop_back();
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