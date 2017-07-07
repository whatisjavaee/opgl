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
    float timeLenght = 1;
};
class Staffta {
public:
    Staffta(Note* _notes, int _noteLenth,int _width,int _height);
	~Staffta();
	Staffta();
    vector<Note> notes;
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
    unsigned int yfNum = 0;
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
