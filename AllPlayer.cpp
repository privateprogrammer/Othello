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

AllPlayer::AllPlayer(string name, Player* p1, Player* p2)
: Info(name) {
  players_.push_back(p1);
  players_.push_back(p2);
}

string AllPlayer::GetPlayerName(int flag){
  return players_[flag] -> GetName();
}

void AllPlayer::SetPlayerName(int flag, string play_name){
  players_[flag] -> SetName(play_name);
}

void AllPlayer::SetScore(int flag, int score){
  players_[flag] -> SetScore(score);
}

int AllPlayer::GetScore(int flag){
  return players_[flag] -> GetScore();
}

void AllPlayer::GetInfo() {
  cout << "\"\"\"\n현재 점수" << endl;
  cout << endl;

  // 모든플레이어 정보 전달
  for (int i = 0; i < players_.size(); i++) {
    string ret = "Player ";

    ret += players_[i] -> GetName() + "(" + players_[i] -> GetColor() + ")" + " : " + to_string(players_[i] -> GetScore());
    cout << ret << endl;
  }
  cout << "\"\"\"" << endl;
}

void AllPlayer::Winner(){
  string ret = "Player ";
  // 무승부의 경우
  if (players_[1] -> GetScore() ==  players_[0] -> GetScore()){
    ret += players_[0] -> GetName() + "(" + players_[1] -> GetColor() + ")" + " : " + to_string(players_[0] -> GetScore() - players_[1] -> GetScore()) + "으로 무승부입니다.";
    cout << ret << endl;
  }

  int i = 0;
  int j = 1;
  if (players_[1] -> GetScore() > players_[0] -> GetScore()){
    i = 1;
    j = 0;
  }
    
  ret += players_[i] -> GetName() + "(" + players_[i] -> GetColor() + ")" + " : " + to_string(players_[i] -> GetScore() - players_[j] -> GetScore()) + "의 점수차로 승리하였습니다.";
  cout << ret << endl;
}
