#pragma once
#include "Sort.hpp"

template <typename T>
class QuickSort : public Sort<T> {
   private:
    /**
     * @brief Szuka mediany 3 elementow i je sortuje (rosnaco)
     *
     * @param array tablica w ktorej sa elementu
     * @param start poczatkowy indeks
     * @param end indeks koncowy
     * @return T mediana
     */
    T MedianOf3(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) {
        // std::size_t median = (start + end) / 2;
        std::size_t median = start + (end - start) / 2;

        if (array[start] > array[end]) {
            std::swap(array[start], array[end]);
        }
        if (array[start] > array[median]) {
            std::swap(array[start], array[median]);
        }
        if (array[end] > array[median]) {
            std::swap(array[end], array[median]);
        }

        return array[end];
    }

   protected:
    /**
     * @brief podzielenie tablicy na pol a nastepnie przesnieienie alementow mniejszych od pivota na
     * lewo, a wiekszych na prawo
     *
     * @param array tablica do podzielenia
     * @param start indeks poczatkowy podzialu
     * @param end indeks koncowy podzialu
     * @return int
     */
    int Split(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) {
        T pivot = MedianOf3(array, start, end);
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
     * @brief Sortowanie szybkie rosnace
     *
     * @param array tablica ktora ma byc posortowana
     * @param start indeks poczatkowy
     * @param end indeks koncowy
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        if (start < end) {
            std::size_t mid = Split(array, start, end);
            SortUp(array, start, mid);
            SortUp(array, mid + 1, end);
        }
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

    QuickSort() = default;
    ~QuickSort() = default;
};