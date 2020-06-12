#include "list.hpp"
#include "loader.hpp"

#include <algorithm>
#include <string>
#include <iostream>
#include <locale>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    LinkedList<std::string> ll = load(argv[1]);
    std::string buffer;

    cout << "Enter word to search for: ";
    cin >> buffer;
    std::transform(buffer.begin(), buffer.end(), buffer.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    if (ll.find(buffer))
    {
        cout << "Found!" << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }

    return 0;
}
