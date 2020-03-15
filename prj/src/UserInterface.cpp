#include "UserInterface.hpp"

/**
 * @brief Rozpoczyna dzialanie UI a tym samym calego zadania sortowania
 *
 * @param argc argc
 * @param argv argv
 */
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

/**
 * @brief Pobiera odpowiednie dane z argumentow wywolania programu
 *
 */
void UserInterface::Parse(int argc, char** argv) {
    if (argc < 6) {
        std::cout << "Brakujacy element! Wpisz help po nazwie programu aby uzyskac pomoc!"
                  << std::endl;
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

/**
 * @brief Na podstawie pobranych danych ustawia odpowiednie parametry sortowania
 *
 */
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

/**
 * @brief Wyswietla pomoc
 *
 */
void UserInterface::DisplayHelp() {
    std::cout << "Parametr 1: Nazwa algorytmu sortowania w postaci xxxSort, np IntroSort"
              << std::endl;
    std::cout << "Parametr 2: Ilosc tablic do posortowania" << std::endl;
    std::cout << "Parametr 3: Wielkosc tablic" << std::endl;
    std::cout << "Parametr 4: Czy tablica wstepnie posortowana (0.5 to 50\% posortowane"
              << std::endl;
    std::cout << "Parametr 5: Jeżeli wpisano DOWN - tablica wstepnie bedzie posortowana malejaco, "
                 "jeżeli UP to rosnaco, zgodnie z parametrem 4"
              << std::endl;
}