output: main.o function_to_test.o
	g++ main.o function_to_test.o -o output

main.o: main.cpp
	g++ -c main.cpp

function_to_test.o: function_to_test.cpp
	g++ -c function_to_test.cpp

clean:
	rm *.o