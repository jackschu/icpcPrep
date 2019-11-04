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
int n;
vector<vi> adj;
vi far;
vi best;
int depth;
int p[5000];
bool *seen;
void dfs(int u, int d = 0, bool set_best = false) {
  if(d> depth){
    depth = d;
    far.clear();
  }
  if(d == depth){
    far.push_back(u);    
    if(set_best){
      int cur = u;
      for(int i = 0; i < d/2; i++){
	cur = p[cur];
      }
      best.push_back(cur);
      if(d%2 == 1)
	best.push_back(p[cur]);
    }
  }
  for (auto v : adj[u]) {
    if (seen[v])
      continue;
    if(set_best)
      p[v] = u;
    seen[v] = true;
    dfs(v, d+1, set_best);
  }
}

int main() {
  while (cin >> n) {
    adj.clear();
    adj.reserve(n);
    for (int i = 0; i < n; i++)
      adj.push_back({});
    for (int i = 0; i < n; i++) {
      int nr;
      cin >> nr;
      for (int j = 0; j < nr; j++) {
        int x;
        cin >> x;
        x--;
        adj[i].push_back(x);
      }
    }
    vi ans;
    depth =0 ;
    seen = new bool[n]();
    seen[0] = true;
    dfs(0);
    delete[] seen;
    
    seen = new bool[n]();
    int x = far[0];
    seen[x] = true;
    far.clear();
    depth = 0;
    dfs(x);
    delete seen;
    
    vi side = far;
    best.clear();
    for(auto u : side){
      seen = new bool[n]();
      int x = u;
      seen[x] = true;      
      dfs(x, 0, true);
      delete seen;
    }
    sort(far.begin(), far.end());
    auto it = unique(far.begin(), far.end());
    far.resize(distance(far.begin(), it));
    sort(best.begin(), best.end());
    it =unique(best.begin(), best.end());
    best.resize(distance(best.begin(), it));
    
    printf( "Best Roots  :");
    int sz = best.size();
    for (int i = 0; i < sz; i++)
      printf(" %d",best[i]+1);
    printf("\n");

    sz = far.size();
    printf("Worst Roots :");
    for (int i = 0; i < sz; i++)
      printf(" %d",far[i]+1);
    printf("\n");
  }
}
