#include "Array.h"

Array::Array() : size(0), capacity(1) { data = new unsigned char[capacity]; }

Array::Array(const size_t &n, unsigned char t) : size(n), capacity(n), data(new unsigned char[n]){
    for (size_t i = 0; i < size; ++i) {
        data[i] = t;
    }
}

Array::Array(const std::initializer_list<unsigned char> &t) : size(t.size()), capacity(t.size()) {
    data = new unsigned char[capacity];
    size_t ind = 0;
    for (const unsigned char *i = t.begin(); size_t ind = 0, i != t.end(); ++i, ++ind) {
        data[ind] = *i;
    }
}

Array::Array(const std::string &t) : size(t.length()), capacity(t.length()) {
    data = new unsigned char[capacity];
    size_t ind = 0;
    for (char chr : t) {
        data[ind] = chr;
        ++ind;
    }
}

Array::Array(const Array &other) : size(other.size), capacity(other.capacity) {
    data = new unsigned char[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Array::Array(Array &&other) noexcept : size(other.size), capacity(other.capacity), data(other.data) {
    other.capacity = 0;
    other.size = 0;
    other.data = nullptr;
}

Array::~Array() noexcept {
    delete[] data;
}

void Array::Resize(size_t new_capacity) {
    unsigned char *new_data = new unsigned char[new_capacity];
    size_t copy_size = (size < new_capacity) ? size : new_capacity;
    for (size_t i = 0; i < copy_size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
    if (size > capacity) {
        size = capacity;
    }
}

unsigned char Array::GetItem(size_t i) const {
    if (i >= size) {
        throw std::out_of_range("Wrong index (OoR)");
    }
    return data[i];
}

void Array::PushItem(unsigned char t) {
    if (size == capacity) {
        Resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = t;
}

void Array::PopItem() {
    if (size > 0) {
        --size;
    } else {
        throw std::out_of_range("PopError: array is empty!");
    }
}

size_t Array::GetSize() const { return size; }
