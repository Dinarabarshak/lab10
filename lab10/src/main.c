#include <stdlib.h>

#include "lib.h"

/*
 * Лабораторна робота №10
 * Завдання: Масиви та показчики
 * Автор: Дінара Баршакаєва
 * Рік: 2025
 */

int main(void) {
    enum { LENGTH = 8 };
    const size_t length = LENGTH;
    const int predefined[LENGTH] = {4, -2, 7, 3, 0, -5, 9, 6};

    int *data = malloc(length * sizeof(int));
    if (data == NULL) {
        return 1;
    }

    for (size_t i = 0; i < length; ++i) {
        *(data + i) = *(predefined + i);
    }

    int *between = NULL;
    size_t between_length = 0;
    long long sum_between = 0;

    int status = build_between_min_max(data, length, &between, &between_length, &sum_between);

    free(data);
    free(between);

    return status == 0 ? 0 : 1;
}
