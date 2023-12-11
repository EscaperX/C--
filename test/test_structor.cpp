#include <cstdio>
#include <iostream>

class A
{
public:
    A()
    {
        puts(__PRETTY_FUNCTION__);
    }
    ~A()
    {
    }
};

int main()
{
    A a;
}