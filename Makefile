all: dz3

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

dz3: TurboString.o dz3.o
	g++ -o $@ $^

clean:
	dz3 rm *.o

test: all
	./dz3
