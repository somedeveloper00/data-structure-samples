#include "includes.cpp"
#include "ListTypes.cpp"
#include <algorithm>

namespace ListMath
{
    template <typename T>
    void Sort(const ListType<T>* list) {
        int c = list->count();
        T* arr = new T[c];
        for (size_t i = 0; i < c; i++) {
            arr[i] = list->get_at(i);
        }
        std::sort(arr, arr + c);
        for (size_t i = 0; i < count; i++) {
            list->set_at(i, arr[i]);
        }
    }

    template <typename T>
    Array<T> ToLTArray(const T* arr, int count) {
        Array<T>* ltarr = new Array<T>();
        ltarr->add(count, arr);
        return ltarr;
    }

    template <typename T>
    LinkedList<T> ToLTLinkedList(const T* arr, int count) {
        LinkedList<T>* ltarr = new LinkedList<T>();
        ltarr->add(count, arr);
        return ltarr;
    }
} // namespace ListMath
