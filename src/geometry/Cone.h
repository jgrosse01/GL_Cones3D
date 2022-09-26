//
// Created by jgros on 9/25/2022.
//

#ifndef CONE_H
#define CONE_H

#include "../Color/Color.h"

class Cone {
private:
    int xOff, yOff, zOff, baseRadius, height;
    std::vector<float> facing;
    Color* defaultColor;

public:
    Cone(int x = 0, int y = 0, int z = 0, int radius=2, int height = 4, Color* color = new Color(0,255,255));
    void draw(Color* color);
    void move(int dx, int dy, int dz);
    void resize(int dRad, int dHeight);
    void changeDefaultColor(Color* color);
    void rotate(float xRot, float yRot, float zRot);
};


#endif //CONE_H
