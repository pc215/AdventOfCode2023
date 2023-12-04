CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++2a
BUILD = 4a 4b

.PHONY: all clean

all: $(BUILD)

clean:
	$(RM) $(BUILD)
