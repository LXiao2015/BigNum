all:
	g++ -std=c++14 -I./ test/test.cpp test/BigNumTest.cpp src/bigNum.cpp -L/usr/local/lib -lcppunit -o bign

clean:
	rm *.o
	rm bign
