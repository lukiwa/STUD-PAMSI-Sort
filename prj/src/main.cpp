#include <iostream>
#include <memory>

#include "InsertionSort.hpp"
#include "TestArrayGenerator.hpp"
#include "UserInterface.hpp"

std::tuple<std::size_t, std::unique_ptr<int[]>> Test(std::size_t size) {
    MergeSort<int> sorter;

    auto array = std::make_unique<int[]>(size);
    // wypełnienie tablicy losowymi elementami
    for (std::size_t i = 0; i < size; ++i) {
        array[i] = std::rand() % 100;
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    sorter.SortDown(array, 0, size - 1);

    for (std::size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return {size, std::move(array)};
}

/**
 * @brief Program realizujacy sortowanie
 *        Wpisz "help" aby uzyskac pomoc
 *        Wpisz "demo" aby wykonac pokazowe sortowanie
 */
int main(int argc, char** argv) {
    srand(time(0));
    // UserInterface ui;
    // ui.Begin(argc, argv);
    // ArrayGenerator<int>::GenerateRandomArray(10, 0.5);
    // ArrayGenerator<int>::GenerateReverseSortedArray(10);
    /*
     auto arr = ArrayGenerator<int>::GenerateRandomArray(10, 0.5);

     for (int i = 0; i < 10; i++) {
         std::cout << std::get<1>(arr)[i] << " ";
     }
     std::cout << std::endl;

     MergeSort<int> merge;
     merge.SortUp(std::get<1>(arr), 0, 9);

     for (int i = 0; i < 10; i++) {
         std::cout << std::get<1>(arr)[i] << " ";
     }

     std::cout << std::endl;
 */
    TestArrayGenerator test;
    test.GenerateRandomArray(10, 0.5);
}
