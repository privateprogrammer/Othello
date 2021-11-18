#ifndef _UTIL_H_
#define _UTIL_H_

class Util {
 public:
  Util* GetInstance();
  void MakeBoard();
  void Find(Player player);
  void Select(Player player);
  void Change(Player player, int x, int y);
  bool IsFinished();

 private:
  Util();
  Util* intstance_;
};

#endif  // _UTIL_H_
