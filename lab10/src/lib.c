#include "lib.h"

#include <stdlib.h>

static int find_min_max_indices(const int *source, size_t length, size_t *min_idx, size_t *max_idx) {
    if (source == NULL || length == 0 || min_idx == NULL || max_idx == NULL) {
        return -1;
    }

    const int *cursor = source;
    int min_value = *cursor;
    int max_value = *cursor;
    *min_idx = 0;
    *max_idx = 0;

    for (size_t i = 1; i < length; ++i) {
        ++cursor;
        int value = *cursor;

        if (value < min_value) {
            min_value = value;
            *min_idx = i;
        }

        if (value > max_value) {
            max_value = value;
            *max_idx = i;
        }
    }

    return 0;
}

int build_between_min_max(const int *source,
                          size_t length,
                          int **result,
                          size_t *result_length,
                          long long *sum_between) {
    if (result == NULL || result_length == NULL || sum_between == NULL) {
        return -1;
    }

    *result = NULL;
    *result_length = 0;
    *sum_between = 0;

    size_t min_idx = 0;
    size_t max_idx = 0;
    if (find_min_max_indices(source, length, &min_idx, &max_idx) != 0) {
        return -1;
    }

    size_t start = min_idx < max_idx ? min_idx + 1 : max_idx + 1;
    size_t end = min_idx < max_idx ? max_idx : min_idx;

    if (start >= end) {
        return 0;
    }

    size_t segment_length = end - start;
    int *buffer = malloc(segment_length * sizeof(int));
    if (buffer == NULL) {
        return -2;
    }

    const int *read_ptr = source + start;
    int *write_ptr = buffer;
    for (size_t i = 0; i < segment_length; ++i) {
        *(write_ptr + i) = *(read_ptr + i);
        *sum_between += *(read_ptr + i);
    }

    *result = buffer;
    *result_length = segment_length;

    return 0;
}
