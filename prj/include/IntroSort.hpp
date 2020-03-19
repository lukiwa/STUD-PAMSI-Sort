#pragma once
#include "MergeSort.hpp"
#include "QuickSort.hpp"

template <typename T>
class IntroSort : public QuickSort<T> {
    MergeSort<T> sort;

   public:
    /**
     * @brief Sortowanie introspektywne - quicksort + mergesort
     *
     * @param array tablica ktora ma byc posortowana
     * @param start poczatek sortowania
     * @param end koniec sortowania
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        if (end <= 15) {
            sort.SortUp(array, start, end);
            return;
        }
        if (start < end) {
            std::size_t mid = this->Split(array, start, end);
            SortUp(array, start, mid);
            SortUp(array, mid + 1, end);
        }
    }

    IntroSort() = default;
    ~IntroSort() = default;
};