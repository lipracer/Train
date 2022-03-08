#include <algorithm>
#include <type_traits>
#include <unordered_set>
#include <unordered_map>

#include "type.h"

namespace lskd {

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
  ::lskd::pop_heap(first, last, std::less<decltype(*first)>());
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
  ::lskd::push_heap(first, last, std::less<decltype(*first)>());
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
    push_heap(first, it);
  }
}

template <typename T>
void make_heap(T first, T last) {
  ::lskd::make_heap(first, last, std::less<decltype(*first)>());
}


template <typename T, typename CMP = std::less<T>>
void mergeSort(T fisrst, T last, CMP cmp) {

}

template <typename T>
void quickSort() {}

/* description: 1. we build two set unvisited and visited
 * 2. we assign all element's weight infinity in unvisited and
 * assign start element's weight with 0
 * 3. traverse all unvisited and find the min element's weight
 * 4. update all min element's adjacency node iff edge(weight)
 * + nin(weight) < adjacency_node(weight)
 * 5 repeat 4-5 until unvisited set is empty
 **/
template <typename T>
void dijkstra(const Grahp<T> &graph,
              typename Grahp<T>::const_node_iterator start) {
  using node_ptr = typename Grahp<T>::const_node_ptr;
  using weight_type = typename Grahp<T>::weight_type;

  std::unordered_set<node_ptr> visited;
  std::unordered_set<node_ptr> remained;
  std::unordered_map<node_ptr, weight_type> weight_map;

  for (auto iter = graph.begin(); iter != graph.end(); ++iter) {
    remained.emplace(*iter);
    weight_map.emplace(*iter, std::numeric_limits<weight_type>::max());
  }

  while (!remained.empty()) {
    auto min = std::min_element(remained.begin(), remained.end(),
                                [&weight_map](auto lhs, auto rhs) {
                                  return weight_map[lhs] < weight_map[rhs];
                                });
    visited.insert(*min);
    for (typename Grahp<T>::GraphEdge edge : (*min)->ajacencyList()) {
      node_ptr adj_node = edge.adjacency_node;
      if (edge.weight + weight_map[(*min)] < weight_map[adj_node]) {
        weight_map[adj_node] = edge.weight + weight_map[(*min)];
      }
    }
    remained.erase(min);
  }
}

template <typename T>
void topologicSort(Grahp<T> &graph) {
  using node_ptr = typename Grahp<T>::const_node_ptr;
  std::vector<node_ptr> stack;
  std::unordered_set<node_ptr> visited;
  std::function<void(node_ptr)> pushNode;
  pushNode = [&](node_ptr node) {
    for (auto input : node->inputs()) {
      if (visited.end() == visited.find(node)) {
        pushNode(input);
      }
    }
    stack.push(node);
    visited.insert(node);
  };
  for (const auto &node : graph) {
    if (visited.end() != visited.find(node)) {
      continue;
    }
    pushNode(node);
  }
}

} // namespace lskd