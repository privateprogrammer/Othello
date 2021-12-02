#include "gtest/gtest.h"
#include "Player.h"
#include "AllPlayer.h"
#include "Board.h"
#include "Util.h"

TEST(Test, PlayerGetScoreTEST) {
  Player *p1 = new Player(2, "Kim");
  EXPECT_EQ(p1->GetScore(), 2);
}

TEST(Test, PlayerSetScoreTEST) {
  Player *p1 = new Player(2, "Kim");
  p1->SetScore(20);
  EXPECT_EQ(p1->GetScore(), 20);
}

TEST(Test, PlayerSetNameTEST) {
  Player *p1 = new Player(2, "Kim");
  p1->SetName("Lee");
  EXPECT_EQ(p1->GetName(), "Lee");
}

TEST(Test, PlayerGetNameTEST) {
  Player *p1 = new Player(2, "Kim");
  EXPECT_EQ(p1->GetName(), "Kim");
}

TEST(Test, AllPlayerGetNameTEST) {
  Player *p1 = new Player(3, "Kim");
  Player *p2 = new Player(4, "Lee");
  AllPlayer *tmp = new AllPlayer("All", p1, p2);
  EXPECT_EQ(tmp->GetPlayerName(0), "Kim");
}

TEST(Test, AllPlayerSetNameTEST) {
  Player *p1 = new Player(3, "Kim");
  Player *p2 = new Player(4, "Lee");
  AllPlayer *tmp = new AllPlayer("All", p1, p2);
  tmp->SetPlayerName(0, "Jang");
  EXPECT_EQ(tmp->GetPlayerName(0), "Jang");
}

TEST(Test, AllPlayerGetScoreTEST) {
  Player *p1 = new Player(3, "Kim");
  Player *p2 = new Player(4, "Lee");
  AllPlayer *tmp = new AllPlayer("All", p1, p2);
  EXPECT_EQ(tmp->GetScore(0), 3);
}

TEST(Test, AllPlayerSetScoreTEST) {
  Player *p1 = new Player(3, "Kim");
  Player *p2 = new Player(4, "Lee");
  AllPlayer *tmp = new AllPlayer("All", p1, p2);
  tmp -> SetScore(1, 300);
  EXPECT_EQ(tmp->GetScore(1), 300);
}

TEST(TEST, BoardTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);

  vector< vector<int> > tmp_vector;

  for (int i = 0; i < 4; i++) {
    tmp_vector.push_back(vector<int>(4, 0));
  }
  int base = 2;
  tmp_vector[base][base] = 1;
  tmp_vector[base - 1][base - 1] = 1;

  // 상태 2의 돌
  tmp_vector[base - 1][base] = 2;
  tmp_vector[base][base - 1] = 2;
  
  ASSERT_EQ(tmp_vector.size(), board_->GetBoard().size()) << "Vectors length are unequal";

  for (int i = 0; i < board_->GetBoard().size(); ++i) {
    EXPECT_EQ(tmp_vector[i], board_->GetBoard()[i]) << "Vectors are different" << i;
  }
}

TEST(TEST, SetBoardTEST){
  Board* board_ = Board::GetInstance();
  board_ -> SetBoard(1, 1, 1);
  EXPECT_EQ(board_->GetBoard()[1][1], 2);
}

TEST(TEST, ReturnBoardTEST){
  Board* board_ = Board::GetInstance();
  board_ -> SetBoard(2, 1, 1);
  board_ -> ReturnBoard();
  EXPECT_EQ(board_->GetBoard()[1][1], 0);
}

TEST(TEST, IsBoardFullFalseTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  EXPECT_EQ(board_->IsBoardFull(), false);
}

TEST(TEST, IsBoardFullTrueTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  for (int i = 0; i < board_->GetBoard().size() ; i++)
    for (int j = 0; j < board_->GetBoard()[i].size(); j++)
      if (board_ -> GetBoard()[i][j] == 0) {
        board_ ->SetBoard(1, i, j);
      }
  EXPECT_EQ(board_->IsBoardFull(), true);
}

TEST(TEST, IsBoardOneColorTrueTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  for (int i = 0; i < board_->GetBoard().size() ; i++)
    for (int j = 0; j < board_->GetBoard()[i].size(); j++){
      board_ ->SetBoard(1, i, j);
    }
  EXPECT_EQ(board_->IsBoardOneColor(), true);
}

TEST(TEST, IsBoardOneColorFalseTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  for (int i = 0; i < board_->GetBoard().size() ; i++)
    for (int j = 0; j < board_->GetBoard()[i].size(); j++){
      board_ -> SetBoard(1, i, j);
    }
  board_ ->SetBoard(0, 0, 0);
  EXPECT_EQ(board_->IsBoardOneColor(), false);
}

TEST(TEST, BoardCheckMyScoreTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  EXPECT_EQ(board_ -> CheckMyScore(0), 2);
}

TEST(TEST, UtilShowValidTEST1){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  Util util;
  EXPECT_EQ(util.ShowValidXY(0, 0), false);
}

TEST(TEST, UtilShowValidTEST2){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  Util util;
  EXPECT_EQ(util.ShowValidXY(0, 2), true);
}

TEST(TEST, UtilToggleStoneTEST2){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  Util util;
  util.ToggleStone(0, 2);
  EXPECT_EQ(board_ -> GetBoard()[0][2], 1);
}

TEST(TEST, UtilUpdateScoreTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  Util util;
  util.ToggleStone(0, 2);
  util.UpdateScore();
  
  EXPECT_EQ(util.allplayers()->GetScore(0), 4);
}

TEST(TEST, TogglePlayerTEST){
  Board* board_ = Board::GetInstance();
  board_ -> MakeBoard(4);
  Util util;
  util.TogglePlayer();
  
  EXPECT_EQ(util.flag(), 1);
}