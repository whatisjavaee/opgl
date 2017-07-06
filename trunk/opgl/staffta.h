#ifndef STAFFTA_H
#define STAFFTA_H

#include "graph.h"
#include <stdio.h>
#include<iostream>
#include <vector>
#include<time.h>
using namespace std;
struct Note{
    int yinDiao = 0;
    Point point;
    float timeLenght = 0;
};
class Staffta {
public:
    Staffta(int (*_notes)[2], int _noteLenth,int _width,int _height);
	~Staffta();
	Staffta();
	int (*notes)[2] = NULL;
	int notesLenth;
	int height = 800;
	int width = 800;
	//�߼��
	const float linejl = 10;
	//ÿ���߾���
    float linezjl = 50;
	//���Ҽ��
	float linex_jl = 20;
    //�������
    float liney_jl = 50;
	//��������
    float yf_jl = 50;
    //��������
    Point* yfPoint;
    //�����������(���������Ϳɻ�����������Сֵ)
    int yfNum = 0;
public:
	/**
	 *��ȡ��������
	 */
    DrawObject getFiveiLines();
    vector<DrawObject> getYfLines();
    void initYfPoint();
    DrawObject getYfLines(int n);
    void resize(int _width,int _height);
    vector<DrawObject> getAllDrawObject();
};

#endif // STAFFTA_H
