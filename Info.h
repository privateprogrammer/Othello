#ifndef _INFO_H_
#define _INFO_H_

#include <string>

using std::string;

class Info {
 public:
  explicit Info(string name);
  void SetName(string name);
  string GetName();
  virtual void GetInfo() = 0;

 private:
  string name_;
};

#endif  // _INFO_H_
