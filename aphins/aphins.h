#ifndef SRC_APHINS_APHINS_H_
#define SRC_APHINS_APHINS_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../parser/parser.h"

double degrees_to_radian(double deg);

void move_x(viewer* src, double x);
void move_y(viewer* src, double y);
void move_z(viewer* src, double z);

void rotation_by_ox(viewer* src, double angle);
void rotation_by_oy(viewer* src, double angle);
void rotation_by_oz(viewer* src, double angle);

void scaling(viewer* src, double proportion);

#endif  // SRC_APHINS_APHINS_H_