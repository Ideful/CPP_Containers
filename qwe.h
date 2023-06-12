class ConstListIterator {   public:
    Node* current_node_;
    value_type nil_ = 0;  //для краевых случаев
    reference zero_ = nil_;

    ConstListIterator() { current_node_ = nullptr; }
    ConstListIterator(Node* value) { current_node_ = value; }
    ConstListIterator(const ConstListIterator& other): current_node_(other.current_node_) {}
    ~ConstListIterator() {}
    ConstListIterator& operator++() noexcept;
    ConstListIterator& operator--() noexcept;
    const_reference operator*() const noexcept;
    bool operator!=(const ConstListIterator& other) const noexcept;
    bool operator==(const ConstListIterator& other) const noexcept;
  };

  class ListIterator : public ConstListIterator {
   public:
    ListIterator();
    ListIterator(Node* value);
    ListIterator(const ListIterator& other);
    ListIterator(const ConstListIterator& other);
    ~ListIterator() {}
    reference operator*() const noexcept;
    ListIterator& operator=(const ListIterator other) noexcept;
  };