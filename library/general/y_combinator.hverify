#ifndef Y_COMBINATOR_H
#define Y_COMBINATOR_H

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

 public:
  template <class T>
  explicit y_combinator_result(T&& fun);

  template <class... Args>
  decltype(auto) operator()(Args&&... args);
};

template <class Fun>
decltype(auto) y_combinator(Fun&& fun);
}  // namespace std

#endif