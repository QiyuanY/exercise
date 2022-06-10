//
// Created by yqy1277 on 2022/6/9.
//

#include <iostream>
#include <cstring>
#include <ctime>
#include <set>

#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

std::set<std::pii> inUse;

std::pii getRandomEdge(int nv) {
  int u = rand() % nv;
  int v = rand() % nv;
  while (u == v) v = rand() % nv;
  return std::mp(u, v);
}

void solve() {
  srand(time(0));
  int nv, ne;
  scanf("%d %d", &nv, &ne);
  std::pii ST = getRandomEdge(nv);
  printf("%d %d %d %d\n", nv, ne, ST.fr, ST.sc);
  for (int i = 0; i < ne; i++) {
    std::pii edge = getRandomEdge(nv);
    while (inUse.count(edge)) edge = getRandomEdge(nv);
    printf("%d %d\n", edge.fr, edge.sc);
  }
}

int main() {
  solve();
  return 0;
}
