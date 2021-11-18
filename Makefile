# TODO: Set your googletest directory path
GTEST_DIR=/home/longnew/practice/TERM/googletest/googletest

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -pthread

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

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

Part.o : Part.cc
	g++ -std=c++17 -c $^

Door.o : Door.cc
	g++ -std=c++17 -c $^

Roof.o : Roof.cc
	g++ -std=c++17 -c $^

Wheel.o : Wheel.cc
	g++ -std=c++17 -c $^

Car.o : Car.cc
	g++ -std=c++17 -c $^ 

CarBuilder.o : CarBuilder.cc
	g++ -std=c++17 -c $^

CarPartsFactory.o : CarPartsFactory.cc
	g++ -std=c++17 -c $^

HyundaiPartsFactory.o : HyundaiPartsFactory.cc 
	g++ -std=c++17 -c $^

KiaPartsFactory.o : KiaPartsFactory.cc
	g++ -std=c++17 -c $^

main : main.cc Part.o Roof.o Wheel.o Door.o Car.o CarBuilder.o CarPartsFactory.o HyundaiPartsFactory.o KiaPartsFactory.o
	g++ -std=c++17 -o $@ $^

# TODO: Change 'calc_test.cc' to your test file
CarTest.o : CarTest.cc $(GTEST_HEADERS)
	g++ $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c CarTest.cc -o $@

# TODO: Change 'calc_test.o' and 'calc.o' to your object targets
test : CarTest.o Part.o Roof.o Wheel.o Door.o Car.o CarBuilder.o CarPartsFactory.o HyundaiPartsFactory.o KiaPartsFactory.o gtest_main.a
	g++ $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

.PHONY: all clean 
