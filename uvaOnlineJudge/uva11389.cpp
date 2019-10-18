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

int main(){
  int n, d ,r;
  cin >> n >> d >> r;
  while(n|d|r){
    vi tops, bots;
    tops.reserve(n);
    bots.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(tops));
    copy_n(istream_iterator<int>(cin), n, back_inserter(bots));
    sort(tops.begin(), tops.end());
    sort(bots.begin(), bots.end(), greater<int>());
    int out =0;
    for(int i = 0; i < n; i++){
      out+= max(0, tops[i]+bots[i]-d);
    }
    cout << out * r<< endl;
    cin >> n >> d >> r;
  }
}
  
