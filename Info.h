#ifndef _INFO_H_
#define _INFO_H_

#include <string>

using std::string;

class Info {
 public:
  explicit Info(int score, string name, string color);
  void SetScore(int score);
  int GetScore();
  void SetName(string name);
  string GetName();
  void SetColor(string color);
  string GetColor();
  virtual void GetInfo() = 0;

 private:
  int score_;
  string name_;
  string color_;
};

#endif  // _INFO_H_
