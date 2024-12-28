ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -c -O ComplexNumber.cpp

main.o : main.cpp ComplexNumber.hpp
	g++ -c -O main.cpp

main : main.o ComplexNumber.o 
	g++ -O -o main main.o ComplexNumber.o 