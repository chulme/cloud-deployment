output: main.o functions_to_test.o
    g++ main.o functions_to_test.o -o output

main.o: main.cpp
    g++ -c main.cpp

functions_to_test.o: functions_to_test.cpp
    g++ -c functions_to_test.cpp

clean:
    rm *.o *.exe