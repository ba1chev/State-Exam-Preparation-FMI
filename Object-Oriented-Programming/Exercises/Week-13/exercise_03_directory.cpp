#include "exercise_03_directory.h"
#include "exercise_03_duplicate_name_exception.h"
#include "exercise_03_not_found_exception.h"

void Directory::free() {
    for (size_t i = 0; i < this->dataSize; i++) {
        delete this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = nullptr;
    this->dataSize = 0;
    this->capacity = 0;
}

void Directory::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    this->capacity = newCapacity;
    Node** newData = new Node*[this->capacity]{nullptr};
    for (size_t i = 0; i < this->dataSize; i++) {
        newData[i] = this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = newData;
}

void Directory::copyFrom(const Directory& other) {
    this->dataSize = other.dataSize;
    this->capacity = other.capacity;
    this->data = new Node*[this->capacity]{nullptr};
    for (size_t i = 0; i < this->dataSize; i++) {
        this->data[i] = other.data[i]->clone();
    }
}

void Directory::moveTo(Directory&& other) noexcept {
    this->data = other.data;
    this->dataSize = other.dataSize;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.dataSize = 0;
    other.capacity = 0;
}

Directory::Directory(const char* name): Node(name, NodeType::Directory) {
    if (!name) {
        throw std::runtime_error("Nullptre detected");
    }

    this->dataSize = 0;
    this->capacity = 8;
    this->data = new Node*[this->capacity]{nullptr};
}

Directory::Directory(const Directory& other): Node(other) {
    this->copyFrom(other);
}

Directory::Directory(Directory&& other) noexcept: Node(std::move(other)) {
    this->moveTo(std::move(other));
}

Directory& Directory::operator = (const Directory& other) {
    if (this != &other) {
        this->free();
        Node::free();
        this->copyFrom(other);
        Node::copyFrom(other);
    }
    return *this;
}

Directory& Directory::operator = (Directory&& other) noexcept {
    if (this != &other) {
        this->free();
        Node::free();
        this->moveTo(std::move(other));
        Node::moveTo(std::move(other));
    }
    return *this;
}

Directory::~Directory() {
    this->free();
}

int Directory::size() const {
    int totalSize = 0;
    for (size_t i = 0; i < this->dataSize; i++) {
        totalSize += this->data[i]->size();
    }
    return totalSize;
}

void Directory::print(int indent) const {
    for (int i = 0; i < indent; i++) {
        std::cout << " ";
    }
    std::cout << this->getName() << "/" << std::endl;
    for (size_t i = 0; i < this->dataSize; i++) {
        this->data[i]->print(indent + 2);
    }
}

Node* Directory::clone() const {
    return new Directory(*this);
}

Node* Directory::findNode(const char* name) const {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < this->dataSize; i++) {
        if (!strcmp(this->data[i]->getName(), name)) {
            return this->data[i];
        }
    }
    throw NodeNotFoundException(name);
}

void Directory::addNode(Node* node) {
    if (!node) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < this->dataSize; i++) {
        if (!strcmp(this->data[i]->getName(), node->getName())) {
            throw DuplicateNameException(node->getName());
        }
    }

    if (this->dataSize == this->capacity) {
        this->resize(this->capacity * 2);
    }
    this->data[this->dataSize] = node->clone();
    this->dataSize += 1;
}