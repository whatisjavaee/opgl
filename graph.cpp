/*
 * graph.cpp
 *
 *  Created on: 2017Äê7ÔÂ1ÈÕ
 *      Author: tangxuegui
 */

#include "graph.h"

#include <math.h>
#include <iostream>

Point* drawCircle(float x, float y, float R, int n) {
    Point* lines = new Point[n];
	for (int i = 0; i < n; i++) {
        lines[i].x = (R * cos(2 * M_PI / n * i) + x);
		lines[i].y = R * sin(2 * M_PI / n * i) + y;
	}
	return lines;
}
void printPoint(Point* p, int n) {
	std::cout << "point:" << n << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "x:" << p[i].x << " y:" << p[i].y << std::endl;
	}
}
void coverPoint2Opgl(Point* p, int n, float x, float y) {
	for (int i = 0; i < n; i++) {
		p[i].x *= x;
		p[i].y *= -y;
	}
}
