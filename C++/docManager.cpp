#include "docManager.hpp"

void DocumentManager::create(const std::string& fileName) 
{
    //Creating a new document
    std::ofstream file(fileName, std::ios::out);
    if (!file) {
        throw std::runtime_error("Error opening the file: " + fileName);
    }
    file.close();
    std::cout << "Document " << fileName << " created successfully." << std::endl;

    //Asking user if he/she wants to edit the document immdiately or not
    std::cout << "Do you want to edit this document now? (yes/no): ";
    std::string response;
    std::getline(std::cin, response);

    if (response == "yes") {
        edit(fileName, false);
    }
}

void DocumentManager::edit(const std::string& fileName, bool append) 
{
    ///Edit an existing document
    std::ofstream file;
    if (append) {
        file.open(fileName, std::ios::app);
    } else {
        //trunc(delete) the contents first, then write
        file.open(fileName, std::ios::out | std::ios::trunc);
    }
    if (!file) {
        throw std::runtime_error("Error opening the file: " + fileName);
    }

    std::cout << "Enter the contents(Enter .(dot) for indicating the end): " << std::endl;
    std::string content;
    while (std::getline(std::cin, content)) {
        if (content == ".") {
            break;
        }
    file << content << std::endl;
}
    //Clearing any flags or errors in cin
    std::cin.clear(); 

    std::cout << "Content added to " << fileName << std::endl;
    file.close();
}

void DocumentManager::view(const std::string& fileName) 
{
    //View the contents of the document
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening the file: " + fileName);
    }

    std::cout << "File contents:" << std::endl;
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void DocumentManager::deleteDocument(const std::string& fileName) {
    //Checking if file exists
    if (!std::filesystem::exists(fileName)) {
        std::cout << "File does not exist: " << fileName << std::endl;
        return;
    }

    try {
        //Removing the file
        std::filesystem::remove(fileName);
        std::cout << "Document " << fileName << " deleted successfully." << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Failed to delete the document: " << e.what() << std::endl;
    }
}

void DocumentManager::show() 
{
    //Show all of the documents in current directory(.)
    std::string path = ".";
    std::cout << "-------------------";
    std::cout << "\nAll documents in " << path << ": " << std::endl;
    bool found = false;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::cout << entry.path().filename() << std::endl;
            found = true;
        }
    }
    std::cout << "-------------------" << std::endl;
    if (!found) {
        std::cout << "No documents found." << std::endl;
    }
}
