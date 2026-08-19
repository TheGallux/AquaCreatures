#include "double_matrix.h"

void double_matrix_inplace_op(struct double_matrix *matrix1,
                              const struct double_matrix *matrix2,
                              double (*f)(double, double))
{
    if (matrix1 == NULL || matrix2 == NULL || f == NULL)
        return;

    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns)
        return;

    for (size_t i = 0; i < matrix1->rows; i++)
    {
        for (size_t j = 0; j < matrix1->columns; j++)
        {
            matrix1->matrix[i][j] =
                f(matrix1->matrix[i][j], matrix2->matrix[i][j]);
        }
    }
}
struct double_matrix *double_matrix_op(const struct double_matrix *matrix1,
                                       const struct double_matrix *matrix2,
                                       double (*f)(double, double))
{
    if (matrix1 == NULL || matrix2 == NULL || f == NULL)
        return NULL;

    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns)
        return NULL;

    struct double_matrix *matrix3 = double_matrix_copy(matrix1);
    double_matrix_inplace_op(matrix3, matrix2, f);

    return matrix3;
}

/* HELPERS */

double sum(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

/* -------  */

void double_matrix_inplace_add(struct double_matrix *matrix1,
                               const struct double_matrix *matrix2)
{
    double_matrix_inplace_op(matrix1, matrix2, sum);
}
struct double_matrix *double_matrix_add(const struct double_matrix *matrix1,
                                        const struct double_matrix *matrix2)
{
    return double_matrix_op(matrix1, matrix2, sum);
}

void double_matrix_inplace_sub(struct double_matrix *matrix1,
                               const struct double_matrix *matrix2)
{
    double_matrix_inplace_op(matrix1, matrix2, sub);
}
struct double_matrix *double_matrix_sub(const struct double_matrix *matrix1,
                                        const struct double_matrix *matrix2)
{
    return double_matrix_op(matrix1, matrix2, sub);
}

struct double_matrix *double_matrix_mul(const struct double_matrix *matrix1,
                                        const struct double_matrix *matrix2)
{
    if (matrix1 == NULL || matrix2 == NULL)
        return NULL;

    if (matrix1->columns != matrix2->rows)
        return NULL;

    struct double_matrix *matrix3 =
        double_matrix_init(matrix1->rows, matrix2->columns);

    for (size_t i = 0; i < matrix1->rows; i++)
    {
        for (size_t j = 0; j < matrix2->columns; j++)
        {
            for (size_t k = 0; k < matrix1->columns; k++)
            {
                matrix3->matrix[i][j] +=
                    matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
        }
    }

    return matrix3;
}
