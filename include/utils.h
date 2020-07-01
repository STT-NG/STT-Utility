#pragma once

#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

namespace STTUtil {

inline std::map<int, std::map<int, std::string>> readCSV(std::ifstream &stream) {
    std::map<int, std::map<int, std::string>> data;
    int row = 0;
    int col = 0;
    std::string line;

    while(std::getline(stream, line)) {
        std::stringstream sstream(line);

        std::string cell;
        while(std::getline(sstream, cell, ',')) {
            data[row][col] = cell;
            col++;
        }

        col = 0;
        row++;
    }

    return data;
}

}
