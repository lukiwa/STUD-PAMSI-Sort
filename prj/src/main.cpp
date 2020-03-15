#include <iostream>
#include <memory>
#include "UserInterface.hpp"

int main(int argc, char** argv) {
    srand(time(0));
    UserInterface ui;
    ui.Begin(argc, argv);
}
