#ifndef _ALLPLAYER_H_
#define _ALLPLAYER_H_

#include <string>

using std::string;

class AllPlayer : public Info {
 public:
  void GetInfo() override();
};

#endif  // _ALLPLAYER_H_
