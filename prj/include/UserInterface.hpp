#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "ForceDemoSortingException.hpp"
#include "ForceHelpDisplayException.hpp"
#include "InputCheckFailedException.hpp"
#include "ManageSorting.hpp"
#include "TestArrayGenerator.hpp"
#include "ToFileSaver.hpp"

class UserInterface {
   private:
    std::string algorithm_name;
    int number_of_arrays;
    std::size_t size;
    double already_sorted;
    std::string already_sorted_way;
    SortingAlgorithm sorting_algorithm;
    double sorting_time;
    ManageSorting<int> sort;
    ToFileSaver save;
    std::tuple<std::size_t, std::unique_ptr<int[]>> array_with_size;
    TestArrayGenerator generator;

    void DisplayHelp();
    void SetParameters();
    void Parse(int argc, char** argv);

   public:
    void Begin(int argc, char** argv);
    UserInterface() = default;
    ~UserInterface() = default;
};