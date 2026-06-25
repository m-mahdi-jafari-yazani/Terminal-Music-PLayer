CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDLIBS = -lpthread -ldl -lm

SRCS = $(wildcard *.cpp)
TARGET = MusicPlayer

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)

clean:
	rm -f $(TARGET)