HOME_PATH: ${HOME}
BIN_PATH: "\./bin"
YAUTF_URL: "https\://github\.com/gmalexander/YAUTF"

bin:
	if [ ! -d bin ]; then mkdir bin; fi

yautf:
	if [ ! -d YAUTF ]; then git clone $(YAUTF_URL); fi
	make -C YAUTF clean
	make -C YAUTF all
	cp YAUTF/bin/libyautf.so bin/libyautf.so

item_test:
	g++ libload/item_test.cc -o item_test -L$(BIN_PATH) -lyautf

dist:
	rm bin/*.o

clean:
	rm bin/*

