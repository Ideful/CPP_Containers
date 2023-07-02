#ifndef SRC_LISTLIKE_S21_QUEUE_H_
#define SRC_LISTLIKE_S21_QUEUE_H_

#include "list.h"
namespace s21 {
template <typename T>

class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  Queue() : listique() {}
  Queue(std::initializer_list<value_type> const &items) : listique(items) {}
  Queue(const Queue &n) : listique(n.listique) {}
  Queue(Queue &&n) : listique(std::move(n.listique)) {}
  ~Queue() {}
  Queue &operator=(Queue &&n) {
    listique = std::move(n.listique);
    return *this;
  }
  const_reference Front() { return listique.Front(); }
  const_reference Back() { return listique.Back(); }
  bool Empty() { return listique.Empty(); }
  size_type Size() { return listique.Size(); }
  void Push(T value) { listique.PushBack(value); }
  void Pop() { listique.PopFront(); }
  void Swap(Queue &value) { listique.Swap(value.listique); }

  template <typename... Args>
  void EmplaceBack(Args &&...args) {
    ([&] { Push(args); }(), ...);
  }

 private:
  List<T> listique;
};
}  // namespace s21

#endif  //  SRC_LISTLIKE_S21_QUEUE_H_
