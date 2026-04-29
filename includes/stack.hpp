#ifndef STACK_HPP
#define STACK_HPP

#include "container.hpp"

template <typename T>
class Stack : public Container<T> {
public:
  Stack();

  Stack(const Stack& other);
  Stack& operator=(const Stack& other);
  ~Stack();

  // Unique Stack Functions
  T& Top();
  const T& Top() const;

  // Override the virtual functions!
};

#endif  // STACK_HPP
