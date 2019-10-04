#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;


void run_case(){
  int n, s,q;
  cin >> n >> s >> q;
  vector<queue<int>> qs;
  qs.reserve(n+1);
  qs.push_back({});
  int items = 0;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    qs.push_back({});
    for(int j = 0; j< x; j++){
      items ++;
      int cur;
      cin >> cur;
      qs[i].push(cur);
    }
  }
  int pos = 0;
  long time = -2;
  stack<int> boat;
  while(items > 0){
    time+= 2;
    pos++;
    if (pos == n+1)pos =1;
    queue<int> &stat_b = qs[pos];
    //unload
    while(!boat.empty()){
      int cur = boat.top();
      if(cur == pos){
	time++;
	items--;
	boat.pop();
      } else {
	if(stat_b.size() == q){
	  break;
	}
	time++;
	stat_b.push(cur);
	boat.pop();
      }
    }
    //load
    while(!stat_b.empty()){
      if(boat.size() ==s){
	break;
      }
      boat.push(stat_b.front());
      stat_b.pop();
      time++;
    }
  }
  cout << time << endl;

}

int main(){
  int tc;
  cin >> tc;
  for(int i = 0; i < tc ;i++){
    run_case();
  }

}
