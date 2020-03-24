#pragma once
#include <memory>

#include "Sort.hpp"

template <typename T>
class HeapSort : public Sort<T> {
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
     * @brief Sortowanie rosnace
     *
     * @param array tablica do posortowania
     * @param start poczatek sortownia (indeks)
     * @param end koniec sortowania (indeks)
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        std::size_t n = end - start + 1;
        std::size_t heap_size = n;
        BuildMaxHeap(array, n);

        for (std::size_t i = n - 1; i > 0; --i) {
            std::swap(array[0], array[i]);
            --heap_size;
            MaxHeapify(array, 0, heap_size);
        }
    }
    /**
     * @brief Sortowanie malejace - niezaimplementowane, poniewaz nie bedzie wykorzystywane
     *
     */
    void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        UNUSED(array);
        UNUSED(start);
        UNUSED(end);
        throw NotIomplementedException();
    }
    HeapSort() = default;
    ~HeapSort() = default;
};