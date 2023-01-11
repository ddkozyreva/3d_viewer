#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QSlider>
//void paint_function() {
////    glBegin(GL_LINES);
////            glVertex3f(-0.5f, 0.0f, 0.0f);
////            glVertex3f(0.5f, 0.0f, 0.0f);
////            glEnd();

////        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
////        glClear(GL_COLOR_BUFFER_BIT);
////        glPushMatrix();
//        glBegin(GL_TRIANGLES);

//            glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0, 0);
//            glColor3f(1.0f, 1.0f, 0.0f); glVertex2f(1, 0);
//            glColor3f(1.0f, 0.0f, 1.0f); glVertex2f(1, 1);
//        glEnd();
////        glPopMatrix();
//    ////    SwapBuffers(hDC);
//}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    QGridLayout layout;
    QSlider rotation;
    layout.addWidget(&rotation, 0, 0, 1, -1);
    window.setLayout(&layout);

    window.show();
    return app.exec();
}
