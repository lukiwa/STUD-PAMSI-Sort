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
     * @brief Laczenie tablic do sortowania rosnacego
     *
     * @param array tablica
     * @param start indeks poczatkowyc
     * @param mid srodek (punkt podzialu)
     * @param end indeks koncowy sortowania
     */
    void MergeUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t mid, std::size_t end) {
        const std::size_t first_half_size = mid - start + 1;  // dlugosc pierwszej tablicy
        const std::size_t second_half_size = end - mid;       // dlugosc drugiej tablicy

        T* first_half = new T[first_half_size];
        T* second_half = new T[second_half_size];
        // przepisanie 1 polowy tablicy
        for (std::size_t i = 0; i < first_half_size; ++i) {
            first_half[i] = array[start + i];
        }

        // przepisanie 2 polowy tablicy
        for (std::size_t i = 0; i < second_half_size; ++i) {
            second_half[i] = array[mid + 1 + i];
        }

        std::size_t i = 0;      // iterator dla pierwszej (lewej) czesci tablicy
        std::size_t j = 0;      // iterator dla drugiej (prawej) czesci tablicy
        std::size_t k = start;  // iterator dla polaczanej tablicy
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
        delete[] first_half;
        delete[] second_half;
    }

    /**
     * @brief Laczenie tablic do sortowania malejacego
     *
     * @param array tablica
     * @param start indeks poczatkowyc
     * @param mid srodek (punkt podzialu)
     * @param end indeks koncowy sortowania
     */
    void MergeDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t mid,
                   std::size_t end) {
        std::size_t first_half_size = mid - start + 1;  // dlugosc pierwszej tablicy
        std::size_t second_half_size = end - mid;       // dlugosc drugiej tablicy

        T* first_half = new T[first_half_size];
        T* second_half = new T[second_half_size];
        // przepisanie 1 polowy tablicy
        for (std::size_t i = 0; i < first_half_size; ++i) {
            first_half[i] = array[start + i];
        }

        // przepisanie 2 polowy tablicy
        for (std::size_t i = 0; i < second_half_size; ++i) {
            second_half[i] = array[mid + 1 + i];
        }

        std::size_t i = 0;      // iterator dla pierwszej (lewej) czesci tablicy
        std::size_t j = 0;      // iterator dla drugiej (prawej) czesci tablicy
        std::size_t k = start;  // iterator dla polaczanej tablicy
        while (i < first_half_size && j < second_half_size) {
            if (first_half[i] >= second_half[j]) {
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
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        if (start < end) {
            std::size_t mid = (start + end) / 2;
            SortUp(array, start, mid);
            SortUp(array, mid + 1, end);
            MergeUp(array, start, mid, end);
        }
    }

    void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        if (start < end) {
            std::size_t mid = (start + end) / 2;
            SortDown(array, start, mid);
            SortDown(array, mid + 1, end);
            MergeDown(array, start, mid, end);
        }
    }

    MergeSort() = default;
    ~MergeSort() = default;
};