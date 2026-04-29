// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : <Your Name>                  Environment : ubuntu:bionic               //
//  Date ......: <00/00/00>                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <vector>

#include "catch.hpp"
#include "container.hpp"
#include "queue.hpp"
#include "stack.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <stdexcept>

#include "solution.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Queue Basic", "[queue]") {
  Queue<int> q;
  REQUIRE(q.Empty());
  q.Push(1);
  REQUIRE(q.Front() == 1);
  q.Pop();
  REQUIRE(q.Empty());

  q.Push(2);
  REQUIRE(q.GrabElement() == 2);
  REQUIRE(q.Empty());

  q.Push(1);
  q.Push(2);
  REQUIRE(q.GrabElement() == 1);
  REQUIRE(q.GrabElement() == 2);
  REQUIRE(q.Empty());
}

TEST_CASE("Stack Basic", "[stack]") {
  Stack<int> s;
  REQUIRE(s.Empty());
  s.Push(1);
  REQUIRE(s.Top() == 1);
  s.Pop();
  REQUIRE(s.Empty());

  s.Push(2);
  REQUIRE(s.GrabElement() == 2);
  REQUIRE(s.Empty());

  s.Push(1);
  s.Push(2);
  REQUIRE(s.GrabElement() == 2);
  REQUIRE(s.GrabElement() == 1);
  REQUIRE(s.Empty());
}

bool TestRandomQueue() {
  size_t size = std::rand() % 30;
  Queue<int> q1;
  std::queue<int> q2;
  for (size_t i = 0; i < size; i++) {
    int r = std::rand();
    q1.Push(r);
    q2.push(r);
  }
  for (size_t i = 0; i < size; i++) {
    if (q1.GrabElement() != q2.front()) {
      return false;
    }
    q2.pop();
  }
  if (!q1.Empty()) {
    return false;
  }
  return true;
}

bool TestRandomStack() {
  size_t size = std::rand() % 30;
  Stack<int> s1;
  std::stack<int> s2;
  for (size_t i = 0; i < size; i++) {
    int r = std::rand();
    s1.Push(r);
    s2.push(r);
  }
  for (size_t i = 0; i < size; i++) {
    if (s1.GrabElement() != s2.top()) {
      return false;
    }
    s2.pop();
  }
  if (!s1.Empty()) {
    return false;
  }
  return true;
}

TEST_CASE("Queue Random Tests", "[queue]") {
  std::srand(std::time(NULL));
  for (int i = 0; i < 10; i++) {
    REQUIRE(TestRandomQueue());
  }
}

TEST_CASE("Stack Random Tests", "[stack]") {
  std::srand(std::time(NULL));
  for (int i = 0; i < 10; i++) {
    REQUIRE(TestRandomStack());
  }
}

TEST_CASE("Stack Traversal", "[GetConnected]") {
  GraphAdjList<char, int> g;
  g.AddVertex('A');
  g.AddVertex('B');
  g.AddVertex('C');
  g.AddVertex('D');
  g.AddVertex('E');
  g.AddVertex('F');

  g.AddEdge('A', 'B', 1);
  g.AddEdge('B', 'C', 1);
  g.AddEdge('B', 'D', 1);
  g.AddEdge('D', 'E', 1);

  Stack<char> s;
  std::vector<char> output = GetConnected(g, 'A', s);
  std::vector<char> expected = {'A', 'B', 'D', 'E', 'C'};
  REQUIRE(output == expected);

  output = GetConnected(g, 'B', s);
  expected = {'B', 'D', 'E', 'C', 'A'};
  REQUIRE(output == expected);

  output = GetConnected(g, 'F', s);
  expected = {'F'};
  REQUIRE(output == expected);
}
TEST_CASE("Queue Traversal", "[GetConnected]") {
  GraphAdjList<char, int> g;
  g.AddVertex('A');
  g.AddVertex('B');
  g.AddVertex('C');
  g.AddVertex('D');
  g.AddVertex('E');
  g.AddVertex('F');

  g.AddEdge('A', 'B', 1);
  g.AddEdge('B', 'C', 1);
  g.AddEdge('B', 'D', 1);
  g.AddEdge('D', 'E', 1);

  Queue<char> q;
  std::vector<char> output = GetConnected(g, 'A', q);
  std::vector<char> expected = {'A', 'B', 'C', 'D', 'E'};
  REQUIRE(output == expected);

  output = GetConnected(g, 'B', q);
  expected = {'B', 'A', 'C', 'D', 'E'};
  REQUIRE(output == expected);

  output = GetConnected(g, 'F', q);
  expected = {'F'};
  REQUIRE(output == expected);
}

/////////////////////////////////////////////////////////////////////////////////////////////