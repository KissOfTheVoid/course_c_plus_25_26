/*
    Work string library
    A system where the user has a nested address class, and methods use `this` to:
        access fields,
        check self-assignment in the assignment operator,
        construct a string representation
*/

#include <iostream>
#include <string>


class User {
public:
    std::string name;
    int id;
    class Address {
    public:
        std::string city;
        std::string street;
        int house;
        std::string toString() const {
            return "city:" + this->city + " street:" + this->street + " house:" + std::to_string(this->house);
        }
    };
    Address address;
    User(const std::string& n, const int& i, const Address& addr) {
        this->name = n;
        this->id = i;
        this->address = addr;
    }

    User(const User& other) {
        this->name = other.name;
        this->id = other.id;
        this->address = other.address;
    }

    User& operator = (const User& other) {
        this->name = other.name;
        this->id = other.id;
        this->address = other.address;
        return *this;
    }
    std::string toString() const {
        return "User[name=" + this->name + ", id=" + std::to_string(id) + ", address=" + address.toString() + "]";
    }

};

int main() {
    User::Address addr{"Moscow", "Tverskaya", 10};
    User u1{"Ivan", 1, addr};

    User u2 = u1;   // копирующий конструктор
    u2 = u2;        // self-assignment

    std::cout << u1.toString() << "\n";
    std::cout << u2.toString() << "\n";
    /*
    ---output---
    User[name=Ivan, id=1, address=city:Moscow street:Tverskaya house:10]
    User[name=Ivan, id=1, address=city:Moscow street:Tverskaya house:10]
    */
    return 0;
}
