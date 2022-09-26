//
// Created by jgros on 9/25/2022.
//

#include <GL/freeglut.h>
#include "Axes.h"

void drawAxes(int dx, int dy, int dz) {
    glBegin(GL_LINE);
    glColor3ub(255,0,0);
    glVertex3i(dx, dy, dz);
    glVertex3i(5+dx, dy, dz);
    glColor3ub(0,255,0);
    glVertex3i(dx,dy,dz);
    glVertex3i(dx,5+dy,dz);
    glColor3ub(0,0,255);
    glVertex3i(dx,dy,dz);
    glVertex3i(dx,dy,5+dz);
    glEnd();
}