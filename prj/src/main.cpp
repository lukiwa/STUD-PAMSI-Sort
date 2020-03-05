#include <iostream>
#include <memory>
#include "ArrayGenerator.hpp"
#include "QuickSort.hpp"

// NOTE testy
int GetSth(std::tuple<std::size_t, std::unique_ptr<int[]>>& array, int index) {
    return std::get<1>(array)[index];
}

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
    ArrayGenerator<int> generator;
    auto tuple = generator.GenerateRandomArray(100);
    std::cout << GetSth(tuple, 12) << std::endl;
    std::get<1>(tuple).reset();
}