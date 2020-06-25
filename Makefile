all: dz2

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz2: Array.o Hex.o HexApplication.o Application.o dz2.o
	g++ -o $@ $^

clean:
	dz2 rm *.o

test: all
	cat test_input.txt | ./dz2
