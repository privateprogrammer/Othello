#ifndef _UTIL_H_
#define _UTIL_H_

using std::string;

class Util {
 public:
  void Init();
  bool SetName();
  bool MakeBoard();
  void TogglePlayer();
  void PrintBoard();
  bool ShowValidXY(Player player);
  bool InputXY();
  void ToggleStone(int x, int y);
};

#endif  // _UTIL_H_
