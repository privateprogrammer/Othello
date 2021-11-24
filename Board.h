#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

using std::vector;

class Board {
 public:
  static Board* GetInstance();
  vector< vector<int> > GetBoard();
  void ShowBoard();
  void MakeBoard(int size);
  void SetBoard(int flag, int x, int y);
  void ReturnBoard();
  void UpdateBoard();  // 플레이어가 돌을 두면 판을 바꿈
  bool IsBoardFull();
  bool IsBoardOneColor();
  int CheckMyScore(int flag);

 private:
  Board();
  static Board* instance_;
  vector< vector<int> > board_;
};

#endif  //  _BOARD_H_
