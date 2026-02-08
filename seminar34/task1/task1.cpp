/*
    Works with memory, cstdio, string, stdexcept libraries
    Demonstrates the smart pointers and creates output.log
*/

#include <iostream>
#include <memory>
#include <cstdio>
#include <string>
#include <stdexcept>


struct deleter {
    void operator()(FILE* fp) const {
        if (fp) {
            std::cout << "deleter\n";
            std::fclose(fp);
        }
    }
};

class FileLogger {
protected:
    std::unique_ptr<FILE, deleter> file_;
public:
    explicit FileLogger(const std::string& path) {
        FILE* fp = std::fopen(path.c_str(), "w");
        if (!fp) {
            throw std::runtime_error("File wasn't opened: " + path);
        }
        file_.reset(fp);
    }
    
    FileLogger(const FileLogger&) = delete;
    FileLogger& operator=(const FileLogger&) = delete;

    FileLogger(FileLogger&&) noexcept = default;
    FileLogger& operator=(FileLogger&&) noexcept = default;

    void log(const std::string& message) {
        if (file_) {
            std::fprintf(file_.get(), "%s\n", message.c_str());
            std::fflush(file_.get());
        }
    }
};

int main() {
    FileLogger logger("output.log");
    logger.log("Application started");
    logger.log("Processing data...");
}
