#include <iostream>
#include "bar.hpp"


int main()
{
    std::cout << "Hello World!" << std::endl;
    Bar bar;
    bar.doSomething();  // Uses Bar's implementation of Foo
    return 0;
}