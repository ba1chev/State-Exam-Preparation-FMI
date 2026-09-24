#include "exercise_04_user.h"
#include "exercise_04_chat.h"

User::User(const char* name, UserType type) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    this->name = new char[strlen(name) + 1]{};
    this->type = type;
    strncpy(this->name, name, strlen(name));
}

User::~User() {
    this->free();
}

void User::free() {
    this->type = UserType::Default;
    delete[] this->name;
    this->name = nullptr;
}

void User::joinChat(const std::shared_ptr<Chat>& chat) {
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chat->getName())) {
            return;
        }
    }
    this->chats.push_back(chat);
}

void User::leaveChat(const char* chatName) {
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chatName)) {
            this->chats[i]->leave(this->name);
            this->chats.erase(this->chats.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Chat not found");
}

void User::send(const char* chatName, const char* content) {
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chatName)) {
            if (this->chats[i]->isMuted(this->name)) {
                return;
            }
            Message message = Message(this->name, content, chatName);
            this->chats[i]->broadcast(message);
            return;
        }
    }
    throw std::runtime_error("Chat not found");
}

void User::receive(const Message& message) const {
    std::cout << "[" << this->name << " received]" << std::endl;
    std::cout << message;
}

void User::sendPrivate(const char* chatName, const char* recipient, const char* content) {
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chatName)) {
            Message message = Message(this->name, content, recipient);
            for (size_t j = 0; j < this->chats[i]->getUsersCount(); j++) {
                std::shared_ptr<User> currentUserPtr = (*this->chats[i])[j].lock();
                if (currentUserPtr && !strcmp(currentUserPtr->getName(), recipient)) {
                    currentUserPtr->receive(message);
                    return;
                }
            }
            throw std::runtime_error("Recipient not found");
        }
    }
    throw std::runtime_error("Chat not found");
}

void User::kick(const char* chatName, const char* userName) {
    if (this->type != UserType::Moderator) {
        throw std::runtime_error("Only moderators can kick");
    }
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chatName)) {
            this->chats[i]->kick(userName);
            return;
        }
    }
    throw std::runtime_error("Chat not found");
}

void User::mute(const char* chatName, const char* userName) {
    if (this->type != UserType::Moderator) {
        throw std::runtime_error("Only moderators can mute");
    }
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chatName)) {
            this->chats[i]->mute(userName);
            return;
        }
    }
    throw std::runtime_error("Chat not found");
}

void User::unmute(const char* chatName, const char* userName) {
    if (this->type != UserType::Moderator) {
        throw std::runtime_error("Only moderators can unmute");
    }
    for (size_t i = 0; i < this->chats.size(); i++) {
        if (!strcmp(this->chats[i]->getName(), chatName)) {
            this->chats[i]->unmute(userName);
            return;
        }
    }
    throw std::runtime_error("Chat not found");
}

UserType User::getType() const {
    return this->type;
}

const char* User::getName() const {
    return this->name;
}
