#include <iostream>
using namespace std;

int main(){
  int TC;
  cin >> TC;
  for(int i = 0; i <TC ; i++){
    long a,b;
    cin >> a >> b;
    if (a==b) cout << '=' << endl;
    else if (a < b) cout  << '<' << endl;
    else  cout  << '>' << endl;
  }
}
