#pragma once
#include <memory>

template <typename T>
class Sort {
   public:
    virtual void SortUp(std::unique_ptr<T[]>& array, int start, int end) = 0;

    // virtual bool SortDown(std::unique_ptr<T[]> array, std::size_t size,
    //                      double sorting_length = 1) = 0;

    Sort() = default;
    virtual ~Sort() = default;
};