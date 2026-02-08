/*
    Works with iomanip, vector libraries
    Employee payroll system with inheritance and polymorphism
*/

#include <iostream>
#include <iomanip>
#include <vector>


//1st part
//An interface-like class in C++ is an abstract base class containing 
//only pure virtual functions (declared with = 0), 
//which defines a contract that derived classes must implement, 
//without providing any implementation details itself.
class Reportable {
public:
    virtual void printShortReport() const = 0; // abstract
protected:
    virtual ~Reportable() = default;
};


// 2nd part
class Employee : public Reportable {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string _name, int _id) : name(_name), id(_id) {};

    virtual double calculatePay() const = 0;

    virtual std::string getRole() const = 0;
    virtual void printInfo() const = 0;
    virtual bool isManager() const {
        return false;
    };

    void printShortReport() const override {
        std::cout << name << ' ' << id << getRole() << std::endl;
    };

    virtual ~Employee() = default;
};

// 3rd part
class SalariedEmployee : public Employee {
protected:
    double monthSalary;
public:
    SalariedEmployee(const std::string _name, int _id, double _month_salary) : Employee(_name, _id), monthSalary(_month_salary) {};

    //overrriding
    double calculatePay() const override {
        return monthSalary;
    };
    std::string getRole() const override {
        return "SalariedEmployee";
    };
    void printInfo() const override {
        std::cout << id << ' ' << name << ' ' << getRole() << ' ' << monthSalary << std::endl;
    };
    bool isManager() const override {
        return false;
    };
};


//4th part
class HourlyEmployee final : public Employee {
protected:
    double hourlyRate;
    double hoursWorked;
public:
    HourlyEmployee(const std::string _name, int _id, double _hourly_rate, double _hours_worked) : Employee(_name, _id), hourlyRate(_hourly_rate), hoursWorked(_hours_worked) {};
    //ovirriding
    double calculatePay() const override {
        return hourlyRate * hoursWorked;
    };
    std::string getRole() const override {
        return "HourlyEmployee";
    };
    void printInfo() const override {
        std::cout << id << ' ' << name << ' ' << getRole() << ' ' << hourlyRate << ' ' << hoursWorked << std::endl;
    };
    bool isManager() const override {
        return false;
    };
};

//5th part
class Manager final : public SalariedEmployee {
protected:
    double bonus;
public:
    Manager(const std::string _name, int _id, double _month_salary, double _bonus) : SalariedEmployee(_name, _id, _month_salary), bonus(_bonus) {};
    double calculatePay() const override {
        return monthSalary + bonus;
    };
    std::string getRole() const override {
        return "Manager";
    };
    void printInfo() const override {
        std::cout << id << ' ' << name << ' ' << getRole() << ' ' << monthSalary << ' ' << bonus << std::endl;
    };
    bool isManager() const override {
        return true;
    };
};

//6th part
class Company {
protected:
    std::vector<Employee*> employees;
public:
    void addEmployee(Employee* e) {
        employees.push_back(e);
    };
    void printAllEmployees() const {
        for (auto& e : employees) {
            e->printInfo();
        }
    };
    void printAllShortReports() const {
        for (auto& e : employees) {
            e->printShortReport();
        }
    };
    double calculateTotalPayroll() const {
        double s = 0;
        for (auto& e : employees) {
            s += e->calculatePay();
        }
        std::cout << s << std::endl;
        return s;
    };
    int countManager() const {
        uint8_t s = 0;
        for (auto& e : employees) {
            s += e->isManager();
        }
        std::cout << s << std::endl;
        return s;
    };
    ~Company()  {
        for (auto& e : employees) {
            delete e;
        }
    };
};

//7th part
int main() {
    Company fancyCompany;
    fancyCompany.addEmployee(new SalariedEmployee("name0", 0, 0.1));
    fancyCompany.addEmployee(new HourlyEmployee("name1", 1, 0.0083, 47653.33));
    fancyCompany.addEmployee(new Manager("name2", 2, 0.600, 234435));

    fancyCompany.printAllEmployees();
    fancyCompany.printAllShortReports();
    fancyCompany.calculateTotalPayroll();
    fancyCompany.countManager();
    /*
    ---output---
    0 name0 SalariedEmployee 0.1
    1 name1 HourlyEmployee 0.0083 47653.3
    2 name2 Manager 0.6 234435
    name0 0SalariedEmployee
    name1 1HourlyEmployee
    name2 2Manager
    234831
    */
    return 0;
}