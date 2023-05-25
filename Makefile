all:
	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 

storage.o: storage/mathVector.cpp storage/mathVector.h storage/matrix.cpp storage/matrix.h
	g++ -c storage/mathVector.cpp  storage/matrix.cpp

test.o: storage/test.cpp storage/test.h
	g++ -c storage/test.cpp