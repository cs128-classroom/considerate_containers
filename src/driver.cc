#include <iostream>

#include "GraphAdjList.hpp"
#include "queue.hpp"
#include "solution.hpp"
#include "stack.hpp"

int main() {
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
  Stack<char> s;
  std::vector<char> out1 = GetConnected(g, 'A', q);
  std::vector<char> out2 = GetConnected(g, 'A', s);

  std::cout << "BFS output:" << std::endl;
  for (char c : out1) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
  std::cout << "DFS output:" << std::endl;
  for (char c : out2) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
}
