// Създайте структура, която представлява песен, която съдържа следните характеристики:
// заглавие (до 100 символа)
// изпълнител (до 100 символа)
// жанр (може да бъде Rock, Pop, Thrash Metal, K-pop, Chalga)
// рейтинг (дробно число от 0 до 10 примерно)
// брой слушания (цяло число)
// Създайте структура Playlist, която се описва с най-много 64 песни. 
// Реализирайте следните функции:

// Добавяне на песен в колекцията (ако капацитетът е запълнен, принтирайте 
// подходящо съобщение).
// Връщане на указател към книга по подаден унарен предикат, приемащ като аргумент 1 песен.
// Сортиране на песните по подаден бинарен предикат, приемащ като аргументи 2 песни.
#include <iostream>

enum class Genre {
    Rock, Pop, Thrash, Metal, KPop, Chalga
};

struct Song {
public:
    char tittle[100 + 1] = "";
    char executor[100 + 1] = "";
    Genre genre = Genre::Chalga;
    float rating = 10.0f;
    int countOfListeners = 0;
};

struct Playlist {
public:
    Song songs[64];
    int countOfSongs = 0;
};

void addSong(Playlist& playlist, const Song& song) {
    if (playlist.countOfSongs >= 64) {
        std::cout << "Out of capacity" << std::endl;
        return;
    }

    playlist.songs[playlist.countOfSongs] = song;
    playlist.countOfSongs += 1;
}

typedef bool(*Predicate)(const Song&);
const Song* getByPredicate(const Playlist& playlist, Predicate predicate) {
    for (size_t i = 0; i < playlist.countOfSongs; i++) {
        if (predicate(playlist.songs[i])) {
            return &playlist.songs[i];
        }
    }
    return nullptr;
}

typedef bool(*SortingPredicate)(const Song&, const Song&);
void sortByPredicate(Playlist& playlist, SortingPredicate predicate) {
    for (size_t i = 0; i + 1 < playlist.countOfSongs; i++) {
        for (size_t j = 0; j + 1 < playlist.countOfSongs - i; j++) {
            if (predicate(playlist.songs[j], playlist.songs[j + 1])) {
                Song temp = playlist.songs[j];
                playlist.songs[j] = playlist.songs[j + 1];
                playlist.songs[j + 1] = temp;
            }
        }
    }
}

void printSong(const Song& song) {
    std::cout << song.tittle << " ";
    std::cout << song.executor << " ";
    std::cout << song.rating << " ";
    std::cout << song.countOfListeners << std::endl;
}

bool isHighlyRated(const Song& song) {
    return song.rating >= 9.0f;
}

bool byRatingDescending(const Song& left, const Song& right) {
    return left.rating < right.rating;
}

int main() {
    Playlist playlist;
    
    addSong(playlist, Song{"Bohemian Rhapsody", "Queen", Genre::Rock, 9.5f, 1000});
    addSong(playlist, Song{"Blinding Lights", "The Weeknd", Genre::Pop, 8.7f, 5000});
    addSong(playlist, Song{"Master of Puppets", "Metallica", Genre::Thrash, 9.8f, 2000});

    sortByPredicate(playlist, byRatingDescending);
    for (size_t i = 0; i < playlist.countOfSongs; i++) {
        printSong(playlist.songs[i]);
    }

    const Song* found = getByPredicate(playlist, isHighlyRated);
    if (found != nullptr) {
        std::cout << "First highly rated: ";
        printSong(*found);
    }

    return 0;
}