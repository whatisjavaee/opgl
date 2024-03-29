#include "staffta.h"
#include "graph.h"
#include <math.h>
#include <string.h>
#ifdef Q_OS_WIN32
#include <GL/gl.h>
#endif
#ifdef Q_OS_MAC
#include <gl.h>
#endif
#ifdef Q_OS_LINUX
#include <GL/gl.h>
#endif
Staffta::Staffta(Note* _notes, int _noteLenth,int _width,int _height) {
    notes.reserve(_noteLenth);
    notes.assign(_notes,&_notes[_noteLenth]);
    yfPoint = new Point[_noteLenth];
    this->width=_width;
    this->height=_height;
    initYfPoint();
    initAllDrawObject();
}

Staffta::~Staffta() {
    delete yfPoint;
}

DrawObject Staffta::getFiveiLines() {
    DrawObject t;
    int n = (int) ((height - liney_jl) / (linejl * 4 + linezjl));
    vector<Point> vertices(n * 5 * 2);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 5; i++) {
            float lineY = linejl * i + (linejl * 4 + linezjl) * j + liney_jl;
            vertices[j*10+i*2].x = linex_jl;
            vertices[j*10+i*2].y = lineY;
            vertices[j*10+i*2+1].x = this->width - linex_jl;
            vertices[j*10+i*2+1].y = lineY;
        }
    }
    t.point = vertices;
    t.type = GL_LINES;
    t.colorFlag = false;
    return t;
}

vector<DrawObject> Staffta::getYfLines() {
    vector<DrawObject> drawObject(yfNum+1);
    for (unsigned i = 0; i < yfNum; i++) {
        drawObject[i].point=drawCircle(yfPoint[i].x, yfPoint[i].y, (linejl / 2), N);
        drawObject[i].type = GL_POLYGON;
    }
    if(drawObject.size() > 0){
        drawObject[0].colorFlag = true;
    }
    return drawObject;
}

DrawObject Staffta::getYfLines(int n) {
    DrawObject  objDrawObject;
    objDrawObject.point=drawCircle(yfPoint[n].x, yfPoint[n].y, (linejl / 2), N);
    objDrawObject.type = GL_POLYGON;
    objDrawObject.colorFlag = true;
    objDrawObject.color[0] = 1;
    return objDrawObject;
}

void Staffta::initYfPoint(){
    //五线谱行数
    int wxlines = (int) ((height - liney_jl) / (linejl * 4 + linezjl));
    //每行音符数量
    int yflineNum = (int) (width - linex_jl*2)/ yf_jl;
    //音符总数
    yfNum = wxlines * yflineNum;
    //取最大
    if (notes.size() < yfNum) {
        yfNum = notes.size();
    }
    for(unsigned index=0;index<yfNum;index++){
        int yf_y_line = index / yflineNum;
        int yf_x_line = index % yflineNum;
        // 音符正中间位置
        yfPoint[index].x = yf_x_line * yf_jl + linex_jl + yf_jl / 2;
        //音符第一根线位置
        yfPoint[index].y = yf_y_line * (linezjl + linejl * 4) + liney_jl - (notes[index].yinDiao-4)*linejl/2;
    }
}

void Staffta::initAllDrawObject(){
    allDrawObject = getYfLines();
    allDrawObject.push_back(this->getFiveiLines());
}

void Staffta::resize(int _width,int _height){
    if(this->width == _width &&this->height == _height){
        return;
    }
    width=_width;
    height=_height;
    initYfPoint();
    initAllDrawObject();
}
