# Board.h

---

### Design pattern

- Singleton pattern

---

### function

```C++
Board(); // 기본 생성자
static Board* GetInstance();
vector< vector<int> > GetBoard();
void ShowBoard(); //판을 보여줌
void MakeBoard(int size); //size에 맞게 판을 만듦.
void SetBoard(int flag, int x, int y);
//flag는 현재 플레이어가 누군지, x, y좌표에 돌 놓기
void ReturnBoard();
void UpdateBoard(); //플레이어가 돌을 두면 판을 바꿈
 int CheckMyScore(int flag) : flag_에 따라 보드에 flag + 1의 상태가 몇 개나 있는지 확인
```

---

### member field

```C++
static Board* instance_;
vector< vector<int> > board_;
```
<br><br>

# Util.h

---

### Design pattern

- Singleton pattern

---

### function

```C++
void InIt() : 모든 게임의 진행과정을 맡을 함수(main 이라 볼 수 있음)
void SetName(): 플레이어 두명의 이름 입력받는 함수
void MakeBoard(): Board 칸 입력받고, Board만드는 함수
bool InputXY(): 돌을 놓고 싶은 좌표 입력 받는 함수
bool CheckCondition() : 게임 진행 가능한지 확인하는 함수.

void UpdateScore() : 한 플레이어가 돌을 놓은 이후 모두의 점수를 업데이트 하는 함수
void TogglePlayer() : now_player_ 바꿔주기
void PrintBoard(): board 출력
bool ShowValidXY(int x, int y) : 둘 수 있는 돌의 좌표 알려주기, valid_ 횟수 세기
void ToggleStone(int x, int y): 돌 뒤집기
```

### member field

---

```C++
int x_, int y_ : 현재 입력 받은 돌 좌표
int is_finished_ : ShowValidXY 갯수 세기
AllPlayer players_ : All플레이어 객체 
vector<pair<int, int>> place_valid_ : 놓을 수 있는 공간들의 벡터
Board* board_ : 보드 객체를 가지고 있음.
```


### Util 시나리오
```
1. 게임 시작
  - 보드의 사이즈 입력
  - 플레이어 이름 입력
  
  - 1. 보드 제작
  - 2. 보드 초기 설정 하는 메소드

2. 플레이어 입력
  - 게임 진행 가능 판별
    - 1. 모든 돌이 동일한 색인지.
    - 2. 모든 공간이 채워졌는지
    - 3. 아무것도 하지 않은 턴이 2전 되었는지.
  - 놓을 수 있는 공간 확인
  - 현재 보드 상황 
  
  - 입력을 받음
    true
      . 1 놓으려는 좌표 입력
      . 2 놓을 수 있는 공간인지 확인
        
        true -> 공간에 돌을 둠
        false -> 다시 2 - true. 1로 이동

    false
      - 턴이 넘어간 횟수가 2번인지 확인

      true -> 게임 종료
      false -> 턴이 넘어간 횟수 업데이트, 플레이어 순서 넘김
  
  - 돌을 뒤집은 후에 "3"으로 업데이트 되었던 값을 다시 0으로 보냄.

3. 게임 종료
  - 보드에 존재하는 돌의 개수 체크
  - 누가 이겼는지 출력
  - 게임을 더 할 것인지 물어봄

  true -> 1.로 돌아가 게임 시작
  false -> 프로그램 종료

```
<br><br>

# Info.h

---

### function

```C++
explicit Info(string name) : 이름을 초기화 하기 위한 생성자
void SetName(string name) : 현재 객체의 이름을 지정함.
string GetName() : 현재 객체의 이름을 가져감
virtual void GetInfo() = 0 : 각 플레이어의 정보 즉, 객체의 정보를 출력함.
```

---

### member field

```C++
string name_;
```
<br>

## Player.h : [Inherit Info.h]

---

### function

```C++
Player(int score, string name, string color) : 이름, 점수, 색깔을 초기화하는 생성자
void SetScore(int score) : setter for score
int GetScore() : getter for score
void GetInfo() override : 객체의 정보를 출력
```

---

### member field

```C++
int score_
```
<br>

## AllPlayer.h

---

### function

```C++
AllPlayer(string name, Player* p1, Player* p2) : 이름, 플레이어 2명을 초기화하는 생성자.
string GetPlayerName(int flag) : flag에 따라 지정된 플레이어의 이름을 리턴
void SetPlayerName(int flag) : flag에 따라 지정된 플레이어의 이름을 업데이트
void GetInfo() override : 현재 플레이어의 점수상황을 출력
void SetScore(int flag, int score) : flag에 따라 지정된 플레이어의 점수를 지정
int GetScore(int flag) : flag에 따라 지정된 플레이어의 점수를 리턴.
void Winner() : 게임이 종료되고 두 플레이어 중 승자를 출력함

```

---

### member field

```C++
vector<Player*> players_
```
