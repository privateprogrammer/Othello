# Board.h

---

### Design pattern

- Singleton pattern

---

### function

```C++
static Board* GetInstance();
vector< vector<int> > GetBoard();
void ShowBoard(); //판을 보여줌
void MakeBoard(int size); //size에 맞게 판을 만듦.
void SetBoard(int flag, int x, int y);
//flag는 현재 플레이어가 누군지, x, y좌표에 돌 놓기
void ReturnBoard();
void UpdateBoard(); //플레이어가 돌을 두면 판을 바꿈
```

---

### member field

```C++
static instance_
```

### Point.h

```C++
struct Point {
  int x, y;
}
```

# Util.h

---

### Design pattern

- Singleton pattern

---

### function

```c++
Util* GetInstance() : 싱글톤 객체 반환하는 함수
void InIt() : InputSize, SetName(), PrintBoard()
void SetName(string name1, string name2): 플레이어 두명의 이름 입력받는 함수
void MakeBoard(int size): Board 칸 입력받고, Board만드는 함수
bool InputXY(): 돌을 놓고 싶은 좌표 입력 받는 함수
bool CheckCondition() : 게임 진행 가능한지 확인하는 함수.

void TogglePlayer() : now_player_ 바꿔주기
void PrintBoard(): board 출력
vector<Point> ShowValidXY() : 둘 수 있는 돌의 좌표 알려주기, valid_ 횟수 세기
void ToggleStone(): 돌 뒤집기
```

### member field

---

```C++
int x_, int y_ : 현재 입력 받은 돌 좌표
int is_finished_ : ShowValidXY 갯수 세기
vector<Player*> players_ : 플레이어 객체 포인터를 가진 벡터
Board* board_ : 보드 객체를 가지고 있음.
```

struct Point

### member field

```C++
int x_
int y_
```

### Util 시나리오
```
1. 게임 시작
  - 보드의 사이즈 입력
  - 플레이어 이름 입력
  
  - 1. 보드 제작

2. 플레이어 입력
  - 놓을 수 있는 공간 확인
  - 게임 진행 가능 판별
    - 1. 모든 돌이 동일한 색인지.
    - 2. 모든 공간이 채워졌는지
    - 3. 아무것도 하지 않은 턴이 2전 되었는지.
  
    true
      . 1 놓으려는 좌표 입력
      . 2 놓을 수 있는 공간인지 확인
        
        true -> 공간에 돌을 둠
        false -> 다시 2 - true. 1로 이동

    false
      - 턴이 넘어간 횟수가 2번인지 확인

      true -> 게임 종료
      false -> 턴이 넘어간 횟수 업데이트, 플레이어 순서 넘김

3. 게임 종료
  - 보드에 존재하는 돌의 개수 체크
  - 누가 이겼는지 출력
  - 게임을 더 할 것인지 물어봄

  true -> 1.로 돌아가 게임 시작
  false -> 프로그램 종료

```

## player.h

---

### function

```C++
int GetScore()
string GetName()
string GetColor()
```

---

### member field

```C++
int score_
string name_
string color_
```
