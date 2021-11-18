#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

using std::vector;

class Board {
 public:
  static Board* GetInstance();
  vector< vector<int> > GetBoard();
  void ShowBoard();
  void SetBoard(int size);
  void ReturnBoard();

 private:
  Board();
  static Board* instance_;
  vector< vector<int> > board_;
};

#endif  // _BOARD_H_
