#include <map>
#include <algorithm>
#include <sstream>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
  bool first = true;
  int numC;
  cin >> numC;
  for(; numC > 0; numC--){

    if(cin.eof()) break;
    //    cout << "res" << endl;
    map<int,string> dudes;
    int numD;
    cin >> numD;
    cin.ignore();

   
    for(int i = 0; i < numD; i++){
      getline(cin,dudes[i]);
    }
    vector< list<int> > arr;
    vector<int> temp;
    /*    for(int l1 = 0; l1 <numD; l1 ++){
      temp.clear();
      for(int l2 = 0; l2 <numD; l2 ++)
	temp.push_back(0);
      arr.push_back(temp);
      }*/

    string tempstr = "t";
    while(tempstr != "" &&getline(cin,tempstr)){
      stringstream ss;
      int x;
      list<int> t1;
      t1.clear();


      ss << tempstr;
      for(int j = 0; j < numD; j++){
	ss >> x;
	/*	if(x > numD){
	  cin.setstate(ios::failbit);
	  break;
	  }*/
	t1.push_back(x-1);
      }
      if(t1.size() > 0) arr.push_back(t1);
    }

    if(!cin.eof())arr.pop_back();
    /*    for(auto x: arr){
      for(auto y : x)
	cout << y <<" ";
	cout << endl;*/
    int goal = arr.size();
    goal = goal >> 1;
    map<int,int> tally;
    for(int i = 0; i < numD; i++)
      tally[i] = 0;
    for(auto const &elem : arr){
      tally[elem.front()]++;
    }
    int minT = -1;
    vector<int> minE;
    bool win = false;
    int winInd;
    bool tie = false;
    while(!win && !tie){
      minT = 20000;
      int tieVal = tally.begin()->second;
      tie = true;
      for(auto elem : tally){
	if(minT > elem.second){
	  minT = elem.second;
	  minE.clear();
	  minE.push_back(elem.first);
	} else if (minT == elem.second)
	  minE.push_back(elem.first);
	tie &= tieVal == elem.second;
	if(elem.second > goal){
	  win = true;
	  winInd = elem.first;
	  break;
	}
      }
      if(!win && !tie){
	for(int elem2 : minE)
	  tally.erase(elem2);
	for(auto &elem2: tally)
	  elem2.second = 0;
	for(auto &elem2 : arr){

	  //replace(elem2.begin(),elem2.end(),minE,-1);
	  for(int elem3 : minE)
	    elem2.remove(elem3);

	  tally[elem2.front()]++;


	}
      }
    
    }
    if(first){
      first = false;
    }else{
      cout << endl << endl;
    }
    if(win)
      cout << dudes[winInd];
    else if (tie){
      cout << dudes[tally.begin()->first];
      tally.erase(tally.begin());
      for(auto elem : tally)
	cout << endl << dudes[elem.first];
    }
    
  
  }//end of test case
  cout << endl;

}
