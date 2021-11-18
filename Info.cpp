#include <string>

#include "Info.h"

using std::string;

// 생성자
Info::Info(int score, string name, string color)
: score_(score), name_(name), color_(color) {}

// Getter Setter 지정
void Info::SetScore(int score) { this->score_ = score; }
int Info::GetScore() { return this->score_; }
void Info::SetName(string name) { this->name_ = name; }
string Info::GetName() { return this->name_; }
void Info::SetColor(string color) { this->color_ = color; }
string Info::GetColor() { return this->color_; }
