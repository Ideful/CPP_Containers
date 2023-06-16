// https://github.com/Ideful/CPP_Containers

namespace s21{
template <typename T>
List<T>::List() : _head(nullptr),_tail(nullptr),_end(nullptr),_size(0) {}

template <typename T>
void List<T>::ParCons(size_type n){
    if (n < MaxSize()) {
        _head = _tail = _end = nullptr, _size = 0; 
        for(size_type i = 0; i < n; i++) {
            Node *tmp = new Node();
            if (_head == nullptr) {
                _head = _tail = tmp;
                _end = new Node();
                tmp->_prev = _end;
            } else {
                tmp->_prev = _tail;
                _tail->_next = tmp;
                _tail = tmp;
            }
            _end->_next = _head;
            _end->_prev = _tail;
            _tail->_next = _end;
            _size++;
        }
    } 
}


template <typename T>
List<T>::List(size_type n):List() { 
    ParCons(n);
}


// template <typename T>
// List<T>::List(std::initializer_list<value_type> const &items){
//     for(auto iter = items.begin(); iter != items.end(); ++iter){
//         std::cout << iter;
//         PushBack(*iter);
//     }
// }


template <typename T>
List<T>::List(std::initializer_list<value_type> const& items) {
  typename std::initializer_list<T>::iterator it = items.begin();
  value_type size = 0;
  for (size_type i = 0; items.size() > i; i++) {
    PushBack(*it);
    it++;
    size++;
  }
  _size = size;
}


template <typename T>
List<T>::List(const List &l) : List(l._size) {
    ListIterator ListIterator(l._head);
    while(_head != _end) {
        _head->_data = *ListIterator;
        _head = _head->_next;
        ++ListIterator;
    }
    _head = _end->_next; 
}


template <typename T>
List<T>::List(List&& l):_head(nullptr),_tail(nullptr),_end(nullptr),_size(0) {
    Swap(l);
}


template <typename T>
void List<T>::Cpy(const List &l) {
    Clear();
    ParCons(l._size);
    Node *tmp(l._head);
    if (l._size > 0) {
        while(_head != _end) {
            _head->_data = tmp->_data;
            _head = _head->_next;
            tmp = tmp->_next;
        }
        _head = _end->_next;
    }

}


template <typename T>
typename List<T>::List& List<T>::operator=(List &&l)  {
    Cpy(l);
    return *this;
}


template <typename T>
typename List<T>::List& List<T>::operator=(List &l)  {
    Cpy(l);
    return *this; 
}


template <typename T>
bool List <T>::Empty() const noexcept {
    return (_head == nullptr) ? true : false;
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
    if (_head && _head->_data ) return  _head->_data;
    else return _variable;
}


template <typename T>
typename List<T>::const_reference List<T>::Back() const noexcept {
    if (_tail && _tail->_data) return _tail->_data;
    else return _variable;
}


template <typename T>
void List<T>::Clear() noexcept{
    if (_head && _head != _end) {
        while(_head->_next != _end) {
            Node *tmp = _head->_next;
            delete _head;
            _head = tmp;
        }
    }
    if (_head) delete _head;
    if (_end && _end != _head) delete _end;
    _head = _tail = _end = nullptr;
    _size = 0;
}


template <typename T>
void List<T>::PushBack(typename List<T>::value_type value){
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


template <typename T>
void List<T>::PushFront(typename List<T>::value_type value){
    Node* newnode = new Node(value);
    if (!_head) {
        _head = _tail = newnode;
        _end = new Node();
        _tail->_next = _end;
        _end->_prev = _tail;
    } else {
        newnode->_next = _head;
        _head->_prev = newnode;
        _head = newnode;
    }
    _end->_next = _head;
    _head->_prev = _end;

    _size++;
}


template <typename T>
void List<T>::PopFront(){
    if (_head == nullptr) throw std::out_of_range("nothing to pop");
    if (_size == 1) {
        delete _end;
        delete _head;
        _head = _tail = _end = nullptr;
    } 
    else {
        Node* newnode = _head->_next;
        _head = newnode;
        newnode = newnode->_prev;
        delete newnode;
        _head->_prev = _end;
        _end->_next = _head;
    }
    _size--;
}


template <typename T>
void List<T>::PopBack(){
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


template <typename T>
typename List<T>::size_type List<T>::Size()  noexcept { // 
    int res = 0;
    while(_head != _end) {
        _head = _head->_next;
        res++;
    }
    if(_head) _head = _end->_next;
    return res;
}


template <typename T>
typename List<T>::ListIterator List<T>::Begin() {
    iterator res(_head);
    if (!_head) {
        Node* tmp = new Node();
        iterator qwe(tmp);
        res = qwe;
        res._current_node->_data = 0;
        delete tmp;
    }
    return res;
    // return _head ? iterator(_head) : iterator(_end);
}


template <typename T>
typename List<T>::ListIterator  List<T>::End() {
    iterator res(_end);
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
    if (other._head != _head) {
        if (!_head) Cpy(other);
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
    const_iterator iter(_head);
    int flag = 0;
    size_type size = Size();
    for(size_type i = 0; i < size; i++) {
        if (iter == pos) flag = 1;
        ++iter;
    }
    if (flag) {
        // int cnt = 0;
        // ListIterator tmp = pos;
        // while(pos._current_node != other._end) {
        //     cnt++;
        //     ++pos;
        // }
        // ListIterator qwe(_tail);
        // ParCons(cnt);
        // for(int i = 0; i < cnt; i++) {
        //     ++qwe;
        //     *qwe = *tmp;
        //     ++tmp;
        // }
        iterator iter_other(other._tail);
        while(iter_other != other._end) {
            pos = Insert(pos,*iter_other);
            --iter_other;
        }
    }
    other.Clear();
}


template <typename T>
void List<T>::Reverse() noexcept{
    if (_size > 1) {
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
}


template <typename T>
void List<T>::Erase(typename List<T>::iterator pos)  {
    iterator iter(_head);
    int flag = 0;
    size_type size = Size();
    for(size_type i = 0; i < size; i++) {
        if (iter == pos) flag = 1;
        ++iter;
    }
    if (pos._current_node == _end) {
        throw std::out_of_range("pls don't");
    }
    if (flag) {
        if (_size == 0) {}
        else if (_size == 1) PopBack(); // eto ne to4no
        else {
            if (pos._current_node == _head) {
                PopFront();
            } else if (pos._current_node == _tail) {
                PopBack();
            } else {
                pos._current_node->_prev->_next = pos._current_node->_next;
                pos._current_node->_next->_prev = pos._current_node->_prev;
                Node* tmp = pos._current_node;
                pos._current_node = pos._current_node->_prev;
                delete tmp;     
                // tmp = nullptr;
            }
        }
        _size--;
    }
}


template <typename T>
typename List<T>::iterator List<T>::Insert(iterator pos, const_reference value) {
    iterator newpos(_head);
    int iterator_checker = 0;
    size_type size = Size();
    for(size_type i = 0; i < size;i++) {
        if (newpos == pos) iterator_checker = 1;
        ++newpos;
    }
    newpos._current_node = _head;
    if (iterator_checker) { 
        if (pos._current_node == _head) {
            PushFront(value);
        } else if (pos._current_node == _end) {
            PushBack(value);
            // --newpos;
        } else {
            int index = pos.FindIndex(*this);
            Node* newval = new Node(value);
            pos._current_node->_prev->_next = newval;
            newval->_next = pos._current_node;
            newval->_prev = pos._current_node->_prev;
            pos._current_node->_prev = newval;
            for (int i = 0; i < index; i++) {
                ++newpos; 
            }
        }
    } else if (_head == nullptr) {
        PushBack(value);
        newpos._current_node = _head;
    } else if (pos == End()) {
        PushBack(value);
        ++pos;
    } else {
        throw std::out_of_range("wrong iterator");
    }
    _size++;
    return newpos;
}


template <typename T>
void List<T>::Unique() noexcept{
    for(ListIterator iter_i(_head); iter_i != End(); ++iter_i) {
        for(ListIterator iter_j(iter_i._current_node->_next); iter_j != End(); ++iter_j) {
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
    iterator pivot(_head);
    for(int i = 0; i < end; i++) {
        ++pivot;
    }
    int i = start - 1;
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
            Swapper(ichecker,jchecker);
        }
    }
    i++;
    iterator ichecker(_head);
    for(int k = 0; k < i; k++) {
        ++ichecker;
    }
    Swapper(ichecker,pivot);
    return (i);
}


template <typename T>
void List<T>::Sort() noexcept{
    iterator head_iter(_head);
    iterator end(_tail);
    int end_iter = end.FindIndex(*this);
    KindOfQS(0, end_iter);
}

template <typename T>
void List<T>::PrintList() {
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


template <typename T>
typename List<T>::reference List<T>::ListIterator::operator*() {
    return _current_node->_data;
}


// template <typename T>
// void List<T>::ListIterator::operator++() {
//     _current_node = _current_node->_next;
// }

// template <typename T>
// void List<T>::ListIterator::operator--() {
//     _current_node = _current_node->_prev;
// }


template <typename T>
int List<T>::ListIterator::FindIndex(List &a){ 
    size_type res = 0;
    Node * tmp = _current_node;
    while(tmp != a._head){ 
        tmp = tmp->_prev;
        res++;
    }
    return res;
}

template <typename T>
bool List<T>::ListIterator::operator==(const ListIterator &other) const{
    return (_current_node==other._current_node);
}

template <typename T>
bool List<T>::ListIterator::operator!=(const ListIterator &other) const{
    return (_current_node!=other._current_node);
}



template <typename T>
typename List<T>::ListIterator& List<T>::ListIterator::operator=(ListIterator other) noexcept{
    _current_node = other._current_node;
    _index = other._index;
    return *this;
}

// const iterator ##############################################################

template <typename T>
typename List<T>::const_reference List<T>::ListConstIterator::operator*() {
    return _current_node->_data;
}


template <typename T>
typename List<T>::ListConstIterator& List<T>::ListConstIterator::operator=(ListConstIterator other){
    _current_node = other._current_node;
    return *this;
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

// void print(std::List<int>  List)
// {
//     for (auto const &i: List) {
//         std::cout << i << std::endl;
//     }
// }
}

