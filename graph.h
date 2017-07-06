#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
using namespace std;
const int N = 20;
struct Point {
	float x;
	float y;
};
struct DrawObject{
    unsigned int type;
    int n;
    Point* point;
    float color[3]={0};
    bool colorFlag = false;
};
Point* drawCircle(float x, float y, float R, int n);
void printPoint(Point* p, int n);
void coverPoint2Opgl(Point* p, int n, float x, float y);
#endif // GRAPH_H
