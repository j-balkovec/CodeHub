CXX = g++
CXXFLAGS = -std=c++17 -O3

.PHONY: all clean

all: main

main: main.cpp
	@echo "[compiling main.cpp]"
	$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "[compilation complete]"

clean:
	@echo "[cleaning...]"
	rm -f main
	@echo "[cleanup complete]"
