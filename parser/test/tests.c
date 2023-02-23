#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// #define PathTestFile = obj_files/cube_test.obj
#include "../../aphins/aphins.h"
#include "../parser.h"


START_TEST(parser_array_v) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 1, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(parser_array_f) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  ck_assert_uint_eq(a.array_f[0], 0);
  ck_assert_uint_eq(a.array_f[1], 6);
  ck_assert_uint_eq(a.array_f[2], 6);
  ck_assert_uint_eq(a.array_f[3], 4);
  ck_assert_uint_eq(a.array_f[4], 4);
  ck_assert_uint_eq(a.array_f[5], 0);
  ck_assert_uint_eq(a.array_f[6], 0);
  ck_assert_uint_eq(a.array_f[7], 2);
  ck_assert_uint_eq(a.array_f[8], 2);
  ck_assert_uint_eq(a.array_f[9], 6);
  ck_assert_uint_eq(a.array_f[10], 6);
  ck_assert_uint_eq(a.array_f[11], 0);
  ck_assert_uint_eq(a.array_f[12], 0);
  ck_assert_uint_eq(a.array_f[13], 3);
  ck_assert_uint_eq(a.array_f[14], 3);
  ck_assert_uint_eq(a.array_f[15], 2);
  ck_assert_uint_eq(a.array_f[16], 2);
  ck_assert_uint_eq(a.array_f[17], 0);
  ck_assert_uint_eq(a.array_f[18], 0);
  ck_assert_uint_eq(a.array_f[19], 1);
  ck_assert_uint_eq(a.array_f[20], 1);
  ck_assert_uint_eq(a.array_f[21], 3);
  ck_assert_uint_eq(a.array_f[22], 3);
  ck_assert_uint_eq(a.array_f[23], 0);
  ck_assert_uint_eq(a.array_f[24], 2);
  ck_assert_uint_eq(a.array_f[25], 7);
  ck_assert_uint_eq(a.array_f[26], 7);
  ck_assert_uint_eq(a.array_f[27], 6);
  ck_assert_uint_eq(a.array_f[28], 6);
  ck_assert_uint_eq(a.array_f[29], 2);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(parser_viewer) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  ck_assert_uint_eq(a.count_vertex, 24);
  ck_assert_uint_eq(a.count_facet, 72);
  ck_assert_float_eq_tol(a.maxV, 1, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(scaling_test) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  scaling(&a, 3);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 3, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 3, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(rotateX) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  rotation_by_ox(&a, -2);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0.034899, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 0.999391, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 0.999391, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], -0.034899, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 0.964491, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 0.034899, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 0.999391, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 0.999391, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], -0.034899, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 1.034290, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 0.964491, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(rotateY) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  rotation_by_oy(&a, 1);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0.017452, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 0.999848, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0.017452, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 0.999848, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 0.999848, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], -0.017452, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 1.017300, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 0.982395, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 0.999848, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], -0.017452, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 1.017300, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 0.982395, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(rotateZ) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  rotation_by_oz(&a, 2.5);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0.043619, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 0.999048, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0.043619, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 0.999048, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 0.999048, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], -0.043619, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 0.999048, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], -0.043619, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 1.042668, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 0.955429, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 1.042668, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 0.955429, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 1, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(moveX) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  move_x(&a, 8);
  ck_assert_float_eq_tol(a.array_v[0], 8, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 8, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 8, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 8, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 9, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 9, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 9, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 9, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 1, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(moveY) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  move_y(&a, 4);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 4, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 4, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 5, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 5, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 4, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 4, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 5, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 5, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 1, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(moveZ) {
  viewer a;
  parser_obj("obj_files/cube_test.obj", &a);
  move_z(&a, 0);
  ck_assert_float_eq_tol(a.array_v[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[7], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[10], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[11], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[15], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[17], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[18], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.array_v[21], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.array_v[23], 1, 1e-6);
  free(a.array_v);
  free(a.array_f);
}
END_TEST

START_TEST(nofile) {
  viewer a;
  int res = parser_obj("obj_files/cube.obj", &a);
  ck_assert_float_eq_tol(res, 1, 1e-6);
}
END_TEST

START_TEST(memory) {
  viewer a;
  int res = parser_obj("obj_files/memory.obj", &a);
  ck_assert_float_eq_tol(res, 1, 1e-6);
}
END_TEST

Suite *s21_3d_suite(void) {
  Suite *suite;
  suite = suite_create("s21_3d");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, parser_array_v);
  tcase_add_test(tcase_core, parser_array_f);
  tcase_add_test(tcase_core, parser_viewer);
  tcase_add_test(tcase_core, scaling_test);
  tcase_add_test(tcase_core, rotateX);
  tcase_add_test(tcase_core, rotateY);
  tcase_add_test(tcase_core, rotateZ);
  tcase_add_test(tcase_core, moveX);
  tcase_add_test(tcase_core, moveY);
  tcase_add_test(tcase_core, moveZ);
  tcase_add_test(tcase_core, nofile);
  tcase_add_test(tcase_core, memory);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  
  Suite *suite = s21_3d_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
