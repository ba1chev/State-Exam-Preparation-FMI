#pragma once
#include "exercise_03_directory.h"

class FileSystem {
private:
    Directory root;

    Node* findByPath(const char* path) const;
    Directory* findDirectory(const char* path) const;

public:
    FileSystem(const Directory& root);

    void mkdir(const char* path);
    void touch(const char* path, const char* data);
    int du(const char* path) const;
    void ls(const char* path) const;
};
