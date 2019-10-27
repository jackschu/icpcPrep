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

priority_queue<pair<ll, int>> pq;
vector<vector<pair<int, ll>>> adj;
bool seen[200000];
void process(int u){
  seen[u]= true;
  for(auto v: adj[u]){
    if(!seen[v.first]) pq.push(pair<ll, int>(-v.second, -v.first));
  }
}

int main(){
  int m, n;
  cin >> m >> n;
  
  while(m | n){
    fill_n(seen, m, 0);
    adj.clear();
    adj.reserve(m);
    for(int i = 0; i < m; i++){
      adj.push_back({});
    }
    ll tot= 0;
    for(int i = 0; i < n ; i++){

      int a,b;
      ll w;
      cin >> a >> b >>w;
      tot+=w;
      adj[a].push_back(pair<int, ll>(b, w));
      adj[b].push_back(pair<int, ll>(a, w));
    }
    ll cost = 0;
    process(0);
    while(!pq.empty()){
      pair<ll, int> front  = pq.top(); pq.pop();
      int u =  -front.second;
      if(!seen[u]){
	cost -=front.first;
	process(u);
      }
    }
    cout << tot - cost << endl;
    cin >> m >> n;
  }
}
