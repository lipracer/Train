#pragma once

#include <cstdlib>
#include <algorithm>

namespace type {

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  TreeNode* lhs;
  TreeNode* rhs;
  int idx;
};
typedef TreeNode* tree;

// simple implement ArrayRef remove const
// same as mutable arrayref
template <typename T>
class ArrayRef {
 public:
  using value_type = T;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  ArrayRef(const T* data, size_type size)
      : data_(const_cast<T*>(data)), size_(size) {}
  // ArrayRef(iterator begin, iterator end) : data_(begin), size_(std::distance(begin, end)) {}

  template <size_type N>
  ArrayRef(T (&array)[N]) : ArrayRef(array, N) {}

  template <typename Iter>
  ArrayRef(Iter begin, Iter end)
      : data_(&*begin), size_(std::distance(begin, end)) {}

  reference front() { return *data_; }
  reference back() { return *(data_ + size_); }

  iterator begin() { return data_; }
  iterator end() { return data_ + size_; }

  size_type size() const { return size_; }
  reference operator[](size_type idx) { return *(data_ + idx); }

 private:
  T* data_;
  size_type size_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, ArrayRef<T> array) {
  // 
  for (const auto& it : array) {
    os << it << ", ";
  }
}
}