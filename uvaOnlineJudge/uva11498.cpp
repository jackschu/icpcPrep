#include <iostream>
using namespace std;

int main() {
  int TC = -1;
  while (TC != 0) {
    cin >> TC;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < TC; i++) {
      int cx, cy;
      cin >> cx >> cy;
      if (cx == x || cy == y) {
        cout << "divisa" << endl;
        continue;
      }
      if (cy < y)
        cout << "S";
      else
        cout << "N";
      if (cx < x)
        cout << "O" << endl;
      else
        cout << "E" << endl;
    }
  }
}
