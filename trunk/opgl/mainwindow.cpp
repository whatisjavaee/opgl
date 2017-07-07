#include "mainwindow.h"
MainWindow::MainWindow()
{

}
MainWindow::~MainWindow()
{
    delete staffta;
}

void MainWindow::initializeGL()
{
    int const length = 1000;
    Note t[length];;
    for(int i=0;i<length;i++){
        t[i].yinDiao = (rand())/(RAND_MAX+0.0)*10-5;
    }
    staffta = new Staffta(t,length,width(),height());
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glGenBuffers(1,&vboId);
    glColor4f(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);
    glTranslatef(-1,1,0.0);
    glEnable(GL_POLYGON_SMOOTH);
    QTimer *timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(rePaintYf()) );
    timer->start(5); //
}
/**
 * @brief MainWindow::paintGL
 * @param vertices
 */
void MainWindow::paintGL(vector<DrawObject> vertices){
    int sum = 0 ;
    int n= vertices.size();
    if(n == 0){
        return;
    }
    for(int i=0;i<n;i++){
        sum += vertices[i].n;
    }
    Point point[sum];
    int index = 0;
    for(int i=0;i<n;i++){
        memcpy(&point[index],vertices[i].point,vertices[i].n*sizeof(Point));
        index+=vertices[i].n;
    }
    coverPoint2Opgl(point,sum,2.0/this->width(),2.0/this->height());
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER,sum*sizeof(Point),point,GL_STATIC_DRAW);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, 0);
    index = 0;
    for(int i=0;i<n;i++){
        if(vertices[i].colorFlag == true){
            glColor4f(vertices[i].color[0],vertices[i].color[1],vertices[i].color[2],0);
        }
        glDrawArrays(vertices[i].type, index, vertices[i].n);
        index+= vertices[i].n;
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void MainWindow::rePaintYf(){
    long time = clock();
    if(time - refreshTime <(1.0/60)){
        return;
    }
    refreshTime = time;
    DrawObject objDrawObject = staffta->getYfLines(redYf%staffta->yfNum);
    redYf++;
    reDrawObjects.push_back(objDrawObject);
    update();
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    vector<DrawObject>  vertices = staffta->getAllDrawObject();
    this->paintGL(vertices);
    if(reDrawObjects.size() > 0){
        this->paintGL(reDrawObjects);
        reDrawObjects.clear();
    }
}
void MainWindow::resizeGL(int w, int h)
{
    staffta->resize(w,h);
}
