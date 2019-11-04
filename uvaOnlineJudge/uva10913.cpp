#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
int n;
int board[75][75];
ll memo[6][75][75];
ll inf = 1e16;

int main() {
  int mk;
  cin >> n >> mk;
  int ic = 0;
  while (n | mk) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cin >> board[i][j];
        for (int ik = 0; ik <= mk; ik++)
          memo[ik][i][j] = -inf;
      }
    int negct = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += board[0][i];
      if (board[0][i] < 0)
        negct++;
      for (int j = negct; j <= mk; j++) {
        memo[j][0][i] = sum;
      }
    }
    for (int k = 0; k <= mk; k++) {
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
          int ck = k;
          if (board[i][j] < 0)
            ck--;
          if (ck < 0)
            continue;
          int old_k = ck;
          ll sum = board[i][j];
          ll out = memo[ck][i - 1][j];
          if (out != -inf)
            out += sum;
          for (int x = j - 1; x >= 0; x--) {
            if (board[i][x] < 0)
              ck--;
            if (ck < 0)
              break;
            sum += board[i][x];
            ll opt = memo[ck][i - 1][x];
            if (opt != -inf)
              opt += sum;
            out = max(opt, out);
          }
          ck = old_k;
          sum = board[i][j];
          for (int x = j + 1; x < n; x++) {
            if (board[i][x] < 0)
              ck--;
            if (ck < 0)
              break;
            sum += board[i][x];
            ll opt = memo[ck][i - 1][x];
            if (opt != -inf)
              opt += sum;
            out = max(opt, out);
          }
          memo[k][i][j] = out;
        }
      }
    }
    ll out = memo[mk][n - 1][n - 1];
    for (int k = 0; k < mk; k++) {
      out = max(memo[k][n - 1][n - 1], out);
    }
    printf("Case %d: ", ++ic);
    if (out == -inf)
      cout << "impossible" << endl;
    else
      cout << out << endl;
    cin >> n >> mk;
  }
}
