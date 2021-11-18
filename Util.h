#ifndef _UTIL_H_
#define _UTIL_H_

using std::string;

class Util {
 public:
  Util* GetInstance();
  void Init();
  bool SetName(string name1, string name2);
  bool MakeBoard(int size);
  void TogglePlayer();
  void PrintBoard();
  bool ShowValidXY(Player player);
  bool InputXY();
  void ToggleStone(int x, int y);

 private:
  Util();
  Util* intstance_;
  int x_, y_, is_finished_;
  Player* now_player_;
};

#endif  // _UTIL_H_
