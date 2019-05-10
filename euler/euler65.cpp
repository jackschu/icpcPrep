#include <iostream>
#include <vector>

using namespace std;

struct myFrac{
  long num;
  long den;
  myFrac(int x, int y){
    num = x;
    den = y;
  }
  void oneOverAdd(int x){
    cout << "adding " << x << endl;
    int temp = num;
    num = den;
    den = temp;

    num += den*x;
    printf("num: %d, den: %d\n", num, den);
  }
};



void onekone(int n){

  
  myFrac theFrac(1,0);
  int pos = n % 3;
  int rounds = n/3;


  if( pos == 2 ) {
    theFrac.oneOverAdd((rounds+1)*2);
    --pos;
  }
  if( pos == 1 ) theFrac.oneOverAdd(1);
  for(; rounds > 0; rounds--){
    theFrac.oneOverAdd(1);
    theFrac.oneOverAdd(2*rounds);
    theFrac.oneOverAdd(1);
  }
    theFrac.oneOverAdd(2);
  
}

int main(){
  int x;
  cin >> x;


  onekone(x);


}
