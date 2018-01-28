#include <GL/glut.h>

char lastKeyPressed = 'a';

void init() {

    GLfloat mat_specular[] = {0.7, 0.7, 0.7, 1};
    GLfloat mat_shininess[] = {20};
    GLfloat light_position[] = {1, 1, 1, 0};
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void reshape (int w, int h) {

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
            1.5*(GLfloat)h/(GLfloat)w, -10, 10);
    else
        glOrtho(-1.5*(GLfloat)w/(GLfloat)h,
            1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void vertices() {
    /* Makes two colored triangles in the shape of an hourglass
    //
    // The first triangle is drawn in the clockwise direction
    // The second triangle is drawn in the counter-clockwise direction
    */

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glFlush();
}

void triangleStrip() {
    /* Makes strips of triangles connected together */

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glFlush();
}

void triangleFan() {
    /* Makes a fan of triangles with the first vertex fixed */

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glFlush();
}

void quads() {
    // Draws retangles stacked in a pyramid shape
    // Shown by pressing f or F key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glFlush();
}

void quadStrip() {
    // Draws strips of quadrilaterals connected together
    // Shown by pressing g or G key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glFlush();
}

void polygons() {
    // Makes a polygon shape (GL_POLYGON can make any n-sided poly)
    // Shown by pressing h or H key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    glFlush();
}

void points() {
    // Draws a line of points in a row
    // Shown by pressing z or Z key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(20);
    glEnable(GL_POINT_SMOOTH);

    glBegin(GL_POINTS);

    glColor3f(1, 1, 1);

    for(int i = 1; i <= 6; i++){

        glVertex2f(0.3*i - 1.1, 0);

    }

    glEnd();
    glFlush();
}

void lines() {
    // Shows a series of parallel lines
    // Shown by drawing x or X key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINES);

    for(int i = 1; i < 7; i++){

        glColor3f(1 - .15*i, 1 - .15*i, 1 - .15*i);
        glVertex2f(.3*i - 1.1, -.5);
        glVertex2f(.3*i - 1.1, .5);

    }


    glEnd();
    glFlush();
}

void lineStrip() {
    // Shows a series of parallel lines connected by diags
    // Shown by pressing c or C key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

    for(int i = 1; i < 7; i++){

        glColor3f(1 - .15*i, 1 - .15*i, 1 - .15*i);
        glVertex2f(.3*i - 1.1, -.5);
        glVertex2f(.3*i - 1.1, .5);

    }

    glEnd();
    glFlush();
}

void lineLoop() {
    // Shows a series of parallel connected lines, and loops around
    // Shown by pressing v or V key

    glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);

    for(int i = 1; i < 7; i++){

        glColor3f(1 - .15*i, 1 - .15*i, 1 - .15*i);
        glVertex2f(.3*i - 1.1, -.5);
        glVertex2f(.3*i - 1.1, .5);

    }

    glEnd();
    glFlush();
}

// 3D primitives:
// Source: https://www.opengl.org/resources/libraries/glut/spec3/node81.html
// glutSolidSphere, glutWireSphere
// glutSolidCube, glutWireCube
// glutSolidCone, glutWireCone
// glutSolidTorus, glutWireTorus
// glutSolidDodecahedron, glutWireDodecahedron
// glutSolidOctahedron, glutWireOctahedron
// glutSolidTetrahedron. glutWireTetrahedron
// glutSolidIcosahedron, glutWireIcosahedron
// glutSolidTeapot, glutWireTeapot

void sphereWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 0);

    glutWireSphere(1.0, 100, 100);
    glFlush();
}

void sphereSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 1);
    glutSolidSphere(1.0, 100, 100);
    glFlush();
}

void cubeWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);

    glutWireCube(1.0);

    glPopMatrix();
    glFlush();
}

void cubeSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);

    glutSolidCube(1.0);

    glPopMatrix();
    glFlush();
}

void coneWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);

    glutWireCone(0.3, 0.8, 10, 10);

    glPopMatrix();
    glFlush();
}

void coneSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);

    glutSolidCone(0.3, 0.8, 10, 10);

    glPopMatrix();
    glFlush();
}

void torusWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glutWireTorus(0.1, 0.5, 100, 100);
    glFlush();
}

void torusSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glutSolidTorus(0.1, 0.5, 100, 100);
    glFlush();
}

void dodecahedronWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutWireDodecahedron();
    glPopMatrix();
    glFlush();
}

void dodecahedronSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutSolidDodecahedron();
    glPopMatrix();
    glFlush();
}

void octahedronWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutWireOctahedron();
    glPopMatrix();
    glFlush();
}

void octahedronSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutSolidOctahedron();
    glPopMatrix();
    glFlush();
}

void tetrahedronWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutWireTetrahedron();
    glPopMatrix();
    glFlush();
}

void tetrahedronSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutSolidTetrahedron();
    glPopMatrix();
    glFlush();
}

void icosahedronWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutWireIcosahedron();
    glPopMatrix();
    glFlush();
}

void icosahedronSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(20.0, 0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 0.5);

    glutSolidIcosahedron();
    glPopMatrix();
    glFlush();
}

void teapotWire() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glutWireTeapot(0.8);
    glFlush();
}

void teapotSolid() {

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glutSolidTeapot(0.8);
    glFlush();
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
        case 'q':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            sphereWire();
            break;
        case 'Q':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            sphereSolid();
            break;
        case 'w':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            cubeWire();
            break;
        case 'W':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            cubeSolid();
            break;
        case 'e':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            coneWire();
            break;
        case 'E':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            coneSolid();
            break;
        case 'r':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            torusWire();
            break;
        case 'R':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            torusSolid();
            break;
        case 't':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            dodecahedronWire();
            break;
        case 'T':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            dodecahedronSolid();
            break;
        case 'y':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            octahedronWire();
            break;
        case 'Y':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            octahedronSolid();
            break;
        case 'u':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            tetrahedronWire();
            break;
        case 'U':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            tetrahedronSolid();
            break;
        case 'i':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            icosahedronWire();
            break;
        case 'I':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            icosahedronSolid();
            break;
        case 'o':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            teapotWire();
            break;
        case 'O':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            teapotSolid();
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Primitives -- 1D, 2D, 3D");
    init();

    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
}
