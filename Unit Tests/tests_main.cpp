#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "tests.h"

int main()
{
    Catch::Session session;
    char*args[6]= {(char*) "Hello World", (char*) "-r", (char*) "junit",
        (char*) "--out", (char*) "test-results.xml", (char*) "--sucesss"};
    
    int result = session.run(6,args);
    
    return result;
}