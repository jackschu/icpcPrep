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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int k;
  while (cin >> k) {
    int ct = 0;
    vii outs;
    for (int x = k+1; x <= 2*k; x++) {
      if((k*x)%(x-k)==0){
	int y = (k*x)/(x-k);
	outs.push_back(ii(y, x));
      }
    }
    sort(outs.begin(), outs.end(), greater<ii>());
    cout << outs.size() << endl;
    for(auto elem: outs){
      printf("1/%d = 1/%d + 1/%d\n", k, elem.first, elem.second);
    }
  }
}
