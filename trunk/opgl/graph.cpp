/*
 * graph.cpp
 *
 *  Created on: 2017Äê7ÔÂ1ÈÕ
 *      Author: tangxuegui
 */

#include "graph.h"

#include <math.h>
#include <iostream>
#include <vector>
vector<Point> drawCircle(float x, float y, float R, int n) {
    vector<Point> lines(n);
	for (int i = 0; i < n; i++) {
        lines[i].x = (R * cos(2 * M_PI / n * i) + x);
        lines[i].y = R * sin(2 * M_PI / n * i) + y;
    }
    return lines;
}

void coverPoint2Opgl(Point* p, int n, float x, float y) {
	for (int i = 0; i < n; i++) {
		p[i].x *= x;
		p[i].y *= -y;
	}
}
