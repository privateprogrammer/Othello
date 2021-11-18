#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

using std::vector;

class Board {
 public:
  Board* GetInstance();
  vector<vector<int>> GetBoard();

 private:
  Board();
  Board* instance_;
  vector<vector<int>> board_;
};

#endif  // _BOARD_H_
