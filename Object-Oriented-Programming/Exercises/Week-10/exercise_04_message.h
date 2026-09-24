#pragma once
#include <iostream>
#include <cstring>

class Message {
private:
    char* sender = nullptr;
    char* content = nullptr;
    char* recipient = nullptr;

    void free();
    void copyFrom(const Message& other);
    void moveTo(Message&& other);

public:
    Message() = default;
    Message(const char* sender, const char* content, const char* recipient);
    Message(const Message& other);
    Message(Message&& other) noexcept;
    Message& operator = (const Message& other);
    Message& operator = (Message&& other) noexcept;
    ~Message();

    const char* getSender() const;
    const char* getRecipient() const;

    friend std::ostream& operator << (std::ostream& os, const Message& message);
};