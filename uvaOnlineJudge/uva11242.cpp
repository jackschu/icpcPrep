#include <algorithm>
#include <bitset>
#include <cctype>
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

int main() {
  int f;
  cin >> f;
  while(f){
    int r;
    vi fs, rs;
    cin >> r;
    fs.reserve(f);
    rs.reserve(r);
    copy_n(istream_iterator<int>(cin), f, back_inserter(fs));
    copy_n(istream_iterator<int>(cin), r, back_inserter(rs));
    vector<double> opts;
    opts.reserve(f*r);
    for(int i = 0; i < f; i++){
      for(int j = 0; j < r; j++){
	opts.push_back(double(rs[j])/double(fs[i]));
      }
    }
    sort(opts.begin(), opts.end());
    unique(opts.begin(), opts.end());
    int n= opts.size();
    double mx = 0;
    for(int i= 1; i < n; i++){
      mx = max(mx,double(opts[i])/double(opts[i-1]));
    }
    printf("%.2lf\n", mx);
    cin >>f;
  }
}
