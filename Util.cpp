#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "Player.h"
#include "Util.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;

Util::Util(){
	this -> x_ = 0;
	this -> y_ = 0;
	this -> is_finished_ = 0;
	this -> flag_ = 0;
	this -> players_;
  this -> place_valid_;
  this -> board_ = Board::GetInstance();
}

void Util::Init(){
	// 선 플레이어 A로 가정.
	string start = "y";

	while(true){
		if ((start.compare("N") == 0) || (start.compare("n") == 0)){
			cout << "게임을 종료 합니다." << endl;
			break;
		}
		
		// 1. 게임시작 파트
		this -> MakeBoard();
		this -> SetName();

		// 2. 플레이어 입력
		// 게임 진행은 끝나는 조건을 만날 때 까지 진행.
		// 플레이어의 색깔은 flag_로 판별.
		while(this -> CheckCondition()){
			if (this -> place_valid_.size() == 0){
				this -> PrintBoard();
				cout << "놓을 수 있는 공간이 없습니다." << endl;

				this -> TogglePlayer();
				cout << this -> players_ -> GetPlayerName(flag_) << " 플레이어의 차례입니다." << endl;
				continue;
			}

			this -> PrintBoard();
			cout << this -> players_ -> GetPlayerName(flag_) << " 플레이어의 차례입니다." <<  endl;

			while(!this -> InputXY()){
				cout << "옳은 선택이 아닙니다." << endl;
			}

			this -> ToggleStone(this -> x_, this -> y_);

			this -> board_ -> ReturnBoard();

			// 점수 출력.
			this -> UpdateScore();
			this -> players_ -> GetInfo();
			this -> TogglePlayer();

		}

		// 누가 이겼는지 말해줘야 함. 점수 계산 함수????
		this -> players_ -> Winner();

		cout << endl;
		cout << "게임을 계속 하시겠습니까? (Y / N) : ";
		cin >> start;
	}
}

void Util::SetName(){
 	// 각 플레이어 이름 설정
	// cin을 통해 입력을 받음 
	// 이 플레이어들을 players에 저장.
	string temp_name = "";

	// 색깔은 flag로 판별할 거니까 숫자를 문자열로 지정했음
	// 초기 점수는 0점으로 시작.
	cout << "Player 1 Name: ";
	cin >> temp_name;
	Player *p1 = new Player(2, temp_name, "0");

	cout << "Player 2 Name: ";
	cin >> temp_name;
	Player *p2 = new Player(2, temp_name, "1");

	this -> players_ = new AllPlayer("All", p1, p2);
}

void Util::MakeBoard(){
	// 보드의 사이즈 입력 (짝수 && num >=4 && num <= 20)
	// cin을 통해 입력
	// board_ instance_를 호출해서 배열 생성.
	int board_size = 0;

	cout << "보드의 사이즈를 지정해주세요. : ";
	cin >> board_size;
	while (board_size % 2 == 1 || board_size < 4 || board_size > 20){
		cout << "6 ~ 18 사이의 짝수를 입력해주세요. : ";
		cin >> board_size;
	}
	
	this -> board_ -> MakeBoard(board_size);
}

bool Util::InputXY(){
	// 입력을 받는 공간. 
	// cin을 통해 플레이어가 놓고 싶은 위치를 입력 받음.
	// 예외 조건을 따져서 true, false를 출력
	// 입력 받은 x, y값이
	// 1. 보드 내부의 값
	// 2. 보드의 값이 3
	// 인지 확인을 해서 둘 다 만족하면 true, 아니면 false

	cout << "x, y 좌표를 입력하세요 : ";
  cin >> this -> x_ >> this -> y_;

	vector<vector<int>> add_board = board_ -> GetBoard();
	int board_size = add_board.size();

	// 입력한 공간이 보드 내부이고 3으로 업데이트 된 경우에만 true
	if (this -> x_ >= 0 && this -> x_ < board_size && this -> y_ >= 0 && this -> y_ < board_size && add_board[this -> x_][this -> y_] == 3)
		return true;

	return false;
}

bool Util::CheckCondition(){
	vector<vector<int>> add_board = board_ -> GetBoard();
	int board_size = add_board.size();

	// 모든 공간이 채워졌는지
	if (board_ -> IsBoardFull())
		return false;
	
	// 모두 동일한색인지
	if (board_ -> IsBoardOneColor())
		return false;

	// 입력 가능한 공간을 초기화 해서 판단
	this -> place_valid_.clear();
	vector<pair<int, int>>().swap(this -> place_valid_);

	for (int x = 0; x < board_size; x++)
		for (int y = 0; y < board_size; y++)
			if (ShowValidXY(x, y)){
				this -> place_valid_.push_back(make_pair(x, y));
			}
				
	cout << endl;
	// 놓을 수 있는 공간 없으면 + 업데이트.
	// 놓을 수 있으면 다시 0으로 초기화.
	for (int i = 0; i < this -> place_valid_.size(); i++){
		cout << this -> place_valid_[i].first << " " << this -> place_valid_[i].second << endl;
	}

	if (this -> place_valid_.size() == 0)
		this -> is_finished_++;
	else
		this -> is_finished_ = 0;
	
	// 턴이 그냥 2번 넘어갔는지
	if (this -> is_finished_ == 2)
		return false;
	
	return true;
}

void Util::UpdateScore(){
	// players_의 SetScore()을 사용해야 하고
	// Board에서 1, 2의 개수를 체크 해야 함.
	int one_cnt = this -> board_ -> CheckMyScore(0);
	int two_cnt = this -> board_ -> CheckMyScore(1);

	this -> players_ -> SetScore(0, one_cnt);
	this -> players_ -> SetScore(1, two_cnt);
}
void Util::TogglePlayer(){
	// 플레이어 순서 변경을 위한 메소드
	// flag를 통해 순서를 변경.
	// 0, 1 idx를 통해서 가져오자.
	if (this -> flag_ == 0){
		this -> flag_++;
	}else{
		this -> flag_--;
	}
}

void Util::PrintBoard(){
	// Board 상황을 출력 board_ 객체를 이용.
	// board_에서 프린트 하는 메소드를 사용.
	board_ -> ShowBoard();
}

bool Util::ShowValidXY(int x, int y){
	// 현재 Player가 놓을 수 있는 위치를 계산.
	// 자기 자신의 돌은 flag + 1이 됨.

	// 현재 위치가 우선적으로 빈칸이어야 함.

	// flag를 통해 현재 플레이어가 누구인지 확인
	// 상, 하, 좌, 우, 상좌, 상우, 하좌, 하우 8방향으로
	// 뒤집을 수 있는 위치 존재하는 지 좌표로 비교에
	// 저장하고 나서 길이를 체크 해서 불가능 한지 판단.

	// 놓을 수 있는 공간을 3으로 업데이트
	int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
	int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

	// ret의 경우 가능한 경우가 존재함을 의미.
	vector<vector<int>> add_board = board_ -> GetBoard();
	int board_size = add_board.size();
	int ret = 0;

	// 현재 위치가 빈칸인지 부터 확인.
	if (add_board[x][y] != 0){
		return false;
	}

	// 상대 돌의 상태를 초기화
	int oppent = 0;
	int my_status = 0;
	if (flag_ == 1){
		oppent = 1;
		my_status = 2;
	}else{
		oppent = 2;
		my_status = 1;
	}

	for (int idx = 0; idx < 8; idx++){
		// possible을 통해 마지막에 위치하는 곳이 자기의 상태와 동일한지 판단
		// 
		int temp_x = x;
		int temp_y = y;
		int cnt = 0;
		int possible = 0;

		for(int i = 0; i < board_size; i++){
			temp_x += dx[idx];
			temp_y += dy[idx];

			// 보드 내부의 위치가 아닌 경우 종료
			if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
				break;

			// 나와 동일한 상대를 만나는 경우 possible 업데이트
			if (add_board[temp_x][temp_y] == my_status){
				possible = 1;
				break;
			}

			// 상대방의 돌이 있는 경우에만 cnt++; 
			// 그 외의 경우에는 이 지점에 돌을 놓을 수 없음.
			if (add_board[temp_x][temp_y] == oppent)
				cnt++;
			
			// 아직 자기 자신을 만나지 않았는데 빈칸인 경우
			if (add_board[temp_x][temp_y] == 3 || add_board[temp_x][temp_y] == 0)
				break;
		}

		if(possible && (cnt != 0)){
			// 가능한 경우기 때문에
			// 3으로 업데이트 하는 방식
			board_ -> SetBoard(2, x, y);
			return true;
		}
	}
	return false;
}

void Util::ToggleStone(int x, int y){
	// 상, 하, 좌, 우, 상좌, 상우, 하좌, 하우 8방향으로
	// 뒤집을 수 있는 위치인지 판단
	// 뒤집을 수 있는 경우 해당 방향에 존재하는 상대팀 돌을 뒤집기.
	int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
	int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

	// ret의 경우 가능한 경우가 존재함을 의미.
	vector<vector<int>> add_board = board_ -> GetBoard();
	int board_size = add_board.size();

	// 상대 돌의 상태를 초기화
	int oppent = 0;
	int my_status = 0;
	if (flag_ == 1){
		oppent = 1;
		my_status = 2;
	}else{
		oppent = 2;
		my_status = 1;
	}

	// 우선 직접 놓은 위치의 상태를 업데이트.
	board_ -> SetBoard(my_status - 1, x, y);

	for (int idx = 0; idx < 8; idx++){
		// possible을 통해 마지막에 위치하는 곳이 자기의 상태와 동일한지 판단
		int temp_x = x;
		int temp_y = y;
		int cnt = 0;
		int possible = 0;

		for(int i = 0; i < board_size; i++){
			temp_x += dx[idx];
			temp_y += dy[idx];

			if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
				break;

			if (add_board[temp_x][temp_y] == my_status){
				possible = 1;
				break;
			}

			if (add_board[temp_x][temp_y] == oppent)
				cnt++;
			
			if (add_board[temp_x][temp_y] == 0 || add_board[temp_x][temp_y] == 3)
				break;
		}

		if(possible && (cnt != 0)){
			// 위의 반복문으로 값이 바껴서 업데이트 해야함.
			temp_x = x;
			temp_y = y;

			for(int i = 0; i < board_size; i++){
				temp_x += dx[idx];
				temp_y += dy[idx];

				if (temp_x < 0 || temp_x >= board_size || temp_y < 0 || temp_y >= board_size)
					break;

				if (add_board[temp_x][temp_y] == my_status)
					break;

				board_ -> SetBoard(my_status - 1, temp_x, temp_y);
			}
		}
	}
}
