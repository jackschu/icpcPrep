#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

void printBoard(vector<vi> &board) {
  for (auto row : board) {
    for (auto elem : row)
      cout << elem << "\t";
    cout << endl;
  }
}

int main() {
  vector<vi> board;
  vector<vi> dists;
  string l;
  int h = 0, w;
  while (getline(cin, l)) {
    w = l.size() * 5;
    vi row;
    h++;
    vi empty_dists(w, 100000);
    for (int i = 0; i < 5; i++) {
      for (auto one_char : l) {
        int targ_value = one_char - '0' + i;
        if (targ_value > 9)
          targ_value -= 9;
        if (targ_value > 9)
          cout << "heck" << endl;
        row.push_back(targ_value);
      }
    }
    board.push_back(row);
    dists.push_back(empty_dists);
  }

  int initial_size = board.size();
  for (int i = 1; i < 5; i++) {
    vi empty_dists(w, 100000);
    for (int j = 0; j < initial_size; j++) {
      vi new_row;
      for (auto elem : board[j]) {
        int targ_value = elem + i;
        if (targ_value > 9)
          targ_value -= 9;
        if (targ_value > 9)
          cout << "heck" << endl;
        new_row.push_back(targ_value);
      }
      board.push_back(new_row);
      dists.push_back(empty_dists);
      h++;
    }
  }

  dists[0][0] = 0;
  int prev_ans = dists[h - 1][w - 1];
  int ans = prev_ans + 1;
  while (prev_ans != ans) {
    for (int i = 1; i < h + w; i++) {
      for (int j = 0; j <= i; j++) {
        int x = i - j;
        int y = j;
        if (y >= h || x >= w)
          continue;
        vi dx = {1, -1, 0, 0};
        vi dy = {0, 0, 1, -1};
        for (int i = 0; i < dx.size(); i++) {
          int new_y = y + dy[i];
          int new_x = x + dx[i];
          if (min(new_y, new_x) < 0 || new_y >= h || new_x >= w)
            continue;
          int new_dist = board[y][x] + dists[new_y][new_x];
          dists[y][x] = min(dists[y][x], new_dist);
        }
      }
    }
    prev_ans = ans;
    ans = dists[h - 1][w - 1];
  }
  cout << ans << endl;
}
