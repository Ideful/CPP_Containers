// // https://github.com/Ideful/CPP_Containers
// #include "queue.h"

// namespace s21 {
//     template <class T>
//     Queue<T>::Queue(): _head(nullptr),_tail(nullptr),_size(0) {}


//     template <class T>
//     Queue<T>::Queue(std::initializer_list<value_type> const &items){

//     }

//     template <class T>
//     Queue<T>::~Queue() {
//         // while(_head) {
//         //     Node * tmp = _head->_next;
//         //     delete _head;
//         //     _head = _head->_next;
//         // }
//         _head = _tail = nullptr;
//     }

// // delete iz head, add v tail
//     template <class T>
//     void Queue<T>::Push(const_reference val) {
//         Node * newnode = new Node(val);
//         if (!_tail) _tail = _head = newnode; 
//         else if (_size == 1) {
//             _tail = newnode;
//             _head->_next = _tail;
//         } else {
//             Node* tmp2 = _tail;
//             for(int i = 0; i <= _size; i++) {
                
//             }
//         }
//         _size++;
//     }

//     template <class T>
//     void Queue<T>::Pop() {
//         Node * tmp(_head->_next);
//         delete _head;
//         _head = tmp;
//     }

//     template <class T>
//     void Queue<T>::PrintQ() {
//         Node * tmp = _head;
//         while(tmp) {
//             std::cout<<tmp->_data<<std::endl;
//             tmp = tmp->_next;      
//         }
//     }


//     // template <class T>
//     // template <class T>
//     // template <class T>
//     // template <class T>
//     // template <class T>





// }

// int main() {
//     s21::Queue<int> a;
//     a.Push(2);
//     a.Push(3);
//     a.Push(4);
//     // a.Push(5);
//     a.PrintQ();
// }