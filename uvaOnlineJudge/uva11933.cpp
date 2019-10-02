#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main(){
  long x;
  cin >> x;
  while(x){
    long a = 0;
    long b = 0;
    bool adda = true;
    while (x != 0){
      long next = x & (x-1);
      if(adda) a+=x-next;
      else b+= x-next;
      adda = !adda;
      x =next;
    }
    printf("%ld %ld\n", a,b);
    cin >>x;
  }
}
