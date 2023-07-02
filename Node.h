#ifndef SRC_LISTLIKE_S21_NODE_H_
#define SRC_LISTLIKE_S21_NODE_H_
#include <cstddef>

namespace s21 {
template <typename T>
class Node {
 public:
  Node() : data_(), prev_(nullptr), next_(nullptr){}
  Node(const T value) : data_(value), prev_(nullptr), next_(nullptr){}
  T data_;
  Node* prev_ = nullptr;
  Node* next_ = nullptr;
};
}  // namespace s21
#endif  // SRC_LISTLIKE_S21_NODE_H_
