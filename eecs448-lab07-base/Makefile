#	Author: John Gibbons modified by Alex Bardas
#	Date: 2016.10.26


#Add needed Test.o
prog: Test.o
	g++ -g -Wall -std=c++11 Test.o LinkedListOfInts.o -o prog

Test.o: Test.cpp
	g++ -g -Wall -std=c++11 -c Test.cpp

#Add needed Test.o recipe and compiler command

#DON'T delete LinkedList.o!
clean:
	rm Test.o *.*~ prog
