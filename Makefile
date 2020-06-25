all: dz2 dz3

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz2: Array.o Hex.o HexApplication.o Application.o dz2.o
	g++ -o $@ $^

clean:
	rm dz2 dz3 *.o

test: all
	cat test_input.txt | ./dz2
	./dz3

dz3: TurboString.o dz3.o
	g++ -o $@ $^
