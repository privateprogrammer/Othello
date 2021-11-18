#include <iostream>

#include "Util.h"
#include "Board.h"

int main() {
    Util util;
    Board* board_util = Board::GetInstance();
    int size = 10;
    board_util->SetBoard(size);
    board_util->ShowBoard();
    
    return 0;
}
