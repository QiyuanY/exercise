//
// Created by yqy1277 on 2022/4/23.
//

#include <random>
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
  SetCount();
}
Graph::~Graph() {
  free(a);
}
int Graph::RandomWalk() {
  //float prob = 0.0;
  int num = 0;
  int current = 0;
  v.push_back(current);
  while (num < state) {
    SelectNode(current);
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
void Graph::SelectNode(int &node) {
  //std::default_random_engine e;
  srand((unsigned) time(nullptr));
  auto random = (float) (rand() % 100);
  random /= 100;
  float p = getPro(node);
  //写个二分查找？

  //占比 * 权重
  *node  =

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
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
int Graph::getMatrix(int x, int y) {
  return a[x][y];
}
float Graph::getPro(int node) {

  return pro;
}
void Graph::getProMatrix(int node) {
  int count = Count[node];
  float tmp;
  for (int i = 0; i < dim; i++) {
    //std::cout << a[node][i] << std::endl;
    if (0 < a[node][i]) {
      tmp = (float) (a[node][i] / count);
      Trans.insert(std::pair<int, float>(i, tmp));
    }
  }
}
void Graph::SetCount() {
  for (int i = 0; i < dim; i++) {
    int tmp = 0;
    for (int j = 0; j < dim; j++) {
      if (0 < a[i][j]) {
        tmp += a[i][j];
      }
    }
    Count.push_back(tmp);
  }
  /*for (auto &it:Count) {
    std::cout << it << std::endl;
  }*/
}
