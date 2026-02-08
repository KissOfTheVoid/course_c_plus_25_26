/*
    Works with fstream, vector, sstream, string, cstdint libraries
    Titanic dataset processing with CSV parsing, string structure, data reading, statistics calculation: survival rate, class distribution, mean age, results output.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdint>

enum Category { E = 0, D = 1, C = 2, B = 3, A = 4, S = 5 };

struct Stats {
    double survival_rate = 0.0;
    std::vector<double> survival_by_cat;
    double avg_age = 0.0;
};

class Titanic {
public:
    std::string full_name;
    uint16_t age{};
    Category cat{};
    bool is_alive{};
};

std::vector<Titanic> parsingCSV(const std::string& filename) {
    std::vector<Titanic> passengers;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return passengers;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> data;
        while (std::getline(ss, token, ',')) data.push_back(token);
        if (data.size() < 4) continue;

        Titanic t;
        t.full_name = data[0];
        t.age = static_cast<uint16_t>(std::stoi(data[1]));
        t.cat = static_cast<Category>(std::stoi(data[2]));
        t.is_alive = (std::stoi(data[3]) != 0);
        passengers.push_back(t);
    }
    return passengers;
}

Stats computeStats(const std::vector<Titanic>& passengers) {
    Stats st;
    const std::size_t n = passengers.size();
    if (n == 0) return st;

    std::size_t alive_count = 0;
    std::vector<std::size_t> total_by_cat(6, 0);
    std::vector<std::size_t> alive_by_cat(6, 0);
    double age_sum = 0.0;
    std::size_t age_count = 0;

    for (const auto& p : passengers) {
        if (p.is_alive) ++alive_count;

        if (static_cast<std::size_t>(p.cat) < total_by_cat.size()) {
            ++total_by_cat[p.cat];
            if (p.is_alive) ++alive_by_cat[p.cat];
        }

        if (p.age > 0 || p.age == 0) {
            age_sum += p.age;
            ++age_count;
        }
    }

    st.survival_rate = static_cast<double>(alive_count) / static_cast<double>(n);

    st.survival_by_cat.resize(6, 0.0);
    for (std::size_t i = 0; i < total_by_cat.size(); ++i) {
        if (total_by_cat[i] > 0) {
            st.survival_by_cat[i] =
                static_cast<double>(alive_by_cat[i]) /
                static_cast<double>(total_by_cat[i]);
        } else {
            st.survival_by_cat[i] = 0.0;
        }
    }

    if (age_count > 0) {
        st.avg_age = age_sum / static_cast<double>(age_count);
    }

    return st;
}

int main() {
    std::string filename = "titanic_simple.csv";
    auto passengers = parsingCSV(filename);
    if (passengers.empty()) {
        std::cerr << "No data loaded\n";
        return 1;
    }

    Stats st = computeStats(passengers);

    std::cout << "Total passengers: " << passengers.size() << "\n";
    std::cout << "Survival rate: " << st.survival_rate << "\n";
    std::cout << "Average age: " << st.avg_age << "\n";

    std::cout << "Survival by category (E,D,C,B,A,S):\n";
    for (std::size_t i = 0; i < st.survival_by_cat.size(); ++i) {
        std::cout << i << ": " << st.survival_by_cat[i] << "\n";
    }
    /*
    ---output---
    Total passengers: 9
    Survival rate: 0.444444
    Average age: 30
    Survival by category (E,D,C,B,A,S):
    0: 0
    1: 0
    2: 0.5
    3: 1
    4: 0.666667
    5: 0
    */
    return 0;
}
