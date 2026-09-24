#include "exercise_04_chat.h"
#include "exercise_04_user.h"

void testMessage() {
    Message message = Message(
        "Yoan Baychev", "Hello what's up", "Magi Dicheva"
    );
    std::cout << message;
}

void testChat() {
    std::shared_ptr<User> moderator = std::make_shared<User>("Yoan Baychev", UserType::Moderator);
    std::shared_ptr<User> magi = std::make_shared<User>("Magi Dicheva", UserType::Default);
    std::shared_ptr<User> ivan = std::make_shared<User>("Ivan Ivanov", UserType::Default);

    std::shared_ptr<Chat> chat = Chat::create("FMI");
    chat->join(moderator);
    chat->join(magi);
    chat->join(ivan);

    moderator->joinChat(chat);
    magi->joinChat(chat);
    ivan->joinChat(chat);

    std::cout << "--- broadcast ---" << std::endl;
    moderator->send("FMI", "Hello everyone");

    std::cout << "--- mute Ivan, he tries to send ---" << std::endl;
    moderator->mute("FMI", "Ivan Ivanov");
    ivan->send("FMI", "This should not be delivered");

    std::cout << "--- kick Ivan ---" << std::endl;
    moderator->kick("FMI", "Ivan Ivanov");
    std::cout << "Users left: " << chat->getUsersCount() << std::endl;

    std::cout << "--- private message ---" << std::endl;
    moderator->sendPrivate("FMI", "Magi Dicheva", "Hi Magi, this is private");
}

int main() {
    testMessage();
    testChat();
    return 0;
}
