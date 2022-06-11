//
// Created by yqy1277 on 2022/4/23.
//

#include <random>
#include <list>
#include <map>
#include "Graph.h"

Graph::Graph(int di, int sta, int &p_int) {

  //a = (int *)malloc(sizeof(int) * dim);
  dim = di;
  memset(&arr, 0, sizeof(int *));
  state = sta; //转移次数
  arr = &p_int;//邻接矩阵（不区分有向图或者无向图）
  a = (int **) malloc(sizeof(arr) * di); //a是为了方便使用索引访问图
  for (int i = 0; i < di; i++) {
    a[i] = arr + dim * i;
  }
  //free(arr);
  SetCount(); //各节点相邻节点之和及节点个数
  getProMatrix(); //根据权重所得的转移概率表
  TransProMatrix();
  getProArea(); //获得各节点概率转移区域（1-100）
}
Graph::~Graph() {
  free(a);
}

/***
 * 根据图的有向边权重产生的随机游走通路
 * @return
 */
int Graph::RandomWalk() {
  //float prob = 0.0;
  int num = 0;
  int current = 0;
  v.push_back(current); //将起始节点存入通路容器v
  while (num < state) { //统计当前通路长度num 和指定长度state
    SelectNode(current); //选择一个节点，并将下一跳的节点通过指针传递的方式传回
    v.push_back(current); //将下一跳的节点存入容器v
    num++;
  }
  return 0;
}

/***
 * 遍历通路v
 */
void Graph::print() {
  for (auto &it : v) {
    std::cout << it << std::endl;
  }
}

/***
 * 根据当前节点得到下一跳节点
 * @param node 传入时是当前节点，最终为下一跳节点
 */
void Graph::SelectNode(int &node) {
  //std::default_random_engine e;
  srand((unsigned) time(nullptr));
  auto random = (rand() % 100);
  printf("%.2f\n", random);
  int NodeAdj = 1; //当前节点相邻节点个数计数
  while (NodeAdj <= dim)
    if (IsIn(random, NodeAdj))
      node = NodeAdj; //等于random所在范围对应的节点序号
//  while (random > total) {
//    total += Trans[node][cnt++];
//  }
//  auto p = cnt;
//  //写个二分查找？如何将权重与索引挂钩呢？
//  std::list<float> s;
//  int num = 0;
//  s.push_back(0.0);
//  while (num++) {
//    s.push_back(((float) a[node][num] / (float) Count[node]) + s.back());
//    if (num == node)
//      continue;
//  }
//
//  //占比 * 权重
//  node = cnt;
//  std::cout << node << std::endl;

}

/***
 * 以邻接矩阵的方式打印图
 */
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

/***
 *
 * @param x 矩阵行索引
 * @param y 矩阵列索引
 * @return 返回a[x][y]所对应的元素
 */
int Graph::getMatrix(int x, int y) {
  return a[x][y];
}

/***
 *
 * @param node
 * @return
 */
std::vector<float> Graph::getPro(int node) {
  std::vector<float> t;
  auto total = (float) Count[node];
  for (int i = 0; i < dim; i++) {
    auto pro_t = (float) ((float) getMatrix(node, i) / total);
    //std::cout << node << "with " << i << " :pro: " << pro_t << " "<<std::endl;
    t.push_back(pro_t);
  }
  //std::cout << std::endl;
  return t;
}

/***
 * 初始化了转移概率矩阵
 */
void Graph::getProMatrix() {
  std::cout << "Get an initial Probility" << std::endl;
  for (int i = 0; i < dim; i++) {
    auto ProM = getPro(i);
    Trans.insert(std::pair<int, std::vector<float>>(i, ProM));
  }
}

/***
 * 统计每个节点所连接的点的个数，并存入count容器中
 */
void Graph::SetCount() {
  for (int i = 0; i < dim; i++) {
    int tmp = 0, cnt = 0;
    for (int j = 0; j < dim; j++) {
      if (0 < a[i][j]) {
        tmp += a[i][j];
//        cnt++;
      }
    }
    Count.push_back(tmp);
  }
  /*for (auto &it:Count) {
    std::cout << it << std::endl;
  }*/
}

/***
 * 判断num是否在某个容器中
 * @param num 所要判断的元素
 * @return 存在返回真，否则为假
 */
bool Graph::IsIn(int num, int n) {
  for (int (i) = 0; (i) < dim; ++(i)) {

    auto t = Area[n][i];
    if (num >= t.first && num < t.second)
      return true;
  }
  return false;
}

/***
 * 输出概率转换矩阵
 */
void Graph::TransProMatrix() {
  for (auto &it: Trans) {
   std::cout<<it.first<<" ";
   for (auto &item :it.second){
     std::cout<<item<<" ";
   }
   std::cout<<std::endl;
 }
}

/***
 * 获得一个 dim * dim 维度的二元组矩阵
 * 其中每个二元组代表节点 i -> j的概率区域（区域为1-100）
 */
void Graph::getProArea() {
  printf("Initial a ProArea\n");
  std::vector<std::pair<int, int>>t;
  int left = 0, right = 0;
  for (int i = 0; i < dim; ++i) {
    left = right = 0;
    right = (int)(Trans[i][0] * 100.0);
    t.emplace_back(left, right);
    for (int j = 0; j < dim-1; ++j) {
      left = right; //左边界
      right += (int)(Trans[i][j+1] * 100.0); //右边界
      t.emplace_back(left, right); //一个二元组
    }
    Area.push_back(t); //一个节点对应的二元组列表被存入
    t.clear();
  }
  /*for(auto &it:Area) {
    for (auto &item:it){
      std::cout<<item.first<<"----"<<item.second;
      std::cout<<std::endl;
    }
    std::cout<<std::endl;
  }*/
}
