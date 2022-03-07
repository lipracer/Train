#include "type.h"

namespace lskd {

template <typename Node, typename Alloc>
typename Grahp<Node, Alloc>::node_ptr Grahp<Node, Alloc>::addNode(
    const Node& data) {
  nodes.emplace_back(
      new GraphNode{.data = data, .adjacency_list = {}, .graph_ = this});
  return nodes.back().get();
}

template <typename Node, typename Alloc>
void Grahp<Node, Alloc>::addEdge(GraphNode* lhs, GraphNode* rhs,
                                 weight_type weight) {
  lhs->inputs.push_back(GraphEdge{weight, rhs});
  lhs->outputs.push_back(GraphEdge{weight, rhs});
  rhs->inputs.push_back(GraphEdge{weight, lhs});
  rhs->outputs.push_back(GraphEdge{weight, lhs});
}

template <typename Node, typename Alloc>
std::string Grahp<Node, Alloc>::toString() const {
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

template <typename Node, typename Alloc>
void Grahp<Node, Alloc>::GraphNode::setInputs() const {

}

template <typename Node, typename Alloc>
void Grahp<Node, Alloc>::GraphNode::setOutputs() const {

}

// template <typename Node, typename Alloc>
// std::vector<typename Grahp<Node, Alloc>::GraphEdge> Grahp<Node, Alloc>::GraphNode::ajacencyList() const 

}  // namespace lskd