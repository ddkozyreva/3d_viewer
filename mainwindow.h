#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qbytearraylist.h>
#include <QtGui/qevent.h>

#include <QDebug>
#include <QMainWindow>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QThread>
#include <QWidget>
#include <QWindow>
#include <iostream>
// #include <QtWidgets/qfiledialog.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qstatusbar.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#include "options_window.h"
#include "viewport.h"

extern "C" {
#include "parser/parser.h"
}

#include <float.h>

#include "ui_ViewerInterface.h"
#include "ui_options_window.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  // // void mousePressEvent(QMouseEvent*) override;
  // void mouseMoveEvent(QMouseEvent*) override;
  double x_rot, y_rot, z_rot;

  int background_color_red_value, background_color_green_value,
      background_color_blue_value;
  int edges_color_red_value, edges_color_green_value, edges_color_blue_value;
  int vertex_color_red_value, vertex_color_green_value, vertex_color_blue_value;

  double vertex_size, edge_size;
  int edge_type, vertex_type, projection_type;

public:
  MainWindow(QMainWindow *parent = nullptr);
  Ui::ViewerInterface ui;
  // ViewPort vport;
  options_window settings_window;
  // QSettings settings_viewport;

  void StatusBarSetup();
  void SpinBoxValueSensor();
  void Settings();

private slots:
  void OptionsPressed();
  void SpinBoxValueChanged();
  void OpenButtonPressed();
  void RecordButtonPressed();

public slots:
};

#endif // MAINWINDOW_H
