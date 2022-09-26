#include <iostream>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include "src/geometry/Cone.h"
#include "src/geometry/Axes.h"

int width = 800, height = 800;

Cone cone1 = Cone(0,0,0, 3);
Cone cone2 = Cone(-8,0,0, 1);

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(100,16/9.0,1,100);
    gluLookAt(0,5,5,0,0,0,0,0,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,width,height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    cone1.draw();
    cone2.draw();


    glutSwapBuffers();
    glutPostRedisplay();
}

void idle() {}

void reshape(int x, int y) {
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90,16/9.0,1,100);
    gluLookAt(0,5,5,0,0,0,0,0,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Ted... Where is my cone?");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


