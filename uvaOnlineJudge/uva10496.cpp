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

int mem[11][2050];
int dists[11][11];
int n;
int backtrack(int last, int used){
  DEBUG printf("%d %d %d\n",last,used, (1<<n)-1);
  if(used == (1<<n)-1) return dists[last][0];
  if(mem[last][used]!= -1) return mem[last][used];
  int best = -1;
  for(int i = 1; i < n; i++){
    if(used & 1 << i) continue;
    int cur = dists[last][i] + backtrack(i, used|(1<<i));
    if(best == -1 || cur < best){
      best = cur;
    }
  }
  return mem[last][used] = best;
}
int main(){
  int tc;
  cin >> tc;
  for(int ic = 0; ic <tc; ic++){
    memset(mem, -1, sizeof mem);
    vii verts;
    
    int stx, sty;
    cin >> stx >> sty;
    cin >> stx >>  sty;

    cin >> n;
    n++;
    verts.reserve(n);
    
    verts.push_back(ii(stx,sty));
    for(int i = 1; i <n ; i++){
      int a,b;
      cin>> a>>b;
      verts.push_back(ii(a,b));
    }
    for(int i = 0; i <n; i++){
      for(int j = 0; j <n; j++){
	ii a = verts[i], b =verts[j];
	dists[i][j] = abs(a.first-b.first)+ abs(a.second- b.second);
      }
    }
    int out = backtrack(0,1);
    printf("The shortest path has length %d\n", out);
  }
}
