#include <iostream>
#include <memory>

#include "InsertionSort.hpp"
#include "UserInterface.hpp"

/**
 * @brief Program realizujacy sortowanie
 *        Wpisz "help" aby uzyskac pomoc
 *        Wpisz "demo" aby wykonac pokazowe sortowanie
 */
int main(int argc, char** argv) {
    srand(time(0));
    UserInterface ui;
    ui.Begin(argc, argv);
}
