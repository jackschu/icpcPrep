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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
  int n , m;
  while(cin >> n >> m){
    map<int, vi> s;
    for(int i = 0; i < n; i++){
      int x;
      cin>> x;
      auto found = s.find(x);
      if(found == s.end()){
	s[x] = {i+1};
      }else{
	s[x].push_back(i+1);
      }
    }
    for(int i = 0; i < m; i++){
      int k,v;
      cin >> k >> v;
      auto found = s.find(v);
      if(found == s.end()){
	cout << 0 << endl;
      }else{
	vi &cur= found->second;
	if(cur.size() < k){
	  cout << 0 << endl;
	} else {
	  cout << cur[k-1] <<endl;
	}
      }
    }
  }
}
