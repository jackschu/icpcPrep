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

void run_case(){
  string s;
  map<string, long> mp;
  long ct = 0;
  while(getline(cin,s)){
    if (s.size() == 0)break;
    mp[s]++;
    ct++;
  }
  vector<pair<string, long>> out (mp.begin(), mp.end());
  for(auto &elem: out){
    printf("%s %.4f\n", elem.first.c_str(), double(elem.second*100)/double(ct));
  }
}

int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  if (tc == 0) return 0;
  string s;
  getline(cin, s);
  bool first =  true;

  for (int i = 0; i < tc; i++) {

    if(!first) cout << endl;
    first = false;
    run_case();
  }
}
