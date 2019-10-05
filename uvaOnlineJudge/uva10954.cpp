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
  int x;
  cin>>x;
  while(x != 0){
    vector<long> v;
    v.reserve(x);
    copy_n(istream_iterator<long>(cin), x, back_inserter(v));
    priority_queue<long,vector<long>,greater<long>>pq(v.begin(), v.end());
    long cost = 0;
    while(!pq.empty()){
      long x = pq.top();
      pq.pop();
      long y = pq.top();
      pq.pop();
      if(!pq.empty()){
	pq.push(x+y);
      }
      cost += x+y;
    }
    cout << cost << endl;
    cin >> x;
  }
}
