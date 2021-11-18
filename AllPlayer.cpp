#include <iostream>
#include <string>
#include <vector>

#inclue "AllPlayer.h"

using std::string;
using std::cout;
using std::endl;

AllPlayer::AllPlayer(int score, string name, string color, Player* p1, Player* p2)
: Info(int score, string name, string color) {
  players_.push_back(p1);
  players_.push_back(p2);
}

void AllPlayer::GetInfo() {
  // 모든플레이어 정보 전달
  for (int i = 0; i < players.size(); i++) {
    string ret = "Player ";
    ret += GetName() + "(" + GetColor() + ")" + " : " + GetPoint();
    cout << ret << endl;
  }
}
