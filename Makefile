CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++2a
BUILD = 7a 7b

.PHONY: all clean

all: $(BUILD)

clean:
	$(RM) $(BUILD)
