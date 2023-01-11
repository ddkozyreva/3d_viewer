#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QWindow>
#include <QMainWindow>
//#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>


class MainWindow : public QOpenGLWidget {//, public QOpenGLFunctions {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    void glView(QWidget* parent = nullptr);
public:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
//    void paint_function();
};

#endif // MAINWINDOW_H
