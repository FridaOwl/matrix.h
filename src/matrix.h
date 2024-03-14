#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT 1
#define CALC_ERR 2

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

int d3_create_matrix(int rows, int columns, matrix_t* result);
void d3_remove_matrix(matrix_t* A);
int d3_eq_matrix(matrix_t* A, matrix_t* B);
int d3_is_null_matrix(matrix_t* A);
int d3_compare_fract_parts(double a, double b);
int d3_check_matrix_inputs(matrix_t* A, matrix_t* B, matrix_t* result);
int d3_square_matrix(matrix_t* A);
int d3_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int d3_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int d3_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int d3_mult_number(matrix_t* A, double number, matrix_t* result);
int d3_transpose(matrix_t* A, matrix_t* result);
int d3_determinant(matrix_t* A, double* result);
void d3_matrix_filling(matrix_t* A, int rows, int columns, matrix_t* result);
double d3_complement_of_first_row(matrix_t* A, int* check);
int d3_calc_complements(matrix_t* A, matrix_t* result);
int d3_inverse_matrix(matrix_t* A, matrix_t* result);

#endif  // SRC_MATRIX_H_