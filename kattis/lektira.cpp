#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  string s;
  vector<string> opts;
  cin >> s;
  int n = s.size();
  for(int i = 1; i < n-1; i++){
    for( int j = i+1; j < n; j++){
      string p1, p2, p3;
      p1 = s.substr(0,i);
      p2 = s.substr(i,j-i);
      p3 = s.substr(j,n-j);
      reverse(p1.begin(), p1.end());
      reverse(p2.begin(), p2.end());
      reverse(p3.begin(), p3.end());
      opts.push_back(p1 +  p2 + p3);
    }
  }
  
  cout << *min_element(opts.begin(), opts.end()) <<endl;
  
}
