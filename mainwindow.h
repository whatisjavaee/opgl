#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QOpenGLWindow>
#include<QOpenGLFunctions>
#include <iostream>
#include "staffta.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QOpenGLWindow,protected QOpenGLFunctions
{
    Q_OBJECT

public:
    ~MainWindow();
    void initializeGL();
    void paintGL();
    void paintGL(vector<DrawObject> drawObjects);
private :
    GLuint vboId;
};

#endif // MAINWINDOW_H
