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

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
ii weights[1000][1000];

int inf = 1e8;
typedef pair<int,ii> iii;
int main(){
  int tc;
  cin >> tc;
  for(int ic = 0; ic < tc; ic++){
    int n, m;
    cin >> n >> m;
    ii targ = ii(n-1, m-1);
    for(int i = 0; i <n; i++){
      for(int j = 0; j < m ; j++){
	int x;
	cin >> x;
	weights[i][j] = ii(inf, x);
      }
    }
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(0,ii(0,0)));
    weights[0][0].first = weights[0][0].second;
    bool win = false;
    while(!pq.empty()&&!win){
      auto cur = pq.top();
      pq.pop();
      int d = cur.first;
      ii u = cur.second;
      int old_d = weights[u.first][u.second].first;
      if(d > old_d) continue;
      for(int i = 0; i< 4; i++){
	ii v = u;
	v.first += dx[i]; v.second += dy[i];
	if( v.first < 0 || v.first >=n || v.second <0 || v.second >= m) continue;
	ii &v_cost = weights[v.first][v.second];
	if(old_d + v_cost.second < v_cost.first){
	  v_cost.first = old_d+v_cost.second;
	  if(v == targ) {
	    win = true;
	    break;
	  }
	  pq.push(iii(v_cost.first, v));
	}
      }
    }
    cout << weights[targ.first][targ.second].first << endl;
  }
}

