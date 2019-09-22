#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#define DEBUG if (false)

using namespace std;

bool can_win(int n, int **w, int x) {
  bool *v = new bool[n]();
  queue<int> q;
  v[x] = true;
  q.push(x);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (w[cur][i] != 0 && !v[i]) {
        v[i] = true;
        q.push(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      delete[] v;
      return false;
    }
  }
  delete[] v;
  return true;
}

struct bal {
  int w;
  string b;
  bal(int w, string b) : w(w), b(b) {}
  int winner(int x, int y) {
    char xc = char(x + 65);
    char yc = char(y + 65);
    for (auto elem : this->b) {
      if (elem == xc)
        return w;
      if (elem == yc)
        return -w;
    }
    DEBUG printf("hecc\n");
    return 0;
  }
};

int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<bal> bals;
  for (int i = 0; i < m; i++) {
    int w;
    string b;
    cin >> w;
    cin >> b;
    bals.push_back(bal(w, b));
  }
  int **wins = new int *[n]();
  for (int i = 0; i < n; i++) {
    wins[i] = new int[n]();
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int sum = 0;
      for (auto &elem : bals) {
        sum += elem.winner(i, j);
      }
      if (sum < 0)
        wins[j][i] = -sum;
      else
        wins[i][j] = sum;
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      DEBUG printf("%d ", wins[i][j]);
    }
    DEBUG printf("\n");
  }
  for (int i = 0; i < n; i++) {
    bool can = can_win(n, wins, i);
    printf("%c: %s\n", char(i + 65), can ? "can win" : "can't win");
  }
}
