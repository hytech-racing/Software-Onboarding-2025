#include <iostream>
#include "hello_world.cpp"
#include "../include/hello_world.hpp"
using namespace std;

int main() {
    HelloWorld h;
    h.hello_world();
    return 0;
}