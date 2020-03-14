#pragma once
#include <fstream>
#include <iostream>
#include <string>

class ToFileSaver {
   private:
    std::string file_path;
    std::string filename;
    std::string full_path;

   public:
    void SetFilename(std::string algorithm_name, int number_of_arrays, std::size_t size,
                     double already_sorted, std::string already_sorted_way);
    void SaveToFile(double time);
    void ClearFilename();

    ToFileSaver();
    ~ToFileSaver() = default;
};