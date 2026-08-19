#include <stdio.h>

#include "double_matrix.h"

bool double_matrix_fill(struct double_matrix *matrix, const double *array,
                        size_t length)
{
    if (matrix->columns * matrix->rows != length)
        return false;

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            matrix->matrix[i][j] = array[i * matrix->columns + j];
        }
    }

    return true;
}

void double_matrix_display(const struct double_matrix *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        printf("( ");
        for (size_t j = 0; j < matrix->columns; j++)
        {
            printf("%.3f ", matrix->matrix[i][j]);
        }
        printf(")\n");
    }
    printf("\n");
}
