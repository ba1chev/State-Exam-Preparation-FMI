#pragma once
#include <cstring>
#include <iostream>

enum class NodeType {
    File, Directory, None
};

class Node {
protected:
    char* name = nullptr;
    NodeType type = NodeType::None;

    void free();
    void copyFrom(const Node& other);
    void moveTo(Node&& other) noexcept;

public:
    Node(const char* name, NodeType type);
    Node(const Node& other);
    Node(Node&& other) noexcept;
    Node& operator = (const Node& other);
    Node& operator = (Node&& other) noexcept;

    virtual ~Node();
    virtual int size() const = 0;
    virtual void print(int indent) const = 0;
    virtual Node* clone() const = 0;

    const char* getName() const;
    NodeType getType() const;
};
