#include <iostream>
#include <vector>

#include "Util.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void Init(){
	// 선 플레이어 A로 가정.


	SetName();
	MakeBoard();  

	while(1){

		PrintBoard();
	}
	
}

bool SetName(){
 	// 각 플레이어 이름 설정
	// cin을 통해 입력을 받음 
	// 이 플레이어들을 players에 저장.
}

bool MakeBoard(){
	// 보드의 사이즈 입력 (짝수 && num >=4 && num <= 20)
	// cin을 통해 입력
	// board_ instance_를 호출해서 배열 생성.

}

bool InputXY(){
		// 입력을 받는 공간. 
		// cin을 통해 플레이어가 놓고 싶은 위치를 입력 받음.
		// 예외 조건을 따져서 true, false를 출력
		// 입력 받은 x, y값이
		// 1. 보드 내부의 값
		// 2. 보드의 값이 3
		// 인지 확인을 해서 둘 다 만족하면 true, 아니면 false
  
}

void TogglePlayer(){
		// 플레이어 순서 변경을 위한 메소드
		// flag를 통해 순서를 변경.
		// 0, 1 idx를 통해서 가져오자.
}

void PrintBoard(){
		// Board 상황을 출력 board_ 객체를 이용.
		// board_에서 프린트 하는 메소드를 사용.
}

bool ShowValidXY(){
		// 현재 Player가 놓을 수 있는 위치를 계산.
		// flag를 통해 현재 플레이어가 누구인지 확인
		// 상, 하, 좌, 우, 상좌, 상우, 하좌, 하우 8방향으로
		// 뒤집을 수 있는 위치 존재하는 지 좌표로 비교에
		// 저장하고 나서 길이를 체크 해서 불가능 한지 판단.
		// 
		// 놓을 수 있는 공간을 3으로 업데이트

}

void ToggleStone(int x, int y){
		// 상, 하, 좌, 우, 상좌, 상우, 하좌, 하우 8방향으로
		// 뒤집을 수 있는 위치인지 판단
		// 뒤집을 수 있는 경우 해당 방향에 존재하는 상대팀 돌을 뒤집기.

}
