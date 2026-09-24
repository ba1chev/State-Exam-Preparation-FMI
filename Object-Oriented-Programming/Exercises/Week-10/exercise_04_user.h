#pragma once
#include <memory>
#include <cstring>
#include <iostream>
#include <vector>
#include "exercise_04_message.h"

class Chat;

enum class UserType {
    Default, Moderator
};

class User {
private:
    char* name = nullptr;
    UserType type = UserType::Default;
    std::vector<std::shared_ptr<Chat>> chats;

    void free();

public:
    User() = delete;
    User(const char* name, UserType type);
    User(const User& other) = delete;
    User(User&& other) noexcept = delete;
    User& operator = (const User& other) = delete;
    User& operator = (User&& other) noexcept = delete;
    ~User();

    void send(const char* chatName, const char* content);
    void receive(const Message& message) const;
    void sendPrivate(const char* chatName, const char* recipient, const char* content);

    void joinChat(const std::shared_ptr<Chat>& chat);
    void leaveChat(const char* chatName);
    void kick(const char* chatName, const char* userName);
    void mute(const char* chatName, const char* userName);
    void unmute(const char* chatName, const char* userName);

    UserType getType() const;
    const char* getName() const;
};
