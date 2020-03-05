#pragma once
#include <iostream>
#include <memory>
#include "IntroSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

enum class SortingAlgorithm { QUICKSORT, MERGESORT, INTROSORT };

template <typename T>
class ManageSorting {
   private:
    std::unique_ptr<Sort<T>> sorting_algorithm;

   public:
    /**
     * @brief Ustawia wybrany algorytm sortowania
     *
     * @param algorithm algorytm sortowania ktory ma zostac uzyty
     */
    void SetSortingAlgorithm(SortingAlgorithm algorithm) {
        switch (algorithm) {
            case SortingAlgorithm::QUICKSORT:
                sorting_algorithm = std::make_unique<QuickSort<T>>();
                break;
            case SortingAlgorithm::MERGESORT:
                sorting_algorithm = std::make_unique<MergeSort<T>>();
                break;
            case SortingAlgorithm::INTROSORT:
                sorting_algorithm = std::make_unique<IntroSort<T>>();
                break;
        }
    }

    void RealiseSorting(std::tuple<std::size_t, std::unique_ptr<int[]>>& array) {}

    ManageSorting() { sorting_algorithm = std::make_unique<QuickSort<T>>(); }
    ~ManageSorting() = default;
};