#ifndef _INFO_H_
#define _INFO_H_

#include <string>

using std::string;

class Info {
 public:
  void SetScore();
  int GetScore();
  void SetName();
  string GetName();
  void SetColor();
  string GetColor();
  virtual void GetInfo();

 private:
  int score_;
  string name_;
  string color_;
};

#endif  // _INFO_H_
