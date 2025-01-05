#include <catch2/catch_test_macros.hpp>
#include "Array.h"
#include "List.h"
#include "Singleton.h"

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

TEST_CASE( "Array tests", "[Array]" ) {
    My::Array a = {1, 4, 9, 16, 25};

    REQUIRE(a.size() == 5);

    for_each(a.begin(), a.end(), [](int&x){return x = sqrt(x);});

    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
    REQUIRE(a[3] == 4);
    REQUIRE(a[4] == 5);
    
    My::Array<int> b;
    b = a;

    REQUIRE(a.size() == 5);
    REQUIRE(a[0] == 1);
    REQUIRE(a[1] == 2);
    REQUIRE(a[2] == 3);
    REQUIRE(a[3] == 4);
    REQUIRE(a[4] == 5);

    My::Array<int> c = b;

    REQUIRE(c.size() == 5);
    REQUIRE(c[0] == 1);
    REQUIRE(c[1] == 2);
    REQUIRE(c[2] == 3);
    REQUIRE(c[3] == 4);
    REQUIRE(c[4] == 5);

    My::Array d = move(c);

    REQUIRE(c.size() == 0);
    REQUIRE(d.size() == 5);
    REQUIRE(d[0] == 1);
    REQUIRE(d[1] == 2);
    REQUIRE(d[2] == 3);
    REQUIRE(d[3] == 4);
    REQUIRE(d[4] == 5);
}

TEST_CASE( "Singleton", "[Singleton]" ) {
    
    stringstream buffer1;
    streambuf *oldcout = std::cout.rdbuf(buffer1.rdbuf());

    My::Singleton::sayHello();
    std::string result1 = buffer1.str();
    
    stringstream buffer2;
    std::cout.rdbuf(buffer2.rdbuf());


    My::Singleton::sayHello();

    std::string result2 = buffer2.str();


    REQUIRE(result1 == result2);
    std::cout.rdbuf(oldcout);
}

TEST_CASE( "List", "[List]" ) {
    My::List<int> list = {1, 2, 3, 4, 5};

    REQUIRE(list.size() == 5);
    REQUIRE(list[0] == 1);
    REQUIRE(list[1] == 2);
    REQUIRE(list[2] == 3);
    REQUIRE(list[3] == 4);
    REQUIRE(list[4] == 5);

    list.append(6);
    list.append(7);

    REQUIRE(list[5] == 6);
    REQUIRE(list[6] == 7);

    vector<int> v = {1,2,3,4,5,6,7};
    
    REQUIRE(v == list.getList());


    list.clear();

    REQUIRE(list.size() == 0);
}