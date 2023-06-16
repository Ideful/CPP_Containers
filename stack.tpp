// https://github.com/Ideful/CPP_Containers
// #include "stack.h"
namespace s21{
    template <typename T>
    Stack<T>::Stack(): _head(nullptr),_size(0) {}

    template <typename T>
    Stack<T>::Stack(std::initializer_list<T> const &items) {
        typename std::initializer_list<T>::iterator it = items.begin();
        for(size_type i = 0; items.size() > i; i++) {
            Push((*it));
            it++;
        }
    }

    template <typename T>
    void Stack<T>::Clear() {
        while(_head != nullptr) {
            Node* tmp = _head;
            _head = _head->_next;
            delete tmp;
        }    
        _head = nullptr;
    }

    template <class T>
    void Stack<T>::operator=(Stack &&n) {
        Mover(n);
        // return this;
    // }
    }

    template <class T>
    void Stack<T>::operator=(Stack &n) {
        Copier(n);
    }

    template <typename T>
    Stack<T>::Stack(const Stack &n) {
        Copier(n);
    }

    template <typename T>
    Stack<T>::Stack(Stack &&n) {
        Mover(n);
    }


    template <typename T>
    void Stack<T>::Copier(const Stack &n) {
        Node * tmp = n._head;
        Stack revstack;
        while(tmp) {
            revstack.Push(tmp->_data);
            tmp = tmp->_next;
        }
        Node * tmp2 = revstack._head;
        while(tmp2) {
            Push(tmp2->_data);
            tmp2 = tmp2->_next;
        }
    }


    template <class T>
    void Stack<T>::Mover(Stack &n){
        _head = n._head;
        _size = n._size;
        n._head = nullptr;
        n._size = 0;
    }

    
    template <class T>
    typename Stack<T>::const_reference Stack<T>::Top() {
        if (_head) return _head->_data;
        else (throw std::out_of_range("empty stack"));
    }

    
    template <class T>
    bool Stack<T>::Empty(){
        return _head == nullptr ? true : false;
    }

    
    template <class T>
    typename Stack<T>::size_type Stack<T>::Size() {
        return _size;
    }

    template <typename T>
    Stack<T>::~Stack(){
        Clear();
    }


    template <typename T>
    void Stack<T>::Push(const_reference val) {
        Node* tmp = new Node(val);
        if (!_head) {
            _head = tmp;
        } else {
            Node* tmp2 = _head;
            _head = tmp;
            _head->_next = tmp2;
        }
        _size++;
    }

    template <typename T>
    void Stack<T>::Pop(){
        if (_size > 0) {
            Node* tmp = _head;
            _head = _head->_next;
            delete tmp;
            _size--;
        } 
        // else {
        //     throw std::out_of_range("nothing to pop");
        // }
        
    }

    template <class T>
    void Stack<T>::Swap(Stack &val){
        Stack tmp(std::move(val));
        val = std::move(*this);
        *this = std::move(tmp);
        
    }

template <typename T>
template <typename... Args>
void Stack<T>::EmplaceFront(Args &&...args) {
    ([&] { Push(args); }(), ...);
}


    template <typename T>
    void Stack<T>::PrintStack() {
        Node * tmp = _head;
        while(tmp != nullptr) {
            std::cout<<tmp->_data<<std::endl;
            tmp = tmp->_next;
        }
    }
}

// int main() {
//     s21::Stack<int> qwe{2,3,4,5};
//     s21::Stack<int> zxc{22,24,25,7};
//     qwe.Swap(zxc);
//     // qwe.Push(2);
//     // qwe.Push(23);
//     // qwe.Push(23);
//     // qwe.Push(23);
//     // qwe.Push(23);
//     qwe.PrintStack();
//     std::cout<<'\n';
//     std::cout<<'\n';
//     zxc.PrintStack();
    
// }