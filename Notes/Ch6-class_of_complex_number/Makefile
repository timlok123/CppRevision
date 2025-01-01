ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -c -O ComplexNumber.cpp

ComplexMatrix.o: ComplexMatrix.cpp ComplexMatrix.hpp ComplexNumber.hpp
	g++ -c -O ComplexMatrix.cpp

main.o : main.cpp ComplexNumber.hpp ComplexMatrix.hpp
	g++ -c -O main.cpp

main : main.o ComplexNumber.o ComplexMatrix.o
	g++ -O -o main main.o ComplexNumber.o ComplexMatrix.o