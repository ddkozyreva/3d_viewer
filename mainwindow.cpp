#include "mainwindow.h"

#include <QtCore/qsettings.h>
#include <stdio.h>

#include "QtGifImage-master/src/3rdParty/giflib/gif_hash.h"
#include "QtGifImage-master/src/3rdParty/giflib/gif_lib.h"
#include "QtGifImage-master/src/3rdParty/giflib/gif_lib_private.h"
#include "QtGifImage-master/src/gifimage/qgifglobal.h"
#include "QtGifImage-master/src/gifimage/qgifimage.h"
#include "QtGifImage-master/src/gifimage/qgifimage_p.h"
#include "options_window.h"

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent) {
  ui.setupUi(this);
  ui.centralwidget->setFixedSize(1000, 1000);
  Settings();
  StatusBarSetup();
  SpinBoxValueSensor();
  // Нажатие на Open..
  connect(ui.actionimport, SIGNAL(triggered()), this,
          SLOT(OpenButtonPressed()));
  // Нажатие на кнопку настроек
  connect(ui.actionInterface_settings, SIGNAL(triggered()), this,
          SLOT(OptionsPressed()));
  connect(ui.pushButton_record, SIGNAL(pressed()), this,
          SLOT(RecordButtonPressed()));
  connect(ui.pushButton_screenshot, SIGNAL(pressed()), this,
          SLOT(ScreenshotButtonPressed()));
}
void MainWindow::Settings() {
  QString ini_file_name = QDir::homePath() + "/build/config.ini";
  QSettings *settings = new QSettings(ini_file_name, QSettings::IniFormat);
  settings_window.settings = settings;
  ui.centralwidget->settings = settings;
  settings_window.LoadSettings();
}
void MainWindow::OptionsPressed() { settings_window.show(); }

void MainWindow::ScreenshotButtonPressed() {
  QFileDialog dialogPhoto(this);
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("dd.MM.yy_HH.mm.ss_zzz");
  QString name_photo = dialogPhoto.getSaveFileName(
      this, "Save as...", "Screenshot_" + currentDateTime,
      "BMP (*.bmp);; JPEG (*.jpeg)");
  ui.centralwidget->grabFramebuffer().save(name_photo);
  ui.centralwidget->update();
}

void MainWindow::RecordButtonPressed() {
  if (!record_counter) {
    record_counter = 1;
    ui.pushButton_record->setStyleSheet("background-color: red");
    ui.pushButton_record->setText("recording");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(CreateGif()));
    timer->start(100);

  } else if (record_counter) {
    // record_counter = 0;
    ui.pushButton_record->setStyleSheet("background-color: ");
    ui.pushButton_record->setText("Record");
  }
}
void MainWindow::CreateGif() {
  counter = 0;
  // gif_vector = new QVector<QImage>;
  while (counter < 15) {
    gif_vector.push_back(ui.centralwidget->grabFramebuffer());
    counter++;
    qDebug() << "counter: " << counter;
  }
  SaveGif();
  gif_vector.clear();
  timer->stop();
}

void MainWindow::SaveGif() {
  QFileDialog dialogPhoto(this);
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("dd.MM.yy_HH.mm.ss_zzz");
  QString filename =
      dialogPhoto.getSaveFileName(this, "Save as...", currentDateTime + ".gif");
  // QString filename = "111.gif";
  QGifImage gif_file(QSize(640, 480));
  gif_file.setDefaultDelay(100);
  for (auto img = gif_vector.begin(); img != gif_vector.end(); img++) {
    gif_file.addFrame(*img);
  }
  gif_file.save(filename);
}

void MainWindow::SpinBoxValueSensor() {
  // Следующий блок отслеживает изменение спин боксов при нажатии
  connect(ui.spin_box_position_x, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
  connect(ui.spin_box_position_y, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
  connect(ui.spin_box_position_z, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
  connect(ui.spin_box_rotate_x, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
  connect(ui.spin_box_rotate_y, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
  connect(ui.spin_box_rotate_z, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
  connect(ui.spin_box_scale, SIGNAL(valueChanged(double)), this,
          SLOT(SpinBoxValueChanged()));
}

void MainWindow::SpinBoxValueChanged() {
  if (ui.spin_box_scale->value() != 0)
    ui.centralwidget->InitializeModelParameters(
        ui.spin_box_position_x->value(), ui.spin_box_position_y->value(),
        ui.spin_box_position_z->value(), ui.spin_box_rotate_x->value(),
        ui.spin_box_rotate_y->value(), ui.spin_box_rotate_z->value(),
        ui.spin_box_scale->value());
  else
    ui.centralwidget->InitializeModelParameters(
        ui.spin_box_position_x->value(), ui.spin_box_position_y->value(),
        ui.spin_box_position_z->value(), ui.spin_box_rotate_x->value(),
        ui.spin_box_rotate_y->value(), ui.spin_box_rotate_z->value(), 0.00001);
}

void MainWindow::StatusBarSetup() {
  // Следующий блок задает рамки спинбоксов
  ui.spin_box_position_x->setMinimum(-DBL_MAX);
  ui.spin_box_position_x->setMaximum(DBL_MAX);
  ui.spin_box_position_y->setMinimum(-DBL_MAX);
  ui.spin_box_position_y->setMaximum(DBL_MAX);
  ui.spin_box_position_z->setMinimum(-DBL_MAX);
  ui.spin_box_position_z->setMaximum(DBL_MAX);
  ui.spin_box_rotate_x->setMinimum(-DBL_MAX);
  ui.spin_box_rotate_x->setMaximum(DBL_MAX);
  ui.spin_box_rotate_y->setMinimum(-DBL_MAX);
  ui.spin_box_rotate_y->setMaximum(DBL_MAX);
  ui.spin_box_rotate_z->setMinimum(-DBL_MAX);
  ui.spin_box_rotate_z->setMaximum(DBL_MAX);
  ui.spin_box_scale->setValue(1);
  ui.spin_box_scale->setMinimum(0.00001);
  ui.spin_box_scale->setMaximum(DBL_MAX);
}

void MainWindow::OpenButtonPressed() {
  QString file_name = QFileDialog::getOpenFileName(
      this, "Open a file", QDir::homePath(), "OBJ Files (*.obj)");
  ui.statusbar->showMessage(file_name);
  ui.label_statusbar_vertecies_count->setText("vertecies count");
  ui.label_statusbar_edges_count->setText("edges count");
  ui.statusbar->addPermanentWidget(ui.label_statusbar_vertecies_count);
  ui.statusbar->addPermanentWidget(ui.label_statusbar_edges_count);
  QByteArray model_path_conversion = file_name.toLocal8Bit().data();
  char *model_path = model_path_conversion.data();
  strcpy(ui.centralwidget->file_path, model_path);

  int parser_return_value = parser_obj(model_path, &(ui.centralwidget->src));
  ui.centralwidget->InitializeModelParameters(0, 0, 0, 0, 0, 0, 1);
  if (parser_return_value) {
    QMessageBox::warning(this, "title", "File is corrupted!\n");
  }
  // ui.centralwidget->IsParserFailed(parser_return_value);
  unsigned vertecies_count = 0;
  unsigned edges_count = 0;
  vertecies_count = ui.centralwidget->src.count_vertex / 3;
  edges_count = ui.centralwidget->src.count_edges;
  QString vertecies_count_text =
      "Vertecies:" + QString::number(vertecies_count);
  QString edges_count_text = "Edges:" + QString::number(edges_count);
  ui.label_statusbar_vertecies_count->setText(vertecies_count_text);
  ui.label_statusbar_edges_count->setText(edges_count_text);
  ui.statusbar->addPermanentWidget(ui.label_statusbar_vertecies_count);
  ui.statusbar->addPermanentWidget(ui.label_statusbar_edges_count);
}
