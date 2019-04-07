HOME_PATH: ${HOME}
BIN_PATH: "-L./bin"
YAUTF_URL: "https://github.com/gmalexander/YAUTF"

bin:
	if [ ! -d bin ]; then mkdir bin; fi

yautf:	bin
	if [ ! -d YAUTF ]; then git clone $(YAUTF_URL); fi
	make -C YAUTF clean
	make -C YAUTF all
	cp YAUTF/bin/libyautf.so bin/libyautf.so

dist:
	rm bin/*.o

clean:
	rm bin/*

