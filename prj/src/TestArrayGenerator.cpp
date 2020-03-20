#include "TestArrayGenerator.hpp"

/**
 * @brief Generuje tablice danego typu o danym rozmiarze
 *        Jeżeli ma zostać wstepnie posortowana, to dzieje
 *        sie to za pomoca Merge Sort
 *
 * @param size rozmiar tablicy
 * @param already_sorted jaka czesc tablicy ma byc posortowana (np 0.5 to 50%)
 * @return std::tuple<std::size_t, std::unique_ptr<int[]>> para, gdzie 1 wartość oznacza rozmiar
 * stworzonej tablicy, a 2 jest tablicą
 */
std::tuple<std::size_t, std::unique_ptr<int[]>> TestArrayGenerator::GenerateRandomArray(
    std::size_t size, double already_sorted) {
    MergeSort<int> sort;

    auto array = std::make_unique<int[]>(size);
    // wypełnienie tablicy losowymi elementami
    for (std::size_t i = 0; i < size; ++i) {
        array[i] = std::rand();
    }

    // jezeli tablica ma byc wstepnie posortowana
    if (already_sorted > 0) {
        std::size_t last_index = (size - 1) * already_sorted;
        sort.SortUp(array, 0, last_index);
    }

    return {size, std::move(array)};
}

/**
 * @brief Generowanie tablicy testowej o dlugosci 10, z elementami od 0 do 100
 *
 * @return std::tuple<std::size_t, std::unique_ptr<int[]>> para, gdzie 1 wartość oznacza rozmiar
 * stworzonej tablicy, a 2 jest tablicą
 */
std::tuple<std::size_t, std::unique_ptr<int[]>> TestArrayGenerator::GenerateDemoArray() {
    const int demo_array_size = 15;
    const int demo_array_max = 100;

    auto array = std::make_unique<int[]>(demo_array_size);
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
 * @return std::tuple<std::size_t, std::unique_ptr<int[]>>
 */
std::tuple<std::size_t, std::unique_ptr<int[]>> TestArrayGenerator::GenerateReverseSortedArray(
    std::size_t size) {
    MergeSort<int> sorter;

    auto array = std::make_unique<int[]>(size);
    // wypełnienie tablicy losowymi elementami
    for (std::size_t i = 0; i < size; ++i) {
        array[i] = std::rand();
    }

    sorter.SortDown(array, 0, size - 1);

    return {size, std::move(array)};
}