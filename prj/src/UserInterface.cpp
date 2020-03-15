#include "UserInterface.hpp"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::Begin(int argc, char** argv) {
    Parse(argc, argv);
    SetParameters();
    for (int i = 0; i < number_of_arrays; ++i) {
        if (already_sorted_way == "DOWN") {
            array_with_size = ArrayGenerator<int>::GenerateReverseSortedArray(size);
        } else {
            array_with_size = ArrayGenerator<int>::GenerateRandomArray(size, already_sorted);
        }

        sorting_time = sort.RealiseSorting(array_with_size);
        save.SaveToFile(sorting_time);
    }
}

void UserInterface::Parse(int argc, char** argv) {
    if (argc < 6) {
        std::cout << "Brrakujacy element! Zobacz pomoc" << std::endl;
        DisplayHelp();
        return;
    }
    algorithm_name = argv[1];
    number_of_arrays = std::stoi(argv[2]);

    // Konsersja do size_t
    std::stringstream ss(argv[3]);
    ss >> size;

    already_sorted = std::stod(argv[4]);
    already_sorted_way = argv[5];
}
void UserInterface::SetParameters() {
    if (algorithm_name == "IntroSort") {
        sorting_algorithm = SortingAlgorithm::INTROSORT;
    } else if (algorithm_name == "MergeSort") {
        sorting_algorithm = SortingAlgorithm::MERGESORT;
    } else if (algorithm_name == "QuickSort") {
        sorting_algorithm = SortingAlgorithm::QUICKSORT;
    } else {
        std::cout << "Nierozpoznana nazwa algorytmu sortowania!" << std::endl;
        DisplayHelp();
        return;
    }
    sort.SetSortingAlgorithm(sorting_algorithm);
    save.SetFilename(algorithm_name, number_of_arrays, size, already_sorted, already_sorted_way);
}
