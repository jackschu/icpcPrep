#define DEBUG if(false)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct turtle{
  enum direction {N, S, E, W};
  direction dir;
  int x, y;  
  turtle() : x(0), y(0), dir(E) {}
  void rot_r(){
    switch(dir){
    case N:
      dir = E;
      break;
    case E:
      dir = S;
      break;
    case S:
      dir = W;
      break;
    case W:
      dir = N;
      break;
    }
  }
  void rot_l(){
    switch(dir){
    case N:
      dir = W;
      break;
    case E:
      dir = N;
      break;
    case S:
      dir = E;
      break;
    case W:
      dir = S;
      break;
    }
  }


};

struct tile{
  enum tile_type {EMPTY, CASTLE, ICE, DIAMOND};
  tile_type t;
  tile() : t(EMPTY) {}
  tile(char type) {
    switch (type){
    case 'C':
      t = CASTLE;
      break;
    case 'I':
      t = ICE;
      break;
    case 'D':
      t = DIAMOND;
      break;
    default:
      t = EMPTY;      
    }
  }
    
};

bool forward_valid(turtle &turt){
  switch (turt.dir){
  case turtle::N:
    return turt.y != 7;
  case turtle::S:
    return turt.y != 0;
  case turtle::E:
    return turt.x != 7;
  case turtle::W:
    return turt.x != 0;

  }
}

bool handle_ice(turtle &turt, vector<vector<tile>> &board){
  if (!forward_valid(turt)){
    return false;
  }
  bool out;
  switch (turt.dir){    
  case turtle::N:
    out = board[turt.y+1][turt.x].t == tile::ICE;
    board[turt.y+1][turt.x].t = tile::EMPTY;
    break;
  case turtle::S:    
    out = board[turt.y-1][turt.x].t == tile::ICE;
    board[turt.y-1][turt.x].t = tile::EMPTY;    
    break;
  case turtle::E:
    out = board[turt.y][turt.x+1].t == tile::ICE;
    board[turt.y][turt.x+1].t = tile::EMPTY;    
    break;
  case turtle::W:
    out = board[turt.y][turt.x-1].t == tile::ICE;
    board[turt.y][turt.x-1].t = tile::EMPTY;    
    break;    
  }
  return out;  
}
bool handle_forward(turtle &turt, vector<vector<tile>> board){
  bool out = forward_valid(turt);
  DEBUG printf("turt N %d\n", int(turt.dir == turtle::N));
  DEBUG printf("forward valid %d\n", int(out));
  if (!out) return out;
  switch (turt.dir){
  case turtle::N:
    DEBUG printf("N");
    turt.y++;
    break;
  case turtle::S:
    DEBUG printf("S");    
    turt.y--;
    break;
  case turtle::E:
    DEBUG printf("E");        
    turt.x++;
    break;
  case turtle::W:
    DEBUG printf("W");        
    turt.x--;
    break;
  default:
    cout << "shold not reach"<<endl;
  }
  return board[turt.y][turt.x].t == tile::EMPTY ||
    board[turt.y][turt.x].t == tile::DIAMOND;
}

vector<vector<tile> > parse_board(){
  vector<vector<tile> > out;
  for(int i = 7; i >= 0; i--){
    string temp;
    getline(cin, temp);
    vector<tile> row;
    for(int j = 0; j < 8; j++)
      row.push_back(tile(temp[j]));
    out.push_back(row);
  }
  reverse(out.begin(), out.end());				    
  return out;
}

bool run_commands(vector<vector<tile>> board){
  turtle turt;
  string commands;
  getline(cin, commands);
  for(int i = 0; i < commands.size(); i++){
    DEBUG printf("pos x %d, y %d, command: %c\n",turt.x, turt.y, commands[i]);
    bool success = true;
    switch (commands[i]){      
    case 'F':
      success = handle_forward(turt, board);
      break;
    case 'X':
      success = handle_ice(turt, board);
      break;
    case 'L':
      turt.rot_l();
      break;
    case 'R':
      turt.rot_r();
      break;
    }
    if (!success)return false;
  }
  return board[turt.y][turt.x].t == tile::DIAMOND;

}
  
int main(){
  auto board = parse_board();
  bool result = run_commands(board);
  if (result)
    cout << "Diamond!"<<endl;
  else
    cout << "Bug!"<<endl;    
}
