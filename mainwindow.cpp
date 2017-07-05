#include "mainwindow.h"
const float PI = 3.1415926535898;
MainWindow::~MainWindow()
{

}

void MainWindow::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glGenBuffers(1,&vboId);
    glColor4f(0.0,0.0,0.0,0.0);
    glLineWidth(1);
    glTranslatef(-1,1,0.0);
}
/**
 * @brief MainWindow::paintGL
 * @param vertices
 */
void MainWindow::paintGL(vector<DrawObject> vertices){
    long start = clock();
    int sum = 0 ;
    int n= vertices.size();
    for(int i=0;i<n;i++){
        sum += vertices[i].n;
    }
    Point point[sum];
    int index = 0;
    for(int i=0;i<n;i++){
        memcpy(&point[index],vertices[i].point,vertices[i].n*sizeof(Point));
        index+=vertices[i].n;
        delete[] vertices[i].point;
    }
    coverPoint2Opgl(point,sum,2.0/this->width(),2.0/this->height());
    glClear(GL_COLOR_BUFFER_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER,sum*sizeof(Point),point,GL_STATIC_DRAW);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, 0);
    index = 0;
    for(int i=0;i<n;i++){
        glDrawArrays(vertices[i].type, index, vertices[i].n);
        index+= vertices[i].n;
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    std::cout<<clock() - start<<std::endl;
}

void MainWindow::paintGL()
{
    int t[1000][2] ={0};
    for(int i=0;i<1000;i++){
        t[i][0] = (rand())/(RAND_MAX+0.0)*10-5;
    }
    Staffta a(t,1000);
    a.height = this->height();
    a.width = this->width();
    vector<DrawObject>  vertices = a.getYfLines();
    vertices.push_back(a.getFiveiLines());
    this->paintGL(vertices);
}
