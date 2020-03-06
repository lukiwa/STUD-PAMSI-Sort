#pragma once
#include "Sort.hpp"

template <typename T>
class MergeSort : public Sort<T> {
   private:
    void Merge(std::unique_ptr<T[]>& array, int start, int mid, int end) {
        /*
        int temp_arr[end - start + 1];
        std::cout << end - start + 1 << std::endl;

        int i = start, t = 0, j = mid + 1;

        while (i <= mid && j <= end) {
            if (array[i] < array[j]) {
                temp_arr[t] = array[i];
                ++i;
            } else {
                temp_arr[t] = array[j];
                ++j;
            }
            ++t;
        }

        while (i <= mid) {
            temp_arr[t] = array[i];
            ++t;
            ++i;
        }

        while (j < end) {
            temp_arr[t] = array[j];
            ++t;
            ++j;
        }

        for (int i = start; i <= end; ++i) {
            array[i] = temp_arr[i];
        }
        */
        int first_half_size = mid - start + 1;
        int second_half_size = end - mid;

        int first_half[first_half_size];
        int second_half[second_half_size];

        for (int i = 0; i < first_half_size; ++i) {
            
        }
        for (int i = 0; i < second_half_size; ++i) {
            /* code */
        }
    }

   public:
    void SortUp(std::unique_ptr<T[]>& array, int start, int end) override {
        if (start < end) {
            int mid = (start + end) / 2;
            SortUp(array, start, mid);
            SortUp(array, mid + 1, end);
            Merge(array, start, mid, end);
        }
    }

    // bool SortDown(std::unique_ptr<T[]> array, std::size_t size,
    //             double sorting_length = 1) override {}

    MergeSort() = default;
    ~MergeSort() = default;
};