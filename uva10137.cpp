#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {

  vector<int> higher;
  int x = 1;
  cin >> x;
  while(x!=0){
    higher.clear();
    int sum = 0;
    double temp;
    for(int i = 0; i < x; i++){
      cin >> temp;
      
      higher.push_back(round(temp * 100));
      sum += round(temp *100);
    }
    double goal;

    goal = floor(double(sum) /double(x));
    double goal1 =ceil(double(sum) /double(x));


    //    cout << goal << endl;
    double moveD = 0;
    double moveU = 0;
    for( auto cur1 : higher){
      double cur = double(cur1);
      if(cur > goal){
	moveD += round(cur - (goal1));
      }else
      	moveU += round(-cur + (goal));
    }
    //    cout << move << endl;
    //    cout << moveD <<endl <<moveU<< endl;
    double out1 = (moveD > moveU) ? moveD : moveU;
    out1 /= 100;
    printf("$%.2f\n",out1);




    
    cin >> x;
  }
 
}
