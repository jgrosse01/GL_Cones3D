//
// Created by jgros on 8/31/2022.
//

#include "Color.h"
#include <random>

int rgba_arr[4];
static int black[4] = {0,0,0,0};

void Color::makeRandomColor(int alpha = 255) {
    std::random_device planter;
    std::ranlux24 gen(planter());
    std::uniform_int_distribution<int> dist(0,255);
    int* color = new int[4];
    for (int i = 0; i < 3; i++) {
        color[i] = dist(gen);
    }
    color[3] = alpha;
    rgba_arr = color;
    delete[] color;
}

Color::Color() {
    makeRandomColor();
}

Color::Color(int* rgba, bool alpha) {
    if (alpha) {
        Color::rgba_arr = rgba;
    } else {
        makeRandomColor(255);
    }
}

Color::Color(int red, int green, int blue) {
    int* color = new int[4];
    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = 255;
    Color::rgba_arr = color;
}

Color::Color(int red, int green, int blue, int alpha) {
    int* color = new int[4];
    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = alpha;
    Color::rgba_arr = color;
}

void Color::setColor(int* rgba) {
    Color::rgba_arr = rgba;
}

void Color::setColor(int red, int green, int blue) {
    int col[4] = {red, green, blue, 255};
    Color::setColor(col);
}

void Color::setColor(int red, int green, int blue, int alpha) {
    int col[4] = {red, green, blue, alpha};
    Color::setColor(col);
}

void Color::setRColor() {
    makeRandomColor();
}

void Color::setRColor(int alpha) {
    makeRandomColor(alpha);
}

int Color::getRed() {
    return Color::rgba_arr[0];
}

int Color::getGreen() {
    return Color::rgba_arr[1];
}

int Color::getBlue() {
    return Color::rgba_arr[2];
}

int Color::getAlpha() {
    return Color::rgba_arr[3];
}

int* Color::getColor() {
    int* rgb = new int[3];
    for (int i = 0; i < 3; i++) {
        rgb[i] = Color::rgba_arr[i];
    }
    return rgb;
}

int* Color::getColorA() {
    return Color::rgba_arr;
}



