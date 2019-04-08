HOME_PATH = ${HOME}
BIN_PATH = "./bin"
YAUTF_URL = "https://github.com/gmalexander/YAUTF"

bin:
	if [ ! -d bin ]; then mkdir bin; fi
	if [ ! -d temp ]; then mkdir temp; fi

yautf:
	if [ ! -d YAUTF ]; then git clone ${YAUTF_URL}; fi
	make -C YAUTF clean
	make -C YAUTF all
	cp YAUTF/bin/libyautf.so bin/libyautf.so
	cp YAUTF/src/*.hh temp
	cp YAUTF/src/*.cc temp

item_test:
    cp libload/item* temp
	g++ temp/item_test.cc -o bin/item_test -L${BIN_PATH} -lyautf

dist:
	rm bin/*.o

clean:
	rm -f bin/*
	rm -f temp/*

