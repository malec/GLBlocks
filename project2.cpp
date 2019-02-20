#ifdef MAC
#include <GLUT/glut.h>
#else
#ifdef _WIN32
#include "GL\glew.h"
#include "GL\freeglut.h"
#else
#include <GL/glut.h>
#endif
#endif
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int angle = 0;

//---------------------------------------
// Function to draw 3D cube
//---------------------------------------
void cube(float midx, float midy, float midz, float size)
{
	// Define 8 vertices
	float ax = midx - size / 2;
	float ay = midy - size / 2;
	float az = midz + size / 2;
	float bx = midx + size / 2;
	float by = midy - size / 2;
	float bz = midz + size / 2;
	float cx = midx + size / 2;
	float cy = midy + size / 2;
	float cz = midz + size / 2;
	float dx = midx - size / 2;
	float dy = midy + size / 2;
	float dz = midz + size / 2;
	float ex = midx - size / 2;
	float ey = midy - size / 2;
	float ez = midz - size / 2;
	float fx = midx + size / 2;
	float fy = midy - size / 2;
	float fz = midz - size / 2;
	float gx = midx + size / 2;
	float gy = midy + size / 2;
	float gz = midz - size / 2;
	float hx = midx - size / 2;
	float hy = midy + size / 2;
	float hz = midz - size / 2;

	// Draw 6 faces
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(ax, ay, az);
	glVertex3f(bx, by, bz);
	glVertex3f(cx, cy, cz);
	glVertex3f(dx, dy, dz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(ax, ay, az);
	glVertex3f(dx, dy, dz);
	glVertex3f(hx, hy, hz);
	glVertex3f(ex, ey, ez);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(ax, ay, az);
	glVertex3f(ex, ey, ez);
	glVertex3f(fx, fy, fz);
	glVertex3f(bx, by, bz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(gx, gy, gz);
	glVertex3f(fx, fy, fz);
	glVertex3f(ex, ey, ez);
	glVertex3f(hx, hy, hz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(gx, gy, gz);
	glVertex3f(cx, cy, cz);
	glVertex3f(bx, by, bz);
	glVertex3f(fx, fy, fz);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(gx, gy, gz);
	glVertex3f(hx, hy, hz);
	glVertex3f(dx, dy, dz);
	glVertex3f(cx, cy, cz);
	glEnd();
}

// Draw a cube with a color
void cube(float midx, float midy, float midz, float size, float r, float g, float b)
{
	// Define 8 vertices
	float ax = midx - size / 2;
	float ay = midy - size / 2;
	float az = midz + size / 2;
	float bx = midx + size / 2;
	float by = midy - size / 2;
	float bz = midz + size / 2;
	float cx = midx + size / 2;
	float cy = midy + size / 2;
	float cz = midz + size / 2;
	float dx = midx - size / 2;
	float dy = midy + size / 2;
	float dz = midz + size / 2;
	float ex = midx - size / 2;
	float ey = midy - size / 2;
	float ez = midz - size / 2;
	float fx = midx + size / 2;
	float fy = midy - size / 2;
	float fz = midz - size / 2;
	float gx = midx + size / 2;
	float gy = midy + size / 2;
	float gz = midz - size / 2;
	float hx = midx - size / 2;
	float hy = midy + size / 2;
	float hz = midz - size / 2;

	// Draw 6 faces
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex3f(ax, ay, az);
	glVertex3f(bx, by, bz);
	glVertex3f(cx, cy, cz);
	glVertex3f(dx, dy, dz);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r - .1, g - .1, b - .1);
	glVertex3f(ax, ay, az);
	glVertex3f(dx, dy, dz);
	glVertex3f(hx, hy, hz);
	glVertex3f(ex, ey, ez);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r - .04, g - .04, b - .04);
	glVertex3f(ax, ay, az);
	glVertex3f(ex, ey, ez);
	glVertex3f(fx, fy, fz);
	glVertex3f(bx, by, bz);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r + .04, g + .04, b + .04);
	glVertex3f(gx, gy, gz);
	glVertex3f(fx, fy, fz);
	glVertex3f(ex, ey, ez);
	glVertex3f(hx, hy, hz);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r - .12, g - .12, b - .12);

	glVertex3f(gx, gy, gz);
	glVertex3f(cx, cy, cz);
	glVertex3f(bx, by, bz);
	glVertex3f(fx, fy, fz);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r - .2, g - .2, b - .2);
	glVertex3f(gx, gy, gz);
	glVertex3f(hx, hy, hz);
	glVertex3f(dx, dy, dz);
	glVertex3f(cx, cy, cz);
	glEnd();
}

bool rotateMode = false;
float selectorX = 0;
float selectorY = 0;
float selectorZ = 0;
float speed = .02;
float yTol = .5;
float zTol = .8;
int angleX = 0;
int angleY = 0;
int angleZ = 0;

class Coordinate {
public:
	float x, y, z;
	Coordinate(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};
vector<Coordinate> cubes;
void keyPressed(unsigned char key, int _x, int _y) {
	if (tolower(key) == 'r') {
		rotateMode = true;
		cout << (rotateMode ? "Rotate mode " : "Fly Mode ") << "on!" << endl;
	}
	else if (tolower(key) == 'f') {
		rotateMode = false;
		cout << (rotateMode ? "Rotate mode " : "Fly Mode ") << "on!" << endl;
	}
	else if (key == 'z') {
		// move forward
		if (rotateMode) {
			angleZ = (angleZ - 5) % 360;
			// flyZ = ((flyZ -= speed) < (-1 - zTol)) ? -1 : flyZ - speed;
		}
		else {
			selectorZ = ((selectorZ -= speed) < -1) ? -1 : selectorZ - speed;
		}
		glutPostRedisplay();
	}
	else if (key == 'Z') { // move back
		if (rotateMode) {
			// flyZ = ((flyZ += speed) > 1) ? 1 : flyZ + speed;
			angleZ = (angleZ + 5) % 360;
		}
		else {
			selectorZ = ((selectorZ += speed) > 1) ? 1 : selectorZ + speed;
		}
		glutPostRedisplay();
	}
	else if (key == 'X') {
		// move left
		if (rotateMode) {
			angleX = (angleX - 5) % 360;
		}
		else {
			selectorX = ((selectorX -= speed) < -1) ? -1 : selectorX - speed;
		}
		glutPostRedisplay();
	}
	else if (key == 'x') {
		if (rotateMode) {
			angleX = (angleX + 5) % 360;
			// flyX = ((flyX += speed) > 1) ? 1 : flyX + speed;
		}
		else {
			// move right
			selectorX = ((selectorX += speed) > 1) ? 1 : selectorX + speed;
		}
		glutPostRedisplay();
	}
	// Add block
	else if (key == ' ') {
		cubes.push_back(Coordinate(selectorX, selectorY, selectorZ));
		glutPostRedisplay();
	}
	else if (key == 'y') {
		if (rotateMode) {
			// flyY = ((flyY += speed) > 1) ? 1 : flyY + speed;
			angleY = (angleY + 5) % 360;
		}
		else {
			selectorY = ((selectorY += speed) > 1) ? 1 : selectorY + speed;
		}
		glutPostRedisplay();
	}
	else if (key == 'Y') {
		if (rotateMode) {
			// flyY = ((flyY -= speed) < -1) ? -1 : flyY - speed;
			angleY = (angleY - 5) % 360;
		}
		else {
			selectorY = ((selectorY -= speed) < -1) ? -1 : selectorY - speed;
		}
		glutPostRedisplay();
	}
	// Delete key - Delete a block
	else if (key == 127) {
		// find the block in a vector of cubes
		// tolerance var for checking block position
		float tol = .05;
		bool found = false;
		int count = 0;
		while (!found && count < cubes.size()) {
			Coordinate temp = cubes[count];
			bool xGood = (temp.x < (selectorX + tol) && temp.x >(selectorX - tol)) || false;
			bool yGood = (temp.y < (selectorY + tol) && temp.y >(selectorY - tol)) || false;
			bool zGood = (temp.z < (selectorZ + tol) && temp.z >(selectorZ - tol)) || false;

			// If it's a good match, delete it
			if (xGood && yGood && zGood) {
				cubes.erase(cubes.begin() + count);
				found = true;
				// redisplay for the removed cube
				glutPostRedisplay();
			}
			count++;
		}
	}
}

void init()
{
	// Initialize OpenGL
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyPressed);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// make some cube colors
	float colorSelectorR = 0.063;
	float colorSelectorG = 0.886;
	float colorSelectorB = 0.929;
	float colorCubeDefaultR = 0.227;
	float colorCubeDefaultG = 0.988;
	float colorCubeDefaultB = 0.216;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0, 0, 1);

	cube(selectorX, selectorY, selectorZ, .125, colorSelectorR, colorSelectorG, colorSelectorB);
	cube(0, 0, 0, .999);
	for (int i = 0; i < cubes.size(); i++) {
		cube(cubes[i].x, cubes[i].y, cubes[i].z, 0.125, colorCubeDefaultR, colorCubeDefaultG, colorCubeDefaultB);
	}

	//// Draw object surface
	// glColor3f(1.0, 1.0, 1.0);
	glFlush();
}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("Blocks");
	glutDisplayFunc(display);
	init();
	cout << "Rotate mode: r" << endl;
	cout << "\tRotate mode rotates the player space. Commands: " << endl;
	cout << "\tRight:     x" << endl;
	cout << "\tLeft:      X" << endl;
	cout << "\tUp:        y" << endl;
	cout << "\tDown:      Y" << endl;
	cout << "\tForward:   z" << endl;
	cout << "\tBackwards: Z" << endl;
	cout << "Fly mode: f" << endl;
	cout << "\tFly mode moves blocks. Commands: " << endl;
	cout << "Other commands:" << endl;
	cout << "\tAdd block:  Space" << endl;
	cout << "\tresetview: esc" << endl;
	cout << "Have fun!" << endl;
	cout << "Written by Alexander (Alec) Ahlbrandt at the University of Arkansas" << endl;
	glutMainLoop();
	return 0;
}
