#pragma one

#include "list.hpp"
#include <string>
#include <fstream>

LinkedList<std::string> load(std::string filename)
{
    LinkedList<std::string> ll;
    std::ifstream word_file(filename);
    std::string buffer;

    while (word_file >> buffer)
    {
        ll.insert(buffer);
    }

    return ll;
}
