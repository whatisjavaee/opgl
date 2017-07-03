#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};

#endif // MAINWINDOW_H
