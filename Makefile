
TARGET = microfunge
TARGET_RUST = microfunge-rust

CXXSOURCES  = microfunge.cpp
#CXXSOURCES  = microfunge.readable.cpp
CXXOBJECTS = $(CXXSOURCES:.cpp=.o)
CXXASM = $(CXXSOURCES:.cpp=.s)
CXXFLAGS = $(INCLUDEDIRS) -O2 -std=c++11 #-Wall
RUSTSOURCES = microfunge.rust.rs
#RUSTSOURCES = microfunge.rust.readable.rs

CXX = g++
RM = rm
RUST = rustc

all: $(TARGET) $(TARGET_RUST)

$(TARGET): $(CXXOBJECTS)
	$(CXX) -o ./$@ $(CXXOBJECTS) $(LDFLAGS)

$(CXXOBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(TARGET_RUST): $(RUSTSOURCES)
	$(RUST) -o ./$@ $(RUSTSOURCES)

clean:
	$(RM) -f $(CXXOBJECTS) $(CXXASM) $(TARGET) $(TARGET_RUST)

asm: $(CXXASM)

$(CXXASM): %.s: %.cpp
	$(CXX) -S $(CXXFLAGS) -o $@ -c $<
