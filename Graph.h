//
// Created by yqy1277 on 2022/4/23.
//

#ifndef DLIB__GRAPH_H_
#define DLIB__GRAPH_H_

#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

class Graph {
  int **a;
  int *arr;
  int dim;
  int state;
  std::vector<int> v;
  ~Graph();

 public:
  explicit Graph(int di, int sta, int &p_int);
  int RandomWalk();
  static void SelectNode(int &node, float p);
  void print();
  void PrintMatrix();
  int getMatrix(int x, int y);
};

#endif //DLIB__GRAPH_H_
