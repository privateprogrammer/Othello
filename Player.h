#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Info.h"

using std::string;

class Player : public Info {
 public:
  Player(int score, string name);  // 이름, 점수를 초기화하는 생성자
  void SetScore(int score);  // setter for score
  int GetScore();  // getter for score
  void GetInfo() override;  // 객체의 정보를 출력
  ~Player();  // 소멸자

 private:
  int score_;  // 플레이어 점수를 저장하는 변수
};

#endif  // _PLAYER_H_
