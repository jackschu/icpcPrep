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


ii mk_pair(int x){
  return ii(x/5,x%5);
}
int dist(ii a, ii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int get_score(vii &offices, vector<pair<ii,int>> &places){
  int sum = 0;
  for(auto elem: places){
    int mn = 100;
    for(auto off : offices){
      mn = min(mn, dist(elem.first, off));
    }
    sum += mn * elem.second;
  }
  return sum;
}
int main() {
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    vector<pair<ii, int>> places;
    int n;
    cin >> n;
    places.reserve(n);
    for (int i = 0; i < n; i++) {
      int r, c, v;
      cin >> r >> c >> v;
      places.push_back(pair<ii, int>(ii(r, c), v));
    }
    int mn = -1;
    vi best = {0,0,0,0,0};
    for(int a=0; a< 25; a++){
      for(int b=a+1; b<25;b++){
	for(int c=b+1; c<25; c++){
	  for(int d=c+1; d<25; d++){
	    for(int e=d+1; e<25; e++){
	      vii offices = {mk_pair(a),mk_pair(b),mk_pair(c),mk_pair(d),mk_pair(e)};
	      int score = get_score(offices, places);
	      if(score < mn || mn == -1){
		best = {a,b,c,d,e};
		mn = score;
	      }
	    }
	  }
	}
      }
    }
    for(int i = 0; i < 5; i++){
      if(i!= 0) cout << " ";
      cout << best[i];
    }
    cout <<endl;
  }
}
