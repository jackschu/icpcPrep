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

int n;
vector<vi> board;
int ctaken;
int rtaken;
map<ii, int> mem;

int alice();
int bob(int last) {
  int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (ctaken & 1 << i)
      continue;
    ctaken |= 1 << i;
    mn = min(alice() + board[i][last], mn);
    ctaken ^= 1 << i;
  }
  int out = mn == INT_MAX ? 0 : mn;
  return out;
}

int alice() {
  int mx = INT_MIN;
  auto found = mem.find(ii(ctaken, rtaken));
  if (found != mem.end())
    return found->second;
  for (int i = 0; i < n; i++) {
    if (rtaken & 1 << i)
      continue;
    rtaken |= 1 << i;
    mx = max(mx, bob(i));
    rtaken ^= 1 << i;
  }
  int out = (mx == INT_MIN) ? 0 : mx;
  mem[ii(ctaken, rtaken)] = out;
  return out;
}

void run_case() {
  mem.clear();
  board.clear();
  ctaken = 0;
  rtaken = 0;
  board.reserve(n);
  for (int i = 0; i < n; i++) {
    vi temp;
    temp.reserve(n);
    int x;
    for (int j = 0; j < n; j++) {
      cin >> x;
      temp.push_back(x);
    }
    board.push_back(temp);
  }
  cout << alice() << endl;
}

int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    cin >> n;
    run_case();
  }
}
