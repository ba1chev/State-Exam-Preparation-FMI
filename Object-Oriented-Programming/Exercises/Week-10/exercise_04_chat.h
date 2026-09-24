#pragma once
#include <memory>
#include <cstring>
#include <vector>
#include "exercise_04_message.h"

class User;

class Chat : public std::enable_shared_from_this<Chat> {
private:
    char* name = nullptr;
    std::vector<std::weak_ptr<User>> usersWeakPtrs;
    std::vector<char*> mutedNames;

    void free();
    Chat(const char* name);

public:
    Chat(const Chat& other) = delete;
    Chat(Chat&& other) noexcept = delete;
    Chat& operator = (const Chat& other) = delete;
    Chat& operator = (Chat&& other) noexcept = delete;
    ~Chat();

    static std::shared_ptr<Chat> create(const char* name);
    std::shared_ptr<Chat> join(const std::shared_ptr<User>& user);

    std::weak_ptr<User> operator [] (size_t index);
    const std::weak_ptr<User> operator [] (size_t index) const;

    void leave(const char* name);
    void kick(const char* name);
    void mute(const char* name);
    void unmute(const char* name);
    void broadcast(const Message& message) const;

    bool isMuted(const char* name) const;
    size_t getUsersCount() const;
    const char* getName() const;
};
