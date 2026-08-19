#ifndef DOUBLE_MATRIX_H
#define DOUBLE_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

struct double_matrix
{
    size_t rows;
    size_t columns;
    double **matrix;
};

struct double_matrix *double_matrix_init(size_t rows, size_t columns);
struct double_matrix *double_matrix_copy(const struct double_matrix *matrix);
void double_matrix_destroy(struct double_matrix *matrix);

bool double_matrix_fill(struct double_matrix *matrix, const double *array,
                        size_t length);

void double_matrix_display(const struct double_matrix *matrix);

struct double_matrix *double_matrix_op(const struct double_matrix *matrix1,
                                       const struct double_matrix *matrix2,
                                       double (*f)(double, double));
void double_matrix_inplace_op(struct double_matrix *matrix1,
                              const struct double_matrix *matrix2,
                              double (*f)(double, double));

void double_matrix_inplace_add(struct double_matrix *matrix1,
                               const struct double_matrix *matrix2);
struct double_matrix *double_matrix_add(const struct double_matrix *matrix1,
                                        const struct double_matrix *matrix2);

struct double_matrix *double_matrix_sub(const struct double_matrix *matrix1,
                                        const struct double_matrix *matrix2);
void double_matrix_inplace_sub(struct double_matrix *matrix1,
                               const struct double_matrix *matrix2);

struct double_matrix *double_matrix_mul(const struct double_matrix *matrix1,
                                        const struct double_matrix *matrix2);
void double_matrix_inplace_mul(struct double_matrix *matrix1,
                               const struct double_matrix *matrix2);

struct double_matrix *double_matrix_neg(const struct double_matrix *matrix);
void double_matrix_inplace_neg(struct double_matrix *matrix);

void double_matrix_inplace_scale(struct double_matrix *matrix, double scalar);
struct double_matrix *double_matrix_scale(const struct double_matrix *matrix,
                                          double scalar);

struct double_matrix *
double_matrix_transpose(const struct double_matrix *matrix);

#endif /* ! DOUBLE_MATRIX_H */
