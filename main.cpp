#include "BiList.hpp"
#include "functions.hpp"
#include <iostream>

int main()
{
int arr[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    BiList<int>* list = convert(arr, size);
    std::cout << "Начальный список: "; traverse(list, print<int>); std::cout << "\n";

    add(list, 60);
    insert(list, 5);
    std::cout << "После add(60) и insert(fake,5): "; traverse(list, print<int>); std::cout << "\n";

    BiList<int>* node = list->next;
    while (node && node->data != 20) node = node->next;
    if (node)
    {
      insert(node, 25);
    }

    node = list->next;
    while (node && node->data != 40) node = node->next;
    if (node)
    {
      erase(list, node);
    }

    node = list->next;
    while (node && node->data != 50) node = node->next;
    if (node)
    {
      delete cut(list, node);
    }

    std::cout << "После изменений: "; traverse(list, print<int>); std::cout << "\n";

    clear(list);
    destroyList(list);
    return 0;
}
