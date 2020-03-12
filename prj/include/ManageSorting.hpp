#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "IntroSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

enum class SortingAlgorithm { QUICKSORT, MERGESORT, INTROSORT };
enum class SortingWay { ASCENDING, DESCENDING };

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
    void DisplayArray(const ArrayWithSize& array) {
        for (std::size_t i = 0; i < std::get<0>(array); ++i) {
            std::cout << std::get<1>(array)[i] << " ";
        }
    }
    /** REVIEW czu sorting way potrzebne??
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
                    if (std::get<1>(array)[i] > std::get<1>(array)[i]) {
                        return false;
                    }
                }
                break;

            case SortingWay::DESCENDING:
                for (std::size_t i = 0; i < std::get<0>(array); ++i) {
                    if (std::get<1>(array)[i] < std::get<1>(array)[i]) {
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
                algorithm_name = "Quick Sort";
                break;
            case SortingAlgorithm::MERGESORT:
                sorting_algorithm = std::make_unique<MergeSort<T>>();
                algorithm_name = "Merge Sort";
                break;
            case SortingAlgorithm::INTROSORT:
                sorting_algorithm = std::make_unique<IntroSort<T>>();
                algorithm_name = "Intro Sort";
                break;
        }
    }

    /**
     * @brief Realizuje zadanie sortowania przez wybrany wczesniej algorytm
     *
     * @param array tablica do posortowania
     * @param sorting_way kierunek sortowania - rosnaco lub malejaco
     */
    void RealiseSorting(ArrayWithSize& array, SortingWay sorting_way = SortingWay::ASCENDING) {
        bool is_sorted = 0;
        switch (sorting_way) {
            case SortingWay::ASCENDING:
                sorting_algorithm->SortUp(std::get<1>(array), 0, std::get<0>(array) - 1);
                is_sorted = SortingCheck(array, SortingWay::ASCENDING);
                break;
            case SortingWay::DESCENDING:
                sorting_algorithm->SortDown(std::get<1>(array), 0, std::get<0>(array) - 1);
                is_sorted = SortingCheck(array, SortingWay::DESCENDING);
                break;
        }
    }

    /**
     * @brief Sortowanie testowe - wyswietla tablice przed i po sortowaniu dla
     *        wszystkich typów algorytmu - sortowanie rosnace
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

    ManageSorting() {
        sorting_algorithm = std::make_unique<MergeSort<T>>();  // domyslny algorytm sortowania
    }
    ~ManageSorting() = default;
};