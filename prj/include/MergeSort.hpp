#pragma once
#include "Sort.hpp"

/**
 * @brief Klasa umozliwia sortowanie przez scalanie
 *
 * @tparam T tablica zawiera podany typ
 */
template <typename T>
class MergeSort : public Sort<T> {
   private:
    /**
     * @brief Laczenie tablic
     *
     * @param array tablica
     * @param start indeks poczatkowyc
     * @param mid srodek (punkt podzialu)
     * @param end indeks koncowy sortowania
     */
    void Merge(std::unique_ptr<T[]>& array, int start, int mid, int end) {
        int first_half_size = mid - start + 1;  // dlugosc pierwszej tablicy
        int second_half_size = end - mid;       // dlugosc drugiej tablicy

        auto first_half = std::make_unique<int[]>(first_half_size);
        auto second_half = std::make_unique<int[]>(second_half_size);

        // przepisanie 1 polowy tablicy
        for (int i = 0; i < first_half_size; ++i) {
            first_half[i] = array[start + i];
        }

        // przepisanie 2 polowy tablicy
        for (int i = 0; i < second_half_size; ++i) {
            second_half[i] = array[mid + 1 + i];
        }

        int i = 0;      // iterator dla pierwszej (lewej) czesci tablicy
        int j = 0;      // iterator dla drugiej (prawej) czesci tablicy
        int k = start;  // iterator dla polaczanej tablicy
        while (i < first_half_size && j < second_half_size) {
            if (first_half[i] <= second_half[j]) {
                array[k] = first_half[i];
                i++;
            } else {
                array[k] = second_half[j];
                j++;
            }
            k++;
        }

        // laczenie tablic
        while (i < first_half_size) {
            array[k] = first_half[i];
            i++;
            k++;
        }

        while (j < second_half_size) {
            array[k] = second_half[j];
            j++;
            k++;
        }
    }

   public:
    /**
     * @brief Sortowanie przez scalanie
     *
     * @param array tablica zawierajaca elementy
     * @param start indeks poczatkowy(moment poczatku sortowania)
     * @param end indeks koncowy(do ktorego momentu sortowanie)
     */
    void SortUp(std::unique_ptr<T[]>& array, int start, int end) override {
        if (start < end) {
            int mid = (start + end) / 2;
            SortUp(array, start, mid);
            SortUp(array, mid + 1, end);
            Merge(array, start, mid, end);
        }
    }

    // bool SortDown(std::unique_ptr<T[]> array, std::size_t size,
    //             double sorting_length = 1) override {}

    MergeSort() = default;
    ~MergeSort() = default;
};