#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector>
#include "AllPlayer.h"
#include "Board.h"

using std::string;
using std::pair;

class Util {
 public:
  Util();
  void Init();
  void SetName();
  void MakeBoard();
  bool InputXY();
  bool CheckCondition();

  void UpdateScore();
  void TogglePlayer();
  void PrintBoard();
  bool ShowValidXY(int x, int y);
  void ToggleStone(int x, int y);

 private:
  int x_, y_, flag_, is_finished_;
  AllPlayer* players_;
  vector<pair<int, int>> place_valid_;
  Board* board_;
};

#endif  // _UTIL_H_
