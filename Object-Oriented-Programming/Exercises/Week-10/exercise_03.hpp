// Кеш (cache) може да бъде както хардуерен така и софтуерен компонент, 
// който пази вече изчислени или заредени данни от бавен източник за да не 
// изчисляваме или зареждаме данните наново. Например browser-ите "кешират" 
// цели страници/изображения при първо посещение на сайт за да не се налага 
// отново да изтегляте ресурсите при повторно посещение на сайта. Поради това 
// може първия път, в който влизате в някой сайт да зареди бавно, а всеки 
// следващ път много по-бързо.

// Имплементирайте шаблонен клас WeakCache<Key, Value>, който представлява 
// ваша имплементация на кеш, който не притежава стойностите, и да може да:

// Връща стойност асоциирана с даден ключ, ако такава съществува.
// Записва нова асоциация между ключ и стойност в кеша. Ако ключът вече 
// съществува, новата стойност заменя старата.
// Премахва записа с дадения ключ от кеша.
// Премахва от кеша всички записи, чиито стойности вече не съществуват и да 
// връща броя на премахнатите записи.
// Връща общия брой записи в кеша, включително тези, чиито стойности вече са 
// унищожени, но все още не са премахнати от кеша.
// Връща броя на записите, чиито стойности са все още живи в момента на извикване.
// Връща стойност асоциирана с даден ключ, ако такава съществува. В 
// противен случай извиква подадена функция, която произвежда нова стойност, 
// записва я в кеша и я връща.
#pragma once
#include <iostream>
#include <stdexcept>

template <class K, class V>
struct CacheNode {
public:
    K key = K{};
    V value = V{};
    bool isUsed = false;

    CacheNode* nextNode = nullptr;
    CacheNode* prevNode = nullptr;
    CacheNode* chainingNode = nullptr;

    CacheNode() = default;
    CacheNode(const K& key, const V& value);
};

template <class K, class V>
CacheNode<K, V>::CacheNode(const K& key, const V& value) {
    this->key = key;
    this->value = value;
}

template <class K, class V>
class WeakCache {
private:
    CacheNode<K, V>* rootNode = nullptr;
    size_t cacheCapacity = 0;

    void free();
    void copyFrom(const WeakCache& other);
    void moveTo(WeakCache&& other) noexcept;

public:
    WeakCache(const size_t cacheCapacity);
    WeakCache(const WeakCache& other);
    WeakCache(WeakCache&& other) noexcept;
    WeakCache& operator = (const WeakCache& other);
    WeakCache& operator = (WeakCache&& other) noexcept;
    ~WeakCache();

    const V& getValueBy(const K& key) const;
    void removeValueBy(const K& key);
};

template <class K, class V>
WeakCache<K, V>::WeakCache(const size_t cacheCapacity) {
    this->rootNode = new CacheNode<K, V>();
    this->cacheCapacity = cacheCapacity;

    CacheNode<K, V>* currentNode = this->rootNode;
    for (size_t i = 0; i < this->cacheCapacity; i++) {
        currentNode->isUsed = false;
        currentNode->nextNode = new CacheNode<K, V>();
        CacheNode<K, V>* prevNode = currentNode;
        currentNode = currentNode->nextNode;
        currentNode->prevNode = prevNode;
    }
    currentNode->nextNode = nullptr;
}

template <class K, class V>
WeakCache<K, V>::WeakCache(const WeakCache& other) {
    this->copyFrom(other);
}

template <class K, class V>
WeakCache<K, V>::WeakCache(WeakCache&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class K, class V>
WeakCache<K, V>& WeakCache<K, V>::operator = (const WeakCache& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

template <class K, class V>
WeakCache<K, V>& WeakCache<K, V>::operator = (WeakCache&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

template <class K, class V>
WeakCache<K, V>::~WeakCache() {
    this->free();
}


template <class K, class V>
void WeakCache<K, V>::free() {
    CacheNode<K, V>* currentNode = this->rootNode;
    while (currentNode != nullptr && currentNode->prevNode != nullptr) {
        currentNode = currentNode->prevNode;
    }

    while (currentNode != nullptr) {
        currentNode->isUsed = false;
        CacheNode<K, V>* nextNode = currentNode->nextNode;
        CacheNode<K, V>* currentChainingNode = currentNode->chainingNode;
        while (currentChainingNode != nullptr) {
            CacheNode<K, V>* nextChainingNode = currentChainingNode->chainingNode;
            delete currentChainingNode;
            currentChainingNode = nextChainingNode;
        }

        delete currentNode;
        currentNode = nextNode;
    }
    this->cacheCapacity = 0;
}

template <class K, class V>
void WeakCache<K, V>::copyFrom(const WeakCache& other) {
    this->rootNode = new CacheNode<K, V>(*other.rootNode);
    this->cacheCapacity = other.cacheCapacity;

    CacheNode<K, V>* currentNode = this->rootNode;
    CacheNode<K, V>* otherCurrentNode = other.rootNode;
    for (size_t i = 0; i < this->cacheCapacity; i++) {
        currentNode->isUsed = otherCurrentNode->isUsed;
        currentNode->nextNode = new CacheNode<K, V>(*otherCurrentNode->nextNode);
        CacheNode<K, V>* currentChainingNode = currentNode;
        CacheNode<K, V>* otherCurrentChainingNode = otherCurrentNode->chainingNode;

        while (otherCurrentChainingNode != nullptr) {
            currentChainingNode->chainingNode = new CacheNode<K, V>(*otherCurrentChainingNode);
            otherCurrentChainingNode = otherCurrentChainingNode->chainingNode;
            currentChainingNode = currentChainingNode->chainingNode;
        }
        currentChainingNode->chainingNode = nullptr;

        otherCurrentNode = otherCurrentNode->nextNode;
        CacheNode<K, V>* prevNode = currentNode;
        currentNode = currentNode->nextNode;
        currentNode->prevNode = prevNode;
    }
    currentNode->nextNode = nullptr;
}

template <class K, class V>
void WeakCache<K, V>::moveTo(WeakCache&& other) noexcept {
    this->rootNode = other.rootNode;
    this->cacheCapacity = other.cacheCapacity;

    other.rootNode = nullptr;
    other.cacheCapacity = 0;
}

template <class K, class V>
const V& WeakCache<K, V>::getValueBy(const K& key) const {
    CacheNode<K, V>* currentNode = this->rootNode;
    while (currentNode != nullptr && currentNode->nextNode != nullptr) {
        if (currentNode->key == key) {
            return currentNode->value;
        }
        currentNode = currentNode->nextNode;
    }
    throw std::runtime_error("Not found");
}

template <class K, class V>
void WeakCache<K, V>::removeValueBy(const K& key) {
    CacheNode<K, V>* currentNode = this->rootNode;
    while (currentNode != nullptr && currentNode->nextNode != nullptr) {
        if (currentNode->key == key) {
            if (currentNode->chainingNode != nullptr) {
                CacheNode<K, V>* currentChainingNode = currentNode->chainingNode;
                CacheNode<K, V>* lastChainingNode = nullptr;

                while (currentChainingNode != nullptr && 
                    currentChainingNode->chainingNode != nullptr) {
                    lastChainingNode = currentChainingNode;
                    currentChainingNode = currentChainingNode->chainingNode;
                }
                if (lastChainingNode != nullptr) {
                    delete currentChainingNode;
                    currentChainingNode = nullptr;
                    lastChainingNode->chainingNode = nullptr;
                }
                return;
            }
        }
        currentNode = currentNode->nextNode;
    }
    throw std::runtime_error("Not found");
}