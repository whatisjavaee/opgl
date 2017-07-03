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


void MainWindow::paintGL()
{
    long start = clock();
    int t[300][2] ={0};
    for(int i=0;i<300;i++){
        t[i][0] = (rand())/(RAND_MAX+0.0)*10-7;
    }
    Staffta a(t,300);
    a.height = this->height();
    a.width = this->width();
    int n = 0;
    DrawObject*  s = a.getYfLines(n);
    DrawObject drawObject =  a.getFiveiLines();
    DrawObject vertices[n+1];
    memcpy(vertices,&drawObject,sizeof(DrawObject));
    memcpy(&vertices[1],s,n*sizeof(DrawObject));
    int sum = 0 ;
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
    coverPoint2Opgl(point,sum,2.0/a.width,2.0/a.height);
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
