#define DEBUG if(false)
#include <iostream>

using namespace std;

int how_many_carries(int x, int y){
  //we ensure  x > y
  if(x < y){
    int temp = x;
    x = y;
    y = temp;
  }
  int count = 0;
  bool carry = false;
  int lt_ten; //the ones place
  while(x != 0){
    DEBUG printf("1: carry: %d lt_ten: %d x: %d y: %d\n", carry, lt_ten, x, y);
    lt_ten = carry;
    lt_ten += x % 10;
    lt_ten += y % 10;
    x /= 10;
    y /= 10;

    carry = lt_ten >= 10;
    count += carry;
    DEBUG printf("carry: %d lt_ten: %d x: %d y: %d\n", carry, lt_ten, x, y);
  }
  return count;
}

void format_output(int count){
  switch(count){
    case 0:
      cout << "No carry operation." << endl;
      break;
    case 1:
      cout << "1 carry operation." << endl;
      break;
    default:
      printf("%d carry operations.\n", count);
  }
}

int main(){
  int x = 1;
  int y = 1; // numbers to evaluate
  int count;
  cin >> x >> y;
  while(x != 0 || y != 0){ //main loop
    count = how_many_carries(x,y);
    format_output(count);
    cin >> x >> y;
  }


  return 0;
}
