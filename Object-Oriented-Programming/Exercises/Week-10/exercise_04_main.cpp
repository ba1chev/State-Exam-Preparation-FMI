// Разработете чат система Slock, в която потребители комуникират помежду си чрез 
// споделени чатове. Всеки чат има име, списък с участници и история на разменените 
// съобщения. Потребителите могат да изпращат публични съобщения до целия чат или 
// лични съобщения до конкретен участник, а един и същи потребител може да участва 
// едновременно в няколко чата.

// Съобщение
// Всяко съобщение се характеризира с:

// Изпращач - име с произволна дължина
// Съдържание - низ с произволна дължина
// Получател - име с произволна дължина (незадължително)
// Потребител
// Всеки потребител се характеризира с: Име с произволна дължина (уникален идентификатор) Тип - обикновен или модератор Чатове, в които участва

// Класът няма конструктор по подразбиране.

// За всеки потребител реализирайте следните функционалности:

// send(chatName, content) - Изпраща публично съобщение в посочения чат.
// sendPrivate(chatName, recipient, content) - Изпраща лично съобщение в посочения чат.
// receive(msg) - Вика се при получаване на съобщение. Извежда съобщението на
// стандартния изход.
// joinChat(chat) - Чатът извиква това при регистрация, за да може потребителят да го запомни.
// leaveChat(chatName) - Потребителят излиза от чат.
// kick(chatName, userName) - Премахва потребител от специфични чат. При извикване 
// от не-модератор се игнорира.
// mute(chatName, userName) / unmute(chatName, userName) - Заглушава / 
// отглушава потребител от специфични чат. При извикване от не-модератор се игнорира.
// getter-и и setter-и
// Чат
// Име с произволна дължина
// Потребители в чата
// Класът няма публичен конструктор, създава се чрез create.

// За всеки чат реализирайте следните функционалности:

// create(name) - Статичен метод за създаване на чат (наричат се factory методи и 
// много често се използват).
// join(user) - Регистрира потребител в чата и го свързва с него. 
// Вече регистриран потребител с това име се игнорира.
// leave(name) - Премахва потребител от чата.
// mute(name) / unmute(name) - Заглушава / отглушава потребител в рамките на този чат.
// broadcast(msg) - Изпраща съобщение според следните правила:
// Ако подателят е заглушен - съобщението не се разпраща.
// Ако съобщението има получател - отива само на него.
// Ако няма получател - отива на всички освен на самия подател.
// Във всички случаи (освен заглушаване) съобщението се записва в историята.
// operator[](name) - Достъпване на потребител по име. Връща указател към него 
// или nullptr, ако не е намерен.
// operator<< - Извежда чата включително наименование, брой потребители, 
// история на съобщенията.
// operator bool - Чат е "активен", ако в него има поне двама потребителя.
// getter-и и setter-и
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

    std::cout << "--- operator[] by name ---" << std::endl;
    std::shared_ptr<User> found = (*chat)["Magi Dicheva"];
    std::cout << (found ? found->getName() : "not found") << std::endl;
    std::shared_ptr<User> missing = (*chat)["Ivan Ivanov"];
    std::cout << (missing ? missing->getName() : "not found") << std::endl;

    std::cout << "--- operator bool ---" << std::endl;
    std::cout << "Chat active: " << (*chat ? "yes" : "no") << std::endl;

    std::cout << "--- operator << ---" << std::endl;
    std::cout << *chat;
}

int main() {
    testMessage();
    testChat();
    return 0;
}
