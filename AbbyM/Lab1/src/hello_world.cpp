#include "hello_world.h"
#include <iostream>

HelloWorld::HelloWorld() // constructor definition
{}

void HelloWorld::print() const // print function definition
{
    std::cout << "Hello, World!\n";
};