#ifndef OPTIONS_WINDOW_H
#define OPTIONS_WINDOW_H

#include <QtWidgets/qcolordialog.h>

#include <QColorDialog>
#include <QSettings>
#include <QWidget>

#include "ui_options_window.h"

namespace Ui {
class options_window;
}

class options_window : public QWidget {
  Q_OBJECT

 public:
  void LoadSettings();
  QSettings *settings;
  explicit options_window(QWidget *parent = nullptr);
  QColorDialog *background_color;
  QColorDialog *vertex_color, *edge_color;
  float background_color_red_value, background_color_green_value,
      background_color_blue_value;
  float edges_color_red_value, edges_color_green_value, edges_color_blue_value;
  float vertex_color_red_value, vertex_color_green_value,
      vertex_color_blue_value;

  double vertex_size, edge_size;
  int line_type, vertex_type, projection_type;

  ~options_window();

 private slots:
  void on_pushButton_apply_settings_clicked();

  void on_pushButton_edge_color_clicked();

  void on_pushButton_vertex_color_clicked();

 private:
  void SaveSettings();
  void SetDefaultOptions();
  Ui::options_window *ui;
};

#endif  // OPTIONS_WINDOW_H
