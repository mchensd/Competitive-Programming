#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

#define MAXN 100000
vector<int> E[MAXN];
int F[21][MAXN];

int main() {
  freopen("a.in", "r", stdin);
  // freopen("nearcows.out", "w", stdout);
  int N, K; scanf("%d%d", &N, &K);
  assert(1 <= N && N <= 100000 && 1 <= K && K <= 20);
  for(int i = 1; i < N; i++) {
    int u, v; scanf("%d%d", &u, &v); u--; v--;
    assert(0 <= u && u < N && 0 <= v && v < N);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", F[0] + i);
    assert(0 <= F[0][i] && F[0][i] <= 1000);
    F[1][i] += F[0][i];
    for(int j = 0; j < E[i].size(); j++) {
      F[1][E[i][j]] += F[0][i];
    }
  }
  for(int i = 2; i <= K; i++) {
    for(int j = 0; j < N; j++) {
      F[i][j] = -(E[j].size()-1) * F[i - 2][j];
      if (j == 87) printf("%d %d %d %d %d\n", i, j, F[i][j], E[j].size(), F[i-2][j]);
      for(int k = 0; k < E[j].size(); k++) {
        F[i][j] += F[i - 1][E[j][k]];
        if (j == 87)printf("%d %d %d\n", i, E[j][k], F[i-1][E[j][k]]);
      }
      if (j == 87)printf("%d\n", F[i][j]);
    }
    cout << '\n';
  }
  for(int i = 0; i < 10; i++) printf("%d %d %d %d\n", F[0][i], F[1][i], F[2][i], F[3][i]);
}