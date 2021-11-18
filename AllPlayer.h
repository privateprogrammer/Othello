#ifndef _ALLPLAYER_H_
#define _ALLPLAYER_H_

#include <string>

using std::string;

class AllPlayer : public Info {
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

#endif  // _ALLPLAYER_H_
