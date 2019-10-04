#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#define DEBUG if (false)
using namespace std;

bool mx(const pair<vector<int>, int> &i, const pair<vector<int>, int> &j){
  return i.second < j.second;
}


void run_case(int tc){
  map<vector<int>, int> mp;
  for(int i = 0 ; i < tc; i++){
    vector<int> sched;
    sched.reserve(5);
    copy_n(istream_iterator<int>(cin), 5, back_inserter(sched));
    sort(sched.begin(), sched.end());
    mp[sched]++;
  }
  int pop =  max_element(mp.begin(), mp.end(), mx)->second;
  int sum = 0;
  for(auto &elem:mp){
    if (elem.second == pop) sum+=elem.second;
  }
  cout << sum << endl;
}

int main() {
  int tc;
  cin >> tc;
  while(tc != 0){
    run_case(tc);
    cin >> tc;
  }
}
