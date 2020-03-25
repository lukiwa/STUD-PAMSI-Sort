#pragma once
#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#include "HeapSort.hpp"
#include "InsertionSort.hpp"
#include "IntroSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "SortingErrorException.hpp"
#include "TestArrayGenerator.hpp"

enum class SortingAlgorithm { QUICKSORT, MERGESORT, INTROSORT, INSERTIONSORT, HEAPSORT };
enum class SortingWay { ASCENDING, DESCENDING };

template <typename T>
class ManageSorting {
   private:
    std::unique_ptr<Sort<T>> sorting_algorithm;
    std::string algorithm_name;
    TestArrayGenerator generator;

    using ArrayWithSize = std::tuple<std::size_t, std::unique_ptr<int[]>>;

    /**
     * @brief Wyswietla tablice
     *
     * @param arr tablica do wyswietlenia
     */
    void DisplayArray(const ArrayWithSize& array) {
        for (std::size_t i = 0; i < std::get<0>(array); ++i) {
            std::cout << std::get<1>(array)[i] << " ";
        }
    }
    /**
     * @brief Sprawdza poprawnnosc posortowania tablicy
     *
     * @param array tablica ktora powinna byc posortowana
     * @param sorting_way kierunek sortowania (rosnoca, malejaca)
     * @return true jezeli tablica jest posortowana
     * @return false jezeli tablica jest nieposortowana
     */
    bool SortingCheck(const ArrayWithSize& array, SortingWay sorting_way = SortingWay::ASCENDING) {
        switch (sorting_way) {
            case SortingWay::ASCENDING:
                for (std::size_t i = 0; i < std::get<0>(array); ++i) {
                    if (std::get<1>(array)[i - 1] > std::get<1>(array)[i]) {
                        return false;
                    }
                }
                break;

            case SortingWay::DESCENDING:
                for (std::size_t i = 0; i < std::get<0>(array); ++i) {
                    if (std::get<1>(array)[i - 1] < std::get<1>(array)[i]) {
                        return false;
                    }
                }
                break;
        }

        return true;
    }

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
                algorithm_name = "QuickSort";
                break;
            case SortingAlgorithm::MERGESORT:
                sorting_algorithm = std::make_unique<MergeSort<T>>();
                algorithm_name = "MergeSort";
                break;
            case SortingAlgorithm::INTROSORT:
                sorting_algorithm = std::make_unique<IntroSort<T>>();
                algorithm_name = "IntroSort";
                break;
            case SortingAlgorithm::INSERTIONSORT:
                sorting_algorithm = std::make_unique<InsertionSort<T>>();
                algorithm_name = "InsertionSort";
                break;
            case SortingAlgorithm::HEAPSORT:
                sorting_algorithm = std::make_unique<HeapSort<T>>();
                algorithm_name = "HeapSort";
                break;
        }
    }

    /**
     * @brief Realizuje zadanie sortowania (TYLKO W GORE!) przez wybrany wczensiej algorytm
     *
     * @param array tablica do posortowania
     * @return double czas sortowania w ms - jeżeli sortowanie sie nie powiodło zwraca 9999
     */
    double RealiseSorting(ArrayWithSize& array) {
        auto start = std::chrono::steady_clock::now();
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        auto end = std::chrono::steady_clock::now();

        if (SortingCheck(array)) {
            return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        } else {
            throw SortingErrorException();
        }
    }

    /**
     * @brief Sortowanie testowe - wyswietla tablice przed i po sortowaniu dla
     *        wszystkich typów algorytmu - sortowanie rosnace
     *
     */
    void RealiseDemoSorting() {
        /*
        auto array = generator.GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::MERGESORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl << std::endl;

        array = generator.GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::QUICKSORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl << std::endl;

        array = generator.GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::INSERTIONSORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl << std::endl;

        array = generator.GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::HEAPSORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl << std::endl;
*/
        /* --------------------------------- INSERT --------------------------------- */
        auto array = generator.GenerateRandomArray(100);
        SetSortingAlgorithm(SortingAlgorithm::INTROSORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        if (SortingCheck(array)) {
            std::cout << "CHODZI" << std::endl;
        }
    }

    ManageSorting() {
        sorting_algorithm = std::make_unique<MergeSort<T>>();  // domyslny algorytm sortowania
    }
    ~ManageSorting() = default;
};