// https://github.com/Ideful/CPP_Containers
#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include <iostream>
#include <limits>
#include <initializer_list>
#include "listiterators.h"

namespace s21{
template <typename T>

class List {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;
        class ListIterator;
        class ListConstIterator;
        using iterator = ListIterator;
        using const_iterator = ListConstIterator;

        List();
        List(size_type n); /* size_type n */
        List(std::initializer_list<value_type> const &items); // cho za items
        List(const List &l);
        List(List &&l);
        ~List();
        List& operator=(List &&l);
        List& operator=(List &l);

        void ParCons(size_type n);
        void Cpy(const List &l);

        const_reference Front() const noexcept;	  //      access the first element
        const_reference Back() const noexcept;	  //      access the last element
        bool Empty() const noexcept;  //	checks whether the container is empty
        size_type Size()  noexcept;	// returns size
        size_type MaxSize() const noexcept;	// check node qty
        void Clear() noexcept; //	clears the contents
        void PushFront(value_type value); //	adds an element to the end
        void PushBack(value_type value); //	adds an elements to the head
        void PopFront(); //	removes the first element
        void PopBack(); //	removes the last element
        void Swap(List& other);  //	swaps the contents
        void Merge(List& other); //	merges two sorted lists
        void Reverse() noexcept; //	reverses the order of the elements
        void Unique()noexcept; //	removes consecutive duplicate elements
        void Sort()noexcept; //	sorts the elements
        void PrintList();

        struct Node{
                value_type data_;
                Node* prev_ = nullptr;
                Node* next_ = nullptr;
                Node() : data_(), prev_(nullptr), next_(nullptr){};
                Node(const T value) : data_(value), prev_(nullptr), next_(nullptr){};
        };

        private:
                Node* head_ = nullptr;
                Node* tail_ = nullptr;
                Node* end_;
                int size_;
                value_type var_ = 0;
                const_reference _variable = var_;

        public:
        class ListIterator {
                public:
                        ListIterator():current_node_(nullptr){}
                        ListIterator(Node* value):current_node_(value){}
                        ListIterator(const ListIterator &value):current_node_(value.current_node_), _index(value._index){}
                        ListIterator(const ListConstIterator &value):current_node_(value.current_node_), _index(value._index){}
                        ~ListIterator(){};
                        // reference operator*();
                        reference operator*(){return current_node_->data_;}
                        void operator++() { current_node_ = current_node_->next_;}
                        void operator--() { current_node_ = current_node_->prev_;}
                        
                        
                        bool operator==(const ListIterator &other) const {
                                return current_node_==other.current_node_;
                        }

                        bool operator!=(const ListIterator &other) const {
                                return current_node_!=other.current_node_;
                        }

                        ListIterator& operator=(ListIterator other) noexcept {
                                current_node_ = other.current_node_;
                                _index = other._index;
                                return *this;
                        }
                        size_type FindIndex(List &a) {
                                size_type res = 0;
                                Node * tmp = current_node_;
                                while(tmp != a.head_){ 
                                        tmp = tmp->prev_;
                                        res++;
                                }
                                return res;
                        }
                        Node* current_node_ = nullptr;
                        int _index;
        };

        class ListConstIterator: public ListIterator{
                public:
                        ListConstIterator() {current_node_ = nullptr;}
                        ListConstIterator(Node* value) {current_node_ = value; }
                        ListConstIterator(const ListConstIterator &value): current_node_(value.current_node_) {} 
                        ListConstIterator(const ListIterator value) {current_node_ = value.current_node_;} 
                        ~ListConstIterator(){};
                        void operator++() {current_node_ = current_node_->next_;}
                        bool operator!=(const ListIterator &value) {return (current_node_!=value.current_node_);}
                        const_reference operator*() {return current_node_->data_;}
                        ListConstIterator& operator=(ListConstIterator other) {
                                current_node_ = other.current_node_;
                                return *this;
                        };
                        Node* current_node_ = nullptr;  
        };

        public:
        void Erase(iterator pos) ;	//erases element at pos
        void KindOfQS(int head_iter, int tail_iter);
        int Partition(int start, int end);
        void Splice(const_iterator pos, List& other) noexcept; //	transfers elements from List other starting from pos
        void Swapper(iterator a, iterator b);
        iterator Begin();
        iterator End();  
        iterator Insert(iterator pos, const_reference value); //	inserts elements into concrete pos and returns the iterator that points to the new element

        template <typename... Args>
        iterator Emplace(const_iterator pos, Args&&... args);
        template <typename... Args>
        void EmplaceFront(Args&&... args);
        template <typename... Args>
        void EmplaceBack(Args&&... args);
};

template <typename T>
List<T>::List() : head_(nullptr),tail_(nullptr),end_(nullptr),size_(0) {}

template <typename T>
void List<T>::ParCons(size_type n){
    if (n < MaxSize()) {
        head_ = tail_ = end_ = nullptr, size_ = 0; 
        for(size_type i = 0; i < n; i++) {
            Node *tmp = new Node();
            if (head_ == nullptr) {
                head_ = tail_ = tmp;
                end_ = new Node();
                tmp->prev_ = end_;
            } else {
                tmp->prev_ = tail_;
                tail_->next_ = tmp;
                tail_ = tmp;
            }
            end_->next_ = head_;
            end_->prev_ = tail_;
            tail_->next_ = end_;
            size_++;
        }
    } 
}


template <typename T>
List<T>::List(size_type n):List() { 
    ParCons(n);
}


template <typename T>
List<T>::List(std::initializer_list<value_type> const& items) {
  typename std::initializer_list<T>::iterator it = items.begin();
  value_type size = 0;
  for (size_type i = 0; items.size() > i; i++) {
    PushBack(*it);
    it++;
    size++;
  }
  size_ = size;
}


template <typename T>
List<T>::List(const List &l) : List(l.size_) {
    ListIterator ListIterator(l.head_);
    Node * tmp(head_);
    while(tmp != end_) {
        tmp->data_ = *ListIterator;
        tmp = tmp->next_;
        ++ListIterator;
    }
}


template <typename T>
List<T>::List(List&& other){
    head_ = std::exchange(other.head_,nullptr);
    tail_ =std::exchange(other.tail_,nullptr);
    end_ = std::exchange(other.end_,nullptr);
    size_ = std::exchange(other.size_,0);
}


template <typename T>
void List<T>::Cpy(const List &l) {
    Clear();
    ParCons(l.size_);
    Node *tmp(l.head_);
    if (l.size_ > 0) {
        while(head_ != end_) {
            head_->data_ = tmp->data_;
            head_ = head_->next_;
            tmp = tmp->next_;
        }
        head_ = end_->next_;
    }

}


template <typename T>
typename List<T>::List& List<T>::operator=(List &&other)  {
    Clear();
    head_ = std::exchange(other.head_,nullptr);
    tail_ =std::exchange(other.tail_,nullptr);
    end_ = std::exchange(other.end_,nullptr);
    size_ = std::exchange(other.size_,0);
    return *this;
}


template <typename T>
typename List<T>::List& List<T>::operator=(List &l)  {
    Cpy(l);
    return *this; 
}


template <typename T>
bool List <T>::Empty() const noexcept {
//     return (head_ == nullptr) ? true : false;
        return size_ == 0;
}


template <typename T>
void List<T>::Swapper(iterator a, iterator b){
    value_type tmp = *a;
    *a = *b;
    *b = tmp;
}


template <typename T>
List<T>::~List(){ 
    Clear();
}

template <typename T>
typename List<T>::size_type List<T>::MaxSize() const noexcept{
    return std::numeric_limits<std::size_t>::max() / sizeof(Node) / 2;
}

// ######################################################


template <typename T>
typename List<T>::const_reference List<T>::Front() const noexcept {
    if (head_ && head_->data_ ) return  head_->data_;
    else return _variable;
}


template <typename T>
typename List<T>::const_reference List<T>::Back() const noexcept {
    if (tail_ && tail_->data_) return tail_->data_;
    else return _variable;
}


template <typename T>
void List<T>::Clear() noexcept{
    while (!Empty()) {PopBack();}
}


template <typename T>
void List<T>::PushBack(typename List<T>::value_type value){
    Node* tmp = new Node(value);
    if(head_ == nullptr){
        head_ = tail_ = tmp;
        end_ = new Node();
        tmp->prev_ = end_;
        end_->next_ = head_;
    } 
    else {
        tmp->prev_ = tail_;
        tail_->next_ = tmp;
        tail_ = tmp;
    }
    end_->prev_ = tail_;
    tail_->next_ = end_;
    size_++;
}


template <typename T>
void List<T>::PushFront(typename List<T>::value_type value){
    Node* newnode = new Node(value);
    if (!head_) {
        head_ = tail_ = newnode;
        end_ = new Node();
        tail_->next_ = end_;
        end_->prev_ = tail_;
    } else {
        newnode->next_ = head_;
        head_->prev_ = newnode;
        head_ = newnode;
    }
    end_->next_ = head_;
    head_->prev_ = end_;

    size_++;
}


template <typename T>
void List<T>::PopFront(){
    if (head_ == nullptr) throw std::out_of_range("nothing to pop");
    if (size_ == 1) {
        delete end_;
        delete head_;
        head_ = tail_ = end_ = nullptr;
    } 
    else {
        Node* newnode = head_->next_;
        head_ = newnode;
        newnode = newnode->prev_;
        delete newnode;
        head_->prev_ = end_;
        end_->next_ = head_;
    }
    size_--;
}


template <typename T>
void List<T>::PopBack(){
    if(head_ == nullptr) throw std::out_of_range("nothing to pop");
    if (size_ == 1) {
        delete end_;
        delete tail_;
        head_ = tail_ = end_ = nullptr;
    } 
    else{
        Node * tmp = tail_->prev_;
        tail_ = tmp;
        tmp = tmp->next_;
        delete tmp;
        tail_->next_ = end_;    
        end_->prev_ = tail_;
    }
    size_--;
}


template <typename T>
typename List<T>::size_type List<T>::Size()  noexcept { // 
    int res = 0;
    while(head_ != end_) {
        head_ = head_->next_;
        res++;
    }
    if(head_) head_ = end_->next_;
    return res;
}


template <typename T>
typename List<T>::ListIterator List<T>::Begin() {
    iterator res(head_);
    if (!head_) {
        Node* tmp = new Node();
        iterator qwe(tmp);
        res = qwe;
        res.current_node_->data_ = 0;
        delete tmp;
    }
    return res;
    // return head_ ? iterator(head_) : iterator(end_);
}


template <typename T>
typename List<T>::ListIterator  List<T>::End() {
    iterator res(end_);
    return res;
}


template <typename T>
void List<T>::Swap(List& other){
    List tmp(other);
    other.Clear();
    other.Cpy(*this);
    Clear();
    Cpy(tmp);
}


template <typename T>
void List<T>::Merge(List& other){
    iterator this_iter = Begin();
    iterator other_iter = other.Begin();
    if (other.head_ != head_) {
        if (!head_) Cpy(other);
        else {
            while(this_iter != End() && other_iter != other.End()){
                if (this_iter == End()) {
                    while(other_iter != other.End()) {
                        PushBack(*other_iter);
                        ++other_iter;
                    }
                } 
                if (*other_iter <= *this_iter && other_iter != other.End()) {
                    Insert(this_iter,*other_iter);
                    ++other_iter;
                    // ++this_iter;
                }  
                if (*other_iter > *this_iter && this_iter != End()) {
                    ++this_iter;
                }
            }
        }
    }
    other.Clear();
}


template <typename T>
void List<T>::Splice(typename List<T>::const_iterator pos, List& other) noexcept{
    const_iterator iter(head_);
    int flag = 0;
    size_type size = Size();
    for(size_type i = 0; i < size; i++) {
        if (iter == pos) flag = 1;
        ++iter;
    }
    if (flag) {
        iterator iter_other(other.tail_);
        while(iter_other != other.end_) {
            pos = Insert(pos,*iter_other);
            --iter_other;
        }
    }
    other.Clear();
}


template <typename T>
void List<T>::Reverse() noexcept{
    if (size_ > 1) {
        ListIterator iteratorhead(head_);
        ListIterator iteratortail(tail_);
        Node * tmp_h = head_;
        Node * tmp_t = tail_;
        T data = *iteratorhead;

        for(int i = 0; i < size_ / 2; i++) {
            tmp_h->data_ = *iteratortail;
            tmp_t->data_ = data;

            tmp_h = tmp_h->next_;
            tmp_t = tmp_t->prev_;

            data = tmp_h->data_;
            ++iteratorhead;
            --iteratortail;
        }
    }
}


template <typename T>
void List<T>::Erase(typename List<T>::iterator pos)  {
    iterator iter(head_);
    int flag = 0;
    size_type size = Size();
    for(size_type i = 0; i < size; i++) {
        if (iter == pos) flag = 1;
        ++iter;
    }
    if (pos.current_node_ == end_) {
        throw std::out_of_range("pls don't");
    }
    if (flag) {
        if (size_ == 0) {}
        else if (size_ == 1) PopBack(); // eto ne to4no
        else {
            if (pos.current_node_ == head_) {
                PopFront();
            } else if (pos.current_node_ == tail_) {
                PopBack();
            } else {
                pos.current_node_->prev_->next_ = pos.current_node_->next_;
                pos.current_node_->next_->prev_ = pos.current_node_->prev_;
                Node* tmp = pos.current_node_;
                pos.current_node_ = pos.current_node_->prev_;
                delete tmp;     
                // tmp = nullptr;
            }
        }
        size_--;
    }
}


template <typename T>
typename List<T>::iterator List<T>::Insert(iterator pos, const_reference value) {
    iterator newpos(head_);
    int iterator_checker = 0;
    size_type size = Size();
    for(size_type i = 0; i < size;i++) {
        if (newpos == pos) iterator_checker = 1;
        ++newpos;
    }
    newpos.current_node_ = head_;
    if (iterator_checker) { 
        if (pos.current_node_ == head_) {
            PushFront(value);
        } else if (pos.current_node_ == end_) {
            PushBack(value);
            // --newpos;
        } else {
            int index = pos.FindIndex(*this);
            Node* newval = new Node(value);
            pos.current_node_->prev_->next_ = newval;
            newval->next_ = pos.current_node_;
            newval->prev_ = pos.current_node_->prev_;
            pos.current_node_->prev_ = newval;
            for (int i = 0; i < index; i++) {
                ++newpos; 
            }
            size_++;
        }
    } else if (head_ == nullptr) {
        PushBack(value);
        newpos.current_node_ = head_;
    } else if (pos == End()) {
        PushBack(value);
        ++pos;
    } else {
        throw std::out_of_range("wrong iterator");
    }
    return newpos;
}


template <typename T>
void List<T>::Unique() noexcept{
    for(ListIterator iter_i(head_); iter_i != End(); ++iter_i) {
        for(ListIterator iter_j(iter_i.current_node_->next_); iter_j != End(); ++iter_j) {
            if (*iter_i == *iter_j) Erase(iter_j);
        }
    }
}


template <typename T>
void List<T>::KindOfQS(int start, int end) {
    if (start < end) {
        int pivot_index = Partition(start,end);
        KindOfQS(start, pivot_index - 1);
        KindOfQS(pivot_index + 1, end);
    }
}


template <typename T>
int List<T>::Partition(int start, int end) {
    iterator pivot(head_);
    for(int i = 0; i < end; i++) {
        ++pivot;
    }
    int i = start - 1;
    for(int j = start; j <= end - 1; j++) { // mb ne nujen -1
        iterator jchecker(head_);
        for(int k = 0; k < j; k++) {
            ++jchecker;
        }
        if (*jchecker < *pivot) {
            i++;
            iterator ichecker(head_);
            for(int z = 0; z < i; z++) {
                ++ichecker;
            }            
            Swapper(ichecker,jchecker);
        }
    }
    i++;
    iterator ichecker(head_);
    for(int k = 0; k < i; k++) {
        ++ichecker;
    }
    Swapper(ichecker,pivot);
    return (i);
}


template <typename T>
void List<T>::Sort() noexcept{
    iterator head_iter(head_);
    iterator end(tail_);
    int end_iter = end.FindIndex(*this);
    KindOfQS(0, end_iter);
}

template <typename T>
void List<T>::PrintList() {
    int k = 0;
    if (head_ != nullptr) {
        while(head_ != end_) {
            std::cout << head_->data_ << std:: endl;
            head_ = head_->next_;
        }
        head_ = end_->next_;
        std::cout << std:: endl;
    }

}

// bonus          ##############################################################


template <typename T>
template <typename... Args>
void List<T>::EmplaceFront(Args &&...args) {
    ([&] { PushFront(args); }(), ...);
}


template <typename T>
template <typename... Args>
void List<T>::EmplaceBack(Args &&...args) {
    ([&] { PushBack(args); }(), ...);
}


template <typename T>
template <typename... Args>
typename List<T>::iterator List<T>::Emplace(const_iterator pos, Args &&...args) {
    iterator iter = pos;    
    ([&] { Insert(pos, args); }(), ...);
    --iter;
    return iter;
}


}
// #include "list.tpp"

#endif //  SRC_LIST_H_
