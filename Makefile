CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++2a
BUILD = 5a 5b

.PHONY: all clean

all: $(BUILD)

clean:
	$(RM) $(BUILD)
