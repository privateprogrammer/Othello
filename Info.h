#ifndef INFO_H_
#define INFO_H_

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

#endif  // INFO_H_
