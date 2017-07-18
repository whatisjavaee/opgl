#ifndef STAFFTA_H
#define STAFFTA_H

#include "graph.h"
#include <stdio.h>
#include<iostream>
#include <vector>
#include<time.h>
#include<QTime>
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
    //音符坐标
    Point* yfPoint;
    //最大音符数量(音符总数和可绘制音符的最小值)
    unsigned int yfNum = 0;
public:
    /**
     * @brief 获取指定音符绘制线条
     * @param  音符序号
     * @return 音符线条
     */
    DrawObject getYfLines(int n);
    /**
     * @brief 修改绘制宽高
     * @param _width 宽度
     * @param _height 高度
     */
    void resize(int _width,int _height);
    /**
     * @brief 获取所有绘制线条
     * @return
     */
    vector<DrawObject>* getAllDrawObject();
private:
    QTime* time;
    /** 缓冲所有绘制线条 */
    vector<DrawObject> allDrawObject;
    /** 音符 */
    vector<Note> notes;
    /** 高度 */
    int height = 800;
    /** 宽度 */
    int width = 800;
    /** 线间距 */
    const float linejl = 10;
    /** 每组线距离 */
    const float linezjl = 50;
    /** 左右间距 */
    const float linex_jl = 20;
    /** 顶部间距 */
    const float liney_jl = 50;
    /** 音符距离 */
    const float yf_jl = 50;
    /**
     * @brief 初始化所有绘制线条
     */
    void initAllDrawObject();
    /**
     * @brief 初始化音符坐标
     */
    void initYfPoint();
    /**
     * @brief 获取绘制的线条
     * @return
     */
    vector<DrawObject> getYfLines();
    /**
     * @brief 获取所有音符
     * @return
     */
    DrawObject getFiveiLines();

    /**
     * @brief 开始运行
     */
    void start();
    /**
     * @brief 停止
     */
    void stop();
    /**
     * @brief 暂停
     */
    void pause();
};

#endif // STAFFTA_H
