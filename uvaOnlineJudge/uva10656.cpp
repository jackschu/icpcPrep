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
  int n;
  cin>>n;
  while(n){
    bool first = true;
    for(int i = 0; i< n; i++){

      int x;
      cin >> x;
      if(x) {
	if(!first) cout << " ";
	first= false;
	cout << x ;
      }
    }
    if(first) cout << 0;
    cout <<endl;
    cin>>n;
  }
   
}
