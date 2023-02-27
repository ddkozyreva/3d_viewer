#ifndef VIREWPORT_H
#define VIREWPORT_H
#define GL_SILENCE_DEPRECATION

#include <QtCore/qsettings.h>
#include <QtGui/qevent.h>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMainWindow>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QThread>
#include <QWidget>
#include <QWindow>

#include "options_window.h"
extern "C" {
#include "aphins/aphins.h"
#include "parser/parser.h"
}

#define N 256
#define VERTEX_TYPE_CIRCLE 1
#define VERTEX_TYPE_SQUARE 2
#define VERTEX_TYPE_DISABLED 0

class ViewPort : public QOpenGLWidget {
  Q_OBJECT

 private:
  float hwidth, hheight;

  QPoint mPos;
  QPoint mPos_old;
  double xRot_old;
  double yRot_old;

  double x_pos_old;
  double y_pos_old;
  double z_pos_old;

  double x_rot_old;
  double y_rot_old;
  double z_rot_old;

  double scale_old;

  double lineWidth;
  double vertex_size;
  int line_type;
  int vertex_type;
  int projection_type;

  double scaleFactorX, scaleFactorY, scaleFactorZ;
  double xMov, yMov, zMov;
  double xRot, yRot, zRot;

  double rColor, gColor, bColor;
  double rBackColor, gBackColor, bBackColor;

  void mousePressEvent(QMouseEvent*) override;
  void mouseMoveEvent(QMouseEvent*) override;
  void mouseReleaseEvent(QMouseEvent*) override;
  void ParallelProjection();
  void PerspectiveProjection();
  double x_min, x_max;
  bool mouse_released_flag;

 public:
  QSettings* settings;
  ViewPort(QWidget* parent = nullptr);
  void InitializeViewportParameters();
  void InitializeModelParameters(double x_pos, double y_pos, double z_pos,
                                 double x_rot, double y_rot, double z_rot,
                                 double scale);
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void SetModelPath(char* model_path);
  // int parser_return_value;
  // int IsParserFailed(int);
  viewer src;
  // char file_path[256] =
  //     "/Users/longshot/projects/C8_3DViewer_v1.0-1/src/cow.obj";
  char file_path[256] = "";
 public slots:
};

#endif  // VIEWPORT_H
