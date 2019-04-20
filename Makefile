#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed Test.o
prog: main.o Test.o
	g++ -g -Wall -std=c++11 main.o LinkedListOfInts.o Test.o -o prog


main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp


Test.o: Test.h Test.cpp
	g++ -g -Wall -std=c++11 -c Test.cpp


#DON'T delete LinkedList.o!f
clean:
	rm main.o *.*~ prog
