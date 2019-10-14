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


int main(){
  long mx = 2000;
  for(long a = 1; a < mx; a+=1){
    //cout << a << endl;
    for(long b = a; b < mx-a; b+=1){
      for(long c = b; c < mx-a-b; c+=1){
	long top =1000000*(a+b+c);
	long bot = a*b*c - 1000000;
	if(bot == 0) continue;
	if (top %bot == 0){
	  long d = top/bot;
	  if(d >= c && a+b+c+d <= 2000){
	    printf("%.2f %.2f %.2f %.2f\n", float(a)/100., float(b)/100., float(c)/100., float(d)/100.);
	  }
	}
      }
    }
  }
  
}
