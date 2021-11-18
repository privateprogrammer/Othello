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
bool SetName(string name1, string name2): 플레이어 두명의 이름 입력받는 함수
bool MakeBoard(int size): Board 칸 입력받고, Board만드는 함수
void TogglePlayer() : now_player_ 바꿔주기
void PrintBoard(): board 출력
vector<Point> ShowValidXY() : 둘 수 있는 돌의 좌표 알려주기, valid_ 횟수 세기
bool InputXY(): 돌을 놓고 싶은 좌표 입력 받는 함수
void ToggleStone(): 돌 뒤집기
```

### member field

---

```C++
int x_, int y_ : 현재 입력 받은 돌 좌표
int is_finished_ : ShowValidXY 갯수 세기
Player now_player_ : 현재 플레이하고 있는 사람
```

struct Point

### member field

```C++
int x_
int y_
```

### Util 시나리오

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
