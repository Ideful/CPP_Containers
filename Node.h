#ifndef SRC_NODE_H_
#define SRC_NODE_H_

namespace s21{
  template <typename T>
  class Node {
    public:
      T data_;
      Node* prev_ = nullptr;
      Node* next_ = nullptr;
      Node() : data_(), prev_(nullptr), next_(nullptr){};
      Node(const T value) : data_(value), prev_(nullptr), next_(nullptr){};
  };
}
#endif //SRC_NODE_H_

