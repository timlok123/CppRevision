# Declare the variables
CXX = mpic++
CXXFLAGS = -O3 

all: MpiHelloWorld SeriesSummation

MpiHelloWorld: 
	$(CXX) $(CXXFLAGS) -o MpiHelloWorld MpiHelloWorld.cpp

SeriesSummation:
	$(CXX) $(CXXFLAGS) -o SeriesSummation SeriesSummation.cpp

clean:
	rm -f MpiHelloWorld SeriesSummation

.PHONY: clean all

