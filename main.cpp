#include <QApplication>
#include <QCoreApplication>
#include <QGridLayout>

#include "mainwindow.h"
#include "viewport.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  // QCoreApplication::setOrganizationName("DreamTem");
  // QCoreApplication::setOrganizationDomain("21-school.ru");
  // QCoreApplication::setApplicationName("3D Viewer 1.0");
  MainWindow window;
  window.setFixedSize(1000, 1010);

  window.show();
  return app.exec();
}
