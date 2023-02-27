#include "options_window.h"

#include <QtCore/qlogging.h>
#include <QtCore/qnamespace.h>
#include <QtGui/qcolor.h>
#include <QtWidgets/qcolordialog.h>

options_window::options_window(QWidget *parent)
    : QWidget(parent), ui(new Ui::options_window) {
  ui->setupUi(this);
  background_color = new QColorDialog;
  background_color->setWindowFlags(Qt::Widget);
  background_color->setOptions(QColorDialog::DontUseNativeDialog |
                               QColorDialog::NoButtons);
  ui->groupBox_background_settings->layout()->addWidget(background_color);
  connect(ui->pushButton_apply_settings, SIGNAL(clicked()), this,
          SLOT(on_pushButton_apply_settings_clicked()));
  connect(ui->pushButton_edge_color, SIGNAL(clicked()), this,
          SLOT(on_pushButton_edge_color_clicked()));
  connect(ui->pushButton_vertex_color, SIGNAL(clicked()), this,
          SLOT(on_pushButton_vertex_color_clicked()));
  LoadSettings();
}

options_window::~options_window() {
  delete background_color;
  delete ui;
}

void options_window::SetDefaultOptions() {}

void options_window::LoadSettings() {
  background_color_red_value =
      settings->value("background_color_red").toFloat();
  background_color_green_value =
      settings->value("background_color_green").toFloat();
  background_color_blue_value =
      settings->value("background_color_blue").toFloat();
  QColor background_color_from_settings;
  background_color_from_settings.setRedF(
      settings->value("background_color_red").toFloat());
  background_color_from_settings.setGreenF(
      settings->value("background_color_green").toFloat());
  background_color_from_settings.setBlueF(
      settings->value("background_color_blue").toFloat());
  background_color->setCurrentColor(background_color_from_settings);
  ui->doubleSpinBox_edge_size->setValue(
      settings->value("edges_size").toDouble());
  ui->doubleSpinBox_vertex_size->setValue(
      settings->value("vertex_size").toDouble());

  if (settings->value("line_type").toInt()) {
    ui->radioButton_solid->setChecked(true);
    ui->radioButton_dashed->setChecked(false);
  } else {
    ui->radioButton_solid->setChecked(false);
    ui->radioButton_dashed->setChecked(true);
  }

  if (!settings->value("vertex_type").toInt())
    ui->radioButton_none->setChecked(true);
  else if (settings->value("vertex_type").toInt() == 1)
    ui->radioButton_circle->setChecked(true);
  else if (settings->value("vertex_type").toInt() == 2)
    ui->radioButton_square->setChecked(true);

  if (settings->value("projection_type").toInt())
    ui->radioButton_central_projection->setChecked(true);
}
void options_window::SaveSettings() {
  // background color settings
  settings->setValue("background_color_red", background_color_red_value);
  settings->setValue("background_color_green", background_color_green_value);
  settings->setValue("background_color_blue", background_color_blue_value);

  // vertecies color settings
  settings->setValue("vertex_color_red", vertex_color_red_value);
  settings->setValue("vertex_color_green", vertex_color_green_value);
  settings->setValue("vertex_color_blue", vertex_color_blue_value);

  // edges color settings
  settings->setValue("edges_color_red", edges_color_red_value);
  settings->setValue("edges_color_green", edges_color_green_value);
  settings->setValue("edges_color_blue", edges_color_blue_value);

  // edges size settings
  settings->setValue("edges_size", ui->doubleSpinBox_edge_size->value());

  // Vertecies size settings
  settings->setValue("vertex_size", ui->doubleSpinBox_vertex_size->value());

  // Line Width settings
  settings->setValue("line_width", ui->doubleSpinBox_edge_size->value());

  // Line Type settings
  settings->setValue("line_type", line_type);

  // Vertex Type settings
  settings->setValue("vertex_type", vertex_type);

  // Projection Type settings
  settings->setValue("projection_type", projection_type);
}
void options_window::on_pushButton_apply_settings_clicked() {
  background_color->currentColor().getRgbF(&background_color_red_value,
                                           &background_color_green_value,
                                           &background_color_blue_value);

  // Get Line Type
  line_type = ui->radioButton_solid->isChecked() ? 1 : 0;

  // Get Vertex Type
  if (ui->radioButton_circle->isChecked())
    vertex_type = 1;
  else if (ui->radioButton_square->isChecked())
    vertex_type = 2;
  else
    vertex_type = 0;

  // Get Projectoin
  projection_type = ui->radioButton_central_projection->isChecked() ? 1 : 0;

  SaveSettings();
}

void options_window::on_pushButton_edge_color_clicked() {
  // QColor vertex_color_value =
  //     QColorDialog::getColor(Qt::white, this, tr("select color"));
  // vertex_color_value.getRgbF(&edges_color_red_value,
  // &edges_color_green_value,
  //                           &edges_color_blue_value);

  // QColorDialog vertex_color_red = new
  // edges_color->getColor().getRgbF(
  //     &edges_color_red_value, &edges_color_green_value,
  //     &edges_color_red_value);
  QColorDialog edges_color;
  if (edges_color.exec() == QColorDialog::Accepted) {
    edges_color.getColor().getRgbF(&edges_color_red_value,
                                   &edges_color_green_value,
                                   &edges_color_blue_value);
    // edges_color_red_value = 1;
    // edges_color_green_value = 0;
    qDebug() << "after OK\n";
    qDebug() << edges_color_red_value << edges_color_green_value
             << edges_color_blue_value << "\n";
    return;
  } else
    return;
}

void options_window::on_pushButton_vertex_color_clicked() {
  // vertex_color->getColor().getRgb(&vertex_color_red_value,
  //                                 &vertex_color_green_value,
  //                                 &vertex_color_blue_value);
}
