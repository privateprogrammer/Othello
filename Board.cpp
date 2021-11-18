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
  for (int i = 0; i < Board::GetBoard().size() ; i++){
    for(int j = 0; j < Board::GetBoard()[i].size(); j++) {
      if (Board::GetBoard()[i][j] == 3) {
        Board::GetBoard()[i][j] = 0;
      }
    }
  }
}

void Board::ShowBoard(){
  for (int i = 0; i < Board::GetBoard().size() ; i++){
    for(int j = 0; j < Board::GetBoard()[i].size(); j++) {
      cout << Board::GetBoard()[i][j] << " ";
    }
    cout << "\n";
  }
}

bool Board::IsBoardFull(){
  for (int i = 0; i < Board::GetBoard().size() ; i++){
    for(int j = 0; j < Board::GetBoard()[i].size(); j++) {
      if (Board::GetBoard()[i][j] == 0) {
        //하나라도 0이라면 돌이 꽉 찼음.
        return false;
      }
    }
  }
  return true;
}

bool Board::IsBoardOneColor(){
  int player1 = 0;
  int player2 = 0;
  for (int i = 0; i < Board::GetBoard().size() ; i++){
    for(int j = 0; j < Board::GetBoard()[i].size(); j++) {
      if (Board::GetBoard()[i][j] == 0) {
        continue;
      }
      if (Board::GetBoard()[i][j] == 1) {
        player1++;
      }
      if (Board::GetBoard()[i][j] == 2) {
        player2++;
      }
    }
  }
  if (player1 != 0 && player2 != 0) {
    return false;
  }
  return true;
}

