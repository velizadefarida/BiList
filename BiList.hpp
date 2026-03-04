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
