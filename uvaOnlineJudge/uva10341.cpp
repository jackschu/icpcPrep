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
  double p, q, r, s, t, u;
  while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6) {
    //printf("%lf %lf %lf %lf %lf %lf\n", p, q, r, s, t, u);
    double high = 1, low = 0;
    double guess, out;
    int ct = 0;
    while (++ct < 90) {
      guess = (high +low) / 2.0;
      out = p * exp(-guess) + q * sin(guess) + r * cos(guess) + s * tan(guess) +
            t * guess * guess;
      //cout << guess << " : " << out << endl;
      if (out < -u) {
        high = guess;
      } else if (out > -u) {
        low = guess;
      } else {
        break;
      }
    }
    if( (high == 1 || low == 0) &&abs(out+u) > 1e-4) {
      cout << "No solution" << endl;
    } else {
      printf("%.4lf\n", guess);
    }
  }
}
