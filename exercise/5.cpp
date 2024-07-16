#include<iostream>
#include <limits>


// defined globally so will be in data and bss segment
// if defined inside function, will be pushed to stack with base pointer
// so will become local variables

// int data[] = {1, 2}; // DATA segment memory
// int big_data[1000000] = {}; // BSS segment memory

// int main(){
    // int A[] = {1, 2, 3}; // stored in stack memory    
    // return 0;
// }


// stack and heap memory access pattern

// int *f(){
//     // int array[3] = {1,2,3}; // this is pushed on rbp, which is on stack
//     // return array; // and this array is destroyed when function returns, so caller can't access its elements.

//     // so if caller want to acces it outside this function, dynamically allocate it on heap memory
//     int* array = new int[3];
//     array[0] = 10;
//     array[1] = 20;
//     array[2] = 30;
//     return array;
// }

// int main(){
//     int* s = f();
//     std::cout << s[0];

//     return 0;
// }


// Heap memory : new and delete keyword
//are C++ keywords that perform dynamic
// memory allocation/deallocation, and object construction/destruction at runtime

// malloc and free are C functions and they only allocate and free memory blocks

// int main(){
// // allocate single element
// int* value = new int;

// // allocate N elements
// int* value_n = new int[3];

// // deallocate single element
// delete value;

// // deallocate N elements
// delete[] value_n;


// return 0;
// }


// 2D memory allocation

// int main(){
    // on stack:if dimenstions known at compile time
    // int a[2][3];

    // // dynamic allocation: dimenstions known at run time
    // int** b = new int*[2];
    // for (int i=0; i<3; i++){
    //     b[i] = new int[4];
    // }

    // or
    // auto d = new int[2][3]; // allocates 2 objects of type int[3]

    // int dimension = 2;
    // auto c = new int[dimension][3];     // works
    // delete[] c;

    // auto c=  new int[2][dimension] // doesn't work, compiler error

    // ways for dynamic memory allocations
    //  int* a1 = new int; //undefined
    // int* a2 = new int(); // zero-initialization, call "= int()"
    // int* a3 = new int(4); // allocate a single value equal to 4
    // int* a4 = new int[4]; // allocate 4 elements with undefined values
    // int* a5 = new int[4](); // allocate 4 elements zero-initialized, call "= int()"


    // TODO: study non allocating and non deallocating section again later


    // memory leak: dynamically allocated entity in the heap memory that is
// no longer used by the program, but still maintained overall its execution

    // int* a = new int[10];
    // a = nullptr; // now a cannot be deallocated


    //----------------------------------------
    // pointers and references

    // A pointer T* is a value referring to a location in memory
    
    // Pointer dereferencing (*ptr) means obtaining the value stored in at the location
    // referred to the pointer

    // The subscript operator (ptr[]) allows accessing to the pointer element at a given
    // position

    // pointer dereferencing
    // int * a = new int;
    // *a = 10;
    // int b = *a;


    // pointer arithmatic

    // subscript meaning ptr[i] = *(ptr + i)
    // int* a = new int[3];
    // a[0] = 1;
    // a[1] = 2;
    // a[2] = 3;
    // std::cout << a[1] << *(a + 1) << *a; // 2 2 1

    // address-of operator (&): returns the address of a variable
    // int a = 2;
    // int* b = &a;
    // std::cout<<b << " " << &a <<"\n";
    // a++;
    // std::cout << b <<" " << *b;


    // dangling pointer
    // int* a = new int[5];
    // delete[] a; // works -> but a is not dangling pointer
    // a = nullptr; // so do this, no more dangling pointer

    // void pointer
    // its generic pointer, Instead of declaring different types of pointer variable it is possible to declare single
// pointer variable which can act as any pointer types
    // void* can be compared
    // Any pointer type can be implicitly converted to void*
    // Other operations are unsafe because the compiler does not know what kind of object
// is really pointed to

    // int array[3] = {1,2,3};
    // void* ptr = array;

    // // std::cout << *ptr <<" " << ptr[0]<< " " <<ptr[1]; //fails as compiler doesn't know what is it pointing at
    // std::cout<<*array << " " << array[0];

    //-----------------------------------------------
    // Reference
    // A variable reference T& is an alias, namely another name for an already existing
// variable. Both variable and variable reference can be applied to refer the value of the
// variable
    // compiler uses lea instruction for storing the address in rbp, instead of actual values

    // int a = 2;
    // // // int d= a; // 
    // int& b = a;
    // int& c = b;
    // so now if c or b changes, a will also change

    // references with pointers
    // int a = 1;
    // int* b = &a; //pointer
    // int* c = &a; //pointer
    // b++;        //// change the value of the pointer 'b'
    // *c++; // // change the value of 'a' (a = 4)
// }


// function args as reference and pointers
void pointer_f(int* val){}
void reference_f(int& val){}
    
int main(){
    // int a = 3;

    // //TODO: check assembly for this
    // pointer_f(&a); // ok
    // pointer_f(0); // dangerous but works
    // // pointer_f(a); // error

    // reference_f(a); //ok
    // // reference_f(3); //error
    // // reference_f(&a); // error


    //----------------------------------
    // struct access
    // • The dot (.) operator is applied to local objects and references
    // • The arrow operator (->) is used with a pointer to an object

    // struct A{
    //     int x;
    // };
    // A a;
    
    // a.x = 10;   // dot syntax

    // A& ref_a = a;   // reference
    // ref_a.x = 10;   // dot syntax

    // A* ptr_a = &a;  // pointer
    // ptr_a -> x = 10;    // arrow

    //----------------------------------
    // constexpr keyword
    // tells compiler to evaluate value at compile time

    // const int v1 = 3;
    // const int v2 = v1 * 2;// compile-time evaluation
    // // compile-time evaluation
    // int
    // a = 3;
    // const int v3 = a;// "a" is dynamic
    // // run-time evaluation!!
    // constexpr int c1 = v1;
    // // ok
    // // constexpr int c2 = v3; // compile error, "v3" is dynamic

//--------------------------------------
    // volatile keyword
    // is a hint to the compiler to avoid aggressive memory optimizations
// involving a pointer or an object
// The following code compiled with -O3 (full optimization) and without volatile
// works fine

    // volatile int* ptr = new int[1];
    // int pos = 128 * 1024 / 4;
    // ptr[pos] = 20;

// -----------------------------------
// type conversions (casting)

    /*
    Old style cast: (type) value
New style cast:
• static cast performs compile-time (not run-time) type check. This is the safest
cast as it prevents accidental/unsafe conversions between types
• const cast can add or cast away (remove) constness or volatility
• reinterpret cast
reinterpret cast<T*>(v) equal to (T*) v
reinterpret cast<T&>(v) equal to *((T*) &v)
const cast and reinterpret cast do not compile to any CPU instruction
    */

    char a[] = {1, 2, 3, 4};
    int* b= (int*) a;       // works
    std::cout << b[0];  // print 67305985 not 1!!
//int* c = static_cast<int*>(a); // compile error unsafe conversion

    


    return 0;
}





























