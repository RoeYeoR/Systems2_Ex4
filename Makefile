CXX = g++
CXXFLAGS = -std=c++11 -g

SRCS_TREE = main.cpp
SRCS_TEST = Test.cpp TestCounter.cpp
OBJS_TREE = $(SRCS_TREE:.cpp=.o)
OBJS_TEST = $(SRCS_TEST:.cpp=.o)
HEADERS = complex.hpp node.hpp tree.hpp
TEST_HEADERS = doctest.h

.PHONY: all clean tree test

all: tree test

tree: $(OBJS_TREE)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

test: $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lstdc++

%.o: %.cpp $(HEADERS) $(TEST_HEADERS)
	$(CXX) $(CXXFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS_TREE) $(OBJS_TEST) tree test
