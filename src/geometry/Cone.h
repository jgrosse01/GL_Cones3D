//
// Created by jgros on 9/25/2022.
//

#ifndef CONE_H
#define CONE_H

#include "../Color/Color.h"
#include <GL/freeglut.h>

// the stock specular and shiny value that will be loaded
static GLfloat defaultSpecular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
static GLfloat defaultShiny[1] = {80.0f};

class Cone {
private:
    int xOff, yOff, zOff, baseRadius, height;
    float xrot, yrot, zrot, dxrot, dyrot, dzrot;
    std::vector<float> facing;
    // the color of the cone, used by default for the draw method
    Color* defaultColor;

    GLfloat* matSpecular;
    GLfloat* matShininess;
public:
    explicit Cone(int x = 0, int y = 0, int z = 0, int radius=2, int height = 4, Color* color = new Color(0,255,255), GLfloat* spec = defaultSpecular, GLfloat* shin = defaultShiny);
    void draw(Color* color);
    void move(int dx, int dy, int dz);
    void resize(int dRad, int dHeight);
    void changeDefaultColor(Color* color);
    void rotate(float xRot, float yRot, float zRot);
    void setRotation(float xRot, float yRot, float zRot);
    GLfloat * surfaceNormal();
};


#endif //CONE_H
