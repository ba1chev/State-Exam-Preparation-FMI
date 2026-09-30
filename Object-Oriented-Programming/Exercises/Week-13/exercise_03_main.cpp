// Имплементирайте опростена файлова система. Имате дървовидна структура от Node-ове - 
// файлове и директории. Потребителят може да извършва операции върху тях чрез FileSystem клас.

// Структура
// Node е абстрактен клас с std::string name. Наследяват го:

// File - съдържа std::string content и virtual int size() const (връща дължината на съдържанието)
// Directory - съдържа вектор от unique_ptr<Node>. size() връща сумата от размерите на 
// всичко вътре, рекурсивно. Поддържа addNode() и findNode(const std::string& name). 
// И двата класа имплементират virtual void print(int indent) const за визуализация на дървото.
// Йерархия от изключения
// Дефинирайте базов клас FileSystemException, наследяващ std::exception. От него изведете:

// NodeNotFoundException - хвърля се при търсене на несъществуващ път. Съобщението включва липсващото име.
// NotADirectoryException - хвърля се при опит да се добави нещо вътре в File. Съобщението включва името на файла.
// DuplicateNameException - хвърля се при добавяне на Node с вече съществуващо име в 
// директорията. Съобщението включва името на дубликата.
// FileSystem
// FileSystem притежава един корен Directory с име "/" и поддържа операции по път (напр. "home/user/docs"):

// void mkdir(const std::string& path) - създава директория по зададения път
// void touch(const std::string& path, const std::string& content) - създава файл със съдържание
// int du(const std::string& path) - връща общия размер на възела по дадения път
// void ls(const std::string& path) - принтира дървото от дадения възел надолу с отстъп 
// Навигацията по пътя се извършва стъпка по стъпка - всяка невалидна стъпка хвърля подходящо изключение.
// main()
// Изградете следната структура:

// /
// ├── home/
// │   └── user/
// │       ├── notes.txt       ("hello world")
// │       └── docs/
// │           └── report.txt  ("this is my report")
// └── etc/
//     └── config.txt          ("setting=true")
// След това демонстрирайте:

// du("home/user") - принтира общия размер
// ls("/") - принтира цялото дърво
// Опит за mkdir("home/user/notes.txt/newfolder") - хвърля NotADirectoryException
// Опит за touch("home/user/notes.txt", "duplicate") - хвърля DuplicateNameException
// Опит за du("home/ghost") - хвърля NodeNotFoundException Хващайте всяко изключение поотделно и принтирайте what().
#include <iostream>
#include "exercise_03_file_system.h"
#include "exercise_03_not_found_exception.h"
#include "exercise_03_not_a_directory_exception.h"
#include "exercise_03_duplicate_name_exception.h"

int main() {
    FileSystem fs(Directory("/"));

    fs.mkdir("home");
    fs.mkdir("home/user");
    fs.touch("home/user/notes.txt", "hello world");
    fs.mkdir("home/user/docs");
    fs.touch("home/user/docs/report.txt", "this is my report");
    fs.mkdir("etc");
    fs.touch("etc/config.txt", "setting=true");

    std::cout << "du(home/user): " << fs.du("home/user") << std::endl;

    std::cout << "ls(/):" << std::endl;
    fs.ls("/");

    try {
        fs.mkdir("home/user/notes.txt/newfolder");
    }
    catch (const NotADirectoryException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        fs.touch("home/user/notes.txt", "duplicate");
    }
    catch (const DuplicateNameException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        fs.du("home/ghost");
    }
    catch (const NodeNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}