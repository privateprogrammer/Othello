#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

using std::string;

class Player : public Info {
 public:
  void GetInfo override();
};

#endif  // _PLAYER_H_
