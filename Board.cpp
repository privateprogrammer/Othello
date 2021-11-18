#include "Board.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

Board::Board() {}
Board* Board::instance_ = nullptr;
Board* Board::GetInstance() {
  if(instance_ == nullptr) {
    instance_ = new Board();
  }
  return instance_;
}

vector< vector<int> > Board::GetBoard(){
  return Board::board_;
}

void Board::MakeBoard(int size){
  vector< vector<int> > tmp_vector;
  for (int i = 0; i < size; i++){
    tmp_vector.push_back(vector<int>(size, 0));
  }
  board_ = tmp_vector;
}

void Board::SetBoard(int flag, int x, int y){
  board_[x][y] = flag+1;
}

void Board::ReturnBoard(){
  vector< vector<int> > tmp_vector = Board::GetBoard();
  for (int i = 0; i < tmp_vector.size() ; i++){
    for(int j = 0; j < tmp_vector[i].size(); j++) {
      if (tmp_vector[i][j] == 3) {
        tmp_vector[i][j] = 0;
      }
    }
  }
}

void Board::ShowBoard(){
  vector< vector<int> > tmp_vector = Board::GetBoard();
  for (int i = 0; i < tmp_vector.size() ; i++){
    for(int j = 0; j < tmp_vector[i].size(); j++) {
      cout << tmp_vector[i][j] << " ";
    }
    cout << "\n";
  }
}