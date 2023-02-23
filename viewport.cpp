#include "viewport.h"

#include <QtCore/qlogging.h>
#include <QtGui/qcolor.h>
#include <QtWidgets/qmessagebox.h>

#include <QDebug>
#include <cstring>

#include "options_window.h"

// #include <string>
ViewPort::ViewPort(QWidget* parent) : QOpenGLWidget(parent) {
  scaleFactorX = 0.5;
  scaleFactorY = 0.5;
  scaleFactorZ = 0.5;
  xMov = 0;
  yMov = 0;
  zMov = 0;
  xRot = 0;
  yRot = 0;
  zRot = 0;
  mouse_released_flag = 0;
  xRot_old = 0;
  yRot_old = 0;
  x_pos_old = 0;
  y_pos_old = 0;
  z_pos_old = 0;

  x_rot_old = 0;
  y_rot_old = 0;
  z_rot_old = 0;

  scale_old = 1;
  // update();
}

void ViewPort::SetModelPath(char* model_path) { strcpy(file_path, model_path); }

void ViewPort::InitializeViewportParameters() {
  rBackColor = 0.5;
  gBackColor = 0.5;
  bBackColor = 0.5;
  rColor = 1;
  gColor = 1;
  bColor = 0;
  lineWidth = 2;
  vertex_size = 4;
  vertex_type = 1;
  line_type = 1;
  // rBackColor = settings->value("background_color_red").toDouble();
  // gBackColor = settings->value("background_color_green").toDouble();
  // bBackColor = settings->value("background_color_blue").toDouble();
  // rColor = settings->value("edges_coor_red").toDouble();
  // gColor = settings->value("edges_coor_green").toDouble();
  // bColor = settings->value("edges_coor_blue").toDouble();
  // qDebug() << "Model colors \n";
  // qDebug() << rColor << " " << gColor << " " << bColor
  //          << "\n";  // QColor background_color;
  // lineWidth = settings->value("line_width").toDouble();
  // vertex_size = settings->value("vertex_size").toDouble();
  // vertex_type = settings->value("vertex_type").toInt();
  // line_type = settings->value("line_type").toInt();
  // background_color = settings_window.background_color->currentColor();
  // background_color.getRgb(&rBackColor,&gBackColor,&bBackColor);
}
void ViewPort::InitializeModelParameters(double x_pos, double y_pos,
                                         double z_pos, double x_rot,
                                         double y_rot, double z_rot,
                                         double scale) {
  printf("into initialize model parameters\n");
  move_x(&src, x_pos - x_pos_old);
  move_y(&src, y_pos - y_pos_old);
  move_z(&src, z_pos - z_pos_old);
  x_pos_old = x_pos;
  y_pos_old = y_pos;
  z_pos_old = z_pos;

  printf("dasha point\n");
  rotation_by_ox(&src, x_rot - x_rot_old);
  rotation_by_oy(&src, y_rot - y_rot_old);
  rotation_by_oz(&src, z_rot - z_rot_old);
  x_rot_old = x_rot;
  y_rot_old = y_rot;
  z_rot_old = z_rot;

  printf("dasha point\n");
  scaling(&src, scale / scale_old);
  scale_old = scale;

  printf("before update\n");
  update();
  printf("after update\n");
}

void ViewPort::initializeGL() { glEnable(GL_DEPTH_TEST); }

void ViewPort::ParallelProjection() {}
void ViewPort::paintGL() {
  printf("inside paintGL\n");
  if (strlen(file_path)) {
  printf("after if file path \n");
    InitializeViewportParameters();
    float dx = 0.5f;
    glPointSize(vertex_size);  // vertex size
    glLineWidth(lineWidth);

    double* vertices = src.array_v;
    GLdouble colors[] = {rColor, gColor, bColor};
    GLuint* index = src.array_f;
    glClearColor(rBackColor, gBackColor, bBackColor, 1.0f);  // цвет фона
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1 * src.maxV, 1 * src.maxV, -1 * src.maxV, 1 * src.maxV,
            -1 * src.maxV,
            1 * src.maxV);  // изменение диапазона координат по х, y, z
    glScaled(scaleFactorX, scaleFactorY, scaleFactorZ);

    glTranslated(xMov, yMov, zMov);

    glRotated(xRot, 1, 0, 0);
    glRotated(yRot, 0, 1, 0);
    glRotated(zRot, 0, 0, 1);

    glVertexPointer(3, GL_DOUBLE, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, &colors);  // 3 переменные описывают цевт
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3d(rColor, gColor, bColor);
    // Если нужен пунктир, то:
    if (!line_type) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(2, 0x0F0F);
    }

    // if (способ отображения = круг) {
    // 1 = circle
    // 2 = square
    // 0 = none
    if (vertex_type == 1) {
      glEnable(GL_POINT_SMOOTH);
    }
    if (vertex_type) {
      glDrawArrays(GL_POINTS, 0,
                   src.count_vertex / 3);  // 0 - с какого элемента отсчет в
                                           // массиве, 4 - сколько взять
    }
    if (vertex_type == 1) {
      glDisable(GL_POINT_SMOOTH);
    }
    glDrawElements(GL_LINES, src.count_facet, GL_UNSIGNED_INT,
                   index);  // 24 - количество точек из массива индексов

    glDisable(GL_LINE_STIPPLE);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
  printf("after if inside paintGL\n");
  
}

void ViewPort::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  update();
}

void ViewPort::mousePressEvent(QMouseEvent* mouse) { mPos = mouse->pos(); }

void ViewPort::mouseReleaseEvent(QMouseEvent*) {
  mPos_old = mPos;
  mouse_released_flag = 1;
  xRot_old = xRot;
  yRot_old = yRot;
}
void ViewPort::mouseMoveEvent(QMouseEvent* mouse) {
  if (!mouse_released_flag) {
    xRot = 1 / M_PI * (mouse->pos().y() - mPos.y()) + xRot_old;
    yRot = 1 / M_PI * (mouse->pos().x() - mPos.x()) + yRot_old;
    xRot_old = 0;
    yRot_old = 0;
    update();
  } else {
    mPos.setY(mouse->pos().y());
    mPos.setX(mouse->pos().x());
    mouse_released_flag = 0;
  }
}
