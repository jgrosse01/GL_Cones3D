//
// Created by jgros on 9/25/2022.
//

#include "Cone.h"
#include <GL/freeglut.h>
#include <iostream>

Cone::Cone(int x, int y, int z, int radius, int height, Color* color, GLfloat* spec, GLfloat* shin) {
    this->xOff = x;
    this->yOff = y;
    this->zOff = z;
    this->baseRadius = radius;
    this->height = height;
    this->defaultColor = color;
    this->matSpecular = spec;
    this->matShininess = shin;
    // cone has point on the x and y-axis with the point facing up in the z direction
    std::vector<float> temp{0,0,1};
    this->facing = temp;
}

void Cone::draw(Color* color) {
    float x, y, r, b;
    // draw cones now
    glBegin(GL_TRIANGLE_FAN);
    // set material light properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, new float[4] {0.05f,0.05f,0.05f,1.0f});
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, new float[4] {0.7f, 0.7f, 0.7f, 1.0f});
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, this->matSpecular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, this->matShininess);

    glColor3ub(0,255,0);
    glVertex3f(xOff, yOff, zOff+height);

    for (int i = 0; i <= 40; i++) {
        x = cos(M_PI/20*i)*baseRadius + xOff;
        y = sin(M_PI/20*i)*baseRadius + yOff;
        r = 0.5*cos(M_PI/10*i)+0.5;
        b = 1-r;
        glNormal3fv(this->surfaceNormal());
        if (color == nullptr) {
            glColor3f(r, 0, b);
        } else {
            //glColor3ub(color->getRed(), color->getGreen(), color->getBlue());
            glColor3ub(255,0,0);
        }
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

GLfloat * Cone::surfaceNormal() {
    float c = 1.0/sqrt(this->baseRadius*this->baseRadius + this->height * this->height);
    return new GLfloat[3] {c * baseRadius, c * height, c * baseRadius};
}
