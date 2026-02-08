/*
    Works with vector, string, sstream libraries
    Realisazion of csv-parser with overloaded functions
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CSVReader {
public:
    CSVReader() = default;

    friend std::istream& operator>>(std::istream& is, CSVReader& csv) {
        csv.data.clear();
        std::string line;
        while (std::getline(is, line)) {
            if (line.empty()) break;
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;
            while (std::getline(ss, cell, ',')) row.push_back(cell);
            csv.data.push_back(row);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const CSVReader& csv) {
        for (const auto& row : csv.data) {
            for (size_t i = 0; i < row.size(); ++i) {
                if (i > 0) os << ",";
                os << row[i];
            }
            os << "\n";
        }
        return os;
    }

    std::vector<size_t> countNonEmptyCellsPerColumn() const {
        std::vector<size_t> counts;
        size_t max_columns = 0;
        for (const auto& row : data) if (row.size() > max_columns) max_columns = row.size();
        counts.resize(max_columns, 0);
        for (const auto& row : data) for (size_t i = 0; i < row.size(); ++i) if (!row[i].empty()) ++counts[i];
        return counts;
    }

private:
    std::vector<std::vector<std::string>> data;
};

int main() {
    CSVReader test;
    std::cin >> test;
    auto counts = test.countNonEmptyCellsPerColumn();
    for (size_t i = 0; i < counts.size(); ++i) std::cout << i << ": " << counts[i] << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    ,,,,2,234,4
    3,13,1,2,4
    ,2332,1123
    ---output---
    0: 1
    1: 2
    2: 2
    3: 1
    4: 2
    5: 1
    6: 1
    ---input---
    2134saffr934
    dsfws,425gf,234df
    ---output---
    0: 2
    1: 1
    2: 1
    */
    return 0;
}
