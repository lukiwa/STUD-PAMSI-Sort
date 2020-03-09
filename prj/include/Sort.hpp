#pragma once
#include <memory>

template <typename T>
class Sort {
   public:
    virtual void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) = 0;

    virtual void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) = 0;

    Sort() = default;
    virtual ~Sort() = default;
};