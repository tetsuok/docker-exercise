CXX = clang++
CXXFLAGS = -Wall -g -O2 -isystem $(GTEST_DIR)/include
LDFLAGS = $(GTEST_DIR)/gtest_main.a

TESTS = \
	addtest

all: check

check: $(TESTS)

addtest: addtest.cc
	$(CXX) $(CXXFLAGS) -pthread $< $(LDFLAGS) -o $@

clean:
	rm -f $(TESTS)
