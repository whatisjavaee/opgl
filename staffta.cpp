#include "staffta.h"
#include "graph.h"
#include <Math.h>
#include <string.h>
#include <GL/gl.h>
Staffta::Staffta(Note* _notes, int _noteLenth,int _width,int _height) {
    this->notesLenth = _noteLenth;
    this->notes = new Note[_noteLenth];
    memcpy(notes, _notes, _noteLenth * sizeof(Note));
    yfPoint = new Point[_noteLenth];
    this->width=_width;
    this->height=_height;
    initYfPoint();
}
Staffta::~Staffta() {
    delete notes;
    delete yfPoint;
}
/**
 * @brief Staffta::getFiveiLines
 * @param n ��������
 * @return ����N�����������������СΪn*2
 */
DrawObject Staffta::getFiveiLines() {
    DrawObject t;
    int n = (int) ((height - liney_jl) / (linejl * 4 + linezjl));
    Point* vertices = new Point[n * 5 * 2];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 5; i++) {
            float lineY = linejl * i + (linejl * 4 + linezjl) * j + liney_jl;
            vertices[j * 10 + i * 2].x = linex_jl;
            vertices[j * 10 + i * 2].y = lineY;
            vertices[j * 10 + i * 2 + 1].x = this->width - linex_jl;
            vertices[j * 10 + i * 2 + 1].y = lineY;
        }
    }
    n = n * 5 * 2;
    t.n =n;
    t.point = vertices;
    t.type = GL_LINES;
    t.colorFlag = false;
    return t;
}
vector<DrawObject> Staffta::getYfLines() {
    vector<DrawObject> drawObject(yfNum+1);
    for (int i = 0; i < yfNum; i++) {
        DrawObject  objDrawObject;
        objDrawObject.n = N;
        objDrawObject.point=drawCircle(yfPoint[i].x, yfPoint[i].y, (linejl / 2), N);
        objDrawObject.type = GL_POLYGON;
        drawObject.push_back(objDrawObject);
    }
    if(drawObject.size() > 0){
        drawObject[0].colorFlag = true;
    }
    return drawObject;
}

DrawObject Staffta::getYfLines(int n) {
    DrawObject  objDrawObject;
    objDrawObject.n = N;
    objDrawObject.point=drawCircle(yfPoint[n].x, yfPoint[n].y, (linejl / 2), N);
    objDrawObject.type = GL_POLYGON;
    objDrawObject.colorFlag = true;
    objDrawObject.color[0] = 1;
    return objDrawObject;
}

void Staffta::initYfPoint(){
    //����������
    int wxlines = (int) ((height - liney_jl) / (linejl * 4 + linezjl));
    //ÿ����������
    int yflineNum = (int) (width - linex_jl*2)/ yf_jl;
    //��������
    yfNum = wxlines * yflineNum;
    //ȡ���
    if (notesLenth < yfNum) {
        yfNum = notesLenth;
    }
    for(int index=0;index<notesLenth;index++){
        int yf_y_line = index / yflineNum;
        int yf_x_line = index % yflineNum;
        // �������м�λ��
        yfPoint[index].x = yf_x_line * yf_jl + linex_jl + yf_jl / 2;
        //������һ����λ��
        yfPoint[index].y = yf_y_line * (linezjl + linejl * 4) + liney_jl - (notes[index].yinDiao-4)*linejl/2;
    }
}
vector<DrawObject> Staffta::getAllDrawObject(){
    vector<DrawObject> yf =  this->getYfLines();
    yf.push_back(this->getFiveiLines());
    return yf;
}
void Staffta::resize(int _width,int _height){
    if(this->width == _width &&this->height == _height){
        return;
    }
    this->width=_width;
    this->height=_height;
    this->initYfPoint();
}
