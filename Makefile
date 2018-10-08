all:
	g++ -std=c++14 bigNum.cpp -o bign

clean:
	rm *.o
	rm bign
