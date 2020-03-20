#pragma once
#include <math.h>

#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

template <typename T>
class IntroSort : public QuickSort<T> {
    InsertionSort<T> sort;
    MergeSort<T> m_sort;

   private:
    void IntrospectiveSort(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end,
                           std::size_t depth) {
        if (depth == 0) {
            m_sort.SortUp(array, start, end);
        }
        if ((start - end + 1) <= 16) {
            sort.SortUp(array, start, end);
        }
        if (start < end) {
            std::size_t mid = this->Split(array, start, end);
            IntrospectiveSort(array, start, mid, depth - 1);
            IntrospectiveSort(array, mid + 1, end, depth - 1);
        }
    }

   public:
    /**
     * @brief Sortowanie introspektywne - quicksort + mergesort
     *
     * @param array tablica ktora ma byc posortowana
     * @param start poczatek sortowania
     * @param end koniec sortowania
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        std::size_t size = end - start + 1;
        int depth = floor(2 * log(size) / M_LN2);
        IntrospectiveSort(array, start, end, depth);
    }

    IntroSort() = default;
    ~IntroSort() = default;
};