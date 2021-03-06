#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int main(){
  int upTo;
  cin >> upTo;
  unordered_map<int,int> soFar;
  for(int i = 2; i <= upTo; i++){
    for(int cleared = i + i; cleared <= upTo; cleared +=i){
      if(soFar.find(cleared) == soFar.end())
	soFar[cleared] = i +1;
      else
	soFar[cleared] += i;
    }
  }
  long sum = 0;
  for( auto elem : soFar){
    if(soFar[elem.second]  == elem.first && soFar[elem.first] == elem.second && elem.second != elem.first){
      sum += elem.first;
    }
  }
  cout << sum << endl;
  

}
