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


typedef pair<int, ii> iii;
int inf  = 1e9;
int main(){
  int n,k;
  int dist[100][5];
  while(cin >> n >> k){
    vi ts;
    ts.reserve(n);
    for(int i = 0; i < n; i++){
      int t;
      cin >>t;
      ts.push_back(t);
    }
    vector<vi> nums;
    vector<vi> lvls;
    lvls.reserve(100);
    for(int i =0; i < 100; i++)
      lvls.push_back({});
    nums.reserve(n);
    for(int i= 0 ; i < n; i++){
      nums.push_back({});
    }
    cin.ignore();
    for(int i = 0; i < n; i++){
      string s;
      getline(cin, s);
      stringstream ss(s);
      int x;
      while(ss >> x){	
	nums[i].push_back(x);
	lvls[x].push_back(i);
      }
    }
    vector<vector<vector<iii>>> adj;
    adj.reserve(100);
    for(int i =0; i < 100; i++){
      adj.push_back({});
      for(int j =0; j < n; j++){
	adj[i].push_back({});
      }
    }
    
    
    for(int i = 0; i < n; i++){
      int sz = nums[i].size();
      for(int j = 1; j < sz; j++){
	int cost = (nums[i][j]-nums[i][j-1])*ts[i];
	adj[nums[i][j]][i].push_back(iii(cost,ii(nums[i][j-1], i)));
	adj[nums[i][j-1]][i].push_back(iii(cost,ii(nums[i][j], i)));
      }
    }

    for(int i  = 0; i < 100 ; i++){
      int sz= lvls[i].size();
      for(int j = 0 ;j <sz; j++){
	for(int k = j+1; k <sz; k++){
	  int fa = lvls[i][j];
	  int fb = lvls[i][k];
	  adj[i][fa].push_back(iii(60,ii(i, fb)));
	  adj[i][fb].push_back(iii(60,ii(i, fa)));
	}
      }
    }

    for(int i= 0; i < 100; i++)
      for(int j= 0; j < 5; j++)
	dist[i][j] = inf;
    
    priority_queue<iii, vector<iii>, greater<iii>> q;
    for(int i = 0; i < n; i++){
      q.push(iii(0,ii(0,i)));
      dist[0][i] = 0;
    }

    while(!q.empty()){
      auto cur  = q.top(); q.pop();
      int d = cur.first;
      int level = cur.second.first;
      int floor = cur.second.second;
      if(d > dist[level][floor]) continue;
      for(auto pv : adj[level][floor]){
	ii v= pv.second;
	if(dist[level][floor] + pv.first < dist[v.first][v.second]){
	  dist[v.first][v.second] = dist[level][floor] + pv.first;
	  q.push(iii(dist[v.first][v.second],v));
	}
      }
    }
    int out = inf;
    for(int i = 0; i < n; i++){
      out = min(out, dist[k][i]);
    }
    if(out == inf)
      cout << "IMPOSSIBLE"<<endl;
    else
      cout << out  << endl;

  }
}
