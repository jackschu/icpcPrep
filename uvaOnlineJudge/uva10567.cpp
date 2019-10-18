#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
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

int conv(int c){
  if(c > 90){
    return  c-97;
  } else {
    return c-65+26;
  }
}

int main(){
  string s;
  getline(cin, s);
  vector<vi> ids;
  for(int i = 0; i< 52;i++){
    ids.push_back({});
  }
  int sz = s.size();
  for(int i=0; i < sz; i++){
    int c = s[i];
    ids[conv(c)].push_back(i);
  }
  int tc;
  cin >> tc;
  int maxs;
  for(int ic =0; ic < tc; ic++){
    maxs= -1;
    cin>> s;
    sz = s.size();
    bool fail = false;
    int first, last;
    for(int i = 0; i < sz;i++){
      int c = conv(s[i]);
      auto found = lower_bound(ids[c].begin(), ids[c].end(), maxs);
      if(found == ids[c].end()) {
	fail = true;
	break;
      }
      maxs = *found + 1;
      if(i == 0)
	first = *found;
      if(i == sz-1)
	last=*found;
    }
    if(fail) cout << "Not matched"<<endl;
    else printf("Matched %d %d\n", first, last);
  }
}
