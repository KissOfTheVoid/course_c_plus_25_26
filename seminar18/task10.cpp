/*
    Works with string, vector, map libraries
    System for storing works, their roles and possible actions
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class Role {
    ENGINEER,
    MANAGER,
    HR,
    SECURITY,
    INTERN
};

std::string roleToString(Role r) {
    switch (r) {
        case Role::ENGINEER: return "ENGINEER";
        case Role::MANAGER:  return "MANAGER";
        case Role::HR:       return "HR";
        case Role::SECURITY: return "SECURITY";
        case Role::INTERN:   return "INTERN";
    }
    return "UNKNOWN";
}

struct Employee {
    std::string name;
    int id;
    Role role;
    float salary;
};

void printEmployee(const Employee& e) {
    std::cout << "[" << e.id << "] " << e.name << " — " << roleToString(e.role) << " — " << e.salary << '\n';
}

std::vector<Employee> filterByRole(const std::vector<Employee>& staff, Role role) {
    std::vector<Employee> result;
    for (const auto& e : staff) {
        if (e.role == role) {
            result.push_back(e);
        }
    }
    return result;
}

std::map<Role, float> averageSalaryByRole(const std::vector<Employee>& staff) {
    std::map<Role, float> sum;
    std::map<Role, int>   count;

    for (const auto& e : staff) {
        sum[e.role]   += e.salary;
        count[e.role] += 1;
    }

    std::map<Role, float> avg;
    for (const auto& [role, s] : sum) {
        avg[role] = s / count[role];
    }
    return avg;
}

void printAverages(const std::map<Role, float>& avg) {
    Role roles[] = {Role::ENGINEER, Role::MANAGER, Role::HR, Role::SECURITY, Role::INTERN};

    for (Role r : roles) {
        std::string prefix;
        switch (r) {
            case Role::ENGINEER:
                prefix = "ENGINEER: ";
                break;
            case Role::MANAGER:
                prefix = "MANAGER: ";
                break;
            case Role::HR:
                prefix = "HR: ";
                break;
            case Role::SECURITY:
                prefix = "SECURITY: ";
                break;
            case Role::INTERN:
                prefix = "INTERN: ";
                break;
        }

        std::cout << prefix;
        auto it = avg.find(r);
        if (it != avg.end()) {
            std::cout << it->second;
        } else {
            std::cout << "нет данных";
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<Employee> staff = {
        {"First", 1, Role::ENGINEER, 12},
        {"Second", 2, Role::MANAGER, 32},
        {"Third", 3, Role::INTERN, 1},
        {"Fourth", 4, Role::HR, 12000},
        {"Tenth", 5, Role::ENGINEER, 13},
        {"Eleventh", 6, Role::SECURITY, 3}
    };

    for (const auto& e : staff) {
        printEmployee(e);
    }

    std::cout << "ENGINEER" << std::endl;
    auto engineers = filterByRole(staff, Role::ENGINEER);
    for (const auto& e : engineers) {
        std::cout << e.name << std::endl;
    }

    std::cout << "Average wage" << std::endl;
    auto avg = averageSalaryByRole(staff);
    printAverages(avg);
    /*
    ---output---
    [1] First — ENGINEER — 12
    [2] Second — MANAGER — 32
    [3] Third — INTERN — 1
    [4] Fourth — HR — 12000
    [5] Tenth — ENGINEER — 13
    [6] Eleventh — SECURITY — 3
    ENGINEER
    First
    Tenth
    Average wage
    ENGINEER: 12.5
    MANAGER: 32
    HR: 12000
    SECURITY: 3
    INTERN: 1
    */
    return 0;
}
