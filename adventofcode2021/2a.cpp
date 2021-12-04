#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;


int main() {
  string dir;
  int val;
  int vert = 0, horiz = 0; 
  while (cin >> dir >> val){
	if (dir == "forward") horiz += val;
	if (dir == "down") vert += val;
	if (dir == "up") vert -= val;
  }
  cout << horiz*vert << endl;
}
