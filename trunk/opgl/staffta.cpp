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
    return t;
}
DrawObject* Staffta::getYfLines(int &n) {
	//����������
	int wxlines = (int) ((height - liney_jl) / (linejl * 4 + linezjl));
	//ÿ����������
    int yflineNum = (int) (width - linex_jl*2)/ yf_jl;
	//��������
	int yfNum = wxlines * yflineNum;
	//ȡ���
	if (notesLenth < yfNum) {
		yfNum = notesLenth;
	}
    DrawObject* drawObject =new DrawObject[yfNum];
	for (int i = 0; i < yfNum; i++) {
		float x, y = 0;
		getYfXY(i, x, y);
        drawObject[i].n = 20;
        drawObject[i].point=drawCircle(x, y, (linejl / 2), 20);
        drawObject[i].type = GL_POLYGON;
	}
    n = yfNum;
    return drawObject;
}
/**
 * @brief Staffta::getYfXY
 * @param index
 * @param x ��������Ѯλ��
 * @param y ������һ����λ��
 */
void Staffta::getYfXY(int index, float &x, float &y) {
	//ÿ����������
    int yflineNum = (int) (width - linex_jl*2)/ yf_jl;
	int yf_y_line = index / yflineNum;
	int yf_x_line = index % yflineNum;
	// �������м�λ��
	x = yf_x_line * yf_jl + linex_jl + yf_jl / 2;
	//������һ����λ��
    y = yf_y_line * (linezjl + linejl * 4) + liney_jl - (notes[index][0]-4)*linejl/2;
}
