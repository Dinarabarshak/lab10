#include "lib.h"

int count_pairs_between_negative(const int *arr, size_t n) {
    int first = -1, last = -1;

    // знайти перший негативний
    for (size_t i = 0; i < n; i++) {
        if (arr[i] < 0) {
            first = i;
            break;
        }
    }

    // знайти останній негативний
    for (size_t i = n; i-- > 0;) {
        if (arr[i] < 0) {
            last = i;
            break;
        }
    }

    if (first == -1 || last == -1 || last <= first + 1)
        return 0;

    int count = 0;

    for (int i = first + 1; i < last; i++) {
        if (arr[i] > 0 && arr[i + 1] > 0)
            count++;
    }

    return count;
}
