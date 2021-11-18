#ifndef _ALLPLAYER_H_
#define _ALLPLAYER_H_

#include <string>
#include <vector>

#include "Info.h"
#include "Player.h"

using std::string;
using std::vector;

class AllPlayer : public Info {
 public:
  AllPlayer(int score, string name, string color, Player* p1, Player* p2);
  void GetInfo() override;
 private:
  vector<Player*> players_;
};

#endif  // _ALLPLAYER_H_
