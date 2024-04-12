# Getting the Address of a Variable.
Every variable is allocated a section of memory large enough to hold a value of the variable's data type. On a PC, for instance, it's common for **1 byte to be allocated for chars**, **2 bytes for shorts**, **4 bytes for ints, longs, and floats**, and **8 bytes for doubles**.

Each byte of memory has a unique address. A ***variable's address is the address of the first byte allocated to that variable.***

## Getting the address of a variable:
Getting the address of a variable is accomplished with `&` operator in C++.

When the address operator (&) is placed in front of a variable name, it returns the address of that variable. Here is an expression that returns the address of the variable amount:
`&amount`

And here is a statement that displays the variable's address on the screen:
`std::cout << &amount`


## Pointer Variables
CONCEPT: Pointer variables, which are often just called pointers, are designed to hold memory addresses. With pointer variables, you can indirectly manipulate data stored in other variables.

A **pointer variable**, which often is just called a pointer, is a special variable that **holds a memory address**. Just as int variables are designed to hold integers, and double variables are designed to hold floating-point numbers, pointer variables are designed to hold memory addresses.

`int *ptr;`
The ***asterisk in front of the variable name indicates that pt r is a pointer variable.*** 


The int data type indicates that pt r can be used to hold the address of an integer variable. The definition statement above would read "ptr is a pointer to an int."



