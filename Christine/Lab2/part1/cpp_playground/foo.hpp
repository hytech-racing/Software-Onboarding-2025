#ifndef FOO_HPP
#define FOO_HPP

class Foo {
public:
    virtual void doSomething();  // Pure virtual function
    virtual ~Foo() = default;
};

#endif