//
// Created by yqy1277 on 2022/4/23.
//

#include "Graph.h"

Graph::Graph(int di, int sta, int &p_int) {
  //a = (int *)malloc(sizeof(int) * dim);
  dim = di;
  memset(&arr, 0, sizeof(int *));
  state = sta;
  arr = &p_int;
  a = (int **) malloc(sizeof(arr) * di);
  for (int i = 0; i < di; i++) {
    a[i] = arr + dim * i;
  }
  //free(arr);
}
Graph::~Graph() {
  free(a);
}
int Graph::RandomWalk() {
  float prob = 0.0;
  int num = 0;
  int current = 0;
  v.push_back(current);
  while (num < state) {
    SelectNode(current, prob);
    v.push_back(current);
    num++;
  }
  return 0;
}
void Graph::print() {
  for (auto &it : v) {
    std::cout << it << std::endl;
  }
}
void Graph::SelectNode(int &node, float p) {
  srand((unsigned)time(nullptr));
  std::cout<<p<<std::endl;
}
void Graph::PrintMatrix() {
  /*for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      cout << arr[i * dim + j] << " ";
    }
    cout << endl;
  }*/
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      std::cout << a[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}
int Graph::getMatrix(int x, int y) {
  return a[x][y];
}
