/*
    Works with vector library
    Counter class with a nested structure for logging operations. Demonstrate the use of `this` in methods, including self-references in logs
*/

#include <iostream>
#include <vector>

class Counter {
public:
    int value;
    struct LogEntry {
        std::string action;
        int oldValue;
        int newValue;
    };
    std::vector<LogEntry> log;
    Counter(int initial = 0) {
        this->value = initial;
    }
    Counter& inc(int delta = 1) {
        auto old = this->value;
        this->value += delta;
        log.push_back({"inc", old, this->value});
        return *this;
    }
    Counter& dec(int delta = 1) {
        auto old = this->value;
        this->value += delta;
        log.push_back({"dec", old, this->value});
        return *this;
    }
    Counter& set(int delta = 1) {
        auto old = this->value;
        this->value += delta;
        log.push_back({"set", old, this->value});
        return *this;
    }
    void printLog() const {
        for (auto l : this->log) {
            std::cout << "Action = " << l.action << ' ';
            std::cout << "OldValue = " << l.oldValue << ' ';
            std::cout << "NewValue = " << l.newValue << '\n';
        }
    }
    int getValue() {
        return log[log.size() - 1].newValue;
    }
};

int main() {
    Counter c(0);
    c.inc(5).dec(2).set(10).inc();

    std::cout << "Final value : " << c.getValue() << "\n";
    std::cout << "=== Log of operations ===\n";
    c.printLog();
    /*
    ---output---
    Final value : 18
    === Log of operations ===
    Action = inc OldValue = 0 NewValue = 5
    Action = dec OldValue = 5 NewValue = 7
    Action = set OldValue = 7 NewValue = 17
    Action = inc OldValue = 17 NewValue = 18
    */
    return 0;
}
