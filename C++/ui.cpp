#include "ui.hpp"
#include "docManager.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <filesystem>


void UI::run()
{
    DocumentManager manager;
    std::string fileName;

    std::cout << "----------------------------------" << std::endl;
    std::cout << "Welcome to Simple Document Manager" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    while (true) {
        displayMenu();
        int choice{0};
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string append;

        switch (choice) {
            case 1:
                std::cout << "Enter file name: ";
                std::getline(std::cin, fileName);
                manager.create(fileName);
                pauseForUserInput();
                break;
            case 2:
                std::cout << "Enter file name to edit: ";
                std::getline(std::cin, fileName);
                if (!std::filesystem::exists(fileName)) {
                    std::cout << "There is no file with such name! Try again." << std::endl;
                    break;
                }
                std::cout << "Append to the document? (yes/no): ";
                std::getline(std::cin, append);
                manager.edit(fileName, append == "yes");
                pauseForUserInput();
                break;
            case 3:
                std::cout << "Enter file name to view: ";
                std::getline(std::cin, fileName);
                manager.view(fileName);
                pauseForUserInput();
                break;
            case 4:
                manager.show();
                pauseForUserInput();
                break;
            case 5:
                std::cout << "Enter file name to delete: ";
                std::getline(std::cin, fileName);
                manager.deleteDocument(fileName);
                pauseForUserInput();
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                return;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }

    }
}

void UI::displayMenu() const
{
    std::cout << "\n-------------------" << std::endl;
    
    std::cout << "Options:\n\n"
              << "1. Create Document\n"
              << "2. Edit Document\n"
              << "3. View Document\n"
              << "4. Show Documents\n"
              << "5. Delete Document\n"
              << "6. Exit\n" << std::endl;
    
    std::cout << "-------------------" << std::endl;
    std::cout << "\nEnter choice: ";
}

void UI::pauseForUserInput() const
{
    std::cout << "\nPress enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}