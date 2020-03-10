#include <iostream>
#include <memory>
#include "ArrayGenerator.hpp"
#include "IntroSort.hpp"
#include "ManageSorting.hpp"
#include "QuickSort.hpp"

int main() {
    ManageSorting<int> heh;

    /*
    auto partial = ArrayGenerator<int>::GenerateRandomArray(10);
    // auto partial = ArrayGenerator<int>::GenerateReverseSortedArray(10);

    //    MergeSort<int> msort;
    heh.SetSortingAlgorithm(SortingAlgorithm::QUICKSORT);

    for (std::size_t i = 0; i < std::get<0>(partial); i++) {
        std::cout << std::get<1>(partial)[i] << " ";
    }

    std::cout << std::endl;

    heh.RealiseSorting(partial);
    // msort.SortUp(std::get<1>(partial), 0, 8);

    for (std::size_t i = 0; i < std::get<0>(partial); i++) {
        std::cout << std::get<1>(partial)[i] << " ";
    }
*/
    heh.RealiseDemoSorting();
}

// TODO w klasach sort juz zwykla tablica + rozmiar zamiast tuple
// using w manage sort
// zapisywanie do pliku