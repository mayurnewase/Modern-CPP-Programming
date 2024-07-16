#include <iostream>
#include <algorithm>

int main(){

    // pass by value, pointer, reference

    // void pass_by_value(int a);
    // void pass_by_reference(int& a);
    // void pass_by_pointer(int* a);

    // int a = 1;
    // pass_by_value(a);
    // pass_by_reference(a);
    // pass_by_pointer(&a);

    // function pointers -> used in c
    // c++ has function objects (called functors)
        // Functors are objects that behave like functions.
        // They can have state and can be customized for specific tasks.
        // They are often used in algorithms and higher-order functions that work with functions as arguments.


    // this is a functor
    // struct descending{
    //     bool operator()(int a, int b){
    //         return a > b;
    //     }
    // };
    // int a[] = {1,2,3,4};
    // std::sort(a, a + 4, descending{});
    // std::cout<< a[0] << a[1] << a[2] << a[3];

    // macro side effect
    // TODO: check assembly code to find problem

    #define MIN(a,b) ((a) < (b) ? (a) : (b));
    int array1[] = { 1, 5, 2 };
    int array2[] = { 6, 3, 4 };
    int i = 0;
    int j = 0;
    int k = 0;

    int v1 = MIN(array1[i++], array2[j++]); // v1 = 5 // how the fuck can this happen?
    std::cout << i << j << v1 << "\n";      // 2 1 5

    int v2 = MIN(array1[i++], array2[j++]); // v2 = 0 // why?
    std::cout<<i << j << v2;                // 4 2 0


    return 0;
}