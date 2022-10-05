#include <iostream>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include "src/geometry/Cone.h"
#include "src/geometry/Axes.h"

int width = 800, height = 800;

float eyeX = 0.0f, eyeY = 5.0f, eyeZ = 5.0f;

// lighting stuff
GLfloat light_position[] = {20.0,1.0,1.0,0.0};
GLfloat light_color[] = {0.7, 0.1, 0.1, 0.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

Cone cone1 = Cone(0,0,0, 3);
Cone cone2 = Cone(-8,0,0, 1);

void init() {
    glClearColor(0,0,0,0);

    glLightfv(GL_LIGHT0, GL_DIFFUSE,light_color);
    glLightfv(GL_LIGHT0, GL_POSITION,light_position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glEnable(GL_DEPTH_TEST);

    glViewport(0,0,width,height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(100,width/(height*1.0),1,100);
    gluLookAt(eyeX,eyeY,eyeZ,0,0,0,0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    cone1.draw(nullptr);
    cone2.draw(nullptr);

    //drawing rectangle under cones
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glColor3ub(0,0,255);
    glVertex3i(3,3,0);
    glVertex3i(3,-3,0);
    glVertex3i(-3,-3,0);
    glVertex3i(-3,3,0);
    glEnd();



    glutSwapBuffers();
    glFlush();
}

void idle() {}

void reshape(int x, int y) {
    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
        case 87:
            eyeY += 5.0f;
            glutPostRedisplay();
            break;
        case 83:
            eyeY -= 5.0f;
            glutPostRedisplay();
            break;
        case 65:
            eyeX += 5.0f;
            glutPostRedisplay();
            break;
        case 68: eyeX -= 5.0f;
            glutPostRedisplay();
            break;
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


