#include "ToFileSaver.hpp"

/**
 * @brief Konstruuje nowy obiekt i ustawia domyslna sciezke do katalogu z plikami z danymi
 *
 */
ToFileSaver::ToFileSaver() { file_path = "data/"; }

/**
 * @brief Ustawia nazwe pliku
 *
 * @param algorithm_name nazwa algorytmu sortowania
 * @param number_of_arrays ilosc posortowanych tablic
 * @param size rozmiar tablc
 * @param already_sorted jaki % juz posortowany
 * @param already_sorted_way czy tablica przed sortowaniem byla posrotowana w gore
 */
void ToFileSaver::SetFilename(std::string algorithm_name, int number_of_arrays, std::size_t size,
                              double already_sorted, std::string already_sorted_way) {
    filename << algorithm_name << "_" << number_of_arrays << "_" << size << "_" << already_sorted
             << "_" << already_sorted_way << ".csv";
    full_path = file_path + filename.str();
}

/**
 * @brief Zapisuje czas do pliku o podanej wczesniej nazwie
 *
 * @param time czas sortowania
 */
void ToFileSaver::SaveToFile(double time) {
    std::ofstream stream;

    stream.open(full_path.c_str(), std::ios::out | std::ios::app);
    if (stream.fail()) {
        std::cout << "Nie otworzono pliku!" << std::endl;
        return;
    }

    stream << time << std::endl;
    stream.flush();
    stream.close();
}

/**
 * @brief Czysci nazwe pliku i pelna sciezke do pliku
 *
 */
void ToFileSaver::ClearFilename() {
    filename.clear();
    full_path.clear();
}