#include <iostream>
#include <string>
#include <vector>

#include "AllPlayer.h"
#include "Player.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::to_string;

AllPlayer::AllPlayer(int score, string name, string color, Player* p1, Player* p2)
: Info(score, name, color) {
  players_.push_back(p1);
  players_.push_back(p2);
}

void AllPlayer::GetInfo() {
  // 모든플레이어 정보 전달
  for (int i = 0; i < players_.size(); i++) {
    string ret = "Player ";
    ret += GetName() + "(" + GetColor() + ")" + " : " + to_string(GetScore());
    cout << ret << endl;
  }
}
