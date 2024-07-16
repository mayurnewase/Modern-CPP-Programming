/*
Compile C++11, C++14, C++17, C++20 programs:
g++ -std=c++14 <program.cpp> -o program
g++ -std=c++11 <program.cpp> -o program

Any C++ standard is backward compatible
C++ is also backward compatible with C (even for very old code) except if it contains
C++ keywords (new, template, class, typename, etc.)
We can potentially compile a pure C program in C++20
*/

#include <iostream>
#include<iostream>

int main(){
        int *p1 = NULL;
    int *p2 = nullptr;
    // int p3 = NULL;
    // int p4 = nullptr;

    float f = 3.0f;
    int i  = 2;
    float r = 5/2; // r = 2
    float rr = 5.0 / 2;  // rr = 2.5
    // std::cout<<r<<"\n";

    // char is converted to int implicitly
    char a = 48;
    // std::cout << a;

    // auto dtype => compiler figures out the type of variable
    auto ab = 1+2;
    std::cout<<ab;

    return r;
}



































