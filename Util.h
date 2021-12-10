#ifndef UTIL_H_
#define UTIL_H_

#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include "AllPlayer.h"
#include "Board.h"

using std::string;
using std::pair;
using std::ofstream;

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
  ofstream* log();

  int x();
  int y();
  int flag();
  int isfinished();
  AllPlayer* allplayers();
  vector< pair<int, int> > placevalid();
  Board* board();

 private:
  int x_;
  int y_;
  int flag_;
  int is_finished_;
  AllPlayer* players_;
  vector< pair<int, int> > place_valid_;
  Board* board_;
  static ofstream fout;
};

#endif  // UTIL_H_
