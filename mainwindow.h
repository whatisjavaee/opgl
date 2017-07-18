#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QOpenGLWindow>
#include<QOpenGLFunctions>
#include <iostream>
#include "staffta.h"
#include<QTimer>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QOpenGLWindow,protected QOpenGLFunctions
{
    Q_OBJECT

public:
    ~MainWindow();
    MainWindow();
    void initializeGL();
    void paintGL();
    void paintGL(vector<DrawObject> &drawObjects);
    void resizeGL(int w, int h);

private :
    GLuint vboId;
    int redYf = 0;
    Staffta* staffta;
    vector<DrawObject> reDrawObjects;
    int flag =0;
    long refreshTime = 0;
private slots:
    void rePaintYf();
};

#endif // MAINWINDOW_H
