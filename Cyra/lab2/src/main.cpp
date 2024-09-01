#include "helloLib.cpp"
#include <iostream>

int main() {
    TestLib lib;
    std::cout << lib.hello() << std::endl;
    return 0;
}