#pragma once
#include <memory>

/**
 * @brief Makro które "wycisza" ostrzezenia kompilatora o nieuzywanej zmiennej w sytuacjach
 *        w ktorych nie chce danej zmiennej uzywac np. nie implementuje sortowania malejacego
 *        dla quicksort
 *
 */
#define UNUSED(expr)  \
    do {              \
        (void)(expr); \
    } while (0)


template <typename T>
class Sort {
   public:
    virtual void SortUp(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) = 0;

    virtual void SortDown(std::unique_ptr<T[]>& array, std::size_t start, std::size_t end) = 0;

    Sort() = default;
    virtual ~Sort() = default;
};