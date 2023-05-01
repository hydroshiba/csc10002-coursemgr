#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

template <typename Type>
class Vector {
private:
    size_t length = 0;
    size_t capacity = 1;
    Type* array = nullptr;

    void reallocate(size_t newCapacity) {
        while (capacity < newCapacity) capacity *= 2;
        Type* temp = new Type[capacity]();

        for (size_t i = 0; i < length; ++i)
            temp[i] = array[i];

        if (array) delete[] array;
        array = temp;
    }

public:
    Vector() : length{ 0 }, capacity{ 1 }, array{ new Type[1]() } {}

    Vector(size_t size) {
        length = size;
        capacity = size;
        array = new Type[size]();
    }

    Vector(const Vector<Type>& vec) {
        resize(vec.size());

        for (int i = 0; i < length; ++i)
            array[i] = vec[i];
    }

    size_t size() const {
        return length;
    }

    Type& operator[](size_t pos) const {
        assert(("Out of bound access!", pos < length));
        return array[pos];
    }

    void operator=(const Vector<Type>& vec) {
        resize(vec.size());

        for (int i = 0; i < length; ++i)
            array[i] = vec[i];
    }

    Type* begin() {
        return array;
    }

    Type* end() {
        return array + length;
    }

    void resize(size_t size) {
        if (size > capacity) reallocate(size);
        else if (size > length) {
            Type* init = new Type();

            for (size_t i = length; i < size; ++i)
                array[i] = *init;

            delete init;
        }

        length = size;
    }

    void append(const Type& value) {
        if (length == capacity) reallocate(length + 1);
        array[length] = value;
        ++length;
    }

    void remove(const Type& value, int amount = -1) {
        size_t cur = 0;

        for (size_t i = 0; i < length; ++i) {
            if (amount && array[i] == value) {
                --amount;
                continue;
            }

            array[cur] = array[i];
            array[i].~Type();
            ++cur;
        }

        resize(cur);
    }

    void remove(Type* const ptr) {
        if (ptr - begin() < 0) return;
        if (ptr - begin() >= length) return;

        size_t pos = ptr - begin();
        for (size_t i = pos; i < length - 1; ++i) {
            array[i] = array[i + 1];
        }

        resize(length - 1);
    }

    Type* find(const Type& value) {
        for (size_t i = 0; i < length; ++i)
            if (value == array[i]) return (array + i);

        return nullptr;
    }

    ~Vector() {
        delete[] array;
        array = nullptr;
        length = 0;
        capacity = 1;
    }
};

#endif