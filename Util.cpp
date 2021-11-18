#include <iostream>
#include <vector>
#include <string>

#include "Util.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void Init(){
	// 선 플레이어 A로 가정.

	flag = 0;
	is_finished_ = 0;
	players_ = vector<Player>();
	board_ = Board::GetInstance();
	
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
	string temp_name = "";

	cout << "Player 1 Name: ";
	cin >> temp_name;
	Player temp_player = new Player(temp_name);
	players_.push_back(temp_player);

	cout << "Player 2 Name: ";
	cin >> temp_name;
	Player temp_player = new Player(temp_name);
	players_.push_back(temp_player);
}

bool MakeBoard(){
	// 보드의 사이즈 입력 (짝수 && num >=4 && num <= 20)
	// cin을 통해 입력
	// board_ instance_를 호출해서 배열 생성.
	int board_size = nullptr;
	cin >> board_size;

	board_.
}

bool InputXY(){
		// 입력을 받는 공간. 
		// cin을 통해 플레이어가 놓고 싶은 위치를 입력 받음.
		// 예외 조건을 따져서 true, false를 출력
		// 입력 받은 x, y값이
		// 1. 보드 내부의 값
		// 2. 보드의 값이 3
		// 인지 확인을 해서 둘 다 만족하면 true, 아니면 false
  cin >> x_;
	cin >> y_;

	if (ShowValidXY())
		return true;

	return false;
}

void TogglePlayer(){
		// 플레이어 순서 변경을 위한 메소드
		// flag를 통해 순서를 변경.
		// 0, 1 idx를 통해서 가져오자.
	if (flag == 0){
		flag--;
	}else{
		flag++;
	}
}

void PrintBoard(){
		// Board 상황을 출력 board_ 객체를 이용.
		// board_에서 프린트 하는 메소드를 사용.
	board_.GetBoard();
}

int ShowValidXY(){
	// 현재 Player가 놓을 수 있는 위치를 계산.
	// 자기 자신의 돌은 flag + 1이 됨.

	// 현재 위치가 우선적으로 빈칸이어야 함.

	// flag를 통해 현재 플레이어가 누구인지 확인
	// 상, 하, 좌, 우, 상좌, 상우, 하좌, 하우 8방향으로
	// 뒤집을 수 있는 위치 존재하는 지 좌표로 비교에
	// 저장하고 나서 길이를 체크 해서 불가능 한지 판단.
	// 
	// 놓을 수 있는 공간을 3으로 업데이트
	int[] dx = [0, 0, -1, 1, -1, -1, 1, 1];
	int[] dy = [-1, 1, 0, 0, -1, 1, -1, 1];

	vector<vector<int, int>> *add_board = board_.GetBoard();
	int board_size = (*add_board).size();
	int cnt = 0;

	// 현재 위치가 빈칸인지 부터 확인.
	if (*(add_board)[x_][y_] != 0){
		return 0;
	}

	// 상대 돌의 상태를 초기화
	int oppent = nullptr;
	if (flag == 1){
		oppent = 1;
	}else{
		oppent = 2;
	}

	for (int idx = 0; idx < 8; idx++{
		int temp_x = x_;
		int temp_y = y_;

		for(int i = 0; i < board_size; i++{
			temp_x += dx[idx];
			temp_y += dy[idx];

			// 보드 내부의 위치가 아닌 경우 종료
			if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
				break;

			// 상대 돌이 아니거나, 빈 칸인 경우 종료
			if ((*add_board)[temp_x][temp_y] != oppent)
				break;
			

			cnt++;
		}

		temp_x = x_;
		temp_y = y_;
		for(int i = 0; i < board_size; i++{
			temp_x -= dx[idx];
			temp_y -= dy[idx];

			// 보드 내부의 위치가 아닌 경우 종료
			if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
				break;

			// 상대 돌이 아니거나, 빈 칸인 경우 종료
			if ((*add_board)[temp_x][temp_y] != oppent)
				break;
			

			cnt++;
		}
	}
}

void ToggleStone(int x, int y){
	// 상, 하, 좌, 우, 상좌, 상우, 하좌, 하우 8방향으로
	// 뒤집을 수 있는 위치인지 판단
	// 뒤집을 수 있는 경우 해당 방향에 존재하는 상대팀 돌을 뒤집기.
	int[] dx = [0, 0, -1, 1, -1, -1, 1, 1];
	int[] dy = [-1, 1, 0, 0, -1, 1, -1, 1];

	vector<vector<int, int>> *add_board = board_.GetBoard();
	int board_size = (*add_board).size();
	int cnt = 0;

	// 상대 돌의 상태를 초기화
	// 자기 자신을 나타내는 정보까지 초기화
	int oppent = nullptr;
	int my_status = nullptr;
	if (flag == 1){
		oppent = 1;
		my_status = 2;
	}else{
		oppent = 2;
		my_status = 1;
	}

	for (int idx = 0; idx < 8; idx++{
		int temp_x = x_;
		int temp_y = y_;

		for(int i = 0; i < board_size; i++{
			temp_x += dx[idx];
			temp_y += dy[idx];

			// 보드 내부의 위치가 아닌 경우 종료
			if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
				break;

			// 상대 돌이 아니거나, 빈 칸인 경우 종료
			if ((*add_board)[temp_x][temp_y] != oppent)
				break;
			
			(*add_board)[temp_x][temp_y] = my_status;
		}

		temp_x = x_;
		temp_y = y_;
		for(int i = 0; i < board_size; i++{
			temp_x -= dx[idx];
			temp_y -= dy[idx];

			// 보드 내부의 위치가 아닌 경우 종료
			if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
				break;

			// 상대 돌이 아니거나, 빈 칸인 경우 종료
			if ((*add_board)[temp_x][temp_y] != oppent)
				break;
			
			(*add_board)[temp_x][temp_y] = my_status;
		}
	}
}
