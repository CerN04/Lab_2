#pragma once

#include <cstddef>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <system_error>

class Array {
private:
    size_t size;
    unsigned char *data;
    size_t capacity;

public:
    Array();
    Array(const size_t &n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char> &t);
    Array(const std::string &t);

    Array(const Array &other);
    Array(Array &&other) noexcept;
    ~Array() noexcept;

    void Resize(size_t new_size);
    unsigned char GetItem(size_t i) const;
    void PushItem(unsigned char t);
    void PopItem();
    size_t GetSize() const;
};