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
// Draw a cube
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
	bool deletable;
	float x, y, z;
	Coordinate(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
		deletable = false;
	}
	bool operator == (Coordinate other) {
		return other.x == x && other.y == y && other.z == z;
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
		// delete all cubes in deletableCubes
		int i = cubes.size() - 1;
		while (i >= 0 && cubes.size() >= 0) {
			Coordinate cube = cubes[i];
			if (cube.deletable) {
				cubes.erase(cubes.begin() + i);
			}
			// redisplay for the removed cube
			i--;
		}
		glutPostRedisplay();
	}
}
bool isDeletable(float x, float y, float z) {
	// find the block in a vector of cubes
	// tolerance var for checking block position
	float tol = .09;
	bool xGood = (x <= (selectorX + tol) && x >= (selectorX - tol)) || false;
	bool yGood = (y <= (selectorY + tol) && y >= (selectorY - tol)) || false;
	bool zGood = (z <= (selectorZ + tol) && z >= (selectorZ - tol)) || false;
	// If it's a good match, return true
	return xGood && yGood && zGood;
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
// make some cube colors
float colorSelectorR = 0.063;
float colorSelectorG = 0.886;
float colorSelectorB = 0.929;
float colorCubeDefaultR = 0.227;
float colorCubeDefaultG = 0.988;
float colorCubeDefaultB = 0.216;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0, 0, 1);
	cube(0, 0, 0, 1);
	if (cubes.size() == 0) {
		cube(selectorX, selectorY, selectorZ, .125, colorSelectorR, colorSelectorG, colorSelectorB);
	}
	for (int i = 0; i < cubes.size(); i++) {
		if (isDeletable(cubes[i].x, cubes[i].y, cubes[i].z)) {
			cubes[i].deletable = true;
			cube(cubes[i].x, cubes[i].y, cubes[i].z, 0.125, 0.99, 0, 0);
			// if we're on top of the cube, we won't be able to see the red one, so don't draw the selector
			if ((Coordinate(cubes[i].x, cubes[i].y, cubes[i].z) == Coordinate(selectorX, selectorY, selectorZ)) == false) {
				cube(selectorX, selectorY, selectorZ, .125, colorSelectorR, colorSelectorG, colorSelectorB);
			}
		}
		else {
			cubes[i].deletable = false;
			cube(cubes[i].x, cubes[i].y, cubes[i].z, 0.125, colorCubeDefaultR, colorCubeDefaultG, colorCubeDefaultB);
			cube(selectorX, selectorY, selectorZ, .125, colorSelectorR, colorSelectorG, colorSelectorB);
		}
	}
	glFlush();
}
int main(int argc, char *argv[])
	{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(600, 250);
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