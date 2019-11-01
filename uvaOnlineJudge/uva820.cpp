#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
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
int flow[100][100];
int p[100];
vector<vi> adj;
int s, t;
int f;
void augment(int cur, int mn){
  if(cur == s){
    f = mn;
  }else if (p[cur] != -1){
    augment(p[cur], min(mn, flow[p[cur]][cur]));
    flow[p[cur]][cur] -=f;
    flow[cur][p[cur]] +=f;
  }
}
int main(){
  int n;
  cin>>n;
  int ic=0;
  while(n){
    adj.clear();
    memset(flow,0 , sizeof flow);
    adj.reserve(n);
    for(int i =0; i <n;i++)
      adj.push_back({});
    int c;
    cin >> s >> t >> c;
    s--;
    t--;
    for(int i =0; i<c; i++){
      int a,b, w;
      cin >> a>>b>>w;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
      flow[a][b] += w;
      flow[b][a]+= w;
    }
    int mf = 0;
    while(true){
      f =0;
      queue<int> q;
      q.push(s);
      bitset<100> seen;
      seen[s] = true;
      memset(p,-1,sizeof p);
      while(!q.empty()){
	int u = q.front();
	q.pop();
	if (u == t)
	  break;
	for(auto v : adj[u]){
	  if(seen[v]) continue;
	  if (flow[u][v] > 0){
	    q.push(v);
	    p[v] =u;
	    seen[v] = true;
	  }
	}
      }
      augment(t, 1e9);
      mf += f;
      if(f == 0 ) break;


    }
    printf("Network %d\n", ++ic);
    printf("The bandwidth is %d.\n\n", mf);
    cin>>n;
  }
  
}
