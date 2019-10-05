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

void run_case(int m, int n){
  cout << n << " " << m<<endl;
  vector<vii> g;
  g.reserve(n);
  for(int i = 0 ;i <n ;i++){
    g.push_back({});
  }
  for(int i = 0; i<m ; i++){
    int r;
    cin >> r;
    if(r==0)continue;
    vi pos, val;
    pos.reserve(r);
    val.reserve(r);
    copy_n(istream_iterator<int>(cin), r, back_inserter(pos));
    copy_n(istream_iterator<int>(cin), r, back_inserter(val));
    for(int j = 0; j < r; j++){
      DEBUG cout << g.size() <<  " " <<pos[j]<<endl;
      g[pos[j]-1].push_back(ii(i+1,val[j]));
    }
  }
  for(int i = 0; i <n; i++){
    sort(g[i].begin(), g[i].end());
    int sz = g[i].size();
    cout<< sz;
    for(int j = 0; j < sz; j++){
      cout << " " << g[i][j].first;
    }
    cout << endl;
    for(int j = 0; j < sz; j++){
      if(j) cout << " ";
      cout<< g[i][j].second;
    }
    cout<<endl;
  }
}
int main(){
  int n, m;
  while(cin >>m >> n){
    run_case(m,n);
  }

}
