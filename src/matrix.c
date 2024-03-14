#include "matrix.h"

int d3_create_matrix(int rows, int columns, matrix_t* result) {
  int check = INCORRECT;

  if (!(rows > 0 && columns > 0)) {
    return CALC_ERR;
  }

  result->matrix = (double**)calloc(rows, sizeof(double*));
  if (!result->matrix) {
    return CALC_ERR;
  }

  for (int i = 0; i < rows; i += 1) {
    result->matrix[i] = (double*)calloc(columns, sizeof(double));
    if (!result->matrix[i]) {
      for (int j = 0; j < i; j += 1) free(result->matrix[j]);
      free(result->matrix);
      return CALC_ERR;
    }
    for (int k = 0; k < columns; k += 1) {
      result->matrix[i][k] = 0;
    }
  }

  result->columns = columns;
  result->rows = rows;
  check = OK;

  return check;
}

void d3_remove_matrix(matrix_t* A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i += 1) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

int d3_check_matrix_inputs(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (A == NULL || B == NULL || result == NULL) {
    return INCORRECT;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return CALC_ERR;
  }

  if (d3_create_matrix(A->rows, A->columns, result) != OK) {
    return CALC_ERR;
  }

  return OK;
}

int d3_square_matrix(matrix_t* A) {
  int check = OK;
  if (A->rows != A->columns) {
    check = CALC_ERR;
  }
  return check;
}

int d3_is_null_matrix(matrix_t* A) {
  int check = OK;
  if (A->matrix == NULL) {
    check = INCORRECT;
  }
  return check;
}

int d3_eq_matrix(matrix_t* A, matrix_t* B) {
  if (A == NULL || B == NULL || A->rows != B->rows ||
      A->columns != B->columns) {
    return FAILURE;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double A_integer, A_fract;
      double B_integer, B_fract;

      A_fract = modf(A->matrix[i][j], &A_integer);
      B_fract = modf(B->matrix[i][j], &B_integer);

      if (A_integer != B_integer || !d3_compare_fract_parts(A_fract, B_fract)) {
        return FAILURE;
      }
    }
  }

  return SUCCESS;
}

int d3_compare_fract_parts(double a, double b) {
  int k = 0;
  int result = SUCCESS;

  while (k < 7 && result == SUCCESS) {
    a *= 10;
    b *= 10;
    double a_integer;
    double b_integer;
    modf(a, &a_integer);
    modf(b, &b_integer);

    if (a_integer != b_integer) {
      result = FAILURE;
    }

    k++;
  }

  return result;
}

int d3_transpose(matrix_t* A, matrix_t* result) {
  int check = d3_is_null_matrix(A);

  if (check != OK) {
    return check;
  }

  check = d3_create_matrix(A->columns, A->rows, result);
  if (check != OK) {
    return check;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}
