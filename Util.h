#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector>
#include "Player.h"
#include "Board.h"

using std::string;

class Util {
 public:
  void Init();
  bool SetName();
  bool MakeBoard();
  void TogglePlayer();
  void PrintBoard();
  int ShowValidXY();
  bool InputXY();
  void ToggleStone(int x, int y);

 private:
  int x_, y_, flag, is_finished_;
  vector<Player> players_;
  Board* board_;
};

#endif  // _UTIL_H_
