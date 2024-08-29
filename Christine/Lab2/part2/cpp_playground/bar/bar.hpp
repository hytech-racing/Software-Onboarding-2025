#ifndef BAR_HPP
#define BAR_HPP

#include "foo.hpp"


class Bar : public Foo{
public:
    void doSomething() override;
};

#endif 