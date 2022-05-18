target:	main.o Circle.o  Employee.o Rectangle.o Shape.o Date.o
	g++ -std=c++17 -o target main.o Circle.o Date.o Employee.o Rectangle.o Shape.o

main.o:main.cpp
	g++ -std=c++17 -c main.cpp
Circle.o:Circle.cpp
	g++ -std=c++17 -c Circle.cpp
Employee.o:Employee.cpp 
	g++ -c Employee.cpp
Rectangle.o:Rectangle.cpp
	g++ -c Rectangle.cpp
Shape.o:Shape.o
	g++ -c Shape.cpp
Date.o:Date.cpp
	g++ -c Date.cpp

clean:
	rm target main.o circle.o  Employee.o Rectangle.o Shape.o Date.o