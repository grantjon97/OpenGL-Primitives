#include <GL/glut.h>

char lastKeyPressed = 'a';

void vertices() {
    /* Makes two colored triangles in the shape of an hourglass
    //
    // The first triangle is drawn in the clockwise direction
    // The second triangle is drawn in the counter-clockwise direction
    */

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    // Triangle made Clockwise
    glColor3f(1, 0, 0);
    glVertex2f(0.0, 0.0);
    glColor3f(0, 1, 0);
    glVertex2f(-0.7, 0.9);
    glColor3f(0, 0, 1);
    glVertex2f(0.7, 0.9);

    // Triangle made Counter-Clockwise
    glColor3f(0, 0, 1);
    glVertex2f(0.0, 0.0);
    glColor3f(0, 1, 0);
    glVertex2f(-0.7, -0.9);
    glColor3f(1, 0, 0);
    glVertex2f(0.7, -0.9);

    glEnd();
    glutSwapBuffers();
}

void triangleStrip() {
    /* Makes strips of triangles connected together */

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_STRIP);

    glColor3f(1, 0, 0);
    glVertex2f(0.0, -0.75);
    glColor3f(0, 1, 0);
    glVertex2f(-0.3, -0.45);
    glColor3f(0, 0, 1);
    glVertex2f(0.0, -0.45);
    glColor3f(1, 0, 0);
    glVertex2f(-0.15, -0.15);
    glColor3f(0, 1, 0);
    glVertex2f(0.15, 0.15);
    glColor3f(0, 0, 1);
    glVertex2f(-0.6, 0.75);

    glEnd();
    glutSwapBuffers();
}

void triangleFan() {
    /* Makes a fan of triangles with the first vertex fixed */

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);

    // Create some vertices for a fan of triangles here
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.0);
    glColor3f(1, 0, 0);
    glVertex2f(0.0, 1.0);
    glColor3f(1, 0.5, 0.1);
    glVertex2f(0.707, 0.707);
    glColor3f(1, 0.9, 0.1);
    glVertex2f(1.0, 0.0);
    glColor3f(0, 1, 0);
    glVertex2f(0.707, -0.707);
    glColor3f(0, 0, 1);
    glVertex2f(0.0, -1.0);
    glColor3f(.1, 0, 0.5);
    glVertex2f(-0.707, -0.707);
    glColor3f(.3, 0, .3);
    glVertex2f(-1.0, 0.0);
    glColor3f(.8, 0, .6);
    glVertex2f(-0.707, 0.707);
    glColor3f(1, 0, 0);
    glVertex2f(0.0, 1.0);

    glEnd();
    glutSwapBuffers();
}

void quads() {
    // Draws retangles stacked in a pyramid shape
    // Shown by pressing f or F key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex2f(-1, -1);
    glVertex2f(-1, -.75);
    glVertex2f(1, -.75);
    glVertex2f(1, -1);

    glColor3f(.85, 0, 0);
    glVertex2f(-.9, -.75);
    glVertex2f(-.9, -.5);
    glVertex2f(.9, -.5);
    glVertex2f(.9, -.75);

    glColor3f(.7, 0, 0);
    glVertex2f(-.75, -.5);
    glVertex2f(-.75, -.25);
    glVertex2f(.75, -.25);
    glVertex2f(.75, -.5);

    glColor3f(.55, 0, 0);
    glVertex2f(-.58, -.25);
    glVertex2f(-.58, 0);
    glVertex2f(.58, 0);
    glVertex2f(.58, -.25);

    glColor3f(.4, 0, 0);
    glVertex2f(-.4, 0);
    glVertex2f(-.4, .25);
    glVertex2f(.4, .25);
    glVertex2f(.4, 0);

    glColor3f(.25, 0, 0);
    glVertex2f(-.25, .25);
    glVertex2f(-.25, .5);
    glVertex2f(.25, .5);
    glVertex2f(.25, .25);

    glColor3f(.1, 0, 0);
    glVertex2f(-.1, .5);
    glVertex2f(-.1, .75);
    glVertex2f(.1, .75);
    glVertex2f(.1, .5);

    glEnd();
    glutSwapBuffers();
}

void quadStrip() {
    // Draws strips of quadrilaterals connected together
    // Shown by pressing g or G key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUAD_STRIP);

    glColor3f(1, 0, 0);
    glVertex2f(0, .5);
    glVertex2f(-.6, -.25);
    glVertex2f(-.4, -.4);
    glVertex2f(.1, .1);

    glColor3f(0, 1, 0);
    glVertex2f(.7, .7);
    glVertex2f(.8, .7);
    glVertex2f(.7, .8);
    glVertex2f(.8, .8);

    glColor3f(0, 0, 1);
    glVertex2f(.9, .5);
    glVertex2f(.3, 0);
    glVertex2f(.8, .2);
    glVertex2f(.7, -.1);

    glEnd();
    glutSwapBuffers();
}

void polygons() {
    // Makes a polygon shape (GL_POLYGON can make any n-sided poly)
    // Shown by pressing h or H key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);

    glColor3f(0, 0, 1);
    glVertex2f(.8, .7);
    glVertex2f(.9, .1);
    glColor3f(0, .2, .8);
    glVertex2f(.6, -.5);
    glVertex2f(0, -.9);
    glColor3f(0, .6, .6);
    glVertex2f(-.2, -.5);
    glVertex2f(-.6, -.7);
    glColor3f(0, 1, .4);
    glVertex2f(-.7, -.3);

    glEnd();
    glutSwapBuffers();
}

void points() {
    // Draws a line of points in a row
    // Shown by pressing z or Z key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(20);
    glEnable(GL_POINT_SMOOTH);

    glBegin(GL_POINTS);

    glColor3f(1, 1, 1);

    for(int i = 1; i <= 6; i++){

        glVertex2f(0.3*i - 1.1, 0);

    }

    glEnd();
    glutSwapBuffers();
}

void lines() {
    // Shows a series of parallel lines
    // Shown by drawing x or X key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    for(int i = 1; i < 7; i++){

        glColor3f(1 - .15*i, 1 - .15*i, 1 - .15*i);
        glVertex2f(.3*i - 1.1, -.5);
        glVertex2f(.3*i - 1.1, .5);

    }


    glEnd();
    glutSwapBuffers();
}

void lineStrip() {
    // Shows a series of parallel lines connected by diags
    // Shown by pressing c or C key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

    for(int i = 1; i < 7; i++){

        glColor3f(1 - .15*i, 1 - .15*i, 1 - .15*i);
        glVertex2f(.3*i - 1.1, -.5);
        glVertex2f(.3*i - 1.1, .5);

    }

    glEnd();
    glutSwapBuffers();
}

void lineLoop() {
    // Shows a series of parallel connected lines, and loops around
    // Shown by pressing v or V key

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);

    for(int i = 1; i < 7; i++){

        glColor3f(1 - .15*i, 1 - .15*i, 1 - .15*i);
        glVertex2f(.3*i - 1.1, -.5);
        glVertex2f(.3*i - 1.1, .5);

    }

    glEnd();
    glutSwapBuffers();
}

void display() {
    /* Function called to decide which shapes to display  */

    switch(lastKeyPressed) {

        case 'a':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            vertices();
            break;
        case 'A':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            vertices();
            break;
        case 's':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            triangleStrip();
            break;
        case 'S':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            triangleStrip();
            break;
        case 'd':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            triangleFan();
            break;
        case 'D':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            triangleFan();
            break;
        case 'f':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            quads();
            break;
        case 'F':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            quads();
            break;
        case 'g':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            quadStrip();
            break;
        case 'G':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            quadStrip();
            break;
        case 'h':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            polygons();
            break;
        case 'H':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            polygons();
            break;
        case 'z':
            points();
            break;
        case 'x':
            lines();
            break;
        case 'c':
            lineStrip();
            break;
        case 'v':
            lineLoop();
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    /* Function called when a key is pressed  */

    lastKeyPressed = key;

    // Normally we don't want to force the display to
    // be called, but OpenGL seems to think that it doesn't
    // need to update the display when a key is pressed.
    // Taking the call to display() out will result in a
    // static image.

    display();
}

void main(int argc, char** argv) {

    // Standard initialization of window properties
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Primitives -- Press asdfgh ASDFGH zxcv");

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
}
