all: program

program: main.o word.o set.o setManager.o menu.o test.o
	g++ -o program main.o word.o set.o setManager.o menu.o test.o

main.o: main.cpp word.h set.h setManager.h menu.h test.h
	g++ -c main.cpp

word.o: word.cpp word.h
	g++ -c word.cpp

set.o: set.cpp set.h word.h
	g++ -c set.cpp

setManager.o: setManager.cpp setManager.h set.h word.h
	g++ -c setManager.cpp

menu.o: menu.cpp menu.h setManager.h set.h word.h
	g++ -c menu.cpp

test.o: test.cpp test.h setManager.h set.h word.h
	g++ -c test.cpp