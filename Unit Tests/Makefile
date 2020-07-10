output: catch_tests.o function_to_test.o
	g++ catch_tests.o function_to_test.o -o output

catch_tests.o: catch_tests.cpp
	g++ -c catch_tests.cpp
    
function_to_test.o: ../function_to_test.cpp ../function_to_test.h
	g++ -c ../function_to_test.cpp

clean:
	rm *.o *.exe