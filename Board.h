#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

using std::vector;

class Board {
 public:
  static Board* GetInstance();  // Singleton 객체 반환
  vector< vector<int> > GetBoard();  // getter for board_
  void MakeBoard(int size);  // size에 맞게 판을 만듦.
  void SetBoard(int flag, int x, int y);  // flag는 현재 플레이어가
                                          // 누군지, x, y좌표에 돌 놓기
  void ReturnBoard();  // 업데이트 된 Board의 상태를 원상복구
  void ShowBoard();  // 게임 판을 출력해줌
  void UpdateBoard();  // 플레이어가 돌을 두면 판을 바꿈
  bool IsBoardFull();  // board_가 가득 찼는지 확인
  bool IsBoardOneColor();  // board_가 하나의 돌로 이루어졌는지 확인
  int CheckMyScore(int flag);  // flag_에 따라 보드에
                               // flag + 1의 상태가 몇 개나 있는지 확인

 private:
  Board();
  static Board* instance_;  // 싱글톤 객체
  vector< vector<int> > board_;  // board 2차원 vector
};

#endif  //  BOARD_H_
