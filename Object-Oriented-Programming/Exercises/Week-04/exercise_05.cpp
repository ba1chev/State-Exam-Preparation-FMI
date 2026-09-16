// Да се имплементира система, която управлява плейлист с песни. Всяка песен има:

// Име (до 64 символа)
// Продължителност
// Жанр - може да бъде прост жанр: рок, поп, хип-хоп, електронна музика, джаз или комбинация между 2 
// или повече прости жанра (напр. рок и поп)
// Съдържание - последователност от байтове (най-много 256), която се прочита от двоични файлове
// Жанрът трябва да се пази в структура/член-данна, която заема най-много 1 байт.

// Съдържанието на песента трябва да може да се модифицира по 1 от следните начини:

// Всеки k-ти бит отзад напред да се преобразува в 1-ца (за създаване на допълнителен ритъм)
// Пример: 0100 0110 0100 0110, 3 -> 0100 1111 0110 0110

// Да се миксира с друга песен - 1-ци остават всички битове, които са 1-ци в само една от двете песни 
// (ако някой бит е 1-ца и в двете песни, то ще бъде 0-ла в резултата). Ако една песен се миксира с 
// друга с различна дължина, се миксират толкова байтове, колкото е дължината на по-кратката.
// При миксиране на дадена изходна песен с друга, миксът презаписва съдържанието на изходната песен, 
// като дължината на съдържанието не се променя.

// Плейлистът може да съдържа най-много 30 песни. Трябва да се поддържат следните функционалности:

// Добавяне на песен в плейлиста с определено име, продължителност, жанр и име на файл, от който се чете 
// съдържанието. Жанрът се подава като стринг, където всяка буква отговаря на даден прост жанр 
// (напр. "rp" означава рок и поп)
// Принтиране на песните в плейлиста - име, продължителност във формат часове:минути:секунди и жанр
// Tърсене на песен по име (всяка песен гарантирано е с уникално име)
// Търсене на песен по жанр - връща всички песни, които съдържат определен жанр
// Сортиране по продължителност на песента
// Сортиране по име на песента
// Модифициране на песен по някой от посочените начини (по подадено име)
// Запазване на дадена песен в двоичен файл (по подадено име на песента и име на двоичен
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstdint>

namespace UTILS {
    size_t getFileSize(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        size_t currentPosition = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t result = ifs.tellg();

        ifs.clear();
        ifs.seekg(currentPosition, std::ios::beg);
        return result;
    }
}

enum class Genre: uint8_t {
    Rock = (1 << 0),
    Pop = (1 << 1),
    HipHop = (1 << 2),
    ElectronicMusic = (1 << 3),
    Jazz = (1 << 4)
};

struct Song {
public:
    char name[64 + 1] = "";
    float duration = 0.0f;
    Genre genre = Genre::Pop;
    uint8_t content[256 + 1]{};
    size_t contentSize = 0;

    Song() = default;

    Song(const char* name, const float duration, Genre genre,
        const uint8_t* content, size_t contentSize) {
        if (!name || !content || contentSize > 256 || strlen(name) > 64) {
            throw std::runtime_error("Invalid input");
        }

        this->contentSize = contentSize;
        for (size_t i = 0; i < this->contentSize; i++) {
            this->content[i] = content[i];
        }

        strncpy(this->name, name, strlen(name));
        this->genre = genre;
        this->duration = duration;
    }


    void modify(int k) {
        if (k <= 0) {
            throw std::runtime_error("Invalid input");
        }

        size_t totalBits = this->contentSize * 8;
        for (size_t bit = k - 1; bit < totalBits; bit += k) {
            size_t byteIndex = this->contentSize - 1 - (bit / 8);
            this->content[byteIndex] |= (1 << (bit % 8));
        }
    }

    void mask(const Song& other) {
        size_t size = std::min(this->contentSize, other.contentSize);
        for (size_t i = 0; i < size; i++) {
            this->content[i] ^= other.content[i];
        }
    }

    void print() const {
        std::cout << name << " ";
        int totalSeconds = (int)this->duration;
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        std::cout << hours << ":" << minutes << ":" << seconds << " ";

        if ((int)this->genre & (int)Genre::Rock) {
            std::cout << "Rock" << " ";
        }
        if ((int)this->genre & (int)Genre::Pop) {
            std::cout << "Pop" << " ";
        }
        if ((int)this->genre & (int)Genre::HipHop) {
            std::cout << "HipHop" << " ";
        }
        if ((int)this->genre & (int)Genre::ElectronicMusic) {
            std::cout << "ElectronicMusic" << " ";
        }
        if ((int)this->genre & (int)Genre::Jazz) {
            std::cout << "Jazz" << " ";
        }
        std::cout << std::endl;
    }
};

class Playlist {
private:
    Song songs[30]{};
    size_t countOfSongs = 0;

public:
    Playlist() = default;

    void addSong(const Song& song) {
        if (this->countOfSongs == 30) {
            throw std::runtime_error("No more space");
        }

        this->songs[this->countOfSongs] = song;
        this->countOfSongs += 1;
    }

    void addSong(const char* name, const float duration, const char* genre, const char* fileName) {
        if (!name || !genre || !fileName) {
            throw std::runtime_error("Nullptr detected");
        }

        std::ifstream ifs(fileName, std::ios::binary);
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        Song newSong;
        size_t sizeOfContent = UTILS::getFileSize(ifs);
        if (sizeOfContent > 256) {
            throw std::runtime_error("Content is too big");
        }

        int genreR = 0;
        for (size_t i = 0; i < strlen(genre); i++) {
            if (genre[i] == 'r') {
                genreR |= (int)Genre::Rock;
            } else if (genre[i] == 'p') {
                genreR |= (int)Genre::Pop;
            } else if (genre[i] == 'h') {
                genreR |= (int)Genre::HipHop;
            } else if (genre[i] == 'e') {
                genreR |= (int)Genre::ElectronicMusic;
            } else if (genre[i] == 'j') {
                genreR |= (int)Genre::Jazz;
            }
        }

        strncpy(newSong.name, name, strlen(name));
        newSong.genre = (Genre)genreR;
        newSong.duration = duration;
        newSong.contentSize = sizeOfContent;
        ifs.read((char*)&newSong.content, sizeOfContent);
        ifs.close();

        this->addSong(newSong);
    }


    void print() const {
        for (size_t i = 0; i < this->countOfSongs; i++) {
            this->songs[i].print();
        }
    }

    Song findSongByName(const char* name) const {
        for (size_t i = 0; i < this->countOfSongs; i++) {
            if (!strcmp(this->songs[i].name, name)) {
                return this->songs[i];
            }
        }
        throw std::runtime_error("Song not found");
    }

    Song* findSongsByGenre(Genre genre, size_t& size) const {
        size_t counter = 0;
        for (size_t i = 0; i < this->countOfSongs; i++) {
            if ((int)this->songs[i].genre & (int)genre) {
                counter += 1;
            }
        }

        Song* result = new Song[counter]{};
        size = counter;
        counter = 0;
        for (size_t i = 0; i < this->countOfSongs; i++) {
            if ((int)this->songs[i].genre & (int)genre) {
                result[counter] = this->songs[i];
                counter += 1;
            }
        }

        return result;
    }

    typedef bool (*SortingPredicate)(const Song&, const Song&);
    void sortBy(SortingPredicate predicate) {
        for (size_t i = 0; i < this->countOfSongs - 1; i++) {
            for (size_t j = 0; j < this->countOfSongs - i - 1; j++) {
                if (predicate(this->songs[j], this->songs[j + 1])) {
                    Song temp = this->songs[j];
                    this->songs[j] = this->songs[j + 1];
                    this->songs[j + 1] = temp;
                }
            }
        }
    }

    void modifySong(const char* name, int k) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        for (size_t i = 0; i < this->countOfSongs; i++) {
            if (!strcmp(this->songs[i].name, name)) {
                this->songs[i].modify(k);
                break;
            }
        }
    }

    void maskSong(const char* name, const Song& song) {
        if (!name) {
            throw std::runtime_error("Nullptr detected");
        }

        for (size_t i = 0; i < this->countOfSongs; i++) {
            if (!strcmp(this->songs[i].name, name)) {
                this->songs[i].mask(song);
                break;
            }
        }
    }

    void writeSongToFile(const char* songName, const char* fileName) const {
        if (!songName || !fileName) {
            throw std::runtime_error("Nullptr detected");
        }

        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        Song song = this->findSongByName(songName);
        ofs.write((const char*)song.content, song.contentSize);
        ofs.close();
    }

    void writeToFile(const char* fileName) const {
        if (!fileName) {
            throw std::runtime_error("Nullptr detected");
        }

        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ofs.write((const char*)&this->countOfSongs, sizeof(size_t));
        ofs.write((const char*)this->songs, sizeof(this->songs));
        ofs.close();
    }

    void readFromFile(const char* fileName) {
        if (!fileName) {
            throw std::runtime_error("Nullptr detected");
        }

        std::ifstream ifs(fileName, std::ios::binary);
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        ifs.read((char*)&this->countOfSongs, sizeof(size_t));
        ifs.read((char*)this->songs, sizeof(this->songs));
        ifs.close();
    }
};

int main() {
    uint8_t content1[] = {0b01000110, 0b01000110};
    uint8_t content2[] = {0b00000010, 0b00000110};

    Song song1 = {"Bohemian Rhapsody", 355.0f, (Genre)((int)Genre::Rock | (int)Genre::Pop), content1, 2};
    Song song2 = {"Stairway", 482.0f, Genre::Rock, content2, 2};

    Playlist playlist;
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.print();
    std::cout << std::endl;

    playlist.sortBy([](const Song& left, const Song& right){
        return left.duration > right.duration;
    });
    playlist.print();
    std::cout << std::endl;

    playlist.sortBy([](const Song& left, const Song& right){
        return strcmp(left.name, right.name) > 0;
    });
    playlist.print();
    std::cout << std::endl;

    size_t size = 0;
    Song* rockSongs = playlist.findSongsByGenre(Genre::Rock, size);
    std::cout << size << std::endl;
    delete[] rockSongs;

    playlist.modifySong("Stairway", 3);
    playlist.maskSong("Bohemian Rhapsody", song2);
    playlist.writeSongToFile("Stairway", "stairway.bin");

    return 0;
}