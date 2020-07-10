#include "function_to_test.h"
#include <iostream>

int main(){
    int var=2;
    std::cout<<"The var's value was" << var << ".\n";
    increment(var);
    std::cout<<"The var's value now is" << var << ".\n";
    return 0;
}