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
    //��������
    Point* yfPoint;
    //�����������(���������Ϳɻ�����������Сֵ)
    unsigned int yfNum = 0;
public:
    /**
     * @brief ��ȡָ��������������
     * @param  �������
     * @return ��������
     */
    DrawObject getYfLines(int n);
    /**
     * @brief �޸Ļ��ƿ��
     * @param _width ���
     * @param _height �߶�
     */
    void resize(int _width,int _height);
    /**
     * @brief ��ȡ���л�������
     * @return
     */
    vector<DrawObject>* getAllDrawObject();
private:
    QTime* time;
    /** �������л������� */
    vector<DrawObject> allDrawObject;
    /** ���� */
    vector<Note> notes;
    /** �߶� */
    int height = 800;
    /** ��� */
    int width = 800;
    /** �߼�� */
    const float linejl = 10;
    /** ÿ���߾��� */
    const float linezjl = 50;
    /** ���Ҽ�� */
    const float linex_jl = 20;
    /** ������� */
    const float liney_jl = 50;
    /** �������� */
    const float yf_jl = 50;
    /**
     * @brief ��ʼ�����л�������
     */
    void initAllDrawObject();
    /**
     * @brief ��ʼ����������
     */
    void initYfPoint();
    /**
     * @brief ��ȡ���Ƶ�����
     * @return
     */
    vector<DrawObject> getYfLines();
    /**
     * @brief ��ȡ��������
     * @return
     */
    DrawObject getFiveiLines();

    /**
     * @brief ��ʼ����
     */
    void start();
    /**
     * @brief ֹͣ
     */
    void stop();
    /**
     * @brief ��ͣ
     */
    void pause();
};

#endif // STAFFTA_H
