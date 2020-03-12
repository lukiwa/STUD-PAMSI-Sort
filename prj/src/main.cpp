#include <iostream>
#include <memory>
#include "ArrayGenerator.hpp"
#include "IntroSort.hpp"
#include "ManageSorting.hpp"
#include "QuickSort.hpp"

int main() {
    srand(time(0));
    ManageSorting<int> heh;

    auto partial = ArrayGenerator<int>::GenerateRandomArray(1000000);
    heh.SetSortingAlgorithm(SortingAlgorithm::INTROSORT);
    heh.RealiseSorting(partial);

    // heh.RealiseDemoSorting();
}

// TODO w klasach sort juz zwykla tablica + rozmiar zamiast tuple
// using w manage sort
// zapisywanie do pliku