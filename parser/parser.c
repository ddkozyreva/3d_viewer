#include "parser.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

static int isnum(char c);
static void parserf(FILE *file, viewer *src, char *c);
static void parserv(FILE *file, viewer *src);

int parser_obj(char file_name[256], viewer *src) {
  setlocale(LC_ALL, "C");
  src->count_edges = 0;
  int return_value = 0;
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("NO FILE\n");
    printf("%s\n", file_name);
    return_value = 1;
  } else {
    src->count_vertex = 0;
    src->count_facet = 0;
    src->array_v = calloc(1, sizeof(double));
    src->array_f = calloc(1, sizeof(unsigned));
    src->polygon_array = calloc(1, sizeof(unsigned));
    unsigned int max_type = 3;
    src->polygon_array[0] = 0;
    char c, buff;
    while (c != EOF) {
      c = fgetc(file);
      if (buff == 'v' && c == ' ') {
        parserv(file, src);
      } else if (buff == 'f' && c == ' ') {
        parserf(file, src, &c);
        if (src->polygon_type > max_type) {
          src->polygon_array =
            realloc(src->polygon_array, (src->polygon_type - max_type) * sizeof(unsigned));
          max_type = src->polygon_type;
        }
        src->polygon_array[src->polygon_type - 3]++;
      }
      buff = c;
    }

    if (!src->count_vertex || !src->count_facet) {
      free(src->array_v);
      free(src->array_f);
      return_value = 1;
    }

    fclose(file);
    for (unsigned int i = 0; i <= max_type - 3; i++) {
        src->count_edges+= src->polygon_array[i] * (i + 3) / 2;
    }
  }
  return return_value;
}

static void parserv(FILE *file, viewer *src) {
  src->array_v =
      realloc(src->array_v, (src->count_vertex + 3) * sizeof(double));
  if (src->array_v == NULL) {
    printf("ERROR MEMORY");
    exit(1);
  }
  for (int k = 0; k < 3; k++) src->array_v[src->count_vertex + k] = 0;
  fscanf(file, "%lf %lf %lf", &src->array_v[src->count_vertex],
         &src->array_v[src->count_vertex + 1],
         &src->array_v[src->count_vertex + 2]);
  for (int k = 0; k < 3; k++) {
    if (fabs(src->array_v[src->count_vertex + k]) > src->maxV)
      src->maxV = fabs(src->array_v[src->count_vertex + k]);
  }
  src->count_vertex += 3;
}

static void parserf(FILE *file, viewer *src, char *c) {
  int k = 1;
  unsigned int first = src->count_facet;
  src->polygon_type = 0;
  while (*c != '\n' && *c != EOF) {
    *c = fgetc(file);
    if (isnum(*c)) {
      if (k < 3) {
        src->array_f =
            realloc(src->array_f, (1 + src->count_facet) * sizeof(unsigned));

        if (src->array_f == NULL) {
          printf("MEMORY ERROR\n");
          exit(1);
        }
      } else {
        src->array_f =
            realloc(src->array_f, (2 + src->count_facet) * sizeof(unsigned));
        if (src->array_f == NULL) {
          printf("MEMORY ERROR\n");
          exit(1);
        }
        src->array_f[src->count_facet] = src->array_f[src->count_facet - 1];
        src->count_facet++;
      }
      src->array_f[src->count_facet] = 0;
      while (isnum(*c)) {
        src->array_f[src->count_facet] *= 10;
        src->array_f[src->count_facet] += *c - 48;
        *c = fgetc(file);
      }
      src->array_f[src->count_facet]--;
      k++;
      while (*c != ' ' && *c != '\n' && *c != EOF) *c = fgetc(file);
      src->count_facet++;
      src->polygon_type++;
    }
  }
  src->array_f =
      realloc(src->array_f, (2 + src->count_facet) * sizeof(unsigned));
  if (src->array_f == NULL) {
    printf("MEMORY ERROR\n");
    exit(1);
  }
  src->array_f[src->count_facet] = src->array_f[src->count_facet - 1];
  src->array_f[src->count_facet + 1] = src->array_f[first];
  src->count_facet += 2;
  if (!src->polygon_type) 
    src->polygon_type = 1;
}

static int isnum(char c) { return (c > 47 && c < 58); }
