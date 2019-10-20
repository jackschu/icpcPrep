#include <algorithm>
#include <list>
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

int main() {
  int n, m;
  cin >> n>>m;
  int ic = 0;
  while (n|m) {
    ic++;
    vi boys, girls;
    boys.reserve(n);
    girls.reserve(m);
    copy_n(istream_iterator<int>(cin), n, back_inserter(boys));
    copy_n(istream_iterator<int>(cin), m, back_inserter(girls));
    sort(boys.begin(), boys.end(), greater<int>());
    sort(girls.begin(), girls.end());
    list<int> em;
    for(auto elem :girls)
      em.push_back(elem);
    int matched= 0;
    for(auto boy:boys){
      if(em.empty()) break;

      auto lb = lower_bound(em.begin(), em.end(), boy);
      int dist1 = 600, dist2 = 600;
      if(lb != em.end()){
	dist1 = abs(*lb - boy);
      }
      if(lb != em.begin()){
	dist2 = abs(*(prev(lb)) -boy);
      }

      if(dist1 < dist2){
	em.erase(lb);
      } else {
	em.erase(prev(lb));
      }
      matched++;
    }
    printf("Case %d: ", ic);
    if(matched == n){
      cout << 0<<endl;; 
    }else{
      printf("%d %d\n",n-matched, boys[n-1]);
    }
    cin >> n >> m;

  }
}
