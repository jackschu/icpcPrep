#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

#define DEBUG if(false)

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    string s =bitset<32>(n).to_string();
    DEBUG cout << s << endl;
    reverse(s.begin(), s.end());
    DEBUG cout << s << endl;
    uint32_t out = stoul(s, nullptr, 2);
    return out;
  }
};

int main() {
  uint32_t n;
  cin >> n;
  Solution a;
  uint32_t output = a.reverseBits(n);
  cout << output << endl;
}
