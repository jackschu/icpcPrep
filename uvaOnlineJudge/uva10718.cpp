#include <stdint.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
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

void printb(long x) {
  for (int i = 35; i >= 0; i--) {
    cout << ((x & (1ULL << i)) != 0);
  }
  cout << endl;
}

int main() {
  unsigned long n, l, u;
  while (cin >> n >> l >> u) {
    DEBUG printb(n);
    DEBUG printb(l);
    DEBUG printb(u);
    unsigned long cur = 0;
    for(int i = 31; i>= 0; i--){
      //if i dont set this bit, and i set every other bit, still too low, set
      if ((cur + (1ULL << (i))-1) < l ){
	cur |= (1ULL << i);
	continue;
      }
      // if i would like to set this bit, and I can, set
      if((n & (1ULL << i)) == 0){
	unsigned long maybe = cur | (1ULL << i);
	if (maybe <= u){
	  cur = maybe;
	}
      }
    }
    DEBUG printb(cur);
    // could still be too low, if too low set minimally until high enough
    vector<unsigned long> res;
    res.reserve(33);
    unsigned long sum =0;
    // calculate how much we can add by filling with ones from idx i to 0
    for(int i= 0; i <32; i++){
      if((cur & (1ULL << i)) == 0){
	sum+= (1ULL << i);
      }
      res.push_back(sum);
    }

    
    for(int i = 31; i >= 0 && cur  < l; i--){
      unsigned long need = l -cur;
      if((cur & (1ULL << i)) == 0){
	// if remaining set ability is too low, then set now
	if(i == 0 || need > res[i-1]){
	  cur |= (1ULL << i);
	}
      }
    }
    DEBUG printb(cur);
    
    cout << cur << endl;
  }
}
