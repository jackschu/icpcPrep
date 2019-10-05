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

int main(){
  int n;
  int m;
  cin >> n >> m ;

  while(n|m){
    set<int> have;
    int ct =0;
    for(int i = 0 ; i < n ;i++){
      int x;
      cin>>x;
      have.insert(x);
    }
    for(int i = 0; i< m ;i++){
      int x;
      cin>>x;
      if(have.find(x) != have.end())
	ct++;
    }
    cout <<ct<<endl;
    cin >> n >> m ;
  }
}
