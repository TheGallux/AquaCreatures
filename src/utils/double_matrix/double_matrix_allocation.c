#include <stdbool.h>
#include <stdlib.h>

#include "double_matrix.h"

struct double_matrix *double_matrix_init(size_t rows, size_t columns)
{
    struct double_matrix *double_matrix =
        calloc(sizeof(struct double_matrix), 1);
    if (double_matrix == NULL)
        return NULL;

    double_matrix->columns = columns;
    double_matrix->rows = rows;

    double **matrix = calloc(sizeof(double *), rows);
    if (matrix == NULL)
    {
        free(double_matrix);
        return NULL;
    }
    double_matrix->matrix = matrix;

    for (size_t i = 0; i < rows; i++)
    {
        double *row = calloc(sizeof(double), columns);
        if (row == NULL)
        {
            for (size_t j = 0; j < i; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            free(double_matrix);
            return NULL;
        }

        matrix[i] = row;
    }

    return double_matrix;
}

struct double_matrix *double_matrix_copy(const struct double_matrix *matrix)
{
    if (matrix == NULL)
        return NULL;

    struct double_matrix *copy =
        double_matrix_init(matrix->rows, matrix->columns);
    if (copy == NULL)
        return NULL;

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            copy->matrix[i][j] = matrix->matrix[i][j];
        }
    }

    return copy;
}

void double_matrix_destroy(struct double_matrix *matrix)
{
    if (matrix == NULL)
        return;

    for (size_t i = 0; i < matrix->rows; i++)
    {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}
