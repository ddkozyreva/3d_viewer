#include "aphins.h"

double degrees_to_radian(double deg) { return deg * M_PI / 180.0; }

void move_x(viewer* src, double x) {
  unsigned int i = 0;
  while (i < src->count_vertex) {
    src->array_v[i] += x;
    i += 3;
  }
}

void move_y(viewer* src, double y) {
  unsigned int i = 0;
  while (i < src->count_vertex) {
    src->array_v[i + 1] += y;
    i += 3;
  }
}

void move_z(viewer* src, double z) {
  unsigned int i = 0;
  while (i < src->count_vertex) {
    src->array_v[i + 2] += z;
    i += 3;
  }
}

void rotation_by_ox(viewer* src, double angle) {
  unsigned int i = 0;
  double temp_y, temp_z;
  angle = degrees_to_radian(angle);
  while (i < src->count_vertex) {
    temp_y = src->array_v[i + 1];
    temp_z = src->array_v[i + 2];
    src->array_v[i + 1] = cos(angle) * temp_y - sin(angle) * temp_z;
    ;
    src->array_v[i + 2] = sin(angle) * temp_y + cos(angle) * temp_z;
    i += 3;
  }
}

void rotation_by_oy(viewer* src, double angle) {
  unsigned int i = 0;
  double temp_x, temp_z;
  angle = degrees_to_radian(angle);
  while (i < src->count_vertex) {
    temp_x = src->array_v[i];
    temp_z = src->array_v[i + 2];
    src->array_v[i] = cos(angle) * temp_x + sin(angle) * temp_z;
    ;
    src->array_v[i + 2] = -sin(angle) * temp_x + cos(angle) * temp_z;
    i += 3;
  }
}

void rotation_by_oz(viewer* src, double angle) {
  unsigned int i = 0;
  double temp_x, temp_y;
  angle = degrees_to_radian(angle);
  while (i < src->count_vertex) {
    temp_x = src->array_v[i];
    temp_y = src->array_v[i + 1];
    src->array_v[i] = cos(angle) * temp_x + sin(angle) * temp_y;
    src->array_v[i + 1] = -sin(angle) * temp_x + cos(angle) * temp_y;
    i += 3;
  }
}

void scaling(viewer* src, double proportion) {
  unsigned int i = 0;
  double temp_x, temp_y;
  if (proportion > 0) {
    while (i < src->count_vertex) {
      src->array_v[i] *= proportion;
      src->array_v[i + 1] *= proportion;
      src->array_v[i + 2] *= proportion;
      i += 3;
    }
  }
}