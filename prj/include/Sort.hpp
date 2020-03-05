#pragma once
#include <memory>

template <typename T>
class Sort {
   public:
    using ArrayWithSize = std::tuple<std::size_t, std::unique_ptr<T[]>>;

    virtual bool SortUp(ArrayWithSize& tuple, double sorting_length = 1) = 0;
    virtual bool SortDown(ArrayWithSize& tuple, double sorting_length = 1) = 0;

    Sort() = default;
    virtual ~Sort() = default;
};