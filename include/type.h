#pragma once

#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
#include <sstream>
#include <iostream>

namespace type {

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  TreeNode* lhs;
  TreeNode* rhs;
  int idx;
};
typedef TreeNode* tree;

template <typename Node, typename Alloc = void>
class Grahp {
 public:
  using weight_type = size_t;
  struct GraphEdge {
    weight_type weight;
    struct GraphNode* adjacency_node;
  };

  struct GraphNode {
    Node data;
    std::list<GraphEdge> adjacency_list;
  };

  using NodeContainer = std::vector<GraphNode>;
  using node_iterator = typename NodeContainer::iterator;
  using const_node_iterator = typename NodeContainer::const_iterator;

  GraphNode& addNode(Node&& data) {
    nodes.emplace_back(GraphEdge{std::forward<Node>(data, {})});
    return nodes.back();
  }
  void addEdge(GraphNode* lhs, GraphNode* rhs, weight_type weight) {
    lhs->adjacency_list.push_back(GraphEdge{.weight = weight, rhs});
    rhs->adjacency_list.push_back(GraphEdge{.weight = weight, lhs});
  }

  const auto begin() const { return nodes.begin(); }
  const auto end() const { return nodes.end(); }

  auto begin() { return nodes.begin(); }
  auto end() { return nodes.end(); }

  std::string toString() const {
    std::stringstream ss;
    for (const auto& node : nodes) {
      ss << "data:" << node.data << " adjacency list:";
      for (auto n : node.adjacency_list) {
        ss << n->data << " ";
      }
      ss << "\n";
    }
    return ss.str();
  }

 private:
  NodeContainer nodes;
};

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
  // ArrayRef(iterator begin, iterator end) : data_(begin),
  // size_(std::distance(begin, end)) {}

  template <size_type N>
  ArrayRef(T (&array)[N]) : ArrayRef(array, N) {}

  template <typename Iter>
  ArrayRef(Iter begin, Iter end)
      : data_(&*begin), size_(std::distance(begin, end)) {}

  ArrayRef(std::vector<T>& vec) : ArrayRef(vec.data(), vec.size()) {}

  reference front() { return *data_; }
  reference back() { return *(data_ + size_); }

  iterator begin() { return data_; }
  iterator end() { return data_ + size_; }

  size_type size() const { return size_; }
  reference operator[](size_type idx) { return *(data_ + idx); }

  ArrayRef<T> slice(size_t start) const {
    return ArrayRef<T>(data_ + start, size() - start);
  }

  ArrayRef<T> slice(size_t start, size_t size) const {
    return ArrayRef<T>(data_ + start, size);
  }

  ArrayRef<T> drop_front(size_t S) const {
    return ArrayRef<T>(data_ + S, size() - S);
  }

  ArrayRef<T> drop_back(size_t S) const {
    return ArrayRef<T>(data_, size() - S);
  }

 private:
  T* data_;
  size_type size_;
};

template <typename T, typename... Argvs>
ArrayRef<T> makeArrayRef(Argvs&&... argvs) {
  return ArrayRef<T>(std::forward<Argvs>(argvs)...);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, ArrayRef<T> array) {
  //
  for (const auto& it : array) {
    os << it << ", ";
  }
  return os;
}
}  // namespace type