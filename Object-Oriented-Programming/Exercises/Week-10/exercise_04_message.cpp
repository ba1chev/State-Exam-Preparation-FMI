#include "exercise_04_message.h"

void Message::free() {
    delete[] this->content;
    delete[] this->recipient;
    delete[] this->sender;
    this->content = nullptr;
    this->recipient = nullptr;
    this->sender = nullptr;
}

void Message::copyFrom(const Message& other) {
    this->sender = new char[strlen(other.sender) + 1]{};
    this->recipient = new char[strlen(other.recipient) + 1]{};
    this->content = new char[strlen(other.content) + 1]{};
    strncpy(this->sender, other.sender, strlen(other.sender));
    strncpy(this->recipient, other.recipient, strlen(other.recipient));
    strncpy(this->content, other.content, strlen(other.content));
}

void Message::moveTo(Message&& other) {
    this->sender = other.sender;
    this->recipient = other.recipient;
    this->content = other.content;

    other.sender = nullptr;
    other.recipient = nullptr;
    other.content = nullptr;
}

Message::Message(const char* sender, const char* content, const char* recipient) {
    if (!sender || !content || !recipient) {
        throw std::runtime_error("Nullptr detected");
    }
    this->sender = new char[strlen(sender) + 1]{};
    this->recipient = new char[strlen(recipient) + 1]{};
    this->content = new char[strlen(content) + 1]{};
    strncpy(this->sender, sender, strlen(sender));
    strncpy(this->recipient, recipient, strlen(recipient));
    strncpy(this->content, content, strlen(content));
}

Message::Message(const Message& other) {
    this->copyFrom(other);
}

Message::Message(Message&& other) noexcept {
    this->moveTo(std::move(other));
}

Message& Message::operator = (const Message& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Message& Message::operator = (Message&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Message::~Message() {
    this->free();
}

const char* Message::getSender() const {
    return this->sender;
}

const char* Message::getRecipient() const {
    return this->recipient;
}

std::ostream& operator << (std::ostream& os, const Message& message) {
    os << "[Sender]:    " << message.sender << std::endl;
    os << "[Recipient]: " << message.recipient << std::endl;
    os << "[Content]:   " << message.content << std::endl;
    return os;
}