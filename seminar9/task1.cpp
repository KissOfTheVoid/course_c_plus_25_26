/*
    Works with thread and chrono libraries
    Creates a loader with symbols -/\|
*/

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Loading: ";
    std::string syms = "-/\\|";
    int c = 1;
    while (c <= 10) {
        for (int i = 0; i < syms.length(); i++) {
            std::cout << syms[i] << std::flush;
            //std::cout << syms[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::cout  << '\r' << "Loading: " << std::flush;
        }
        ++c;
    }
    std::cout << "Done!";
    /*
    the output is dynamic, in the end it's Loading: Done!
    */
    return 0;
}