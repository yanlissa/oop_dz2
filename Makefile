all: dz2

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz2: Array.o Hex.o TurboString.o HexApplication.o TurboStringApplication.o Application.o dz2.o
	g++ -o $@ $^

clean:
	rm dz2 *.o

test: all
	cat test_input.txt | ./dz2
