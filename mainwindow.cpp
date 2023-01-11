#include "mainwindow.h"
//#include "./ui_mainwindow.h"

//extern "C" {

//}

MainWindow::MainWindow(QWidget* parent) : QOpenGLWidget(parent) {
    setWindowTitle("3D_Viewer");
    setGeometry(400, 200, 800, 600);
}

void MainWindow::initializeGL() {
}
void MainWindow::paintGL() {
    glClearColor(0.3f, 0.0f, 0.4f, 0.3f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    glLineWidth(10);
    GLfloat vertices[] = {  -0.5f,  0.0f, 0.0f,
                            -0.25f,-0.4f, 0.0f,
                             0.0f,  0.0f, 0.0f,
                             0.3f,-0.4f, 0.0f
                           };
    GLfloat colors[] = {  1,0,0, 0,1,0, 0,0,1, 1,1,0 };
    GLuint index[] = {1, 2, 2, 3, 3, 1, 0, 1};

    glVertexPointer(3, GL_FLOAT, 0, &vertices);
    glColorPointer(3, GL_FLOAT, 0, &colors);  // 3 переменные описывают цевт
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
//        glDrawArrays(GL_POINTS, 0, 4);  // 0 - с какого элемента отсчет в массиве, 4 - сколько взять точек из массива glVertexPointer
    glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, &index);  // 6 - количество точек из массива индексов

    // if GL_LINES, то в массиве индексов идем "откуда-куда" с дубликатом точек
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

}

void MainWindow::resizeGL(int w, int h) {
    glViewport(0,0,w,h);

}

void MainWindow::glView(QWidget* parent) {

}
