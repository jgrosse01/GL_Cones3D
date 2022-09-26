#include <iostream>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include "src/geometry/Cone.h"
#include "src/geometry/Axes.h"

int width = 800, height = 800;

float eyeX = 0.0f, eyeY = 5.0f, eyeZ = 5.0f;

Cone cone1 = Cone(0,0,0, 3);
Cone cone2 = Cone(-8,0,0, 1);

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(100,width/(height*1.0),1,100);
    gluLookAt(eyeX,eyeY,eyeZ,0,0,0,0,0,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,width,height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cone1.draw(new Color(255,0,0));
    cone2.draw(new Color(0,255,0));

    //drawing rectangle under cones
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3i(3,3,0);
    glVertex3i(3,-3,0);
    glVertex3i(-3,-3,0);
    glVertex3i(-3,3,0);
    glEnd();



    glutSwapBuffers();
    glFlush();
    glutPostRedisplay();
}

void idle() {}

void reshape(int x, int y) {
    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(100,width/(height*1.0),1,100);
    gluLookAt(eyeX,eyeY,eyeZ,0,0,0,0,0,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,width,height);
}

void processKeys(int key, int x, int y) {
    switch (key) {
        case 27: exit(0);
        case 87: eyeY += 0.5f;
        case 83: eyeY -= 0.5f;
        case 65: eyeX += 0.5f;
        case 68: eyeX -= 0.5f;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Ted... WHY ARE MY CONES NOT COLORED?!?");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(reinterpret_cast<void (*)(unsigned char, int, int)>(processKeys));

    glutMainLoop();
    return 0;
}


