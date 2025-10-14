#pragma once

#include "Array.h"
#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <stdexcept>
#include <string>

class Decimal {
private:
    Array spis;

public:
    Decimal();
    Decimal(const size_t &n, unsigned char t = 0);
    Decimal(const std::initializer_list<unsigned char> &t);
    Decimal(const std::string &t);
    Decimal(const Decimal &other);
    Decimal(Decimal &&other) noexcept;

    void Print();
    unsigned char GetItem(size_t i) const;
    size_t GetSize() const;

    Decimal Add(const Decimal &num) const;
    Decimal Sub(const Decimal &num) const;
    bool More(const Decimal &num) const;
    bool Equal(const Decimal &num) const;
    bool Less(const Decimal &num) const;
};