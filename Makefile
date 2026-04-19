CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = xmlreader
SRC = main.cpp

all:
  $(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) -I/usr/include/libxml2 -lxml2

clean:
	del /Q $(TARGET).exe 2>nul || rm -f $(TARGET)
