/*
    Works with cstdint, type_traits, vector, list, map, string libraries
    Huuuuge demonstration of the work of different STL containers with bit flags, which are in according template class, also with the filter fitcha
*/

#include <cstdint>
#include <type_traits>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>


template<typename Enum>
class BitFlags {
    static_assert(std::is_enum_v<Enum>, "Enum must be an enum type");
public:
    using Under = std::underlying_type_t<Enum>;

    BitFlags() = default;
    BitFlags(Enum e) : bits_(static_cast<Under>(e)) {}
    explicit BitFlags(Under bits) : bits_(bits) {}

    void set(Enum e) { 
        bits_ |= static_cast<Under>(e); 
    }
    void reset(Enum e) {
        bits_ &= ~static_cast<Under>(e);
    }
    void toggle(Enum e) {
        bits_ ^= static_cast<Under>(e);
    }

    bool test(Enum e) const { 
        return bits_ & static_cast<Under>(e); 
    }

    void clear() {
        bits_ = 0;
    }

    Under value() const {
        return bits_;
    }

    bool containsAll(BitFlags other) const {
        return (bits_ & other.bits_) == other.bits_;
    }

    bool containsAny(BitFlags other) const {
        return (bits_ & other.bits_) != 0;
    }

private:
    Under bits_ = 0;
};

enum class Permission : std::uint8_t {
    Read  = 1 << 0,
    Write = 1 << 1,
    Exec  = 1 << 2,
    Admin = 1 << 3
};

using PermFlags = BitFlags<Permission>;

struct User {
    std::string name;
    PermFlags   perms;
};

std::vector<User> usersVec;
std::list<User>   usersList;
std::map<int, PermFlags> groupPerms;


void initData() {
    User u1{"User1", PermFlags{}};
    u1.perms.set(Permission::Read);
    u1.perms.set(Permission::Write);

    User u2{"User2", PermFlags{}};
    u2.perms.set(Permission::Read);

    User u3{"User3", PermFlags{}};
    u3.perms.set(Permission::Read);
    u3.perms.set(Permission::Write);
    u3.perms.set(Permission::Exec);
    u3.perms.set(Permission::Admin);

    usersVec = {u1, u2, u3};
    usersList = {u1, u2, u3};

    groupPerms[1] = u1.perms;
    groupPerms[2] = u3.perms;
}


template<typename Container>
std::vector<typename Container::value_type>
filterByAll(const Container& c, PermFlags required) {
    std::vector<typename Container::value_type> result;
    for (const auto& x : c) {
        if (x.perms.containsAll(required)) {
            result.push_back(x);
        }
    }
    return result;
}

template<typename Container>
std::vector<typename Container::value_type>
filterByAny(const Container& c, PermFlags mask) {
    std::vector<typename Container::value_type> result;
    for (const auto& x : c) {
        if (x.perms.containsAny(mask)) {
            result.push_back(x);
        }
    }
    return result;
}


int main() {
    initData();

    PermFlags needRW;
    needRW.set(Permission::Read);
    needRW.set(Permission::Write);

    auto rwUsers = filterByAll(usersVec, needRW);
    std::cout << "Users with R+W:\n";
    for (const auto& u : rwUsers) {
        std::cout << "  " << u.name << std::endl;
    }

    PermFlags anyAdmin;
    anyAdmin.set(Permission::Admin);

    auto admins = filterByAny(usersList, anyAdmin);
    std::cout << "Users with Admin:\n";
    for (const auto& u : admins) {
        std::cout << "  " << u.name << std::endl;
    }
    /*
    ---output---
    Users with R+W:
    User1
    User3
    Users with Admin:
    User3
    */
    return 0;
}
