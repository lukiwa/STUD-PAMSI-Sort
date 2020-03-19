#pragma once
#include <exception>
#include <iostream>

class ForceDemoSortingException : public std::exception {
   public:
    const char* what() const throw() { return "Sortowanie demonstracyjne"; }
};