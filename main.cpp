#include <QApplication>
#include <QCoreApplication>
#include <QGridLayout>

#include "mainwindow.h"
#include "viewport.h"

int main(int argc, char *argv[]) {
  printf("before app\n");
  QApplication app(argc, argv);
  printf("before mainwindow\n");
  MainWindow window;
  printf("after window\n");
  window.setFixedSize(1000, 1010);
  window.show();
  return app.exec();
}
