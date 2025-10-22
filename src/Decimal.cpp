#include "Decimal.h"


Decimal::Decimal() : spis() {};

Decimal::Decimal(const size_t &n, unsigned char t) {
    if (t < '0' || t > '9') {
        throw std::out_of_range("Only 0 - 9 numbers");
    }
    for (size_t i = 0; i < n; ++i) {
        spis.PushItem(t);
    }
}

Decimal::Decimal(const std::initializer_list<unsigned char> &t) {
    size_t ind = 0;
    for (const unsigned char *i = t.begin(); i != t.end(); ++i) {
        if (*i < '0' || *i > '9') {
            throw std::out_of_range("Only 0 - 9 numbers");
        }
        spis.PushItem(*i);
        ++ind;
    }
}

Decimal::Decimal(const std::string &t) {
    size_t ind = 0;
    if (t.empty()) {
        throw std::invalid_argument("String is empty!");
    }
    size_t start = 0;
    while (start < t.length() && t[start] == '0') {
        ++start;
    }
    if (start == t.length()) {
        spis.PushItem('0');
    }
    for (size_t i = t.length(); i > start; --i) {
        if (t[i - 1] < '0' || t[i - 1] > '9') {
            throw std::out_of_range("Only 0 - 9 numbers");
        }
        spis.PushItem(t[i - 1]);
        ++ind;
    }
}

Decimal::Decimal(const Decimal &other) : spis(other.spis) {}

Decimal::Decimal(Decimal &&other) noexcept : spis(std::move(other.spis)) {}

size_t Decimal::GetSize() const { return spis.GetSize(); }

unsigned char Decimal::GetItem(size_t i) const {
    if (i >= spis.GetSize()) {
        throw std::out_of_range("Wrong index (OoR)");
    }
    return spis.GetItem(i);
}

void Decimal::Print() {
    for (size_t i = GetSize(); i > 0; --i) {
        std::cout << GetItem(i - 1);
    }
    std::cout << std::endl;
}

void Decimal::Reserve(size_t n) {
    spis.Reserve(n);
}

Decimal Decimal::Add(const Decimal &num) const {
    Decimal temp;
    size_t sp_size = spis.GetSize(), nm_size = num.GetSize();
    size_t cnt = (sp_size > nm_size) ? sp_size : nm_size;
    int a, b, sm = 0, rest = 0;
    for (size_t i = 0; i < cnt; ++i) {
        if (i < sp_size) {
            a = spis.GetItem(i) - '0';
        } else {
            a = 0;
        }
        if (i < nm_size) {
            b = num.GetItem(i) - '0';
        } else {
            b = 0;
        }
        sm = a + b + rest;
        rest = sm / 10;
        temp.spis.PushItem(static_cast<unsigned char>(sm % 10) + '0');
    }
    if (rest > 0) {
        temp.spis.PushItem(static_cast<unsigned char>(rest) + '0');
    }
    return temp;
}

Decimal Decimal::Sub(const Decimal &num) const {
    if (Less(num)) {
        throw std::logic_error("Negative result");
    }
    Decimal temp;
    size_t sp_size = spis.GetSize(), nm_size = num.GetSize();
    size_t cnt = (sp_size > nm_size) ? sp_size : nm_size;
    int a, b, sb = 0, rest = 0;
    for (size_t i = 0; i < cnt; ++i) {
        if (i < sp_size) {
            a = spis.GetItem(i) - '0';
        } else {
            a = 0;
        }
        if (i < nm_size) {
            b = num.GetItem(i) - '0';
        } else {
            b = 0;
        }
        int curr_diff = a - b - rest;
        sb = (curr_diff < 0) ? (curr_diff + 10) : curr_diff;
        rest = (curr_diff < 0) ? 1 : 0;
        temp.spis.PushItem(static_cast<unsigned char>(sb) + '0');
    }
    while (temp.GetSize() > 1 && temp.GetItem(temp.GetSize() - 1) == '0') {
        temp.spis.PopItem();
    }
    return temp;
}

bool Decimal::More(const Decimal &num) const {
    if (spis.GetSize() > num.GetSize()) {
        return true;
    } else if (spis.GetSize() < num.GetSize()) {
        return false;
    }
    for (size_t i = spis.GetSize(); i > 0; --i) {
        if (spis.GetItem(i - 1) > num.GetItem(i - 1)) {
            return true;
        } else if (spis.GetItem(i - 1) < num.GetItem(i - 1)) {
            return false;
        }
    }
    return false;
}

bool Decimal::Equal(const Decimal &num) const {
    if (spis.GetSize() != num.GetSize()) {
        return false;
    }
    for (size_t i = spis.GetSize(); i > 0; --i) {
        if (spis.GetItem(i - 1) != num.GetItem(i - 1)) {
            return false;
        }
    }
    return true;
}

bool Decimal::Less(const Decimal &num) const {
    if (spis.GetSize() < num.GetSize()) {
        return true;
    } else if (spis.GetSize() > num.GetSize()) {
        return false;
    }
    for (size_t i = spis.GetSize(); i > 0; --i) {
        if (spis.GetItem(i - 1) < num.GetItem(i - 1)) {
            return true;
        } else if (spis.GetItem(i - 1) > num.GetItem(i - 1)) {
            return false;
        }
    }
    return false;
}
