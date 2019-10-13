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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


void run_case(){
  int deg;
  cin >> deg;
  vi cs;
  cs.reserve(deg+1);
  copy_n(istream_iterator<int>(cin), deg+1, back_inserter(cs));
  double k, d;
  cin >> d >> k;
  long targ= ceil( k/d);
  DEBUG cout << targ << endl;
  long n = ceil((sqrt(double(targ)*8+1)-1)/2.0);
  DEBUG cout << n << endl;
  long out = cs[0];
  long curn = 1;
  for(int i =1 ;i < deg+1; i++){
    curn*= n;
    out+= cs[i]*curn;
  }
  cout << out << endl;
}

int main(){
  int c;
  cin >> c;
  for(int i = 0 ; i < c; i++){
    run_case();
  }
}
