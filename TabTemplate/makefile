test: *.o
	g++ -o test *.o

*.o: *.cpp
	g++ -c -g *.cpp

run:
	./test

clean:
	rm -f *.o test

debug:
	gdb test

tar:
	tar -cvf archive.tar makefile *.cpp *.h