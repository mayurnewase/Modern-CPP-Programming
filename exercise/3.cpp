#include<iostream>
#include <limits>

int main(){

    // interger overflow
    // unsigned int a = 2147483648;
    // unsigned int b = 2147483648;
    // int a = 10;
    // int b = 20;
    // int c = (a+b)/2;
    // std::cout<<c;


    // query max and min values
    // int d = std::numeric_limits<float>::max();
    // std::cout<<d;

    // compiler optimizer make this infinite loop
    // no it didnt, it used imul instruction with rax register correctly.
    // for(int i=0; i < 4 ; ++i){
    //     std::cout<<i*1000000000000000000<<"\n";
    // }

    // Floating point arithmetic is not associative
    // std::cout << (0.1 + (0.2 + 0.3) == 0.1 + 0.2+0.3); // this prints 0

    // this loop does not terminalte due to catastrophic cancellation problem
    // float x = 200000;
    // float y = 0.001;
    // while (x > 0) {x = x - y;}

// gives wrong value of x 
// float x = 0.0f;
// for (int i = 0; i < 20000000; i++)
// x += 1.0f;
// std::cout<<x;

// enumerators (enums)
// An enumerator enum is a data type that groups a set of named integral constants

// enum color_t {BLACK, BLUE};     // compiler doesnt put anythign in assembly for this, just remembers the index of values and replaces that below with it
// enum fruit_t {APPLE, CHERRY};
// // char c[] = "BLACK";  // in asssembly this is 1 big number, what is that? address or hex for the string
// color_t color = BLACK;      // compiler just pushes 0
// color_t color_2 = BLUE;// compiler just pushes 1
// fruit_t fruit = APPLE;
// std::cout<<color; // prints 0
// so fruit == color will equal lol..


// struct
//A struct (structure) aggregates different variables into a single unit
// struct A {
//     int x;
//     char y;
// };

// // struct with its instance outside
// struct B{
//     int x;
// } b;
// std::cout<<b.x;


// bitfield
// A bitfield is a variable of a structure with a predefined bit width. A bitfield can hold
// bits instead bytes
// used in a struct

struct A{
    int b1: 10; // range [0, 1023] // 2^10
    int b2: 1; // range [0, 1]
};
std::cout<<sizeof(A);

A a;
a.b1 = 123;
a.b2 = 0;
a.b2 = 1;
a.b2 = 2; // code runs but compiler gives warning
// a.b2 = 3;






    return 0;
}

