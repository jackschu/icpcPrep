#include <algorithm>
#include <bitset>
#include <cctype>
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

vector<pair<set<int>, int>> commons;
vi ones;
bool cur[20];
int ans;
vi vans;

void sim(int n) {
  vi vcur;
  for (int i = 0; i < n; i++) {
    if (cur[i]) {
      DEBUG cout << i << " ";
      vcur.push_back(i);
    }
  }
  DEBUG cout << endl;
  int sum = 0;
  int m = commons.size();
  bool com_use[10];
  fill_n(com_use, 10, 0);
  for (auto num : vcur) {
    sum += ones[num];
    for (int i = 0; i < m; i++) {
      if (commons[i].first.find(num) != commons[i].first.end()) {
        if (com_use[i]) {
          sum -= commons[i].second;
        } else {
          com_use[i] = true;
        }
      }
    }
  }
  DEBUG cout << sum << endl;
  if (sum > ans) {
    ans = sum;
    vans = vcur;
  }
}

void combos(int n, int b, int st = -1) {
  if (b == 0) {
    sim(n);
  } else {
    for (int i = st + 1; i < n; i++) {
      cur[i] = true;
      combos(n, b - 1, i);
      cur[i] = false;
    }
  }
}

int main() {
  int n, b;
  cin >> n >> b;
  int cn = 0;
  while (n | b) {
    cn++;
    printf("Case Number  %d\n", cn);
    for (int i = 0; i < 20; i++)
      cur[i] = false;
    commons.clear();
    ones.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ones.push_back(x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int t;
      cin >> t;
      set<int> s;
      for (int j = 0; j < t; j++) {
        int x;
        cin >> x;
        s.insert(x - 1);
      }
      int v;
      cin >> v;
      commons.push_back(pair<set<int>, int>(s, v));
    }
    ans = -1;
    vans.clear();
    combos(n, b);
    printf("Number of Customers: %d\n", ans);
    cout << "Locations recommended:";
    for (auto elem : vans)
      cout << " " << elem + 1;
    cout << endl << endl;
    cin >> n >> b;
  }
}
