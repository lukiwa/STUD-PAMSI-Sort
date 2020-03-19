#pragma once

#include <exception>
#include <iostream>

class InputCheckException : public std::exception {
   public:
    const char* what() const throw() { return "Napotkano błędy w podanych argumentach!"; }
};