#pragma once
#include <memory>

template <typename T>
class Sort {
   protected:
    virtual bool SortUp(std::tuple<std::size_t, std::unique_ptr<T[]>> tuple) = 0;
    virtual bool SortDown(std::tuple<std::size_t, std::unique_ptr<T[]>> tuple) = 0;

   public:
    Sort() = default;
    ~Sort() = default;
};