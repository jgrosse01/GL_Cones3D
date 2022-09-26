//
// Created by jgros on 8/31/2022.
//

#ifndef Color_h
#define Color_h


#include <random>

class Color {
private:
    static int black[4];
    int* rgba_arr{};

    void makeRandomColor(int alpha);

public:
    Color();
    Color(int* rgba, bool alpha);
    Color(int red, int green, int blue);
    Color(int red, int green, int blue, int alpha);

    void setColor(int* rgba);
    void setColor(int red, int green, int blue);
    void setColor(int red, int blue, int green, int alpha);
    void setRColor();
    void setRColor(int alpha);

    int getRed();
    int getGreen();
    int getBlue();
    int getAlpha();
    int* getColorA();
    int* getColor();

};


#endif //Color_h
