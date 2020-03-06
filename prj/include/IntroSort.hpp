#pragma once
#include "Sort.hpp"

template <typename T>
class IntroSort /*: public Sort<T>*/ {
   public:
    // void SortUp(std::unique_ptr<T[]>& array, int start, int end) override { return false; }

    // bool SortDown(std::unique_ptr<T[]> array, std::size_t size,
    //             double sorting_length = 1) override {}

    IntroSort() = default;
    ~IntroSort() = default;
};