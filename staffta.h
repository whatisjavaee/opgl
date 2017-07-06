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
	//线间距
	const float linejl = 10;
	//每组线距离
    float linezjl = 50;
	//左右间距
	float linex_jl = 20;
    //顶部间距
    float liney_jl = 50;
	//音符距离
    float yf_jl = 50;
    //音符坐标
    Point* yfPoint;
    //最大音符数量(音符总数和可绘制音符的最小值)
    int yfNum = 0;
public:
	/**
	 *获取五线坐标
	 */
    DrawObject getFiveiLines();
    vector<DrawObject> getYfLines();
    void initYfPoint();
    DrawObject getYfLines(int n);
    void resize(int _width,int _height);
    vector<DrawObject> getAllDrawObject();
};

#endif // STAFFTA_H
