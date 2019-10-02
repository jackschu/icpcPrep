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
  int n;
  while(cin >> n){
    int two_n = 1 << n;
    int * weight = new int[two_n];
    for(int i =0; i< two_n; i++){
      int x;
      cin>>x;
      weight[i] = x;
    }
    int * pot = new int[two_n];
    for(int i =0; i< two_n; i++){
      int sum = 0;
      for(int j=0; j <n; j++){
	sum += weight[i^(1 << j)];
      }
      pot[i] = sum;
    }
    delete [] weight;
    int mx = 0;
    for(int i =0; i< two_n; i++){
      int mx1 = 0;
      for(int j=0; j <n; j++){
	int guess =  pot[i^(1 << j)];
	mx1 = max(mx1, guess);
      }
      mx = max(mx1+pot[i], mx);
    }
    cout << mx << endl;
    delete []pot;
  }
}
