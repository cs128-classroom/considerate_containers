#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>
#include "node.hpp"

template <typename T>
class Container {
public:
  Container();

  Container(const Container& other);
  Container& operator=(const Container& other);
  virtual ~Container();

  size_t Size();

  virtual void Push(T element) = 0;
  virtual void Pop() = 0;
  virtual bool Empty() = 0;

  virtual T GrabElement() = 0;

protected:
  T& GetHead();
  T& GetTail();
  void AddHead(T element);
  void AddTail(T element);
  T RemoveHead();
  T RemoveTail();

private:
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  size_t size_ = 0;
};

#endif  // CONTAINER_HPP
