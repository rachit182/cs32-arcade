#include "Text.h"

void drawCharacter(char ch, float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Draw a rectangle as a placeholder for the character
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(20, 0);
    glVertex2f(20, 40);
    glVertex2f(0, 40);
    glEnd();

    // Draw the character (just the character itself for simplicity)
    glColor3f(1.0, 1.0, 1.0);  // Set color to white
    glRasterPos2f(5, 15);     // Set the position for the character
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, ch);

    glPopMatrix();
}

void displayText() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw some text
    drawCharacter('H', 50, 50);
    drawCharacter('i', 80, 50);

    glutSwapBuffers();
}

//void init() {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0, 400, 0, 300);
//}

