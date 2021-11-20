#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Info.h"

using std::string;

class Player : public Info {
 public:
  Player(int score, string name, string color);
  void SetColor(string color);
  string GetColor();
  void SetScore(int score);
  int GetScore();
  void GetInfo() override;

 private:
  int score_;
  string color_;
};

#endif  // _PLAYER_H_
