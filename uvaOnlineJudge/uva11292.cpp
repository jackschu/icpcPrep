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

int main() {
  int n, m;
  cin >> n>>m;
  while (n|m) {
    vi heads, knights;
    heads.reserve(n);
    knights.reserve(m);
    copy_n(istream_iterator<int>(cin), n, back_inserter(heads));
    copy_n(istream_iterator<int>(cin), m, back_inserter(knights));
    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());
    int cur_h = 0, cur_k =0;
    long sum =0;
    bool win = true;
    while(cur_h < n){
      int head = heads[cur_h];
      while(cur_k < m && knights[cur_k] < head){
	cur_k++;
      }
      if(cur_k == m) {
	win = false;
	break;
      }
      sum+= knights[cur_k];
      cur_k++;
      cur_h++;
    }
    if(win){
      cout << sum << endl;
    }else
      cout << "Loowater is doomed!"<<endl;
    cin >> n>>m;
  }
}
