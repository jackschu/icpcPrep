#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  int n;
  while(cin>>n){
    vector<pair<bool,int>> cmds;
    cmds.reserve(n);
    for(int i = 0; i< n; i++){
      int a,b;
      cin >> a >> b;
      cmds.push_back(pair<bool,int>((a==1), b));
    }
    bool stk = true;
    stack<int> st;
    for(auto elem : cmds){
      if(elem.first){
	st.push(elem.second);
      } else {
	if(st.empty() || st.top() != elem.second){
	  stk = false;
	  break;
	}
	st.pop();
      }
    }
    bool q_bool = true;
    queue<int> q;
    for(auto elem : cmds){
      if(elem.first){
	q.push(elem.second);
      } else {
	if(q.empty() || q.front() != elem.second){
	  q_bool = false;
	  break;
	}
	q.pop();
      }
    }
    bool pq_bool = true;
    priority_queue<int> pq;
    for(auto elem : cmds){
      if(elem.first){
	pq.push(elem.second);
      } else {
	if(pq.empty() || pq.top() != elem.second){
	  pq_bool = false;
	  break;
	}
	pq.pop();
      }
    }
    if(pq_bool + q_bool + stk > 1){
      cout << "not sure" <<endl;
    } else if(pq_bool){
      cout << "priority queue" <<endl;
    } else if(q_bool){
      cout << "queue" <<endl;
    } else  if(stk){
      cout << "stack" <<endl;
    }else{
      cout << "impossible" <<endl;
    }
  }
}
