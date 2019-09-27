#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;
    int y = 0;
    int z = 0;
    for (int i = 0; i < n - 1; i++) {
      string s;
      cin >> s;
      if (z == 0) {
        if (s == "+y") {
          y++;
          if (y == 4)
            y = 0;
        } else if (s == "-y") {
          y--;
          if (y == -1)
            y = 3;
        }
      } else if (z== 2){
	if (s == "-y") {
          y++;
          if (y == 4)
            y = 0;
        } else if (s == "+y") {
          y--;
          if (y == -1)
            y = 3;
        }
      }
      if (y == 0 ) {
        if (s == "+z") {
          z++;
          if (z == 4)
            z = 0;
        } else if (s == "-z") {
          z--;
          if (z == -1)
            z = 3;
        }
      } else if (y==2){
	if (s == "-z") {
          z++;
          if (z == 4)
            z = 0;
        } else if (s == "+z") {
          z--;
          if (z == -1)
            z = 3;
        }
      }
    }
    //    cout << z << y << endl;
    if (z == 1)
      cout << "+z" << endl;
    else if (z == 3)
      cout << "-z" << endl;
    else if (y == 3)
      cout << "-y" << endl;
    else if (y == 1)
      cout << "+y" << endl;
    else if (z == 2 && y ==2)
      cout << "+x" << endl;
    else if (z == 2 || y == 2)
      cout << "-x" << endl;
    else
      cout << "+x" << endl;
  }
}
