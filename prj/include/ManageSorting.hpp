#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "IntroSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

enum class SortingAlgorithm { QUICKSORT, MERGESORT, INTROSORT };

template <typename T>
class ManageSorting {
   private:
    std::unique_ptr<Sort<T>> sorting_algorithm;
    std::string algorithm_name;
    using ArrayWithSize = std::tuple<std::size_t, std::unique_ptr<T[]>>;

    /**
     * @brief Wyswietla tablice
     *
     * @param arr tablica do wyswietlenia
     */
    void DisplayArray(ArrayWithSize& arr) {
        for (std::size_t i = 0; i < std::get<0>(arr); ++i) {
            std::cout << std::get<1>(arr)[i] << " ";
        }
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
                algorithm_name = "Quick Sort";
                break;
            case SortingAlgorithm::MERGESORT:
                sorting_algorithm = std::make_unique<MergeSort<T>>();
                algorithm_name = "Merge Sort";
                break;
            case SortingAlgorithm::INTROSORT:
                //               sorting_algorithm = std::make_unique<IntroSort<T>>();
                // algorithm_name = "Intro Sort";
                break;
        }
    }

    void RealiseSorting(ArrayWithSize& array, double sorting_length = 1) {
        // ostatni indeks, do ktorego bedzie przeprowadzone sortowaniej
        int last_index = (std::get<0>(array) - 1) * sorting_length;
        std::cout << last_index << std::endl;

        sorting_algorithm->SortUp(std::get<1>(array), 0, last_index);
    }

    /**
     * @brief Sortowanie testowe - wyswietla tablice przed i po sortowaniu
     *
     */
    void RealiseDemoSorting() {
        auto array = ArrayGenerator<T>::GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::MERGESORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl << std::endl;

        array = ArrayGenerator<T>::GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::QUICKSORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl << std::endl;

        array = ArrayGenerator<T>::GenerateDemoArray();
        SetSortingAlgorithm(SortingAlgorithm::INTROSORT);
        std::cout << "Algorytm sortowania: " << algorithm_name << std::endl
                  << "Tablica przed sortowaniem: ";
        DisplayArray(array);
        sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
        std::cout << std::endl << "Tablica po sortowaniu: ";
        DisplayArray(array);
        std::cout << std::endl;
    }

    ManageSorting() { sorting_algorithm = std::make_unique<MergeSort<T>>(); }
    ~ManageSorting() = default;
};