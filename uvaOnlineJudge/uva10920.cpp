#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

void walk(long ring, long p, long sz) {
  DEBUG cout << ring << endl;
  long ringct = (ring + 1) / 2;
  long c = sz / 2 + 1 + ringct;
  long r = c;
  long cur = (ringct * 2 + 1) * (ringct * 2 + 1);
  DEBUG cout << cur - p << endl;
  if (cur == p) {
    printf("Line = %ld, column = %ld.\n", r, c);
    return;
  }
  for (long i = 0; i < ringct * 2; i++) {
    cur--;
    r--;
    if (cur == p) {
      printf("Line = %ld, column = %ld.\n", r, c);
      return;
    }
  }
  for (long i = 0; i < ringct * 2; i++) {
    cur--;
    c--;
    if (cur == p) {
      printf("Line = %ld, column = %ld.\n", r, c);
      return;
    }
  }
  for (long i = 0; i < ringct * 2; i++) {
    cur--;
    r++;
    if (cur == p) {
      printf("Line = %ld, column = %ld.\n", r, c);
      return;
    }
  }
  for (long i = 0; i < ringct * 2; i++) {
    cur--;
    c++;
    if (cur == p) {
      printf("Line = %ld, column = %ld.\n", r, c);
      return;
    }
  }
}

int main() {
  long sz, p;
  cin >> sz >> p;
  while (sz != 0 && p != 0) {
    long i = sqrt(p) + 2;
    DEBUG cout << p << endl;
    DEBUG cout << i << endl;
    while (i * i >= p) {

      i--;
      DEBUG cout << i * i << endl;
      ;
    }
    DEBUG cout << i << endl;
    DEBUG cout << "walking" << endl;
    walk(i, p, sz);

    cin >> sz >> p;
  }
}
