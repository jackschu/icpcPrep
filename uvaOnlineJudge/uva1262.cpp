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
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (true)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int tc;
  cin >> tc;

  for (int ic = 0; ic < tc; ic++) {

    vector<set<char>> seen;
    for (int i = 0; i < 5; i++)
      seen.push_back({});
    int k;
    cin >> k;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 5; j++) {
        char x;
        cin >> x;
        seen[j].insert(x);
      }
    }
    vector<vector<char>> opts;
    for (int i = 0; i < 6; i++)
      opts.push_back({});
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 5; j++) {
        char x;
        cin >> x;
        if (seen[j].find(x) != seen[j].end()) {
          seen[j].erase(x);
          opts[j].push_back(x);
        }
      }
    }
    int mx = 1;
    for (int i = 0; i < 5; i++) {
      // for(auto elem :opts[i]) cout <<elem;
      // cout <<endl;
      mx *= opts[i].size();
      sort(opts[i].begin(), opts[i].end());
    }
    if (k > mx) {
      cout << "NO" << endl;
      continue;
    }
    char cur[6];
    cur[5] = '\0';
    vector<string> em;
    em.reserve(mx);
    for (int a = 0; a < opts[0].size(); a++) {
      cur[0] = opts[0][a];
      for (int b = 0; b < opts[1].size(); b++) {
        cur[1] = opts[1][b];
        for (int c = 0; c < opts[2].size(); c++) {
          cur[2] = opts[2][c];
          for (int d = 0; d < opts[3].size(); d++) {
            cur[3] = opts[3][d];
            for (int e = 0; e < opts[4].size(); e++) {
              cur[4] = opts[4][e];
	      em.push_back(cur);
            }
          }
        }
      }
    }
    nth_element(em.begin(),em.begin()+k-1, em.end());
    cout << em[k - 1]<<endl;
  }
}
