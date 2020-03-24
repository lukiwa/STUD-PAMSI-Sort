#pragma once
#include <math.h>

#include "HeapSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSort.hpp"

template <typename T>
class IntroSort : public QuickSort<T> {
    InsertionSort<T> insert_sort;
    HeapSort<T> heap_sort;

   private:
    void IntrospectiveSort(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end,
                           std::size_t depth) {
        // unikam sortowania krotkich frafmentow rekursywnie
        if ((start - end + 1) <= 16) {
            insert_sort.SortUp(array, start, end);
            return;
        }

        // w pesymstycznych przypadkach glebokosc rekursji moze byc bardzo duza - spowolnic
        // sortowanie
        if (depth == 0) {
            heap_sort.SortUp(array, start, end);
            return;
        }

        if (start < end) {
            std::size_t mid = this->Split(array, start, end);
            IntrospectiveSort(array, start, mid, depth - 1);
            IntrospectiveSort(array, mid + 1, end, depth - 1);
        }
    }

   public:
    /**
     * @brief Sortowanie introspektywne - quicksort + heapsort
     *
     * @param array tablica ktora ma byc posortowana
     * @param start poczatek sortowania
     * @param end koniec sortowania
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        std::size_t size = end - start + 1;  // ilosc danych wejsciowych
        int depth = 2 * log(size);           // obliczenie maksymalnej glebokosci rekursji
        IntrospectiveSort(array, start, end, depth);
        //  insert_sort.SortUp(array, start, end);
    }

    /**
     * @brief Sortowanie malejace - niezaimplementowane, poniewaz nie bedzie wykorzystywane
     *
     */
    void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        UNUSED(array);
        UNUSED(start);
        UNUSED(end);
        throw NotIomplementedException();
    }

    IntroSort() = default;
    ~IntroSort() = default;
};