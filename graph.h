#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;
const int N = 20;
struct Point {
    float x;
    float y;
//        ~Point(){
//            cout<<"2 ";
//        }
};
struct DrawObject{
    unsigned int type;
    vector<Point> point;
    float color[3]={0};
    bool colorFlag = false;
    ~DrawObject(){
        cout<<"1 ";
    }
};
vector<Point> drawCircle(float x, float y, float R, int n);
void coverPoint2Opgl(Point* p, int n, float x, float y);
#endif // GRAPH_H
