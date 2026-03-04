#ifndef BILIST_HPP
#define BILIST_HPP
#include <cstddef>

template<typename T>
struct BiList {
    T data;
    BiList<T>* next;
    BiList<T>* prev;
};

template<typename T>
BiList<T>* createList() {
    BiList<T>* fake = static_cast<BiList<T>*>(::operator new(sizeof(BiList<T>)));
    fake->next = fake->prev = nullptr;
    return fake;
}

template<typename T>
BiList<T>* add(BiList<T>* fake, const T& value) {
    BiList<T>* newNode = new BiList<T>{value, nullptr, nullptr};
    BiList<T>* last = fake;
    while (last->next) last = last->next;
    last->next = newNode;
    newNode->prev = last;
    return newNode;
}

template<typename T>
BiList<T>* insert(BiList<T>* node, const T& value) {
    if (!node) return nullptr;
    BiList<T>* newNode = new BiList<T>{value, nullptr, nullptr};
    BiList<T>* nextNode = node->next;
    newNode->next = nextNode;
    newNode->prev = node;
    node->next = newNode;
    if (nextNode) nextNode->prev = newNode;
    return newNode;
}

template<typename T>
BiList<T>* erase(BiList<T>* fake, BiList<T>* node) {
    if (!node || node == fake) return nullptr;
    BiList<T>* prev = node->prev;
    BiList<T>* next = node->next;
    prev->next = next;
    if (next) next->prev = prev;
    delete node;
    return next;
}

template<typename T>
BiList<T>* cut(BiList<T>* fake, BiList<T>* node) {
    if (!node || node == fake) return nullptr;
    BiList<T>* prev = node->prev;
    BiList<T>* next = node->next;
    prev->next = next;
    if (next) next->prev = prev;
    node->next = node->prev = nullptr;
    return node;
}
