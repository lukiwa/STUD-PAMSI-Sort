#pragma once
#include <exception>
#include <iostream>

class NotIomplementedException : public std::exception {
   public:
    const char* what() const throw() { return "Function or method not implemented!"; }
};