#ifndef STAFFTA_H
#define STAFFTA_H

#include "graph.h"
#include <stdio.h>
#include <list>
class Staffta {
public:
	Staffta(int (*notes)[2], int _noteLenth);
	~Staffta();
	Staffta();
	int (*notes)[2] = NULL;
	int notesLenth;
	int height = 800;
	int width = 800;
	//线间距
	const float linejl = 10;
	//每组线距离
	float linezjl = 20;
	//左右间距
	float linex_jl = 20;
	//底部间距
	float liney_jl = 20;
	//音符距离
    float yf_jl = 30;
public:
	/**
	 *获取五线坐标
	 */
    DrawObject getFiveiLines();
    DrawObject* getYfLines(int &n);
	void getYfXY(int index, float &x, float &y);
};

#endif // STAFFTA_H
