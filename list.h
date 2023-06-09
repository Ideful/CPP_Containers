#ifndef SRC_LISTLIKE_S21_LIST_H_
#define SRC_LISTLIKE_S21_LIST_H_
#include <initializer_list>
#include <limits>
#include <stdexcept>
#include <utility>

#include "node.h"

namespace s21 {
template <typename T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  class ListIterator;
  class ListConstIterator;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  List();
  explicit List(size_type n);
  List(std::initializer_list<value_type> const& items);
  List(const List& l);
  List(List&& l) noexcept;
  ~List();
  List& operator=(List&& l) noexcept;
  List& operator=(const List& l) noexcept;

  const_reference Front() noexcept;
  const_reference Back() noexcept;
  bool Empty() const noexcept;
  size_type Size() noexcept;
  size_type MaxSize() const noexcept;
  void Clear() noexcept;
  void PushFront(value_type value);
  void PushBack(value_type value);
  void PopFront();
  void PopBack();
  void Swap(List& other);
  void Merge(List& other);
  void Reverse() noexcept;
  void Unique() noexcept;
  void Sort() noexcept;
  void Erase(iterator pos);

  void Splice(const_iterator pos, List& other) noexcept;
  iterator Begin();
  iterator End();
  iterator Insert(iterator pos, const_reference value);

  template <typename... Args>
  iterator Emplace(const_iterator pos, Args&&... args);
  template <typename... Args>
  void EmplaceFront(Args&&... args);
  template <typename... Args>
  void EmplaceBack(Args&&... args);

  class ListIterator {
   public:
    ListIterator() : node_(nullptr), index_(0) {}
    ListIterator(Node<T>* value) : node_(value), index_(0) {}
    ListIterator(const ListIterator& value)
        : node_(value.node_), index_(value.index_) {}
    ~ListIterator() {}
    reference operator*() { return node_->data_; }
    iterator& operator++() {
      node_ = node_->next_;
      return *this;
    }
    iterator& operator--() {
      node_ = node_->prev_;
      return *this;
    }

    bool operator==(const ListIterator& other) const {
      return node_ == other.node_;
    }

    bool operator!=(const ListIterator& other) const {
      return node_ != other.node_;
    }
    ListIterator& operator=(ListIterator other) noexcept {
      node_ = other.node_;
      index_ = other.index_;
      return *this;
    }
    size_type FindIndex(const List& a) {
      size_type res = 0;
      Node<T>* tmp = node_;
      while (tmp != a.head_) {
        tmp = tmp->prev_;
        res++;
      }
      return res;
    }

   private:
    Node<T>* node_ = nullptr;
    size_type index_;
  };

  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator() : ListIterator() {}
    ListConstIterator(const ListConstIterator& ref) : ListIterator(ref) {}
    ListConstIterator(ListIterator value) : ListIterator(value) {}
    ~ListConstIterator() {}
    const_reference operator*() { return ListIterator::operator*(); }
  };

 private:
  void KindOfQS(int head_iter, int tail_iter);
  int Partition(int start, int end);
  void ParCons(const size_type n);
  void Cpy(const List& l);
  void Swapper(iterator a, iterator b);

  struct Node<T> node_;
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  Node<T>* end_ = nullptr;
  size_type size_ = 0;
  value_type var_;
  const_reference _variable = var_;
};

template <class T>
List<T>::List()
    : head_(nullptr), tail_(nullptr), end_(new Node<T>()), size_(0) {}

template <typename T>
void List<T>::ParCons(size_type n) {
  if (n < MaxSize()) {
    head_ = tail_ = nullptr, size_ = 0;
    for (size_type i = 0; i < n; i++) {
      Node<T>* tmp = new Node<T>();
      if (head_ == nullptr) {
        head_ = tail_ = tmp;
        if (!end_) end_ = new Node<T>();
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
List<T>::List(size_type n) : List() {
  ParCons(n);
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const& items) {
  for (auto it = items.begin(); it != items.end(); it++) {
    PushBack(*it);
  }
}

template <typename T>
List<T>::List(const List& l) : List(l.size_) {
  if (l.size_ > 0) {
    ListIterator ListIterator(l.head_);
    Node<T>* tmp(head_);
    while (tmp != end_) {
      tmp->data_ = *ListIterator;
      tmp = tmp->next_;
      ++ListIterator;
    }
  }
}

template <typename T>
List<T>::List(List&& other) noexcept
    : head_(nullptr), tail_(nullptr), end_(new Node<T>()), size_(0) {
  Swap(other);
}

template <typename T>
void List<T>::Cpy(const List& l) {
  Clear();
  ParCons(l.size_);
  iterator tmp(l.head_);
  iterator this_it(head_);
  while (this_it != End()) {
    *this_it = *tmp;
    ++tmp;
    ++this_it;
  }
}

template <typename T>
List<T>& List<T>::operator=(List&& other) noexcept {
  Clear();
  head_ = std::exchange(other.head_, nullptr);
  tail_ = std::exchange(other.tail_, nullptr);
  end_ = std::exchange(other.end_, nullptr);
  size_ = std::exchange(other.size_, 0);
  return *this;
}

template <typename T>
List<T>& List<T>::operator=(const List& l) noexcept {
  Cpy(l);
  return *this;
}

template <typename T>
bool List<T>::Empty() const noexcept {
  return size_ == 0;
}

template <typename T>
void List<T>::Swapper(iterator a, iterator b) {
  value_type tmp = *a;
  *a = *b;
  *b = tmp;
}

template <typename T>
List<T>::~List() {
  Clear();
}

template <typename T>
typename List<T>::size_type List<T>::MaxSize() const noexcept {
  return std::numeric_limits<std::size_t>::max() / sizeof(Node<T>) / 2;
}

template <typename T>
typename List<T>::const_reference List<T>::Front() noexcept {
  if (head_ && head_->data_)
    return head_->data_;
  else
    var_ = 0;
  return _variable;
}

template <typename T>
typename List<T>::const_reference List<T>::Back() noexcept {
  if (tail_ && tail_->data_)
    return tail_->data_;
  else
    var_ = 0;
  return _variable;
}

template <typename T>
void List<T>::Clear() noexcept {
  while (!Empty()) {
    PopBack();
  }
  if (end_) {
    delete end_;
    end_ = nullptr;
  }
}

template <typename T>
void List<T>::PushBack(typename List<T>::value_type value) {
  Node<T>* tmp = new Node(value);
  if (head_ == nullptr) {
    head_ = tail_ = tmp;
    if (!end_) end_ = new Node<T>();
    tmp->prev_ = end_;
    end_->next_ = head_;
  } else {
    tmp->prev_ = tail_;
    tail_->next_ = tmp;
    tail_ = tmp;
  }
  end_->prev_ = tail_;
  tail_->next_ = end_;
  size_++;
}

template <typename T>
void List<T>::PushFront(typename List<T>::value_type value) {
  Node<T>* newnode = new Node<T>(value);
  if (!head_) {
    head_ = tail_ = newnode;
    if (!end_) end_ = new Node<T>();
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
void List<T>::PopFront() {
  if (head_) {
    if (size_ == 1) {
      delete end_;
      delete head_;
      head_ = tail_ = end_ = nullptr;
    } else {
      Node<T>* newnode = head_->next_;
      head_ = newnode;
      newnode = newnode->prev_;
      delete newnode;
      head_->prev_ = end_;
      end_->next_ = head_;
    }
    size_--;
  }
}

template <typename T>
void List<T>::PopBack() {
  if (head_) {
    if (size_ == 1) {
      if (tail_ == head_)
        delete tail_;
      else
        delete tail_, delete head_;
      head_ = tail_ = nullptr;
    } else if (size_ > 1) {
      Node<T>* newnode = tail_->prev_;
      tail_ = newnode;
      newnode = newnode->next_;
      delete newnode;
      tail_->next_ = end_;
      end_->prev_ = tail_;
    }
    size_--;
  }
}

template <typename T>
typename List<T>::size_type List<T>::Size() noexcept {  //
  size_type res = 0;
  Node<T>* tmp(head_);
  if (tmp) {
    while (tmp != end_) {
      tmp = tmp->next_;
      res++;
    }
  }
  return res;
}

template <typename T>
typename List<T>::ListIterator List<T>::Begin() {
  if (head_)
    return iterator(head_);
  else
    return iterator(end_);
}

template <typename T>
typename List<T>::ListIterator List<T>::End() {
  iterator res(end_);
  return res;
}

template <typename T>
void List<T>::Swap(List& other) {
  List tmp(other);
  other.Clear();
  other.Cpy(*this);
  Clear();
  Cpy(tmp);
}

template <typename T>
void List<T>::Merge(List& other) {
  iterator this_iter = Begin();
  iterator other_iter = other.Begin();
  if (other.head_ != head_) {
    if (!head_)
      Cpy(other);
    else {
      while (this_iter != End() && other_iter != other.End()) {
        if (this_iter == End()) {
          while (other_iter != other.End()) {
            PushBack(*other_iter);
            ++other_iter;
          }
        }
        if (*other_iter <= *this_iter && other_iter != other.End()) {
          Insert(this_iter, *other_iter);
          ++other_iter;
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
void List<T>::Splice(typename List<T>::const_iterator pos,
                     List& other) noexcept {
  const_iterator iter(head_);
  int flag = 0;
  size_type size = Size();
  for (size_type i = 0; i < size; i++) {
    if (iter == pos) flag = 1;
    ++iter;
  }
  if (flag) {
    iterator iter_other(other.tail_);
    while (iter_other != other.end_) {
      Insert(pos, *iter_other);
      --iter_other;
    }
  }
  other.Clear();
}

template <typename T>
void List<T>::Reverse() noexcept {
  if (size_ > 1) {
    ListIterator iteratorhead(head_);
    ListIterator iteratortail(tail_);
    for (size_type i = 0; i < size_ / 2; i++) {
      T value = *iteratorhead;
      *iteratorhead = *iteratortail;
      *iteratortail = value;
      ++iteratorhead;
      --iteratortail;
    }
  }
}

template <typename T>
void List<T>::Erase(typename List<T>::iterator pos) {
  iterator iter(head_);
  int flag = 0;
  size_type size = Size();
  for (size_type i = 0; i < size; i++) {
    if (iter == pos) flag = 1;
    ++iter;
  }
  if (pos == End()) {
    throw std::out_of_range("pls don't");
  }
  if (flag) {
    if (size_ == 0) {
    } else if (size_ == 1)
      PopBack();  // eto ne to4no
    else {
      iterator tailit(End());
      --tailit;
      if (pos == Begin()) {
        PopFront();
      } else if (pos == tailit) {
        PopBack();
      } else {
        Node<T>* connector(head_);
        for (size_type i = 0; i < pos.FindIndex(*this); i++) {
          connector = connector->next_;
        }
        connector->prev_->next_ = connector->next_;
        connector->next_->prev_ = connector->prev_;
        delete connector;
      }
    }
    size_--;
  }
}

template <typename T>
typename List<T>::iterator List<T>::Insert(iterator pos,
                                           const_reference value) {
  iterator newpos(head_);
  int iterator_checker = 0;
  size_type size = Size();
  for (size_type i = 0; i < size; i++) {
    if (newpos == pos) iterator_checker = 1;
    ++newpos;
  }
  newpos = head_;
  if (iterator_checker) {
    if (pos == Begin()) {
      PushFront(value);
    } else if (pos == End()) {
      PushBack(value);
    } else {
      size_type index = pos.FindIndex(*this);
      Node<T>* newval = new Node<T>(value);
      Node<T>* connector(head_);
      for (size_type i = 1; i < index; i++) {
        connector = connector->next_;
      }
      connector->next_->prev_ = newval;
      newval->next_ = connector->next_;
      newval->prev_ = connector;
      connector->next_ = newval;
      for (size_type i = 0; i < index; i++) {
        ++newpos;
      }
      size_++;
    }
  } else if (head_ == nullptr) {
    PushBack(value);
    newpos = Begin();
  } else if (pos == End()) {
    PushBack(value);
    ++pos;
  } else {
    throw std::out_of_range("wrong iterator");
  }
  return newpos;
}

template <typename T>
void List<T>::Unique() noexcept {
  for (ListConstIterator iter_i(head_); iter_i != End(); ++iter_i) {
    ListConstIterator tmp(iter_i);
    ++tmp;
    ListConstIterator iter_j(tmp);
    while (iter_j != End()) {
      if (*iter_i == *iter_j) {
        ListConstIterator del(iter_j);
        ++iter_j;
        Erase(del);
      } else {
        ++iter_j;
      }
    }
  }
}

template <typename T>
void List<T>::KindOfQS(int start, int end) {
  if (start < end) {
    int pivotindex_ = Partition(start, end);
    KindOfQS(start, pivotindex_ - 1);
    KindOfQS(pivotindex_ + 1, end);
  }
}

template <typename T>
int List<T>::Partition(int start, int end) {
  iterator pivot(head_);
  for (int i = 0; i < end; i++) {
    ++pivot;
  }
  int i = start - 1;
  for (int j = start; j <= end - 1; j++) {  // mb ne nujen -1
    iterator jchecker(head_);
    for (int k = 0; k < j; k++) {
      ++jchecker;
    }
    if (*jchecker < *pivot) {
      i++;
      iterator ichecker(head_);
      for (int z = 0; z < i; z++) {
        ++ichecker;
      }
      Swapper(ichecker, jchecker);
    }
  }
  i++;
  iterator ichecker(head_);
  for (int k = 0; k < i; k++) {
    ++ichecker;
  }
  Swapper(ichecker, pivot);
  return (i);
}

template <typename T>
void List<T>::Sort() noexcept {
  iterator head_iter(head_);
  iterator end(tail_);
  int end_iter = end.FindIndex(*this);
  KindOfQS(0, end_iter);
}

template <typename T>
template <typename... Args>
void List<T>::EmplaceFront(Args&&... args) {
  ([&] { PushFront(args); }(), ...);
}

template <typename T>
template <typename... Args>
void List<T>::EmplaceBack(Args&&... args) {
  ([&] { PushBack(args); }(), ...);
}

template <typename T>
template <typename... Args>
typename List<T>::iterator List<T>::Emplace(const_iterator pos,
                                            Args&&... args) {
  iterator iter = pos;
  ([&] { Insert(pos, args); }(), ...);
  --iter;
  return iter;
}
}  // namespace s21
#endif  //  SRC_LISTLIKE_S21_LIST_H_
