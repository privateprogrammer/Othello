#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Info.h"

using std::string;

class Player : public Info {
 public:
  Player(int score, string name, string color);
  void GetInfo() override;
};

#endif  // _PLAYER_H_
