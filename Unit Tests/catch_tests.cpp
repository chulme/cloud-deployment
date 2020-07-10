#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "../function_to_test.h"

TEST_CASE("Increment a positive int")
{
    int test_number = 4;
    increment(test_number);
    CHECK(test_number==5);
}

TEST_CASE("Increment a negative int")
{
    int test_number = -4;
    increment(test_number);
    CHECK(test_number==-3);
}

TEST_CASE("Incrementing a 0-valued int")
{
    int test_number = 0;
    increment(test_number);
    CHECK(test_number==1);
}

TEST_CASE("Incrementing some numbers inside sections")
{
    int test_number;
    SECTION("Incrementing 2")
    {
        test_number = 2;
        increment(test_number);
        CHECK(test_number==3);
    }

    SECTION("Incrementing 5")
    {
        test_number = 5;
        increment(test_number);
        CHECK(test_number==5);
    }
}

int main()
{
    Catch::Session session;
    char*args[5]= {(char*) "Hello World", (char*) "-r", (char*) "junit",
        (char*) "--out", (char*) "test-results.xml"};
    
    int result = session.run(6,args);
    
    return result;
}