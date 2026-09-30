#pragma once
#include "exercise_03_node.h"

class File: public Node {
private:
    char* data = nullptr;

    void free();
    void copyFrom(const File& other);
    void moveTo(File&& other) noexcept;

public:
    File(const char* name, const char* data);
    File(const File& other);
    File(File&& other) noexcept;
    File& operator = (const File& other);
    File& operator = (File&& other) noexcept;
    ~File();

    int size() const override;
    void print(int indent) const override;
    Node* clone() const override;
    const char* getData() const;
};