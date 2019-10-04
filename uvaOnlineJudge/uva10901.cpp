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

void run_case() {
  int n, t, m;
  cin >> n >> t >> m;
  queue<pair<int, int*>> l;
  queue<pair<int, int*>> r;
  vector<int> outs(m,0); 
  for (int i = 0; i < m; i++) {
    int x;
    string s;
    cin >> x;
    cin >> s;
    if (s == "left") {
      l.push(pair<int,int*>(x, &outs[i]));
    } else {
    r.push(pair<int,int*>(x, &outs[i]));
    }
  }
  int time = -1;
  bool is_left = true;
  while(!l.empty() || !r.empty()){
    queue<pair<int,int*>> &cur = is_left ? l: r;
    queue<pair<int,int*>> &other = is_left? r: l;
    vector<int*> to_set;
    if(cur.empty()){
      time = max(other.front().first + t, time+t);
      is_left = !is_left;
      continue;
    }
    bool other_is_lower =  other.front().first < cur.front().first;
    int ct = 0;
    while(!cur.empty() && cur.front().first <= time && ct < n){
      ct++;
      to_set.push_back(cur.front().second);
      cur.pop();
    }
    if(ct == 0){
      if(!other.empty() && other_is_lower){
	time = max(time, other.front().first);
      } else {
	time = cur.front().first;
	while(!cur.empty() && cur.front().first == time && ct < n){
	  to_set.push_back(cur.front().second);
	  cur.pop();
	  ct++;
	}
      }
    }
    time += t;
    for(int i = 0; i< ct; i++){
      *to_set[i] = time;
    }
    is_left = !is_left;
  }
  for(auto elem: outs){
    cout << elem << endl;
  }
}

int main() {
  int tc;
  cin >> tc;
  bool first = true;
  for (int i = 0; i < tc; i++) {
    if(!first) cout << endl;
    first =false;
    run_case();
  }
}
