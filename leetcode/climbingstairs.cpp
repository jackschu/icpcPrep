#include <iostream>

#define DEBUG if (false)

using namespace std;

class Solution {
public:
  int climbingStairs(int n) {
    int two_less = 0;
    int one_less = 1;
    int current = 1;
    while (--n > 0) {
      two_less = one_less;
      one_less = current;
      current = one_less + two_less;
    }
    return current;
  }
};

int main() {
  uint32_t n;
  cin >> n;
  Solution a;
  int output = a.climbingStairs(n);
  cout << output << endl;
}
