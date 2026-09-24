// Кеш (cache) може да бъде както хардуерен така и софтуерен компонент,
// който пази вече изчислени или заредени данни от бавен източник за да не
// изчисляваме или зареждаме данните наново. Например browser-ите "кешират"
// цели страници/изображения при първо посещение на сайт за да не се налага
// отново да изтегляте ресурсите при повторно посещение на сайта. Поради това
// може първия път, в който влизате в някой сайт да зареди бавно, а всеки
// следващ път много по-бързо.

// Имплементирайте шаблонен клас WeakCache<Key, Value>, който представлява
// ваша имплементация на кеш с фиксиран капацитет. При създаване кешът
// заделя предварително зададен брой клетки (капацитет), които първоначално
// са свободни. Всяка клетка може да бъде заета от асоциация ключ->стойност
// или да остане свободна. Кешът да може да:

// Връща стойност асоциирана с даден ключ, ако такава съществува. В
// противен случай хвърля изключение.
// Записва нова асоциация между ключ и стойност в кеша. Ако вече има заета
// клетка със същия ключ, новата стойност се добавя към нейната верига от
// стойности. Ако не, стойността заема първата свободна клетка. Ако няма
// свободни клетки, се хвърля изключение.
// Премахва последно добавената стойност от веригата на записа с дадения ключ.
// Връща броя на клетките, които са заети в момента на извикване.
// Връща броя на клетките, които все още са свободни в момента на извикване.
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
    void addValueBy(const K& key, const V& value);

    size_t getCountOfUsedUnits() const;
    size_t getCountOfUnusedUnits() const;
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

template <class K, class V>
size_t WeakCache<K, V>::getCountOfUsedUnits() const {
    size_t result = 0;

    CacheNode<K, V>* currentNode = this->rootNode;
    while (currentNode != nullptr && currentNode->nextNode != nullptr) {
        if (currentNode->isUsed) {
            result += 1;
        }
        currentNode = currentNode->nextNode;
    }

    return result;
}

template <class K, class V>
size_t WeakCache<K, V>::getCountOfUnusedUnits() const {
    return this->cacheCapacity - this->getCountOfUsedUnits();
}

template <class K, class V>
void WeakCache<K, V>::addValueBy(const K& key, const V& value) {
    CacheNode<K, V>* currentNode = this->rootNode;
    while (currentNode != nullptr && currentNode->nextNode != nullptr) {
        if (currentNode->key == key) {
            if (currentNode->chainingNode != nullptr) {
                CacheNode<K, V>* currentChainingNode = currentNode->chainingNode;
                CacheNode<K, V>* lastSeenChainingNode = currentChainingNode;

                while (currentChainingNode != nullptr &&
                    currentChainingNode->chainingNode != nullptr) {
                    lastSeenChainingNode = currentChainingNode;
                    currentChainingNode = currentChainingNode->chainingNode;
                }
                lastSeenChainingNode->chainingNode = new CacheNode<K, V>();
                lastSeenChainingNode->chainingNode->key = key;
                lastSeenChainingNode->chainingNode->value = value;
                lastSeenChainingNode->chainingNode->chainingNode = nullptr;
                return;
            }
        }
        currentNode = currentNode->nextNode;
    }

    currentNode = this->rootNode;
    while (currentNode != nullptr && currentNode->nextNode != nullptr) {
        if (!currentNode->isUsed) {
            currentNode->key = key;
            currentNode->value = value;
            currentNode->isUsed = true;
            return;
        }
        currentNode = currentNode->nextNode;
    }

    throw std::runtime_error("No more space");
}