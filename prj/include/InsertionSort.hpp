#pragma once
#include "Sort.hpp"

/**
 * @brief Klasa umozliwia sortowanie przez wstawianie
 *
 * @tparam T tablica zawiera podany typ
 */
template <typename T>
class InsertionSort : public Sort<T> {
   public:
    /**
     * @brief Sortowanie przez wstawianie
     *
     * @param array tablica ktora ma byc posortowana
     * @param start indeks poczatkowy
     * @param end indeks koncowy
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        T temp_largest;
        std::size_t j;
        for (std::size_t i = start; i <= end; ++i) {
            temp_largest = array[i];
            j = i - 1;
            while (j >= start && array[j] > temp_largest) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = temp_largest;
        }
    }

    /**
     * @brief Sortowanie malejace - niezaimplementowane, poniewaz nie bedzie wykorzystywane
     *
     */
    void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        T temp_lowest;
        std::size_t j;
        for (std::size_t i = start; i <= end; ++i) {
            temp_lowest = array[i];
            j = i - 1;
            while (j >= start && array[j] < temp_lowest) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = temp_lowest;
        }
    }
    InsertionSort() = default;
    ~InsertionSort() = default;
};