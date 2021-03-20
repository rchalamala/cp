// https://github.com/EgorKulikov/cpp/tree/master/lib/graph
// Verification:
//

#include "graph.h"

#include <cstddef>
#include <initializer_list>
#include <vector>

template <typename Edge>
Graph<Edge>::Graph(const std::size_t& N) : graph{N, std::vector<Edge>()} {}

template <typename Edge>
template <typename... Args>
void Graph<Edge>::add_edge(const std::size_t& from, const std::size_t& to,
                           Args&... args) {
  graph[from].emplace_back(to, args...);
  if (Edge::reversable) graph[to].emplace_back(from, args...);
}

template <typename Edge>
void Graph<Edge>::extend() {
  graph.emplace_back();
}

template <typename Edge>
[[nodiscard]] std::size_t Graph<Edge>::size() const noexcept {
  return graph.size();
}

template <typename Edge>
[[nodiscard]] bool Graph<Edge>::empty() const noexcept {
  return graph.empty();
}

template <typename Edge>
template <typename InputIterator>
void Graph<Edge>::assign(InputIterator first, InputIterator last) {
  graph.assign(first, last);
}

template <typename Edge>
void Graph<Edge>::assign(const std::size_t& N, const std::vector<Edge>& value) {
  graph.assign(N, value);
}

template <typename Edge>
void Graph<Edge>::assign(
    const std::initializer_list<std::vector<Edge>>& elements) {
  graph.assign(elements);
}

template <typename Edge>
auto Graph<Edge>::begin() noexcept {
  return graph.begin();
}

template <typename Edge>
auto Graph<Edge>::begin() const noexcept {
  return graph.begin();
}

template <typename Edge>
auto Graph<Edge>::end() noexcept {
  return graph.end();
}

template <typename Edge>
auto Graph<Edge>::end() const noexcept {
  return graph.end();
}

template <typename Edge>
auto Graph<Edge>::rbegin() noexcept {
  return graph.rbegin();
}

template <typename Edge>
auto Graph<Edge>::rbegin() const noexcept {
  return graph.rbegin();
}

template <typename Edge>
auto Graph<Edge>::rend() noexcept {
  return graph.rend();
}

template <typename Edge>
auto Graph<Edge>::rend() const noexcept {
  return graph.rend();
}

template <typename Edge>
auto Graph<Edge>::cbegin() const noexcept {
  return graph.cbegin();
}

template <typename Edge>
auto Graph<Edge>::cend() const noexcept {
  return graph.cend();
}

template <typename Edge>
auto Graph<Edge>::crbegin() const noexcept {
  return graph.crbegin();
}

template <typename Edge>
auto Graph<Edge>::crend() const noexcept {
  return graph.crend();
}

template <typename Edge>
auto& Graph<Edge>::operator[](const std::size_t& at) {
  return graph[at];
}

template <typename Edge>
const auto& Graph<Edge>::operator[](const std::size_t& at) const {
  return graph[at];
}

template <typename Edge>
auto& Graph<Edge>::at(const std::size_t& at) {
  return graph.at(at);
}

template <typename Edge>
const auto& Graph<Edge>::at(const std::size_t& at) const {
  return graph.at(at);
}

template <typename Edge>
auto& Graph<Edge>::front() {
  return graph.front();
}

template <typename Edge>
const auto& Graph<Edge>::front() const {
  return graph.front();
}

template <typename Edge>
auto& Graph<Edge>::back() {
  return graph.back();
}

template <typename Edge>
const auto& Graph<Edge>::back() const {
  return graph.back();
}

template <typename Edge>
void Graph<Edge>::clear() noexcept {
  graph.clear();
}

template <typename Edge>
void Graph<Edge>::resize(const std::size_t& N) {
  graph.resize(N);
}

template <typename Edge>
void Graph<Edge>::resize(const std::size_t& N, const std::vector<Edge>& value) {
  graph.resize(N, value);
}