#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi nums;
int n, m;
bool run(const vi& dists, int pwr){
  for(auto elem : dists){
    if(elem > pwr) return false;
    if(elem == pwr) pwr--;
  }
  return true;
}

int main() {
  int tc;
  cin >> tc;
  for(int ic = 0; ic <tc; ic++){
    int n;
    cin >>n;
    vi dists;
    int past= 0;
    for(int i = 0; i<n;i++){
      int x;
      cin >>x;
      dists.push_back(x -past);
      past = x;
    }
    int k = *max_element(dists.begin(), dists.end())+1;
    if(run(dists, k-1)){
      printf("Case %d: %d\n", ic+1, k-1);
    }
    else
      printf("Case %d: %d\n", ic+1, k);

  }
}
