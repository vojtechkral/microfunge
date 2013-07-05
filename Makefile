
TARGET = microfunge

CXXSOURCES  = microfunge.cpp
#CXXSOURCES  = microfunge.readable.cpp
CXXOBJECTS = $(CXXSOURCES:.cpp=.o)
CXXASM = $(CXXSOURCES:.cpp=.s)
CXXFLAGS = $(INCLUDEDIRS) -O2 -std=c++11 #-Wall

CXX = g++
RM = rm

all: $(TARGET)

$(TARGET): $(CXXOBJECTS)
	$(CXX) -o ./$@ $(CXXOBJECTS) $(LDFLAGS)

$(CXXOBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) -f $(CXXOBJECTS) $(CXXASM) $(TARGET)

asm: $(CXXASM)

$(CXXASM): %.s: %.cpp
	$(CXX) -S $(CXXFLAGS) -o $@ -c $<
