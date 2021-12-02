# TODO: Set your googletest directory path
GTEST_DIR= /Users/nicholaskim/Desktop/School/21-Fall/21_Fall_School/OOD/2021_OOD/Othello/googletest/googletest
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -pthread
#add if your OS is mac OS
CXXFLAGS += --std=c++17
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
TESTOBJECTS = gtest_main.a Board.o Info.o Player.o AllPlayer.o Util.o GameTest.o
# TODO: Set your executable target
all : main

# TODO: Change 'main' and 'main_test' to your executable and test respectively
clean :
	rm -f gtest.a gtest_main.a *.o main test

gtest-all.o : $(GTEST_SRCS_)
	g++ $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	g++ $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o 
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# 보드 그 자체
Board.o : Board.cpp
	g++ -std=c++17 -c $^

#
Info.o : Info.cpp
	g++ -std=c++17 -c $^

# 플레이어 그 자체
Player.o : Player.cpp
	g++ -std=c++17 -c $^

# 전체 플레이어
AllPlayer.o : AllPlayer.cpp
	g++ -std=c++17 -c $^

# Util 그 자체
Util.o : Util.cpp 
	g++ -std=c++17 -c $^ 


main : main.cpp Board.o Info.o Player.o AllPlayer.o Util.o
	g++ -std=c++17 -o $@ $^

# TODO: Change 'calc_test.cc' to your test file
GameTest.o : GameTest.cpp $(GTEST_HEADERS)
	g++ $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c GameTest.cpp -o $@

# TODO: Change 'calc_test.o' and 'calc.o' to your object targets
test : $(TESTOBJECTS)
	g++ $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

.PHONY: all clean 
