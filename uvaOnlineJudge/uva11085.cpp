#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> em;
vi taken;
void backtrack(int c) {
  if (c == 8) {
    bool b1[20];
    bool b2[20];
    fill_n(b1, 20, 0);
    fill_n(b2, 20, 0);
    bool fail = false;
    for (int i = 0; i < 8; i++) {
      int i1 = (i - taken[i] + 7);
      int i2 = i + taken[i];
      if (b1[i1] || b2[i2]) {
        // cout << "fail" << endl;
        fail = true;
        break;
      }
      b1[i1] = true;
      b2[i2] = true;
    }
    if (!fail) {
      em.push_back(taken);
    }
  }
  for (int i = 0; i < 8; i++) {
    if (taken[i] != -1)
      continue;
    taken[i] = c;
    backtrack(c + 1);
    taken[i] = -1;
  }
}
void find_em() {
  taken.assign(8, -1);
  backtrack(0);
}

int main() {
  find_em();
  int in[8];
  int ic = 0;
  while (scanf("%d %d %d %d %d %d %d %d", in, in + 1, in + 2, in + 3, in + 4,
               in + 5, in + 6, in + 7) == 8) {
    ic++;
    int mn = 100;
    for (auto &sol : em) {
      int ct = 8;
      for (int i = 0; i < 8; i++) {
        if (in[i] - 1 == sol[i])
          ct--;
      }
      mn = min(ct, mn);
    }
    printf("Case %d: %d\n", ic, mn);
  }
}
