#pragma once
#include "exercise_03_node.h"

class Directory: public Node {
private:
    Node** data = nullptr;
    size_t dataSize = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const Directory& other);
    void moveTo(Directory&& other) noexcept;

public:
    Directory(const char* name);
    Directory(const Directory& other);
    Directory(Directory&& other) noexcept;
    Directory& operator = (const Directory& other);
    Directory& operator = (Directory&& other) noexcept;
    ~Directory();

    void addNode(Node* node);
    Node* findNode(const char* name) const;
    int size() const override;
    void print(int indent) const override;
    Node* clone() const override;
};