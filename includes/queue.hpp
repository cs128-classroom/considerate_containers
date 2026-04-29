#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "container.hpp"

template <typename T>
class Queue : public Container<T> {
public:
  Queue();

  Queue(const Queue& other);
  Queue& operator=(const Queue& other);
  ~Queue();

  // Unique Queue Functions
  T& Front();
  const T& Front() const;
  T& Back();
  const T& Back() const;

  // Override the virtual functions!
};

#endif  // QUEUE_HPP
