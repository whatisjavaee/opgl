#ifndef STAFFTA_H
#define STAFFTA_H

#include "graph.h"
#include <stdio.h>
#include <vector>
using namespace std;
class Staffta {
public:
	Staffta(int (*notes)[2], int _noteLenth);
	~Staffta();
	Staffta();
	int (*notes)[2] = NULL;
	int notesLenth;
	int height = 800;
	int width = 800;
	//�߼��
	const float linejl = 10;
	//ÿ���߾���
	float linezjl = 20;
	//���Ҽ��
	float linex_jl = 20;
	//�ײ����
	float liney_jl = 20;
	//��������
    float yf_jl = 30;
public:
	/**
	 *��ȡ��������
	 */
    DrawObject getFiveiLines();
    vector<DrawObject> getYfLines();
	void getYfXY(int index, float &x, float &y);
};

#endif // STAFFTA_H
