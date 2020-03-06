#pragma once
#include <memory>

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
     *
     * @param size rozmiar tablicy
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>> para, gdzie 1 wartość oznacza rozmiar
     * stworzonej tablicy, a 2 jest tablicą
     */
    std::tuple<std::size_t, std::unique_ptr<T[]>> GenerateRandomArray(std::size_t size) {
        srand(time(0));
        auto array = std::make_unique<T[]>(size);
        // wypełnienie tablicy losowymi elementami
        for (std::size_t i = 0; i < size; ++i) {
            array[i] = std::rand();
        }
        return {size, std::move(array)};
    }

    /**
     * @brief Generowanie tablicy testowej o dlugosci 10, z elementami od 0 do 100
     *
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>> para, gdzie 1 wartość oznacza rozmiar
     * stworzonej tablicy, a 2 jest tablicą
     */
    std::tuple<std::size_t, std::unique_ptr<T[]>> GenerateDemoArray() {
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
     * @brief Generuje częściowo posortowaną tablicę
     *
     * @param size Rozmiar tablicy
     * @param already_sorted Jaki procent tablicy jest juz posortowany
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>> para, gdzie 1 wartość oznacza rozmiar
     * stworzonej tablicy, a 2 jest tablicą
     */
    std::tuple<std::size_t, std::unique_ptr<T[]>> GeneratePartiallySortedArray(
        std::size_t size, double already_sorted) {
        // TODO
    }

    /**
     * @brief Generuje tablicę posortowaną od elementu największego do najmniejszego
     *
     * @param size rozmiar tablicy
     * @return std::tuple<std::size_t, std::unique_ptr<T[]>>
     */
    std::tuple<std::size_t, std::unique_ptr<T[]>> GenerateReverseSortedArray(std::size_t size) {
        // TODO
    }
};
