#ifndef SRC_PARSER_PARSER_H_
#define SRC_PARSER_PARSER_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct death {
  unsigned int count_vertex;
  unsigned int count_facet;
  double *array_v;
  unsigned int *array_f;
  double maxV;
} viewer;

int parser_obj(char file_name[256], viewer *src);

#endif  // SRC_PARSER_PARSER_H_
