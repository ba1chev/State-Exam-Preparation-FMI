#include "exercise_03_file.h"

void File::free() {
    delete[] this->data;
    this->data = nullptr;
}

void File::copyFrom(const File& other) {
    this->data = new char[strlen(other.data) + 1]{};
    strncpy(this->data, other.data, strlen(other.data));
}

void File::moveTo(File&& other) noexcept {
    this->data = other.data;
    other.data = nullptr;
}

File::File(const char* name, const char* data): Node(name, NodeType::File) {
    if (!name || !data) {
        throw std::runtime_error("Nullptr detected");
    }
    this->data = new char[strlen(data) + 1]{};
    strncpy(this->data, data, strlen(data));
}

File::File(const File& other): Node(other) {
    this->copyFrom(other);
}

File::File(File&& other) noexcept: Node(std::move(other)) {
    this->moveTo(std::move(other));
}

File& File::operator = (const File& other) {
    if (this != &other) {
        this->free();
        Node::free();
        this->copyFrom(other);
        Node::copyFrom(other);
    }
    return *this;
}

File& File::operator = (File&& other) noexcept {
    if (this != &other) {
        this->free();
        Node::free();
        this->moveTo(std::move(other));
        Node::moveTo(std::move(other));
    }
    return *this;
}

File::~File() {
    this->free();
}

int File::size() const {
    return strlen(this->data);
}

void File::print(int indent) const {
    for (int i = 0; i < indent; i++) {
        std::cout << " ";
    }
    std::cout << this->getName() << " (" << this->size() << ")" << std::endl;
}

const char* File::getData() const {
    return this->data;
}

Node* File::clone() const {
    return new File(*this);
}