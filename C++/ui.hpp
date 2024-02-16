#ifndef UI_HPP
#define UI_HPP

#include "docManager.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <filesystem>

class UI
{
public:
    void run();

private:
    void displayMenu() const;
    void pauseForUserInput() const;
};

#endif //UI_HPP
