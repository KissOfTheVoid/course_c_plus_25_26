/*
    Works with memory, string libraries
    Document class that:
        Has a std::string content_ member
        Tracks how many shared_ptr<Document> instances exist via a static counter
        Logs creation/destruction with current reference count
        Has a clone() method returning std::shared_ptr<Document> with copied content
        Use constructor/destructor to update static counter
*/

#include <memory>
#include <string>
#include <iostream>

class Document {
    std::string content_;
    static int instance_count_;
public:
    explicit Document(std::string content);
    ~Document();
    std::shared_ptr<Document> clone() const;
    const std::string& content() const { return content_; }
};

int Document::instance_count_ = 0;

Document::Document(std::string content) : content_(std::move(content)) {
    ++instance_count_;
    std::cout << "current reference count " << instance_count_ << std::endl;
}

Document::~Document() {
    std::cout << "current reference count " << --instance_count_ << std::endl;
}

std::shared_ptr<Document> Document::clone() const {
    return std::make_shared<Document>(content_);
}

int main() {
    {
        auto doc1 = std::make_shared<Document>("Original");
        auto doc2 = doc1;
        auto doc3 = doc1->clone();
        std::cout << doc1.use_count() << "\n";
    }
    std::cout << "Out of scope\n";
    /*
    ---output---
    current reference count 1
    current reference count 2
    2
    current reference count 1
    current reference count 0
    Out of scope
    */
    return 0;
}
