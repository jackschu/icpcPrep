#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define DEBUG if(false) 
using namespace std;

vector<int> getPrimes(int n){
  bool * all = new bool[n+1](); //
  all[1] = true; //1 is not prime
  all[2] = false; //2 is prime
  for(int i = 3; i < n+1; i+=2){
    for(int j = i*2; j < n+1; j+=i){
      all[j] = true;
    }
  }
  vector<int> out;
  out.push_back(2);
  for(int i = 3; i < n+1; i+=2){
    if(!all[i]) out.push_back(i);
  }
  
  delete [] all;
  return out;
}

int getDivisors(vector<pair<int,int>> &p, int x){
  int n = p.size();
  vector<int> cur (n,0);
  int ret = 0;
  int out = 1;
  while(out != x){
    for(int i = 0; ;i++){
      if(cur[i] == p[i].second){
	cur[i] = 0;
	out/=pow(p[i].first, p[i].second);
	continue;
      }
      cur[i]++;
      out*= p[i].first;
      break;
    }
    DEBUG cout << out << endl;
    ret += out;
  }
  ret++;
  ret-=x;
  return ret;
}

int sumDivisors(vector<int> &p, int x){
  vector<pair<int,int>> divs;
  int oldx = x;
  for(int i = 0; p[i] <= sqrt(x); i++){
    int ct = 0;
    while(x % p[i] == 0){
      x /= p[i];
      ct++;
    }
    if(ct != 0){
      divs.push_back(pair<int,int>(p[i], ct));
    }
  }
  if(x != 1) divs.push_back(pair<int,int>(x, 1));
  DEBUG for(auto elem: divs) printf("%d, %d\n", elem.first, elem.second);
  return getDivisors(divs, oldx);
}

int main(){
  int mx = 0;
  vector<int> xs;
  string l;
  while(getline(cin,l)){
    int x = stoi(l);
    mx = max(mx, x);
    xs.push_back(x);
  }
  auto p = getPrimes(int(sqrt(mx))+1);
 
  for(auto elem: xs){
    int sum = sumDivisors(p, elem);
    if(abs(sum-elem) == 0){
      printf("%d perfect\n", elem);
    } else if(abs(sum-elem) < 3){
      printf("%d almost perfect\n", elem);
    } else {
      printf("%d not perfect\n", elem);
    }
  }
}
