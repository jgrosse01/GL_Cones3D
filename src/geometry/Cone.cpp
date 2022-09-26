//
// Created by jgros on 9/25/2022.
//

#include "Cone.h"
#include <GL/freeglut.h>

Cone::Cone(int x, int y, int z, int radius, int height, Color* color) {
    this->xOff = x;
    this->yOff = y;
    this->zOff = z;
    this->baseRadius = radius;
    this->height = height;
    this->defaultColor = color;
    // cone has point on the x and y-axis with the point facing up in the z direction
    std::vector<float> temp{0,0,1};
    this->facing = temp;
}

void Cone::draw() {
    float x, y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,1,0);
    glVertex3f(xOff, yOff, zOff+height);

    for (int i = 0; i <= 40; i++) {
        x = cos(M_PI/20*i)*baseRadius + xOff;
        y = sin(M_PI/20*i)*baseRadius + yOff;

        glColor3f(this->defaultColor->getRed(), this->defaultColor->getGreen(), this->defaultColor->getBlue());
        glVertex3f(x,y,zOff);
    }
    glEnd();
}

void Cone::move(int dx, int dy, int dz) {

}

void Cone::resize(int dRad, int dHeight) {

}

void Cone::changeDefaultColor(Color* color) {

}

void Cone::rotate(float xRot, float yRot, float zRot) {

}