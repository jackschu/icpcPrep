#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  int TC;
  cin >> TC;
  for(int i = 0; i < TC; i++){
    vector<int> cur;
    cur.reserve(3);
    copy_n(istream_iterator<int>(cin), 3, back_inserter(cur));
    sort(cur.begin(), cur.end());
    printf("Case %d: %d\n", i+1, cur[1]);
  }
}
