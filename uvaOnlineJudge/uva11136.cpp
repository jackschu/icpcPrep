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

int main(){
  int n;
  cin >> n;
  while(n != 0){
    multiset<int> s;
    long sum = 0;
    for(int i = 0 ; i < n; i++){
      int k;
      cin >> k;
      for(int j = 0 ; j< k ;j++){
	int x;
	cin >> x;
	s.emplace(x);
      }
      DEBUG cout << s.size()<<endl;
      sum += *(--s.end()) - *s.begin();
      s.erase(--s.end());
      s.erase(s.begin());
      DEBUG cout << s.size()<< endl;
    }
    cout << sum << endl;
    cin >>n;
  }
}
