#pragma once
#include "Sort.hpp"

template <typename T>
class QuickSort : public Sort<T> {
   private:
    int Split(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) {
        T pivot = array[(start + end) / 2];  // pivot wybrany jako srodek tablicy
        std::size_t i = start, j = end;
        while (true) {
            while (array[j] > pivot) {
                j--;
            }
            while (array[i] < pivot) {
                i++;
            }
            if (i < j) {
                std::swap(array[i], array[j]);
                i++;
                j--;
            } else {
                return j;
            }
        }
    }

   public:
    /**
     * @brief Sortowanie szybkie
     *
     * @param array tablica ktora ma byc posortowana
     * @param start poczatek sortowania
     * @param end koniec sortowania
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        if (start < end) {
            std::size_t mid = Split(array, start, end);
            SortUp(array, start, mid);
            SortUp(array, mid + 1, end);
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