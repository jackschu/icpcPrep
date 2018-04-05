#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_set>
using namespace std;
int main(){
  int x; // number of explicit / remaining gnomes
  int y; // number of total gnomes
  while(cin >> y >> x){

    int temp;
    unordered_set<int> postOrd;
    list<int> ordered;

    for(int i = 0; i < x; i++)
      {
	cin >> temp;
	postOrd.insert(temp); // used for linear contains
	ordered.push_back(temp); // used to keep ordering of explicit gnomes

      }
    int count = 1;
    while(x < y){ // only listing as many non explicit gnomes as allowed

      while(!ordered.empty() && count >= ordered.front()){ // list explicit gnomes in correct spot

	  cout << ordered.front() << endl;
	  ordered.pop_front();
	}

      if(postOrd.find(count) == postOrd.end()){ // list implicit gnomes as required
	cout << count <<endl;
	x++;
      }
      count++;
    }
    while(!ordered.empty()){ // list remaining explicit gnomes
      cout << ordered.front() << endl;
      ordered.pop_front();
    }
  }
  

}
