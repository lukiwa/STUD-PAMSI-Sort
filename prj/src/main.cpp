#include <iostream>
#include <memory>
#include "ArrayGenerator.hpp"
#include "IntroSort.hpp"
#include "ManageSorting.hpp"
#include "QuickSort.hpp"

// NOTE testy
int GetSth(std::tuple<std::size_t, std::unique_ptr<int[]>>& array, int index) {
    return std::get<1>(array)[index];
}

int main() {
    ArrayGenerator<int> generator;
    auto tuple = generator.GenerateRandomArray(10);

    ManageSorting<int> heh;
    heh.SetSortingAlgorithm(SortingAlgorithm::MERGESORT);
    /*
        for (int i = 0; i < 10; i++) {
            std::cout << std::get<1>(tuple)[i] << " ";
        }

        std::cout << std::endl;

        heh.RealiseSorting(tuple, 0.5);

        for (int i = 0; i < 10; i++) {
            std::cout << std::get<1>(tuple)[i] << " ";
        }
        */

    heh.RealiseDemoSorting();
}

// TODO w klasach sort juz zwykla tablica + rozmiar zamiast tuple
// using w manage sort
// zapisywanie do pliku