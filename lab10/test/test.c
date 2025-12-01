#include <assert.h>
#include <stdlib.h>

#include "lib.h"

static int *duplicate_array(const int *source, size_t length) {
    int *copy = malloc(length * sizeof(int));
    if (copy == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < length; ++i) {
        *(copy + i) = *(source + i);
    }

    return copy;
}

static void test_min_before_max(void) {
    const int sample[] = {1, -2, 3, 4, -1, 5};
    const size_t length = sizeof(sample) / sizeof(sample[0]);

    int *data = duplicate_array(sample, length);
    assert(data != NULL);

    int *between = NULL;
    size_t between_length = 0;
    long long sum_between = 0;

    int status = build_between_min_max(data, length, &between, &between_length, &sum_between);

    assert(status == 0);
    assert(between_length == 3);
    assert(sum_between == 6);
    assert(*(between + 0) == 3);
    assert(*(between + 1) == 4);
    assert(*(between + 2) == -1);

    free(between);
    free(data);
}

static void test_max_before_min(void) {
    const int sample[] = {9, 1, 2, 3, -5, 7};
    const size_t length = sizeof(sample) / sizeof(sample[0]);

    int *data = duplicate_array(sample, length);
    assert(data != NULL);

    int *between = NULL;
    size_t between_length = 0;
    long long sum_between = 0;

    int status = build_between_min_max(data, length, &between, &between_length, &sum_between);

    assert(status == 0);
    assert(between_length == 3);
    assert(sum_between == 6);
    assert(*(between + 0) == 1);
    assert(*(between + 1) == 2);
    assert(*(between + 2) == 3);

    free(between);
    free(data);
}

static void test_no_elements_between(void) {
    const int sample[] = {5, 5, 5};
    const size_t length = sizeof(sample) / sizeof(sample[0]);

    int *data = duplicate_array(sample, length);
    assert(data != NULL);

    int *between = NULL;
    size_t between_length = 0;
    long long sum_between = 0;

    int status = build_between_min_max(data, length, &between, &between_length, &sum_between);

    assert(status == 0);
    assert(between == NULL);
    assert(between_length == 0);
    assert(sum_between == 0);

    free(data);
}

static void test_invalid_input(void) {
    int *between = NULL;
    size_t between_length = 0;
    long long sum_between = 0;

    int status = build_between_min_max(NULL, 0, &between, &between_length, &sum_between);
    assert(status != 0);
}

int main(void) {
    test_min_before_max();
    test_max_before_min();
    test_no_elements_between();
    test_invalid_input();

    return 0;
}
