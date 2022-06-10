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
#include <array>
#include <map>

class Graph {
  int **a;
  int *arr;
  float *ProMat;
  int dim;
  int state;
  std::vector<int> Count;
  std::vector<int> v;
  std::vector<std::vector<std::pair<int,int>>>Area;
  std::map<int, std::vector<float>> Trans; //转移概率表
  ~Graph();

 public:
  explicit Graph(int di, int sta, int &p_int);
  int RandomWalk();
  bool IsIn(int num, int n);
  void SetCount();
  void getProMatrix();
  void getProArea();
  void SelectNode(int &node);
  void print();
  void PrintMatrix();
  void TransProMatrix();
  std::vector<float> getPro(int node);
  int getMatrix(int x, int y);
};

#endif //DLIB__GRAPH_H_
