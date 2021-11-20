#include <string>

#include "Info.h"

using std::string;

// 생성자
Info::Info(string name) : name_(name){}

// Getter Setter 지정
void Info::SetName(string name) { this->name_ = name; }
string Info::GetName() { return this->name_; }
