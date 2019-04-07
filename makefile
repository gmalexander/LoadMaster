HOME_PATH: ${HOME}
BIN_PATH: "-L./bin"

all: Item.o Executor.o Controller.o libload.so

Item.o: libload/Item.cc libload/Item.hh
	g++ -c libload/Item.cc -o bin/Item.o -fpic

Executor.o: libload/Executor.cc libload/Executor.hh
	g++ -c libload/Executor.cc -o bin/Executor.o -fpic

Controller.o: libload/Controller.cc libload/Controller.hh
	g++ -c libload/Controller.cc -o bin/Controller.o -fpic

libload.so: bin/Controller.o bin/Executor.o bin/Item.o
	g++ -shared bin/Controller.o bin/Executor.o bin/Item.o -o libload.so

dist:
	rm bin/*.o

clean:
	rm bin/*

