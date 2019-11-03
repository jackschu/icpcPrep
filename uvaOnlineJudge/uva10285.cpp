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
int board[100][100];
vector<vi> adj;
int r, c;
vi ts;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int * seen;
void dfs(int u){
  seen[u] = 1;
  for(auto v : adj[u])
    if(seen[v] != 1)
      dfs(v);

  ts.push_back(u);    
}
int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    string name;
    cin >> name;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
	int x;
	cin >> x;
	board[i][j] = x;
      }
    }
    adj.clear();
    adj.reserve(r*c);
    for(int i = 0; i< r*c; i++)
      adj.push_back({});
    for (int i = 0; i < r; i++) {           
      for (int j = 0; j < c; j++) {
	for(int d = 0; d < 4; d++){
	  int ni = i+ dy[d];
	  int nj = j+ dx[d];
	  if(ni < 0 || nj < 0 || ni >= r || nj >= c)
	    continue;
	  if(board[ni][nj] < board[i][j])
	    adj[i*c + j].push_back(ni*c +nj);
	}
      }
    }

    ts.clear();
    ts.reserve(r*c);
    seen = new int[r*c]();
    for(int i = 0; i < r*c ; i++){
      if(seen[i] == 1)continue;
      dfs(i);
    }
    
    int sz = ts.size();
    int out= 0;
    for(int i = sz-1; i >= 0; i--){
      for(auto v : adj[ts[i]]){
	seen[v] = max(seen[ts[i]] + 1, seen[v]);
	out = max(seen[v], out);
      }
    }
    delete []seen;
    cout << name << ": " << out << endl;
  }
}
