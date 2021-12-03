#include "Board.h"
#include <vector>
#include <iostream>

using std::vector;
using std::endl;

Board::Board() {}
Board* Board::instance_ = nullptr;
Board* Board::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new Board();
  }
  return instance_;
}

vector< vector<int> > Board::GetBoard() {
  return Board::board_;
}

void Board::MakeBoard(int size) {
  // 보드를 만들고 중앙에 돌 놓아 주기
  vector< vector<int> > tmp_vector;
  for (int i = 0; i < size; i++) {
    tmp_vector.push_back(vector<int>(size, 0));
  }

  int base = size / 2;
  // 상태 1의 돌
  tmp_vector[base][base] = 1;
  tmp_vector[base - 1][base - 1] = 1;

  // 상태 2의 돌
  tmp_vector[base - 1][base] = 2;
  tmp_vector[base][base - 1] = 2;
  board_ = tmp_vector;
}

void Board::SetBoard(int flag, int x, int y) {
  board_[x][y] = flag + 1;
}

void Board::ReturnBoard() {
  for (int i = 0; i < Board::GetBoard().size() ; i++)
    for (int j = 0; j < Board::GetBoard()[i].size(); j++)
      // 업데이트 할 때는 SetBoard를 쓰지 않으면 접근이 불가능함.
      if (Board::GetBoard()[i][j] == 3)
        this -> SetBoard(-1, i, j);
}

void Board::ShowBoard() {
  int length = Board::GetBoard().size() + 1;

  // 첫 행, 열을 숫자로 표시
  this -> fout << endl;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i == 0) {
        if (j != 0)
          this -> fout << j - 1 << " ";
        else
          this -> fout << " " << " ";
        continue;
      }

      if (j == 0) {
        if (i != 0)
          this -> fout << i - 1 << " ";

        continue;
      }

      if (Board::GetBoard()[i - 1][j - 1] == 0) {
        this -> fout << "." << " ";
      } else if (Board::GetBoard()[i - 1][j - 1] == 1) {
        this -> fout << "○" << " ";
      } else if (Board::GetBoard()[i - 1][j - 1] == 2) {
        this -> fout << "●" << " ";
      } else {
        this -> fout << "*" << " ";
      }
    }
    this -> fout << endl;
  }

  this -> fout << endl;
}

bool Board::IsBoardFull() {
  for (int i = 0; i < Board::GetBoard().size() ; i++)
    for (int j = 0; j < Board::GetBoard()[i].size(); j++)
      // 하나라도 0이라면 돌이 꽉 찼음.
      if (Board::GetBoard()[i][j] == 0)
        return false;

  return true;
}

bool Board::IsBoardOneColor() {
  int player1 = 0;
  int player2 = 0;
  for (int i = 0; i < Board::GetBoard().size() ; i++) {
    for (int j = 0; j < Board::GetBoard()[i].size(); j++) {
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
  if (player1 == 0 || player2 == 0) {
    return true;
  }
  return false;
}

int Board::CheckMyScore(int flag) {
  int length = Board::GetBoard().size();
  int ret = 0;

  for (int i = 0; i < length; i++)
    for (int j = 0; j < length; j++)
      if (board_[i][j] == flag + 1)
        ret++;

  return ret;
}
