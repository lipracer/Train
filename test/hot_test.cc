#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>

#include "gtest/gtest.h"

#include "algorithm.hpp"

namespace {

typedef struct SListNode {
  void* data;
  SListNode* next;
} * slist;

slist append(slist list, void* data) {
  auto node = new SListNode;
  node->data = data;
  node->next = list;
  return node;
}

void destory(slist list, std::function<void(void*)> data_free) {
  std::unordered_set<SListNode*> set;
  while (list) {
    auto tmp = list;
    if (set.find(tmp) != set.end()) {
      return;
    }
    set.emplace(tmp);
    list = list->next;
    if (data_free) data_free(tmp->data);
    delete tmp;
  }
}

slist buildSignleList() {
  slist head = nullptr;
  for (size_t i = 0; i < 100; ++i) {
    auto data = new int;
    *data = i;
    head = append(head, data);
  }
  return head;
}

slist buildCycleList() {
  slist head = nullptr;
  auto data = new int;
  *data = 0;
  head = append(head, data);
  SListNode* tail = head;
  for (size_t i = 1; i < 100; ++i) {
    auto data = new int;
    *data = i;
    head = append(head, data);
  }
  tail->next = head;
  return head;
}

bool hasCycle(slist list) {
  if (!list) return false;
  SListNode* slowPtr = list;
  SListNode* fastPtr = list->next;
  while (fastPtr) {
    if (fastPtr == slowPtr) {
      return true;
    }
    if(!fastPtr->next) {
      return false;
    }
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
  }
  return false;
}

}  // namespace

TEST(ListTest, cycle) {
  auto slist = buildSignleList();
  auto clist = buildCycleList();

  EXPECT_FALSE(hasCycle(slist));
  EXPECT_TRUE(hasCycle(clist));

  destory(slist, [](void* data) { delete reinterpret_cast<int*>(data); });
  destory(clist, [](void* data) { delete reinterpret_cast<int*>(data); });
}

TEST(shotestpath, dijkstra) {
  using Graph = type::Grahp<int>;
  Graph graph;
  Train::dijkstra(graph, graph.begin());
}