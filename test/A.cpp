#include "A.hpp"
#include <iostream>


A::A():impl(std::make_unique<Impl>()) {}
A::~A() {}

struct A::Impl {
    int x = 1;
    void work() {
        x = 2;
        std::cout << x;
        delete this;
    }
};

auto A::work() const -> void {
    impl->work();
}