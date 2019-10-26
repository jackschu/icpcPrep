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

vector<vi> adj;
int color[200];
int n, e;
int c1, c0;

bool dfs(int idx, int c){
  color[idx] = c;
  if(c == 1) c1++;
  else c0++;
  for(auto i : adj[idx]){
    if(color[i] == 1-c) continue;
    if(color[i] == c) return false;        
    if(!dfs(i, 1-c)) return false;
  }
  return true;
}
int main(){
  int tc;
  cin >> tc;
  for(int ic =0; ic<tc; ic++){
    memset(color, -1, sizeof color);
    cin >> n >> e;
    adj.clear();
    adj.reserve(n);
    for(int i=0 ; i<n ;i++){
      adj.push_back({});
    }
    for(int i = 0 ;i <e; i++){
      int f, t;
      cin >> f >> t;
      adj[f].push_back(t);
      adj[t].push_back(f);
    }
    int sum = 0;
    bool win = true;
    for(int i  =0;i <n;i++){
      if(color[i] != -1) continue;
      c1 = 0; c0 =0;
      if(!dfs(i, 1)){
	win = false;
	break;
      }
      sum += max(1,min(c1, c0));
    }
    if(!win) cout << -1 << endl;
    else cout << sum << endl;
  }
}
