#ifndef _ALLPLAYER_H_
#define _ALLPLAYER_H_

#include <string>
#include <vector>

using std::string;

class AllPlayer : public Info {
 public:
  AllPlayer(int score, string name, string color, Player* p1, Player* p2);
  void GetInfo() override();
 priavte:
  vector<Player*> players_;
};

#endif  // _ALLPLAYER_H_
