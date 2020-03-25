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
     * @brief Sortowanie przez kopcowanie
     *
     * @param array tablica do posortowania
     * @param n wielkosc tej tablicy
     */
    void FullHeapSort(std::unique_ptr<T[]>& array, std::size_t n) {
        std::size_t heap_size = n;
        BuildMaxHeap(array, n);

        for (std::size_t i = n - 1; i > 0; --i) {
            std::swap(array[0], array[i]);
            --heap_size;
            MaxHeapify(array, 0, heap_size);
        }
    }

    /**
     * @brief Czesciowe sortowanie przez kopcowanie
     *
     * @param array tablica ktorej fragment ma zostac posortowany
     * @param start poczatkowy indeks od ktorego ma byc sortowanie
     * @param end indeks koncowy
     */
    void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) override {
        // stworzenie tablicy pomocniczej do sortowania
        auto sub_array = std::make_unique<int[]>(end - start + 1);
        for (std::size_t i = 0; i < end - start + 1; ++i) {
            for (std::size_t j = start; j < end; ++j) {
                sub_array[i] = array[j];
            }
        }

        // przeprowadzenie sortowania przez kopcowanie na wydzielonej tablicy
        FullHeapSort(sub_array, end - start + 1);

        // scalenie tablic
        for (std::size_t i = start; i <= end; i++) {
            array[i] = sub_array[i - start];
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