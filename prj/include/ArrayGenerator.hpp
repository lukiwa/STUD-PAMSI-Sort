#pragma once
#include <memory>
#include "MergeSort.hpp"

/**
 * @brief Generator tablic do sortowania
 *
 * @tparam T typ którym wypełniona będzie tablica
 */
template <typename T>
class ArrayGenerator {
   public:
    ArrayGenerator() = default;
    ~ArrayGenerator() = default;
   
    /**
     * @brief Generuje tablice danego typu o danym rozmiarze
     *        Jeżeli ma zostać wstepnie posortowana, to dzieje
     *        sie to za pomoca Merge Sort
     *
     * @param size rozmiar tablicy
     * @param already_sorted jaka czesc tablicy ma byc posortowana (np 0.5 to 50%)
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>> para, gdzie 1 wartość oznacza rozmiar
     * stworzonej tablicy, a 2 jest tablicą
     */
    static std::tuple<std::size_t, std::unique_ptr<T[]>> GenerateRandomArray(
        std::size_t size, double already_sorted = 0) {
        MergeSort<T> sorter;

        srand(time(0));
        auto array = std::make_unique<T[]>(size);
        // wypełnienie tablicy losowymi elementami
        for (std::size_t i = 0; i < size; ++i) {
            array[i] = std::rand() % 100;
        }
        // jezeli tablica ma byc wstepnie posortowana
        if (already_sorted > 0) {
            std::size_t last_index = (size - 1) * already_sorted;
            std::cout << last_index << std::endl;
            sorter.SortUp(array, 0, last_index);
        }

        return {size, std::move(array)};
    }

    /**
     * @brief Generowanie tablicy testowej o dlugosci 10, z elementami od 0 do 100
     *
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>> para, gdzie 1 wartość oznacza rozmiar
     * stworzonej tablicy, a 2 jest tablicą
     */
    static std::tuple<std::size_t, std::unique_ptr<T[]>> GenerateDemoArray() {
        srand(time(0));
        const int demo_array_size = 10;
        const int demo_array_max = 100;

        auto array = std::make_unique<T[]>(demo_array_size);
        // wypełnienie tablicy losowymi elementami
        for (std::size_t i = 0; i < demo_array_size; ++i) {
            array[i] = std::rand() % demo_array_max;
        }
        return {demo_array_size, std::move(array)};
    }

    /**
     * @brief Generuje tablicę posortowaną od elementu największego do najmniejszego
     *        Sortowanie odbywa sie za pomoca Merge Sort
     *
     * @param size rozmiar tablicy
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>>
     */
    static std::tuple<std::size_t, std::unique_ptr<T[]>> GenerateReverseSortedArray(
        std::size_t size) {
        MergeSort<T> sorter;

        srand(time(0));
        auto array = std::make_unique<T[]>(size);
        // wypełnienie tablicy losowymi elementami
        for (std::size_t i = 0; i < size; ++i) {
            array[i] = std::rand() % 100;
        }

        sorter.SortDown(array, 0, size - 1);

        return {size, std::move(array)};
    }
};
