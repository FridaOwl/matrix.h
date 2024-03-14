#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../matrix.h"

START_TEST(create_test_1) {
  matrix_t A = {0}, B = {0};
  int rows = 4, columns = 4;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_2) {
  matrix_t A = {0}, B = {0};
  int rows = 1, columns = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_3) {
  matrix_t A = {0}, B = {0};
  int rows = 2, columns = 3;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_4) {
  matrix_t A = {0}, B = {0};
  int rows = 0, columns = 7;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_5) {
  matrix_t A = {0}, B = {0};
  int rows = 3, columns = 3;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_6) {
  matrix_t A = {0}, B = {0};
  int rows = 15, columns = 10;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_7) {
  matrix_t A = {0}, B = {0};
  int rows = 21, columns = 2;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_8) {
  matrix_t A = {0}, B = {0};
  int rows = 40, columns = 85;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_9) {
  matrix_t A = {0}, B = {0};
  int rows = 0, columns = 10;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(create_test_10) {
  matrix_t A = {0}, B = {0};
  int rows = 0, columns = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
}
END_TEST

START_TEST(transpose_test_1) {
  // симпл transpose test
  matrix_t A = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 2;
  int result_transpose = 0, result_compare = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(columns, rows, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  result_transpose = d3_transpose(&A, &result);

  origin_result.matrix[0][0] = 1;
  origin_result.matrix[0][1] = 2;
  origin_result.matrix[0][2] = 3;

  origin_result.matrix[1][0] = 4;
  origin_result.matrix[1][1] = 5;
  origin_result.matrix[1][2] = 6;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);

  ck_assert_int_eq(0, result_transpose);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(transpose_test_2) {
  // симпл transpose test
  matrix_t A = {0}, result = {0}, origin_result = {0};
  int rows = 2, columns = 3;
  int result_transpose = 0, result_compare = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(columns, rows, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  result_transpose = d3_transpose(&A, &result);

  origin_result.matrix[0][0] = 1;
  origin_result.matrix[0][1] = 4;

  origin_result.matrix[1][0] = 2;
  origin_result.matrix[1][1] = 5;

  origin_result.matrix[2][0] = 3;
  origin_result.matrix[2][1] = 6;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);

  ck_assert_int_eq(0, result_transpose);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(transpose_test_3) {
  // Test with NULL matrix
  matrix_t A = {0}, result = {0};
  int result_transpose = 0;

  result_transpose = d3_transpose(&A, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);
  ck_assert_int_eq(INCORRECT, result_transpose);
}
END_TEST

START_TEST(test_eq_1) {
  // Simple True test
  matrix_t A = {0}, B = {0};
  int rows = 4, columns = 4;
  int result = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
    }
  }
  result = d3_eq_matrix(&A, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test_eq_2) {
  // Simple False test
  matrix_t A = {0}, B = {0};
  int rows = 4, columns = 4;
  int result = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count + 1;
    }
  }
  result = d3_eq_matrix(&A, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test_eq_3) {
  // Test with different rows
  matrix_t A = {0}, B = {0};
  int rows = 4, columns = 4;
  int result = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows + 1, columns, &B);
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }
  for (int i = 0, count = 0; i < rows + 1; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }
  result = d3_eq_matrix(&A, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test_eq_4) {
  // Test with different columns
  matrix_t A = {0}, B = {0};
  int rows = 4, columns = 4;
  int result = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns + 1, &B);
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns + 1; j++, count++) {
      B.matrix[i][j] = count;
    }
  }
  result = d3_eq_matrix(&A, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test_eq_5) {
  // Test with random numbers
  matrix_t A = {0}, B = {0};
  int rows = 5, columns = 5;
  int result = 0;
  double count = 5.1239672;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      result += 0.123123;
    }
  }
  result = d3_eq_matrix(&A, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test_eq_6) {
  // Test with numbers after point
  matrix_t A = {0}, B = {0};
  int rows = 3, columns = 3;
  int result = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);

  A.matrix[0][0] = 2.147239624;
  B.matrix[0][0] = 2.147239665;
  A.matrix[0][1] = -12.651012325;
  B.matrix[0][1] = -12.651012376;
  A.matrix[0][2] = 7.093123285;
  B.matrix[0][2] = 7.093123224;

  A.matrix[1][0] = 1.259812392;
  B.matrix[1][0] = 1.259812375;
  A.matrix[1][1] = 200.012923590;
  B.matrix[1][1] = 200.012923509;
  A.matrix[1][2] = 3000012.125784705;
  B.matrix[1][2] = 3000012.125784724;

  A.matrix[2][0] = 4561.192039409;
  B.matrix[2][0] = 4561.192039423;
  A.matrix[2][1] = 13455.325893512;
  B.matrix[2][1] = 13455.325893589;
  A.matrix[2][2] = 123902.123893436;
  B.matrix[2][2] = 123902.123893422;

  result = d3_eq_matrix(&A, &B);
  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test_sum_1) {
  // Simple sum test
  matrix_t A = {0}, B = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int result_sum = 0, result_compare = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_create_matrix(rows, columns, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 23;
  A.matrix[0][2] = 5;

  A.matrix[1][0] = 4125;
  A.matrix[1][1] = 123;
  A.matrix[1][2] = 565;

  A.matrix[2][0] = 123;
  A.matrix[2][1] = 689;
  A.matrix[2][2] = -12312;

  B.matrix[0][0] = 143;
  B.matrix[0][1] = 535;
  B.matrix[0][2] = 324;

  B.matrix[1][0] = 123;
  B.matrix[1][1] = 123;
  B.matrix[1][2] = 2346;

  B.matrix[2][0] = 7865;
  B.matrix[2][1] = 2423;
  B.matrix[2][2] = 1;

  result_sum = d3_sum_matrix(&A, &B, &result);

  origin_result.matrix[0][0] = 144;
  origin_result.matrix[0][1] = 558;
  origin_result.matrix[0][2] = 329;

  origin_result.matrix[1][0] = 4248;
  origin_result.matrix[1][1] = 246;
  origin_result.matrix[1][2] = 2911;

  origin_result.matrix[2][0] = 7988;
  origin_result.matrix[2][1] = 3112;
  origin_result.matrix[2][2] = -12311;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);
  ck_assert_int_eq(0, result_sum);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(test_sum_2) {
  // Test with different rows
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sum = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows + 1, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }
  for (int i = 0, count = 0; i < rows + 1; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_sum = d3_sum_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(2, result_sum);
}
END_TEST

START_TEST(test_sum_3) {
  // Test with different columns
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sum = 0;
  d3_create_matrix(rows, columns + 1, &A);
  d3_create_matrix(rows, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns + 1; j++, count++) {
      A.matrix[i][j] = count;
    }
  }
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_sum = d3_sum_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(2, result_sum);
}
END_TEST

START_TEST(test_sum_4) {
  // Test with first NULL matrix
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sum = 0;
  d3_create_matrix(rows, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_sum = d3_sum_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(1, result_sum);
}
END_TEST

START_TEST(test_sum_5) {
  // Test with second NULL matrix
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sum = 0;
  d3_create_matrix(rows, columns, &A);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  result_sum = d3_sum_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(1, result_sum);
}
END_TEST

START_TEST(test_sub_1) {
  // Simple sub test
  matrix_t A = {0}, B = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int result_sub = 0, result_compare = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_create_matrix(rows, columns, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 23;
  A.matrix[0][2] = 5;

  A.matrix[1][0] = 4125;
  A.matrix[1][1] = 123;
  A.matrix[1][2] = 565;

  A.matrix[2][0] = 123;
  A.matrix[2][1] = 689;
  A.matrix[2][2] = -12312;

  B.matrix[0][0] = 143;
  B.matrix[0][1] = 535;
  B.matrix[0][2] = 324;

  B.matrix[1][0] = 123;
  B.matrix[1][1] = 123;
  B.matrix[1][2] = 2346;

  B.matrix[2][0] = 7865;
  B.matrix[2][1] = 2423;
  B.matrix[2][2] = 1;

  result_sub = d3_sub_matrix(&A, &B, &result);

  origin_result.matrix[0][0] = -142;
  origin_result.matrix[0][1] = -512;
  origin_result.matrix[0][2] = -319;

  origin_result.matrix[1][0] = 4002;
  origin_result.matrix[1][1] = 0;
  origin_result.matrix[1][2] = -1781;

  origin_result.matrix[2][0] = -7742;
  origin_result.matrix[2][1] = -1734;
  origin_result.matrix[2][2] = -12313;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);
  ck_assert_int_eq(0, result_sub);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(test_sub_2) {
  // Test with different rows
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sub = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows + 1, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }
  for (int i = 0, count = 0; i < rows + 1; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_sub = d3_sub_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(2, result_sub);
}
END_TEST

START_TEST(test_sub_3) {
  // Test with different columns
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sub = 0;
  d3_create_matrix(rows, columns + 1, &A);
  d3_create_matrix(rows, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns + 1; j++, count++) {
      A.matrix[i][j] = count;
    }
  }
  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_sub = d3_sub_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(2, result_sub);
}
END_TEST

START_TEST(test_sub_4) {
  // Test with first NULL matrix
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sub = 0;
  d3_create_matrix(rows, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_sub = d3_sub_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(1, result_sub);
}
END_TEST

START_TEST(test_sub_5) {
  // Test with second NULL matrix
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_sub = 0;
  d3_create_matrix(rows, columns, &A);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  result_sub = d3_sub_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(1, result_sub);
}
END_TEST

START_TEST(test_mult_num_1) {
  // Simple mul_num test
  matrix_t A = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int result_mult_num = 0, result_compare = 0;
  double num = 7;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 23;
  A.matrix[0][2] = 5;

  A.matrix[1][0] = 4125;
  A.matrix[1][1] = 123;
  A.matrix[1][2] = 565;

  A.matrix[2][0] = 123;
  A.matrix[2][1] = 689;
  A.matrix[2][2] = -12312;

  result_mult_num = d3_mult_number(&A, num, &result);

  origin_result.matrix[0][0] = 7;
  origin_result.matrix[0][1] = 161;
  origin_result.matrix[0][2] = 35;

  origin_result.matrix[1][0] = 28875;
  origin_result.matrix[1][1] = 861;
  origin_result.matrix[1][2] = 3955;

  origin_result.matrix[2][0] = 861;
  origin_result.matrix[2][1] = 4823;
  origin_result.matrix[2][2] = -86184;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);
  ck_assert_int_eq(0, result_mult_num);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(test_mult_num_2) {
  // Simple test when matrix is NULL
  matrix_t A = {0}, result = {0};
  int result_mult_num = 0;
  double num = 7;

  result_mult_num = d3_mult_number(&A, num, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);

  ck_assert_int_eq(1, result_mult_num);
}
END_TEST

START_TEST(test_mult_1) {
  // Simple mult test
  matrix_t A = {0}, B = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int result_mult = 0, result_compare = 0;
  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &B);
  d3_create_matrix(rows, columns, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 23;
  A.matrix[0][2] = 5;

  A.matrix[1][0] = 4125;
  A.matrix[1][1] = 123;
  A.matrix[1][2] = 565;

  A.matrix[2][0] = 123;
  A.matrix[2][1] = 689;
  A.matrix[2][2] = -12312;

  B.matrix[0][0] = 143;
  B.matrix[0][1] = 535;
  B.matrix[0][2] = 324;

  B.matrix[1][0] = 123;
  B.matrix[1][1] = 123;
  B.matrix[1][2] = 2346;

  B.matrix[2][0] = 7865;
  B.matrix[2][1] = 2423;
  B.matrix[2][2] = 1;

  result_mult = d3_mult_matrix(&A, &B, &result);

  origin_result.matrix[0][0] = 42297;
  origin_result.matrix[0][1] = 15479;
  origin_result.matrix[0][2] = 54287;

  origin_result.matrix[1][0] = 5048729;
  origin_result.matrix[1][1] = 3590999;
  origin_result.matrix[1][2] = 1625623;

  origin_result.matrix[2][0] = -96731544;
  origin_result.matrix[2][1] = -29681424;
  origin_result.matrix[2][2] = 1643934;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);
  ck_assert_int_eq(0, result_mult);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(test_mult_2) {
  // Mult test with first NULL matrix
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_mult = 0;
  d3_create_matrix(rows, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_mult = d3_mult_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(1, result_mult);
}
END_TEST

START_TEST(test_mult_3) {
  // Mult test with second NULL matrix
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_mult = 0;
  d3_create_matrix(rows, columns, &A);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  result_mult = d3_mult_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(1, result_mult);
}
END_TEST

START_TEST(test_mult_4) {
  // Mult test with different columns / rows
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 3, columns = 3;
  int result_mult = 0;
  d3_create_matrix(rows, columns + 1, &A);
  d3_create_matrix(rows, columns, &B);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns + 1; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      B.matrix[i][j] = count;
    }
  }

  result_mult = d3_mult_matrix(&A, &B, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  ck_assert_int_eq(2, result_mult);
}
END_TEST

START_TEST(test_mult_5) {
  // Test with non quadro matrix
  matrix_t A = {0}, B = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int result_mult = 0, result_compare = 0;
  d3_create_matrix(rows + 1, columns, &A);
  d3_create_matrix(rows, columns + 3, &B);
  d3_create_matrix(rows + 1, columns + 3, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 54;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;

  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 3;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 1;
  B.matrix[0][4] = 4;
  B.matrix[0][5] = 0;

  B.matrix[1][0] = 0;
  B.matrix[1][1] = 1;
  B.matrix[1][2] = 0;
  B.matrix[1][3] = 2;
  B.matrix[1][4] = 0;
  B.matrix[1][5] = 2;

  B.matrix[2][0] = 6;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 5;
  B.matrix[2][3] = 0;
  B.matrix[2][4] = 4;
  B.matrix[2][5] = 5;

  result_mult = d3_mult_matrix(&A, &B, &result);

  origin_result.matrix[0][0] = 18;
  origin_result.matrix[0][1] = 2;
  origin_result.matrix[0][2] = 18;
  origin_result.matrix[0][3] = 5;
  origin_result.matrix[0][4] = 16;
  origin_result.matrix[0][5] = 19;

  origin_result.matrix[1][0] = 324;
  origin_result.matrix[1][1] = 2;
  origin_result.matrix[1][2] = 273;
  origin_result.matrix[1][3] = 5;
  origin_result.matrix[1][4] = 220;
  origin_result.matrix[1][5] = 274;

  origin_result.matrix[2][0] = 0;
  origin_result.matrix[2][1] = 5;
  origin_result.matrix[2][2] = 9;
  origin_result.matrix[2][3] = 13;
  origin_result.matrix[2][4] = 12;
  origin_result.matrix[2][5] = 10;

  origin_result.matrix[3][0] = 18;
  origin_result.matrix[3][1] = 0;
  origin_result.matrix[3][2] = 15;
  origin_result.matrix[3][3] = 0;
  origin_result.matrix[3][4] = 12;
  origin_result.matrix[3][5] = 15;

  result_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&B);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);
  ck_assert_int_eq(0, result_mult);
  ck_assert_int_eq(1, result_compare);
}
END_TEST

START_TEST(test_deter_1) {
  // Simple True test
  matrix_t A = {0};
  int rows = 4, columns = 4;
  double origin_rez = 0, d3_rez = 0;
  double origin_det = 18, d3_det = 0;
  d3_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -5;
  A.matrix[0][3] = 8;

  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = -6;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = -5;
  A.matrix[2][2] = -7;
  A.matrix[2][3] = 5;

  A.matrix[3][0] = -4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = -6;

  d3_rez = d3_determinant(&A, &d3_det);
  d3_remove_matrix(&A);
  ck_assert_double_eq(origin_det, d3_det);
  ck_assert_int_eq(origin_rez, d3_rez);
}
END_TEST

START_TEST(test_deter_2) {
  // Simple True test 5 order
  matrix_t A = {0};
  int rows = 5, columns = 5;
  double origin_rez = 0, d3_rez = 0;
  double origin_det = 5610, d3_det = 0;
  d3_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -5;
  A.matrix[0][3] = 8;
  A.matrix[0][4] = 2;

  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = -6;
  A.matrix[1][4] = -61;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = -5;
  A.matrix[2][2] = -7;
  A.matrix[2][3] = 5;
  A.matrix[2][4] = 24;

  A.matrix[3][0] = -4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = -6;
  A.matrix[3][4] = -21;

  A.matrix[4][0] = 1;
  A.matrix[4][1] = 2;
  A.matrix[4][2] = 3;
  A.matrix[4][3] = 12;
  A.matrix[4][4] = -1;

  d3_rez = d3_determinant(&A, &d3_det);
  d3_remove_matrix(&A);
  ck_assert_double_eq(origin_det, d3_det);
  ck_assert_int_eq(origin_rez, d3_rez);
}
END_TEST

START_TEST(test_deter_3) {
  // test with NULL matrix
  matrix_t A = {0};
  double d3_rez = 0;
  double d3_det = 0;
  d3_rez = d3_determinant(&A, &d3_det);
  d3_remove_matrix(&A);
  ck_assert_int_eq(INCORRECT, d3_rez);
}
END_TEST

START_TEST(test_deter_4) {
  // test with non square matrix
  matrix_t A = {0};
  int rows = 5, columns = 4;
  double d3_rez = 0;
  double d3_det = 0;

  d3_create_matrix(rows, columns, &A);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  d3_rez = d3_determinant(&A, &d3_det);
  d3_remove_matrix(&A);
  ck_assert_int_eq(CALC_ERR, d3_rez);
}
END_TEST

START_TEST(test_dete_5) {
  // one matrix
  matrix_t A = {0};
  int rows = 1, columns = 1;
  int d3_rez = 0;
  double d3_det = 0, origin_determinat = 5;

  d3_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 5;

  d3_rez = d3_determinant(&A, &d3_det);

  d3_remove_matrix(&A);
  ck_assert_int_eq(OK, d3_rez);
  ck_assert_int_eq(origin_determinat, d3_det);
}
END_TEST

START_TEST(minor_test_1) {
  // basic minor test
  matrix_t A = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int d3_rez = 0, d3_compare = 0;

  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &origin_result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  d3_rez = d3_calc_complements(&A, &result);

  origin_result.matrix[0][0] = 0;
  origin_result.matrix[0][1] = 10;
  origin_result.matrix[0][2] = -20;

  origin_result.matrix[1][0] = 4;
  origin_result.matrix[1][1] = -14;
  origin_result.matrix[1][2] = 8;

  origin_result.matrix[2][0] = -8;
  origin_result.matrix[2][1] = -2;
  origin_result.matrix[2][2] = 4;

  d3_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);

  ck_assert_int_eq(0, d3_rez);
  ck_assert_int_eq(1, d3_compare);
}
END_TEST

START_TEST(minor_test_2) {
  // basic minor test with NULL matrix
  matrix_t A = {0}, result = {0};
  int d3_rez = 0;

  d3_rez = d3_calc_complements(&A, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);

  ck_assert_int_eq(INCORRECT, d3_rez);
}
END_TEST

START_TEST(minor_test_3) {
  // test with no square matrix
  matrix_t A = {0}, result = {0};
  int rows = 3, columns = 4;
  int d3_rez = 0;

  d3_create_matrix(rows, columns, &A);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  d3_rez = d3_calc_complements(&A, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);

  ck_assert_int_eq(CALC_ERR, d3_rez);
}
END_TEST

START_TEST(inversion_test_1) {
  // simple inverstion_test
  matrix_t A = {0}, result = {0}, origin_result = {0};
  int rows = 3, columns = 3;
  int d3_rez = 0, d3_compare = 0;

  d3_create_matrix(rows, columns, &A);
  d3_create_matrix(rows, columns, &origin_result);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  d3_rez = d3_inverse_matrix(&A, &result);

  origin_result.matrix[0][0] = 1;
  origin_result.matrix[0][1] = -1;
  origin_result.matrix[0][2] = 1;

  origin_result.matrix[1][0] = -38;
  origin_result.matrix[1][1] = 41;
  origin_result.matrix[1][2] = -34;

  origin_result.matrix[2][0] = 27;
  origin_result.matrix[2][1] = -29;
  origin_result.matrix[2][2] = 24;

  d3_compare = d3_eq_matrix(&result, &origin_result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);
  d3_remove_matrix(&origin_result);

  ck_assert_int_eq(0, d3_rez);
  ck_assert_int_eq(1, d3_compare);
}
END_TEST

START_TEST(inversion_test_2) {
  // inversion with NULL matrix
  matrix_t A = {0}, result = {0};
  int d3_rez = 0;

  d3_rez = d3_inverse_matrix(&A, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);

  ck_assert_int_eq(INCORRECT, d3_rez);
}
END_TEST

START_TEST(inversion_test_3) {
  // inverstion with non square maatrix
  matrix_t A = {0}, result = {0};
  int d3_rez = 0;
  int rows = 3, columns = 4;

  d3_create_matrix(rows, columns, &A);

  for (int i = 0, count = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++, count++) {
      A.matrix[i][j] = count;
    }
  }

  d3_rez = d3_inverse_matrix(&A, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);

  ck_assert_int_eq(CALC_ERR, d3_rez);
}
END_TEST

START_TEST(inversion_test_4) {
  // inverstion with det == 0
  matrix_t A = {0}, result = {0};
  int d3_rez = 0;
  int rows = 3, columns = 3;

  d3_create_matrix(rows, columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 9;
  A.matrix[2][2] = 5;

  d3_rez = d3_inverse_matrix(&A, &result);

  d3_remove_matrix(&A);
  d3_remove_matrix(&result);

  ck_assert_int_eq(CALC_ERR, d3_rez);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  /* User-specified pre-run code */
  srunner_set_fork_status(sr, CK_NOFORK);

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_test_1);
  tcase_add_test(tc1_1, create_test_2);
  tcase_add_test(tc1_1, create_test_3);
  tcase_add_test(tc1_1, create_test_4);
  tcase_add_test(tc1_1, create_test_5);
  tcase_add_test(tc1_1, create_test_6);
  tcase_add_test(tc1_1, create_test_7);
  tcase_add_test(tc1_1, create_test_8);
  tcase_add_test(tc1_1, create_test_9);
  tcase_add_test(tc1_1, create_test_10);
  tcase_add_test(tc1_1, transpose_test_1);
  tcase_add_test(tc1_1, transpose_test_2);
  tcase_add_test(tc1_1, transpose_test_3);
  tcase_add_test(tc1_1, test_eq_1);
  tcase_add_test(tc1_1, test_eq_2);
  tcase_add_test(tc1_1, test_eq_3);
  tcase_add_test(tc1_1, test_eq_4);
  tcase_add_test(tc1_1, test_eq_5);
  tcase_add_test(tc1_1, test_eq_6);
  tcase_add_test(tc1_1, test_sum_1);
  tcase_add_test(tc1_1, test_sum_2);
  tcase_add_test(tc1_1, test_sum_3);
  tcase_add_test(tc1_1, test_sum_4);
  tcase_add_test(tc1_1, test_sum_5);
  tcase_add_test(tc1_1, test_sub_1);
  tcase_add_test(tc1_1, test_sub_2);
  tcase_add_test(tc1_1, test_sub_3);
  tcase_add_test(tc1_1, test_sub_4);
  tcase_add_test(tc1_1, test_sub_5);
  tcase_add_test(tc1_1, test_mult_num_1);
  tcase_add_test(tc1_1, test_mult_num_2);
  tcase_add_test(tc1_1, test_mult_1);
  tcase_add_test(tc1_1, test_mult_2);
  tcase_add_test(tc1_1, test_mult_3);
  tcase_add_test(tc1_1, test_mult_4);
  tcase_add_test(tc1_1, test_mult_5);
  tcase_add_test(tc1_1, test_deter_1);
  tcase_add_test(tc1_1, test_deter_2);
  tcase_add_test(tc1_1, test_deter_3);
  tcase_add_test(tc1_1, test_deter_4);
  tcase_add_test(tc1_1, test_dete_5);
  tcase_add_test(tc1_1, minor_test_1);
  tcase_add_test(tc1_1, minor_test_2);
  tcase_add_test(tc1_1, minor_test_3);
  tcase_add_test(tc1_1, inversion_test_1);
  tcase_add_test(tc1_1, inversion_test_2);
  tcase_add_test(tc1_1, inversion_test_3);
  tcase_add_test(tc1_1, inversion_test_4);

  srunner_run_all(sr, CK_ENV);
  srunner_free(sr);

  return 0;
}
