CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = xmlreader
SRC = main.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) `xml2-config --cflags --libs`

clean:
	rm -f $(TARGET) $(TARGET).exe
