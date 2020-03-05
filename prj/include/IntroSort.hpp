#pragma once
#include "Sort.hpp"

template <typename T>
class IntroSort : public Sort<T> {
    using typename Sort<T>::ArrayWithSize;

   public:
    virtual bool SortUp(ArrayWithSize& tuple, double sorting_length = 1) override {
        // TODO
        return false;
    }
    virtual bool SortDown(ArrayWithSize& tuple, double sorting_length = 1) override {
        // TODO
        return false;
    }
    IntroSort() = default;
    ~IntroSort() = default;
};