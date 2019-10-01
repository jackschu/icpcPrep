#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
void print_o(int x);
int iter(int x) {
  int out = 0;
  out |= (((x >> 7) & 1) ^ ((x >> 5) & 1)) << 8;
  out |= (((x >> 7) & 1) ^ ((x >> 3) & 1)) << 6;
  out |= (((x >> 1) & 1) ^ ((x >> 3) & 1)) << 0;
  out |= (((x >> 1) & 1) ^ ((x >> 5) & 1)) << 2;
  out |= (((x >> 8) & 1) ^ ((x >> 4) & 1) ^ ((x >> 6) & 1)) << 7;
  out |= (((x >> 6) & 1) ^ ((x >> 0) & 1) ^ ((x >> 4) & 1)) << 3;
  out |= (((x >> 2) & 1) ^ ((x >> 0) & 1) ^ ((x >> 4) & 1)) << 1;
  out |= (((x >> 2) & 1) ^ ((x >> 4) & 1) ^ ((x >> 8) & 1)) << 5;
  out |= (((x >> 7) & 1) ^ ((x >> 3) & 1) ^ ((x >> 5) & 1) ^ ((x >> 1) & 1))
         << 4;
  return out;
}
void print_o(int x) { cout << std::bitset<9>(x) << endl; }

void run_case(int x) {
  if (x == iter(x)) {
    cout << -1 << endl;
    return;
  }
  unordered_set<int> seen;
  int ct = 0;
  while (true) {
    x = iter(x);
    ct++;
    auto found = seen.find(x);
    if (found != seen.end()) {
      cout << ct - 2 << endl;
      return;
    }
    seen.insert(x);
  }
}

int main() {
  int TC;
  cin >> TC;
  for (int case_num = 0; case_num < TC; case_num++) {
    int input = 0;
    for (int i = 2; i >= 0; i--) {
      int bit;
      cin >> bit;
      input = (input << 1) | (bit / 100);
      input = (input << 1) | ((bit % 100) / 10);
      input = (input << 1) | ((bit % 10) / 1);
    }
    run_case(input);
  }
}
