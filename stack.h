#ifndef SRC_LISTLIKE_S21_STACK_H_
#define SRC_LISTLIKE_S21_STACK_H_
#include "list.h"

namespace s21 {
template <typename T>

class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  Stack() : listique() {}
  Stack(std::initializer_list<value_type> const &items) : listique(items) {}
  Stack(const Stack &n) : listique(n.listique) {}
  Stack(Stack &&n) : listique(std::move(n.listique)) {}
  ~Stack() {}
  Stack &operator=(Stack &&n) {
    listique = std::move(n.listique);
    return *this;
  }
  const_reference Top() {
    if (listique.Size() > 0)
      return listique.Back();
    else
      throw std::out_of_range("empty stack");
  }
  bool Empty() { return listique.Empty(); }
  size_type Size() { return listique.Size(); }
  void Push(const_reference val) { listique.PushBack(val); }
  void Pop() { listique.PopBack(); }
  void Swap(Stack &val) { listique.Swap(val.listique); }

  template <typename... Args>
  void EmplaceFront(Args &&...args) {
    ([&] { Push(args); }(), ...);
  }

 private:
  List<T> listique;
};
}  // namespace s21

#endif  //  SRC_LISTLIKE_S21_STACK_H_
