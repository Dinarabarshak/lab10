#ifndef LIB_H
#define LIB_H

#include <stddef.h>

/**
 * @brief Builds an array of elements located between the minimum and maximum values.
 *
 * The function searches for the minimum and maximum elements of the source array,
 * calculates the sum of the elements that are positioned between them, and creates
 * a new dynamically allocated array that contains those elements in their original
 * order.
 *
 * @param source Pointer to the source array.
 * @param length Number of elements in the source array.
 * @param result Pointer to the location where the allocated result array pointer will be stored.
 * @param result_length Pointer to the location where the result array length will be stored.
 * @param sum_between Pointer to the location where the sum of the elements between the minimum and maximum will be stored.
 * @return 0 on success, or a non-zero value if the input is invalid or memory allocation fails.
 */
int build_between_min_max(const int *source,
                          size_t length,
                          int **result,
                          size_t *result_length,
                          long long *sum_between);

#endif
