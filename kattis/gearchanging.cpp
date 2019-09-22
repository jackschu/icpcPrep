#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> tops;
  vector<int> bots;
  tops.reserve(n);

  copy_n(istream_iterator<int>(cin), n, back_inserter(tops));
  bots.reserve(m);
  copy_n(istream_iterator<int>(cin), m, back_inserter(bots));
  vector<double> fracs;
  fracs.reserve(n*m);
  for(int i = 0; i<n; i++){
    for(int j =0; j<m; j++){
      fracs.push_back(double(tops[i])/double(bots[j]));
    }
  }
  sort(fracs.begin(), fracs.end());
  double thresh = double(p)/100.0 + 1;
  for(int i = n*m-1; i > 0; i--){
    if(fracs[i]/fracs[i-1] > thresh){
      cout << "Time to change gears!"<< endl;
      return 0;
    }
  }
  cout << "Ride on!" << endl;
  
}
