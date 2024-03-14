#include "matrix.h"

int d3_determinant(matrix_t* A, double* result) {
  int check = d3_is_null_matrix(A);

  if (check != OK) {
    return check;
  }

  check = d3_square_matrix(A);

  if (check != OK) {
    return check;
  }

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  }

  if (A->rows == 2) {
    *result = (A->matrix[0][0] * A->matrix[1][1]) -
              (A->matrix[0][1] * A->matrix[1][0]);
    return OK;
  }

  *result = d3_complement_of_first_row(A, &check);
  return check;
}

double d3_complement_of_first_row(matrix_t* A, int* check) {
  double result = 0;
  double check_buffer = 0;
  matrix_t buffer = {0};
  for (int i = 0; i < A->columns && *check == OK; i++) {
    *check = d3_create_matrix(A->rows - 1, A->columns - 1, &buffer);
    if (*check == OK) {
      d3_matrix_filling(A, 0, i, &buffer);
      *check = d3_determinant(&buffer, &check_buffer);
      if ((i % 2) != 0) {
        check_buffer *= -1;
      }
      result += check_buffer * A->matrix[0][i];
    } else {
      *check = INCORRECT;
    }
    d3_remove_matrix(&buffer);
  }
  return result;
}

void d3_matrix_filling(matrix_t* A, int rows, int columns, matrix_t* result) {
  int k = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != rows) {
      for (int j = 0, m = 0; j < A->columns; j++) {
        if (j != columns) {
          result->matrix[k][m] = A->matrix[i][j];
          m++;
        }
      }
      k++;
    }
  }
}

int d3_calc_complements(matrix_t* A, matrix_t* result) {
  int check = d3_is_null_matrix(A);

  if (check != OK) {
    return check;
  }

  check = d3_square_matrix(A);

  if (check != OK) {
    return check;
  }

  matrix_t buffer = {0};
  check = d3_create_matrix(A->rows, A->columns, result);

  if (check != OK) {
    return check;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      check = d3_create_matrix(A->rows - 1, A->columns - 1, &buffer);

      if (check != OK) {
        d3_remove_matrix(result);
        return INCORRECT;
      }

      d3_matrix_filling(A, i, j, &buffer);
      d3_determinant(&buffer, &(result->matrix[i][j]));

      if (((i + j) % 2) != 0) {
        result->matrix[i][j] *= -1;
      }

      d3_remove_matrix(&buffer);
    }
  }

  return OK;
}

int d3_inverse_matrix(matrix_t* A, matrix_t* result) {
  int check = d3_is_null_matrix(A);

  if (check != OK) {
    return check;
  }

  check = d3_create_matrix(A->columns, A->rows, result);

  if (check != OK) {
    return check;
  }

  matrix_t buffer = {0};
  d3_calc_complements(A, &buffer);
  matrix_t bufferT = {0};
  d3_transpose(&buffer, &bufferT);

  double det = 0;
  check = d3_determinant(A, &det);

  if (check == OK && det == 0) {
    check = 2;
  }

  if (check == OK) {
    for (int i = 0; i < bufferT.rows; i++) {
      for (int j = 0; j < bufferT.columns; j++) {
        result->matrix[i][j] = bufferT.matrix[i][j] / det;
      }
    }
  }

  d3_remove_matrix(&bufferT);
  d3_remove_matrix(&buffer);

  return check;
}
