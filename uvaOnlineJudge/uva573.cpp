#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  int h, u, d, f;
  cin >> h;
  while (h != 0) {
    cin >> u >> d >> f;
    double climb = u;
    double fatigue = double(f) / double(100);
    int day = 0;
    double height = 0;
    while (true) {
      day++;
      height += climb;
      if (height > h) {
        printf("success on day %d\n", day);
        break;
      }
      height -= d;
      climb -= u * fatigue;
      climb = max(0.0, climb);
      if (height < 0) {
        printf("failure on day %d\n", day);
        break;
      }
    }
    cin >> h;
  }
}
