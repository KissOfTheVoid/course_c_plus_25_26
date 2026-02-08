#include "myvector.h"


#include <iostream>
#include <vector>

int main() {
    Myvector<int> myvector;
    std::vector<int> stdvector;
    std::cout << "My vector\n Size = " << myvector.Size() << "\n Capacity = " << myvector.Capacity() << std::endl;
    std::cout << "Std vector\n Size = " << stdvector.size() << "\n Capacity = " << stdvector.capacity() << std::endl;
    


    myvector.PushBack(10);
    stdvector.push_back(10);
    myvector.PushBack(20);
    stdvector.push_back(20);
    myvector.PushBack(30);
    stdvector.push_back(30);

    std::cout << "\nSize after PushBacks\n";
    std::cout << "My vector\n Size = " << myvector.Size() << "\n Capacity = " << myvector.Capacity() << std::endl;
    std::cout << "Std vector\n Size = " << stdvector.size() << "\n Capacity = " << stdvector.capacity() << std::endl;
    
    std::cout << "\nThe content after PushBacks\n";
    std::cout << "My vector's content = ";
    for (auto x : myvector) std::cout << x << ' ';
    std::cout << "\n Std vector's content = ";
    for (auto x : stdvector) std::cout << x << ' ';
    std::cout << std::endl;



    myvector.EmplaceBack(40);
    stdvector.emplace_back(40);

    std::cout << "\nSize after EmplaceBacks\n";
    std::cout << "My vector\n Size = " << myvector.Size() << "\n Capacity = " << myvector.Capacity() << std::endl;
    std::cout << "Std vector\n Size = " << stdvector.size() << "\n Capacity = " << stdvector.capacity() << std::endl;

    std::cout << "\nThe content after EmplaceBacks\n";
    std::cout << "My vector's content = ";
    for (auto x : myvector) std::cout << x << ' ';
    std::cout << "\nStd vector's content = ";
    for (auto x : stdvector) std::cout << x << ' ';
    std::cout << std::endl;



    myvector.PopBack();
    stdvector.pop_back();

    std::cout << "\nSize after PopBacks\n";
    std::cout << "My vector\n Size = " << myvector.Size() << "\n Capacity = " << myvector.Capacity() << std::endl;
    std::cout << "Std vector\n Size = " << stdvector.size() << "\n Capacity = " << stdvector.capacity() << std::endl;

    std::cout << "\nThe content after PopclasBacks\n";
    std::cout << "My vector's content = ";
    for (auto x : myvector) std::cout << x << ' ';
    std::cout << "\nStd vector's content = ";
    for (auto x : stdvector) std::cout << x << ' ';
    std::cout << std::endl;



    myvector.Resize(5);
    stdvector.resize(5);

    std::cout << "\nSize after Resize\n";
    std::cout << "My vector\n Size = " << myvector.Size() << "\n Capacity = " << myvector.Capacity() << std::endl;
    std::cout << "Std vector\n Size = " << stdvector.size() << "\n Capacity = " << stdvector.capacity() << std::endl;


    return 0;
}