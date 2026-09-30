#include "exercise_03_file_system.h"
#include "exercise_03_file.h"
#include "exercise_03_not_a_directory_exception.h"

FileSystem::FileSystem(const Directory& root): root(root) {}

Node* FileSystem::findByPath(const char* path) const {
    if (!path) {
        throw std::runtime_error("Nullptr detected");
    }

    Directory* current = const_cast<Directory*>(&this->root);
    if (strlen(path) == 0 || !strcmp(path, "/")) {
        return current;
    }

    char buffer[256]{};
    strncpy(buffer, path, strlen(path));

    Node* found = current;
    char* token = strtok(buffer, "/");
    while (token) {
        Directory* directory = dynamic_cast<Directory*>(found);
        if (!directory) {
            throw NotADirectoryException(found->getName());
        }
        found = directory->findNode(token);
        token = strtok(nullptr, "/");
    }
    return found;
}

Directory* FileSystem::findDirectory(const char* path) const {
    Node* found = this->findByPath(path);
    Directory* directory = dynamic_cast<Directory*>(found);
    if (!directory) {
        throw NotADirectoryException(found->getName());
    }
    return directory;
}

void FileSystem::mkdir(const char* path) {
    if (!path) {
        throw std::runtime_error("Nullptr detected");
    }

    const char* lastSlash = strrchr(path, '/');
    if (!lastSlash) {
        Directory directory(path);
        this->root.addNode(&directory);
        return;
    }

    char parent[256]{};
    strncpy(parent, path, lastSlash - path);
    Directory* target = this->findDirectory(parent);
    Directory directory(lastSlash + 1);
    target->addNode(&directory);
}

void FileSystem::touch(const char* path, const char* data) {
    if (!path || !data) {
        throw std::runtime_error("Nullptr detected");
    }

    const char* lastSlash = strrchr(path, '/');
    if (!lastSlash) {
        File file(path, data);
        this->root.addNode(&file);
        return;
    }

    char parent[256]{};
    strncpy(parent, path, lastSlash - path);
    Directory* target = this->findDirectory(parent);
    File file(lastSlash + 1, data);
    target->addNode(&file);
}

int FileSystem::du(const char* path) const {
    return this->findByPath(path)->size();
}

void FileSystem::ls(const char* path) const {
    this->findByPath(path)->print(0);
}
