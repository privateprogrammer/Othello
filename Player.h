#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Info.h"

using std::string;

class Player : public Info {
 public:
  Player(int score, string name);
  void SetScore(int score);
  int GetScore();
  void GetInfo() override;
  ~Player();

 private:
  int score_;
};

#endif  // _PLAYER_H_
