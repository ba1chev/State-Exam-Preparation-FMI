// Да се реализира шаблонен клас Pair<K,V> със следните функционалности:
// публични полета:
// first (първият елемент)
// second (вторият елемент)
// функции:
// оператор ==
// оператор !=
// оператор <
#pragma once
#include <iostream>

template <class K, class V>
class Pair {
public:
    K first = K{};
    V second = V{};

    Pair() = default;
    Pair(const K& first, const V& second);
};

template <class K, class V>
Pair<K, V>::Pair(const K& first, const V& second) {
    this->first = first;
    this->second = second;
}

template <class K, class V>
bool operator == (const Pair<K, V>& left, const Pair<K, V>& right) {
    return left.first == right.first && left.second == right.second;
}

template <class K, class V>
bool operator != (const Pair<K, V>& left, const Pair<K, V>& right) {
    return !(left == right);
}

template <class K, class V>
bool operator < (const Pair<K, V>& left, const Pair<K, V>& right) {
    if (left.first == right.first) {
        return left.second < right.second;
    }
    return left.first < right.first;
}
