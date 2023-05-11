#ifndef MATRIX_H
#define MATRIX_H

#ifdef __cplusplus
extern "C"{
#endif

#include "scalar.h"

#include <stdbool.h>
#include <stddef.h>

struct matrix
{
  scalar_t **data __attribute__ ((aligned(16)));
  size_t     rows;
  size_t     cols;
  size_t     size;
};

/**
 * @brief A namespace for the matrix data structure.
 */
typedef struct matrix matrix_t;

matrix_t *mx_empty(void);

void mx_set(matrix_t *mx, const size_t rows, const size_t cols);

matrix_t *mx_new(const scalar_t **data, const size_t rows, const size_t cols);

matrix_t *mx_random(const size_t rows, const size_t cols);

void mx_destroy(matrix_t *mx);

void mx_add(matrix_t *mx, const scalar_t a);

bool mx_cmp(matrix_t *ma, matrix_t *mb);

bool mx_equ(matrix_t *ma, matrix_t *mb);

void mx_div(matrix_t *mx, const scalar_t a);

void mx_mul(matrix_t *mx, const scalar_t a);

void mx_sub(matrix_t *mx, const scalar_t a);

void mx_print(const matrix_t *mx);

#ifdef __cplusplus
}
#endif

#endif/*MATRIX_H*/
