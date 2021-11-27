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
  AllPlayer(string name, Player* p1, Player* p2);
  string GetPlayerName(int flag);
  void SetPlayerName(int flag, string play_name);
  void GetInfo() override;
  void SetScore(int flag, int score);
  int GetScore(int flag);
  void Winner();
  ~AllPlayer();

 private:
  vector<Player*> players_;
};

#endif  // _ALLPLAYER_H_
