#include <iostream>
#include <memory>
#include "ArrayGenerator.hpp"
#include "IntroSort.hpp"
#include "ManageSorting.hpp"
#include "QuickSort.hpp"
#include "ToFileSaver.hpp"

int main() {
    srand(time(0));
    ManageSorting<int> heh;
    ToFileSaver saver;
    auto partial = ArrayGenerator<int>::GenerateRandomArray(10000);
    heh.SetSortingAlgorithm(SortingAlgorithm::INTROSORT);

    double time = heh.RealiseSorting(partial);

    /* ---------------------------------- DEBUG --------------------------------- */
    std::cout << time << std::endl;
    /* -------------------------------------------------------------------------- */

    saver.SetFilename(heh.GetCurrentAlgorithmName(), 1, 10000, 0, "UP");
    saver.SaveToFile(time);
}

// TODO w klasach sort juz zwykla tablica + rozmiar zamiast tuple
// using w manage sort
// zapisywanie do pliku