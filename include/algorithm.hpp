#include <algorithm>
#include <type_traits>
#include <unordered_map>

#include "type.h"

namespace Train {

inline size_t PARENT_INDEX(size_t idx) { return (idx - 1) >> 1; }
inline size_t LNODE_INDEX(size_t idx) { return (idx << 1) + 1; }
inline size_t RNODE_INDEX(size_t idx) { return (idx << 1) + 2; }

template <typename T, typename CMP>
void pop_heap(T first, T last, CMP cmp) {
  std::iter_swap(first, --last);
  size_t size = std::distance(first, last);
  size_t cur = 0;
  auto cur_iter = first + cur;
  while (true) {
    auto lhs_idx = LNODE_INDEX(cur);
    auto rhs_idx = RNODE_INDEX(cur);
    auto next_iter = cur_iter;
    if (lhs_idx < size && cmp(*(first + lhs_idx), *cur_iter)) {
      cur = lhs_idx;
      next_iter = first + lhs_idx;
    }
    if (rhs_idx < size && cmp(*(first + rhs_idx), *next_iter)) {
      cur = rhs_idx;
      next_iter = first + rhs_idx;
    }
    if (next_iter == cur_iter) {
      break;
    } else {
      std::iter_swap(next_iter, cur_iter);
      std::swap(next_iter, cur_iter);
    }
  }
}

template <typename T>
void pop_heap(T first, T last) {
  ::Train::pop_heap(first, last, std::less<decltype(*first)>());
}

template <typename T, typename CMP>
void push_heap(T first, T last, CMP cmp) {
  T cur = --last;
  while (true) {
    auto parent_idx = PARENT_INDEX(std::distance(first, cur));
    auto parent_iter = first;
    std::advance(parent_iter, parent_idx);
    if (cmp(*parent_iter, *cur)) {
      break;
    } else {
      std::iter_swap(parent_iter, cur);
    }
    if (!parent_idx) break;
    cur = parent_iter;
  }
}

template <typename T>
void push_heap(T first, T last) {
  ::Train::push_heap(first, last, std::less<decltype(*first)>());
}

template <typename T, typename CMP>
void make_heap(T first, T last, CMP cmp) {
  //   using category = std::iterator_traits<T>::iterator_category;
  if (std::distance(first, last) <= 1) {
    return;
  }
  auto it = first;
  std::advance(it, 2);
  for (; it != last; ++it) {
    ::Train::push_heap(first, it);
  }
}

template <typename T>
void make_heap(T first, T last) {
  ::Train::make_heap(first, last, std::less<decltype(*first)>());
}


template <typename T, typename CMP = std::less<T>>
void mergeSort(T fisrst, T last, CMP cmp) {

}

template <typename T>
void quickSort() {}

template <typename T>
void dijkstra(const type::Grahp<T>& graph,
              typename type::Grahp<T>::const_node_iterator start) {
  using node_ptr = const typename type::Grahp<T>::GraphNode*;
  using weight_type = typename type::Grahp<T>::weight_type;
  std::unordered_map<node_ptr, weight_type> visited;
  visited.insert(std::make_pair(&*start, 0));
  std::vector<std::pair<node_ptr, weight_type>> remained;
  for (auto iter = graph.begin(); iter != graph.end(); ++iter) {
    remained.emplace_back(&*iter, std::numeric_limits<weight_type>::max());
  }

  while (!remained.empty()) {
    auto min = std::min_element(
        remained.begin(), remained.end(),
        [](auto lhs, auto rhs) { return lhs.second < rhs.second; });
    visited.insert(*min);
    for (auto node : min->first->adjacency_list) {
    }
    remained.erase(min);
  }
}

}  // namespace Train