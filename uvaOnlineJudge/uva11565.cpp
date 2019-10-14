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
  int tc;
  cin >> tc;
  for(int ic = 0; ic < tc; ic++){
    int a, b ,c;
    cin >> a >> b >> c;
    int mx = sqrt(c) + 1;
    bool stop = false;
    for(int x = -mx; x <= mx && !stop; x++){
      for(int y = x+1; y <= mx && !stop; y++){
	int z = a -x -y;
	if(z == y || z == x) continue;
	if (x*y*z == b && x*x + z*z+ y*y ==c){
	  printf("%d %d %d\n", x,y,z);
	  stop = true;
	}
      }
    }
    if(!stop)
      printf("No solution.\n");
  }
}
