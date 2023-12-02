CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++2a
BUILD = 2a 2b

.PHONY: all clean

all: $(BUILD)

clean:
	$(RM) $(BUILD)
