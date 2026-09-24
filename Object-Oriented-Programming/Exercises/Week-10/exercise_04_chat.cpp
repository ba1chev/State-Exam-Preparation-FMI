#include "exercise_04_chat.h"
#include "exercise_04_user.h"

void Chat::free() {
    delete[] this->name;
    this->name = nullptr;

    for (size_t i = 0; i < this->mutedNames.size(); i++) {
        delete[] this->mutedNames[i];
    }
    this->mutedNames.clear();
}

bool Chat::isMuted(const char* name) const {
    for (size_t i = 0; i < this->mutedNames.size(); i++) {
        if (!strcmp(this->mutedNames[i], name)) {
            return true;
        }
    }
    return false;
}

Chat::Chat(const char* name) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }
    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
}

std::shared_ptr<Chat> Chat::create(const char* name) {
    return std::shared_ptr<Chat>(new Chat(name));
}

Chat::~Chat() {
    this->free();
}

std::shared_ptr<Chat> Chat::join(const std::shared_ptr<User>& user) {
    this->usersWeakPtrs.push_back(user);
    return this->shared_from_this();
}

void Chat::leave(const char* name) {
    for (size_t i = 0; i < this->usersWeakPtrs.size(); i++) {
        std::shared_ptr<User> currentUserPtr = this->usersWeakPtrs[i].lock();
        if (currentUserPtr && !strcmp(currentUserPtr->getName(), name)) {
            this->usersWeakPtrs.erase(this->usersWeakPtrs.begin() + i);
            return;
        }
    }
}

void Chat::kick(const char* name) {
    this->leave(name);
}

void Chat::mute(const char* name) {
    if (this->isMuted(name)) {
        return;
    }
    char* mutedName = new char[strlen(name) + 1]{};
    strncpy(mutedName, name, strlen(name));
    this->mutedNames.push_back(mutedName);
}

void Chat::unmute(const char* name) {
    for (size_t i = 0; i < this->mutedNames.size(); i++) {
        if (!strcmp(this->mutedNames[i], name)) {
            delete[] this->mutedNames[i];
            this->mutedNames.erase(this->mutedNames.begin() + i);
            return;
        }
    }
}

std::shared_ptr<User> Chat::operator [] (const char* name) {
    for (size_t i = 0; i < this->usersWeakPtrs.size(); i++) {
        std::shared_ptr<User> currentUserPtr = this->usersWeakPtrs[i].lock();
        if (currentUserPtr && !strcmp(currentUserPtr->getName(), name)) {
            return currentUserPtr;
        }
    }
    return nullptr;
}

void Chat::broadcast(const Message& message) {
    if (this->isMuted(message.getSender())) {
        return;
    }
    this->history.push_back(message);

    if (!strcmp(message.getRecipient(), this->name)) {
        for (size_t i = 0; i < this->usersWeakPtrs.size(); i++) {
            std::shared_ptr<User> currentUserPtr = this->usersWeakPtrs[i].lock();
            if (currentUserPtr && strcmp(currentUserPtr->getName(), message.getSender())) {
                currentUserPtr->receive(message);
            }
        }
        return;
    }

    std::shared_ptr<User> recipientPtr = (*this)[message.getRecipient()];
    if (recipientPtr) {
        recipientPtr->receive(message);
    }
}

Chat::operator bool() const {
    size_t aliveUsers = 0;
    for (size_t i = 0; i < this->usersWeakPtrs.size(); i++) {
        if (this->usersWeakPtrs[i].lock()) {
            aliveUsers += 1;
        }
    }
    return aliveUsers >= 2;
}

const char* Chat::getName() const {
    return this->name;
}

size_t Chat::getUsersCount() const {
    return this->usersWeakPtrs.size();
}

std::ostream& operator << (std::ostream& os, const Chat& chat) {
    os << "[Chat]:  " << chat.name << std::endl;
    os << "[Users]: " << chat.getUsersCount() << std::endl;
    os << "[History]:" << std::endl;
    for (size_t i = 0; i < chat.history.size(); i++) {
        os << chat.history[i];
    }
    return os;
}
