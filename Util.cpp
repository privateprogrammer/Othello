#include <iostream>
#include <vector>

#include "Util.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

Util* Util::instance_ = NULL;
Util::Util() {
}

Util* Util::GetInstance(){
    if (instance_ == NULL){
        instance_ = new Util();
    }
    return instance_;
}