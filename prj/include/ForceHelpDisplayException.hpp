#pragma once
#include <exception>
#include <iostream>

class ForceHelpDisplayException : public std::exception {
   public:
    const char* what() const throw() { return "Wyświetlam pomoc"; }
};