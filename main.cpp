#include <iostream>
#include <cmath>
#include <cstring>
#include "FileRead.h"
#include "Graph.h"

int main() {
  int *InitMatrix;
  int a[4][4] = {{0, 2, 3, 0},
                 {4, 0, 6, 1},
                 {7, 8, 0, 2},
                 {10, 11, 12, 0}};
  InitMatrix = a[0];
  int n = (int) sqrt(sizeof(a) / sizeof(InitMatrix[0]));
  //std::string fileName = "test.txt";
  //auto handle = new FileRead(fileName);
  auto *g = new Graph(n, 2, *InitMatrix);//指针调用
  //g->PrintMatrix();
  g->RandomWalk();
  //g->print();
//  g->getProMatrix();
  return 0;
}



