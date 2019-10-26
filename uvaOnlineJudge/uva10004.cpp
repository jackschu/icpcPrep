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
int n;
int color[200];
int main(){
  int l;
  cin >> n >> l;
  while(n){
    adj.clear();
    adj.reserve(n);
    for(int i = 0; i <n; i++)adj.push_back({});
    for(int  i= 0 ; i <l ;i++){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    memset(color, -1, sizeof color);
    queue<int> q;
    q.push(0);
    color[0] =0;
    bool win = true;
    while(!q.empty()){
      int cur = q.front(); q.pop();
      DEBUG cout << cur << endl;
      int curcol= color[cur];
      int nxtcol= 1-curcol;
      for(auto i: adj[cur]){
	if(color[i] == curcol){
	  DEBUG cout << i <<  " " << cur <<endl;
	  win = false;
	  break;
	}
	if(color[i] == nxtcol) continue;
	color[i] = nxtcol;
	q.push(i);
      }
      if(win == false)
	break;
    }
    cout << (win ? "BICOLORABLE." : "NOT BICOLORABLE.")<<endl;

    cin >>n >>l;
  }

}
