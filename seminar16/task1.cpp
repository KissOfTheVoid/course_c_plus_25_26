/*
    Works with vector, string libraries
    Permission management system with enum class as bit flags, where
        an enum class Permission with rights: READ, WRITE, EXECUTE, DELETE
        implemented bitwise operations (—, &, ˜) for permission combinations
        a function to check for specific permissions
        a collection of users with their access rights
*/

#include <iostream>
#include <vector>
#include <string>

enum class Permission {
    READ = 1,   // 0001
    WRITE = 2,  // 0010
    EXECUTE = 4,// 0100
    DELETE = 8  // 1000
};

Permission operator|(Permission _per1, Permission _per2) {
    return (Permission)(((int)(_per1) | (int)(_per2)));
}

Permission operator&(Permission _per1, Permission _per2) {
    return (Permission)(((int)(_per1) & (int)(_per2)));
}

Permission operator~(Permission _per) {
    return (Permission)((int)(_per));
}

bool is_allowed(Permission _users, Permission _allowed) {
    return (_users & _allowed) == _allowed;
}

struct User {
    std::string name;
    Permission permission;
};

int main() {
    std::vector<User> users = {
        {"user1", Permission::READ | Permission::WRITE},
        {"user2", Permission::READ | Permission::WRITE | Permission::EXECUTE | Permission::DELETE},
        {"user3", Permission::DELETE}
    };
    for (const auto& user : users) {
        std::cout << "User - " << user.name << " permissions \n READ \t";
        std::cout << is_allowed(user.permission, Permission::READ) << "\n WRITE \t";
        std::cout << is_allowed(user.permission, Permission::WRITE) << "\n EXECUTE \t";
        std::cout << is_allowed(user.permission, Permission::EXECUTE) << "\n DELETE \t";
        std::cout << is_allowed(user.permission, Permission::DELETE) << '\n';
    }
    /*
    ---output---
    User - user1 permissions 
    READ   1
    WRITE  1
    EXECUTE        0
    DELETE         0
    User - user2 permissions 
    READ   1
    WRITE  1
    EXECUTE        1
    DELETE         1
    User - user3 permissions 
    READ   0
    WRITE  0
    EXECUTE        0
    DELETE         1
    */
    return 0;
}