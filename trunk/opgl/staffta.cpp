#include "staffta.h"
#include "graph.h"
#include <Math.h>
#include <string.h>
#include <GL/gl.h>
Staffta::Staffta(int (*_notes)[2], int _noteLenth) {
    this->notesLenth = _noteLenth;
    this->notes = new int[_noteLenth][2];
    memcpy(notes, _notes, _noteLenth * 2 * sizeof(int));
}
Staffta::~Staffta() {
    delete notes;
}
/**
 * @brief Staffta::getFiveiLines
 * @param n 坐标数量
 * @return 返回N个坐标数量，数组大小为n*2
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
    return t;
}
vector<DrawObject> Staffta::getYfLines() {
    //五线谱行数
    int wxlines = (int) ((height - liney_jl) / (linejl * 4 + linezjl));
    //每行音符数量
    int yflineNum = (int) (width - linex_jl*2)/ yf_jl;
    //音符总数
    int yfNum = wxlines * yflineNum;
    //取最大
    if (notesLenth < yfNum) {
        yfNum = notesLenth;
    }
    vector<DrawObject> drawObject(yfNum+1);
    for (int i = 0; i < yfNum; i++) {
        float x, y = 0;
        getYfXY(i, x, y);
        DrawObject  objDrawObject;
        objDrawObject.n = 20;
        objDrawObject.point=drawCircle(x, y, (linejl / 2), 20);
        objDrawObject.type = GL_POLYGON;
        drawObject.push_back(objDrawObject);
    }
    return drawObject;
}
/**
 * @brief Staffta::getYfXY
 * @param index
 * @param x 音符正中旬位置
 * @param y 音符第一根线位置
 */
void Staffta::getYfXY(int index, float &x, float &y) {
    //每行音符数量
    int yflineNum = (int) (width - linex_jl*2)/ yf_jl;
    int yf_y_line = index / yflineNum;
    int yf_x_line = index % yflineNum;
    // 音符正中间位置
    x = yf_x_line * yf_jl + linex_jl + yf_jl / 2;
    //音符第一根线位置
    y = yf_y_line * (linezjl + linejl * 4) + liney_jl - (notes[index][0]-4)*linejl/2;
}
