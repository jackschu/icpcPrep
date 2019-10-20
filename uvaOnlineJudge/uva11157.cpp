#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
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

bool works(const vii &stones, int k, int d) {
  int n = stones.size();
  bool *used = new bool[n]();
  int cur = 0;
  int idx = 0;
  bool win = true;
  while(cur != d && win){
    int best = -1;
    for(int i = idx+1; i < n && win; i++){
      DEBUG printf("cur %d best %d i %d stone %d\n",cur, best, i, stones[i].first);
      if(stones[i].second == 0 && used[i]) continue;
      if(stones[i].first > cur && stones[i].first - cur <= k){
	best = i;
      } else if (stones[i].first -cur > k){
	break;
      }
    }
    if(best == -1) {
      win = false; continue;
    }
    cur = stones[best].first;
    used[best] = true;
    idx = best;
  }
  if(!win){
    delete[] used;
    return win;
  }
  
  while(cur != 0 && win){
    int best = -1;
    for(int i = idx-1; i >= 0 && win; i--){
      DEBUG printf("cur %d best %d i %d stone %d\n",cur, best, i, stones[i].first);
      if(stones[i].second == 0 && used[i]) continue;
      if(stones[i].first < cur && cur - stones[i].first <= k){
	best = i;
      } else if (cur - stones[i].first > k){
	break;
      }
    }
    if(best == -1) {
      win = false; continue;
    }
    cur = stones[best].first;
    used[best] = true;
    idx = best;
  }
  delete []used;
  return win;
}

int main() {

  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    vii stones;
    int n, d;
    cin >> n >> d;
    stones.push_back(ii(0, 1));
    for (int i = 0; i < n; i++) {
      char c, idc;
      int dist;
      cin >> c >> idc;
      cin >> dist;
      stones.push_back(ii(dist, (int)(c == 'B')));

    }

    stones.push_back(ii(d, 1));
    int high = d;
    int low = 1;
    int guess;
    int mn = d+1;
    while(high >= low){
      guess = (high+low)/2;
      if(works(stones, guess, d)){
	mn = min (mn, guess);
	high = guess-1;
      }else{
	low = guess+1;
      }
    }
    printf("Case %d: %d\n", ic+1, mn);

  }
}
