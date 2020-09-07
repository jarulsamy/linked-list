#ifndef LOADER_HPP
#define LOADER_HPP

#include "list.hpp"
#include <fstream>

LinkedList<int> load(std::string filename)
{
    LinkedList<int> ll;

    std::ifstream word_file(filename);
    if (!word_file.good())
        throw std::runtime_error("Error reading from file");

    int buffer;
    while (word_file >> buffer)
    {
        ll.push_back(buffer);
    }

    return ll;
}

#endif
