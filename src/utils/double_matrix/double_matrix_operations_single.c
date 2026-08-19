#include "double_matrix.h"

void double_matrix_inplace_neg(struct double_matrix *matrix)
{
    double_matrix_inplace_scale(matrix, -1.0);
}
struct double_matrix *double_matrix_neg(const struct double_matrix *matrix)
{
    return double_matrix_scale(matrix, -1.0);
}

void double_matrix_inplace_scale(struct double_matrix *matrix, double scalar)
{
    if (matrix == NULL)
        return;

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            matrix->matrix[i][j] *= scalar;
        }
    }
}
struct double_matrix *double_matrix_scale(const struct double_matrix *matrix,
                                          double scalar)
{
    if (matrix == NULL)
        return NULL;

    struct double_matrix *copy = double_matrix_copy(matrix);
    double_matrix_inplace_scale(copy, scalar);

    return copy;
}

struct double_matrix *
double_matrix_transpose(const struct double_matrix *matrix)
{
    if (matrix == NULL)
        return NULL;

    struct double_matrix *to_transpose =
        double_matrix_init(matrix->columns, matrix->rows);
    if (to_transpose == NULL)
        return NULL;

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            to_transpose->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    return to_transpose;
}
