#include <iostream>
#include <string>

#include "Player.h"
#include "Info.h"

using std::string;
using std::cout;
using std::endl;
using std::to_string;

Player::Player(int score, string name)
: Info(name), score_(score) {}

void Player::SetScore(int score) {
  this->score_ = score;
}

int Player::GetScore() {
  return this->score_;
}

void Player::GetInfo() {
  // 플레이어 정보 전달
  string ret = "Player ";

  ret += GetName() + " : " + to_string(GetScore());

  cout << ret << endl;
}
