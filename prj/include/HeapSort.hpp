#pragma once
#include <memory>

#include "Sort.hpp"

/**
 * @brief Sortowanie przez kopcowanie - niestety nie udalo mi sie "zmusic " jej do dziedziczenia po
 *        Klasie sort, z roznych wzgledow
 *
 * @tparam T typ danych
 */
template <typename T>
class HeapSort {
   private:
    std::size_t size;  // rozmiar tablicy ktora bedzie sortowana
    /**
     * @brief "Naprawia" kopiec
     *
     */
    void MaxHeapify(std::unique_ptr<T[]>& array, std::size_t index, std::size_t n) {
        std::size_t left_index = 2 * index + 1;
        std::size_t right_index = 2 * index + 2;
        std::size_t largest = 0;

        if (left_index < n && array[left_index] > array[index]) {
            largest = left_index;
        } else {
            largest = index;
        }

        if (right_index < n && array[right_index] > array[largest]) {
            largest = right_index;
        }

        if (index != largest) {
            std::swap(array[index], array[largest]);
            MaxHeapify(array, largest, n);
        }
    }
    /**
     * @brief Zbuduj kopiec typu MAX
     *
     */
    void BuildMaxHeap(std::unique_ptr<T[]>& array, std::size_t n) {
        // z jakiegos powodu przy uzyciu tutaj size_t program nie dziala
        for (int i = n / 2 - 1; i >= 0; --i) {
            MaxHeapify(array, i, n);
        }
    }

   public:
    /**
     * @brief Dodaj rozmiar tablicy ktora bedzie sortowana
     *
     * @param size rozmiar tablicy
     */
    void AddSize(std::size_t size) { this->size = size; }

    /**
     * @brief Sortowanie przez kopcowanie
     *
     * @param array tablica do posortowania
     * @param n wielkosc tej tablicy
     */
    void FullHeapSort(std::unique_ptr<T[]>& array) {
        std::size_t heap_size = size;
        BuildMaxHeap(array, size);

        for (std::size_t i = size - 1; i > 0; --i) {
            std::swap(array[0], array[i]);
            --heap_size;
            MaxHeapify(array, 0, heap_size);
        }
    }

    HeapSort() = default;
    ~HeapSort() = default;
};