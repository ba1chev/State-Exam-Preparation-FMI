// Да се напише програма, която намира поредния номер на най-дългия (най-късия) 
// ред на даден текстов файл.
#include <iostream>
#include <fstream>
#include <cstring>

void get_longest_and_shortest_line_index(const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }

    char current_line[1024]{};
    int max_line_size = -1;
    int min_line_size = -1;
    int longest_index = -1;
    int shortest_index = -1;
    int current_index = 0;
    while (ifs.getline(current_line, sizeof(current_line))) {
        int current_line_size = strlen(current_line);
        if (max_line_size == -1 || current_line_size > max_line_size) {
            max_line_size = current_line_size;
            longest_index = current_index;
        }
        if (min_line_size == -1 || current_line_size < min_line_size) {
            min_line_size = current_line_size;
            shortest_index = current_index;
        }
        current_index += 1;
    }

    std::cout << "Longest line index: " << longest_index << std::endl;
    std::cout << "Shortest line index: " << shortest_index << std::endl;
    ifs.close();
}

int main() {
    get_longest_and_shortest_line_index("file.txt");
    return 0;
}