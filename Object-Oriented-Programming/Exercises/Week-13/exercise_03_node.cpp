#include "exercise_03_node.h"

void Node::free() {
    delete[] this->name;
    this->name = nullptr;
    this->type = NodeType::None;
}

void Node::copyFrom(const Node& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->type = other.type;
}

void Node::moveTo(Node&& other) noexcept {
    this->name = other.name;
    this->type = other.type;

    other.name = nullptr;
    other.type = NodeType::None;
}

Node::Node(const char* name, NodeType type) {
    if (!name || type == NodeType::None) {
        throw std::runtime_error("Nullptre detected or invaid node type");
    }
    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->type = type;
}

Node::Node(const Node& other) {
    this->copyFrom(other);
}

Node::Node(Node&& other) noexcept {
    this->moveTo(std::move(other));
}

Node& Node::operator = (const Node& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Node& Node::operator = (Node&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Node::~Node() {
    this->free();
}

const char* Node::getName() const {
    return this->name;
}

NodeType Node::getType() const {
    return this->type;
}