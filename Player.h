#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

using std::string;

class Player {
 public:
  void SetScore();
  int GetScore();
  void SetName();
  string GetName();
  void SetColor();
  string GetColor();

 private:
  int score_;
  string name_;
  string color_;
};

#endif  // _PLAYER_H_
