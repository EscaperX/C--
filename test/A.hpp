#include <memory>

struct A {
    struct Impl;
    A();
    ~A();
    auto work() const -> void;
private:
    std::unique_ptr<Impl> impl;
};