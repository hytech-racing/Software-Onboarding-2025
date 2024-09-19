#include <iostream>
#include <hellolib.hpp>

using namespace std;

int main()
{
    cout << "Hello World!" << std::endl;
    HelloLib hllib;
    hllib.doSomething();  // Uses Bar's implementation of Foo
    return 0;
}