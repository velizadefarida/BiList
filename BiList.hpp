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

template<typename T>
size_t clear(BiList<T>* fake) {
    size_t count = 0;
    BiList<T>* curr = fake->next;
    while (curr) {
        BiList<T>* next = curr->next;
        delete curr;
        curr = next;
        ++count;
    }
    fake->next = nullptr;
    return count;
}

template<typename T, typename Func>
size_t traverse(BiList<T>* fake, Func func) {
    size_t count = 0;
    BiList<T>* curr = fake->next;
    while (curr) {
        func(curr->data);
        curr = curr->next;
        ++count;
    }
    return count;
}

template<typename T>
BiList<T>* convert(const T arr[], size_t size) {
    BiList<T>* fake = createList<T>();
    for (size_t i = 0; i < size; ++i) add(fake, arr[i]);
    return fake;
}

template<typename T>
BiList<T>* destroyList(BiList<T>* fake) {
    clear(fake);
    ::operator delete(fake);
    return nullptr;
}

#endif
