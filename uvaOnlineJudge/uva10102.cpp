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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dist(ii a, ii b){
  return abs(a.first - b.first) + abs(a.second-b.second);
}
int main() {
  int m;
  while(cin>>m){
    vii ones, threes;
    for(int i =0 ;i < m; i++){
      for(int j = 0; j < m; j++){
	char x;
	cin >> x;
	if(x =='1'){
	  ones.push_back(ii(i,j));
	} else if(x=='3'){
	  threes.push_back(ii(i,j));
	}
      }
    }
    int sz1 = ones.size();
    int sz3 = threes.size();
    int mx = 0;
    
    for(int i = 0; i < sz1; i++){
      int mn = 3*m;
      for(int j = 0; j < sz3; j++){
	mn = min(mn,dist(ones[i], threes[j]));
      }
      mx = max(mx, mn);
    }
    cout << mx<<endl;
  }
}
