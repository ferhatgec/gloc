// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

int main(int argc, char** argv) noexcept {
    if(argc < 2) { return 1; }

    std::vector<std::string> args(argv, argv + argc); args.erase(args.begin());

    for(auto arg : args) {
        unsigned lines = 1, loc = 0;
        std::ifstream read(arg);

        for(std::string temp; std::getline(read, temp)
            ;) {
            temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));

            temp.push_back('\n');

            ++lines;
            if(temp.front() == '\n' ||
                (temp.length() >= 2 && temp[0] == '/' && temp[1] == '/')) {
                continue;
            } ++loc;
        }

        std::cout << arg + " (loc: \x1b[0;93m" << loc << "\x1b[0m, lines: " << lines << ")\n";
    }
}
