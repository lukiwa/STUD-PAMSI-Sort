#pragma once
#include <memory>

#include "MergeSort.hpp"

/**
 * @brief Klasa generujaca tablice testowe z elemantami typu int
 * 
 */
class TestArrayGenerator {
   public:
    TestArrayGenerator() = default;
    ~TestArrayGenerator() = default;

    std::tuple<std::size_t, std::unique_ptr<int[]>> GenerateRandomArray(std::size_t size,
                                                                        double already_sorted = 0);
    std::tuple<std::size_t, std::unique_ptr<int[]>> GenerateDemoArray();
    std::tuple<std::size_t, std::unique_ptr<int[]>> GenerateReverseSortedArray(std::size_t size);
};