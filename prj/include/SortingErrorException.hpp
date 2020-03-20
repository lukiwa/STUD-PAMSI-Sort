#pragma once
#pragma once
#include <exception>
#include <iostream>

class SortingErrorException : public std::exception {
   public:
    const char* what() const throw() { return "Wystapił błąd w sortowaniu!"; }
};