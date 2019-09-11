#include <iostream>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int out = 0;
    while(n != 0){
      out += 1u & n;
      n = n >> 1;
    }
    return out;
  }
};

int main() {
  uint32_t n;
  cin >> n; 
  Solution a;
  int output = a.hammingWeight(n);
  cout << output << endl;
}
