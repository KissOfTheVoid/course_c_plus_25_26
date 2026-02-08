#include <iostream>
#include <vector>

bool isPositive(int _num) {
    return (_num > 0);
}

bool isEven(int _num) {
    return ((_num % 2) == 0);
}

std::vector<int> filterArray(
    const std::vector<int>& arr, 
    bool (*filter)(int), 
    int& resultSize
) {
    std::vector<int> result;
    for (int _temp: arr) {
        if (filter(_temp)) {
            result.push_back(_temp);
        }
    }
    resultSize = result.size();
    return result;
}



int main() {
    int n;
    std::cin >> n;
    std::vector<int> sp(n);
    for (int i = 0; i < n; ++i) std::cin >> sp[i];
    int pl = 0, ev = 0;
    std::vector<int> pls = filterArray(sp, isPositive, pl);
    std::vector<int> evs = filterArray(sp, isEven, ev);
    for (int el: pls) std::cout << el << ' ';
    std::cout << '\n';
    for (int el: evs) std::cout << el << ' ';
    return 0;
}