#include "matrix.h"

int d3_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (d3_is_null_matrix(A) != OK || d3_is_null_matrix(B) != OK) {
    return INCORRECT;
  }

  int check = d3_check_matrix_inputs(A, B, result);
  if (check != OK) {
    return check;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

int d3_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (d3_is_null_matrix(A) != OK || d3_is_null_matrix(B) != OK) {
    return INCORRECT;
  }

  int check = d3_check_matrix_inputs(A, B, result);
  if (check != OK) {
    return check;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

int d3_mult_number(matrix_t* A, double number, matrix_t* result) {
  int check = d3_is_null_matrix(A);

  if (check != OK) {
    return INCORRECT;
  }

  check = d3_create_matrix(A->rows, A->columns, result);
  if (check != OK) {
    return check;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int d3_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int checkA = d3_is_null_matrix(A);
  int checkB = d3_is_null_matrix(B);

  if (checkA != OK || checkB != OK) {
    return INCORRECT;
  }

  if (A->columns != B->rows) {
    return CALC_ERR;
  }

  int checkCreate = d3_create_matrix(A->rows, B->columns, result);
  if (checkCreate != OK) {
    return checkCreate;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}
