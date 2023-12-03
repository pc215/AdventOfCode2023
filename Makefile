CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++2a
BUILD = 3a 3b

.PHONY: all clean

all: $(BUILD)

clean:
	$(RM) $(BUILD)
