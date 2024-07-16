#include <iostream>

// int main(){

//     // templates
//     // A template is a mechanism for generic programming to provide a “schema” (or
//     // placeholders) to represent the structure of an entity
//     /*
//     In C++, templates are a compile-time functionality to represent:
//         • A family of functions
//         • A family of classes
//         • A family of variables C++14
// The compiler automatically generates a function implementation for each template
// instantiation
//     */
//     // problem: need a function to handle argument of different data types
//     int add(int a, int b);
//     float add(float a, float b);
//     // and so on...
//     // instead just make it generic like below

//     return 0;
// }

// template<typename T>
// T add(T a, T b){return a+b;};

// int main(){

//     int a = add(1, 2);

//     return 0;
// }

// template parameter and arguments

template<int a, int b> // a,b are template parmeters
int adder(){return a+b;};

int main(){
    int c = adder<1,2>(); // c is computed at compile time....
                        // 1,2 are template arguments
}




