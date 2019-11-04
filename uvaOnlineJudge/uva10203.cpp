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
  int tc;
  cin >> tc;
  for (int ic = 0; ic < tc; ic++) {
    if (ic != 0)
      cout << endl;
    int hx, hy;
    cin >> hx >> hy;
    string l;
    double sum = 0;
    cin.ignore();
    while (getline(cin, l) && l.size() > 2) {
      stringstream ss(l);
      double x1, y1, x2, y2;
      ss >> x1 >> y1 >> x2 >> y2;
      sum += hypot(x1 - x2, y1 - y2) / 10000.0;
    }
    int hours = floor(sum);
    int minutes = round((sum - floor(sum)) * 60);
    while (minutes >= 60) {
      minutes -= 60;
      hours++;
    }
    if (minutes < 10)
      printf("%d:0%d\n", hours, minutes);
    else
      printf("%d:%d\n", hours, minutes);
  }
}
