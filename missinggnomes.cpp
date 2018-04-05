#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_set>
using namespace std;
int main(){
  int x,y;
  while(cin >> y >> x){
    //    cout << endl << endl;
    int temp;
    unordered_set<int> postOrd;
    list<int> ordered;
    int max = 0;
    for(int i = 0; i < x; i++)
      {
	cin >> temp;
	postOrd.insert(temp);
	ordered.push_back(temp);
	//if(temp > max) max = temp;
      }
    int count = 1;
    while(x < y){
      //      while( count < max){
      while(!ordered.empty() && count >= ordered.front()){
	//	  cout << "here" << endl;
	  cout << ordered.front() << endl;
	  ordered.pop_front();
	}

      if(postOrd.find(count) == postOrd.end()){
	cout << count <<endl;
	x++;
      }
      count++;
    }
    while(!ordered.empty()){
      cout << ordered.front() << endl;
      ordered.pop_front();
    }
  }
  

}
