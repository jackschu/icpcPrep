#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  int n, b, h, w;
  while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
    int mn = b + 1;
    for (int i = 0; i < h; i++) {
      int p;
      cin >> p;
      vector<int> avail;
      avail.reserve(w);
      copy_n(istream_iterator<int>(cin), w, back_inserter(avail));
      if (p * n > mn)
        continue;
      int a = *max_element(avail.begin(), avail.end());
      if (a >= n) {
        mn = p * n;
      }
    }
    if (mn == b + 1)
      cout << "stay home" << endl;
    else
      cout << mn << endl;
  }
}
