#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::u32string> lines;
    std::vector<char32_t> line;

    std::string file_name;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file_name);

    std::locale loc(std::locale(), new std::codecvt_utf8<char32_t>);
    std::basic_ifstream<char32_t> ifs(file_name, std::ios::in);
    ifs.imbue(loc);

    while (!ifs.eof())
        line.push_back(ifs.get());

    auto left_it = std::find(begin(line), end(line), char32_t('['));
    while (left_it != end(line)) {
        auto right_it = std::find(left_it, end(line), char32_t(']'));
        if (right_it == end(line))
            break;
        line.erase(left_it, right_it + 1);
        left_it = std::find(begin(line), end(line), char32_t('['));
    }

    std::basic_ofstream<char32_t> ofs("new_" + file_name, std::ios::out);
    ofs.imbue(loc);
    for(auto element : line)
        ofs << element;
    ofs.close();

    return 0;
}