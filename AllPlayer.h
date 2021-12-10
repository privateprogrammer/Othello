#ifndef ALLPLAYER_H_
#define ALLPLAYER_H_

#include <string>
#include <vector>

#include "Info.h"
#include "Player.h"

using std::string;
using std::vector;

class AllPlayer : public Info {
 public:
  AllPlayer(string name, Player* p1, Player* p2);
  // 이름, 플레이어 2명을 초기화하는 생성자.
  string GetPlayerName(int flag);
  // flag에 따라 지정된 플레이어의 이름을 리턴
  void SetPlayerName(int flag, string play_name);
  // flag에 따라 지정된 플레이어의 이름을 업데이트
  void GetInfo() override;
  // 현재 플레이어의 점수상황을 출력
  void SetScore(int flag, int score);
  // flag에 따라 지정된 플레이어의 점수를 지정
  int GetScore(int flag);
  // flag에 따라 지정된 플레이어의 점수를 리턴.
  void Winner();
  // 게임이 종료되고 두 플레이어 중 승자를 출력함
  ~AllPlayer();
  // players_를 삭제하는 소멸자

 private:
  vector<Player*> players_;
  // 두 명의 플레이어를 저장하는 벡터
};

#endif  // ALLPLAYER_H_
