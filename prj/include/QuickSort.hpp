#pragma once
#include "Sort.hpp"

template <typename T>
class QuickSort : public Sort<T> {
   public:

   /**
    * @brief Sortowanie szybkie 
    * 
    * @param array tablica ktora ma byc posortowana
    * @param start poczatek sortowania
    * @param end koniec sortowania
    */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        std::size_t i = start;
        std::size_t j = end;
        T pivot = array[(start + end) / 2];

        do {
            while (array[i] < pivot) {
                ++i;
            }
            while (array[j] > pivot) {
                --j;
            }
            if (i <= j) {
                std::swap(array[i], array[j]);
                ++i;
                --j;
            }

        } while (i <= j);

        if (start < j) {
            SortUp(array, start, j);
        }
        if (end > i) {
            SortUp(array, i, end);
        }
    }

    void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        UNUSED(array);
        UNUSED(start);
        UNUSED(end);
        throw "Not Implemented";
    }

    QuickSort() = default;
    ~QuickSort() = default;
};