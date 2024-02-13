#ifndef DOCUMENTMANAGER_HPP
#define DOCUMENTMANAGER_HPP

#include <string>

class DocumentManager 
{
public:
    void create(const std::string& fileName);
    void edit(const std::string& fileName, bool app);
    void view(const std::string& fileName);
    void deleteDocument(const std::string& fileName);
    void show();
};

#endif // DOCUMENTMANAGER_HPP

