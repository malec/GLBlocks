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
#define SIZE 32
float Px[SIZE + 1][SIZE + 1];
float Py[SIZE + 1][SIZE + 1];
float Pz[SIZE + 1][SIZE + 1];
int angle = 0;

//---------------------------------------
// Define donut surface
//---------------------------------------
void define_donut()
{
	// Create X-Y profile
	for (int i = 0; i <= SIZE; i++)
	{
		float theta = i * 2 * 3.14 / SIZE;
		Px[i][0] = 0.2 * cos(theta) + 0.5;
		Py[i][0] = 0.2 * sin(theta);
		Pz[i][0] = 0.0;
	}

	// Perform rotation around Y axis
	for (int j = 1; j <= SIZE; j++)
	{
		float theta = j * 2 * 3.14 / SIZE;
		float cos_theta = cos(theta);
		float sin_theta = sin(theta);
		for (int i = 0; i <= SIZE; i++)
		{
			Px[i][j] = Px[i][0] * cos_theta - Pz[i][0] * sin_theta;
			Py[i][j] = Py[i][0];
			Pz[i][j] = Px[i][0] * sin_theta + Pz[i][0] * cos_theta;
		}
	}
}

//---------------------------------------
// Define vase surface
//---------------------------------------
void define_vase()
{
	// Create X-Y profile
	for (int i = 0; i <= SIZE; i++)
	{
		float theta = i * 2 * 3.14 / SIZE;
		Px[i][0] = 0.2 * sin(theta) + 0.5;
		Py[i][0] = (float)i / (float)SIZE - 0.5;
		Pz[i][0] = 0.0;
	}

	// Perform rotation around Y axis
	for (int j = 1; j <= SIZE; j++)
	{
		float theta = j * 2 * 3.14 / SIZE;
		float cos_theta = cos(theta);
		float sin_theta = sin(theta);
		for (int i = 0; i <= SIZE; i++)
		{
			Px[i][j] = Px[i][0] * cos_theta - Pz[i][0] * sin_theta;
			Py[i][j] = Py[i][0];
			Pz[i][j] = Px[i][0] * sin_theta + Pz[i][0] * cos_theta;
		}
	}
}

//---------------------------------------
// Function to draw 3D cube
//---------------------------------------
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

bool flyMode = false;
float selectorX = 0;
float selectorY = 0;
float selectorZ = 0;
float flyX = 0;
float flyY = 0;
float flyZ = 0;
float speed = .02;
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
	if (tolower(key) == 'f') {
		flyMode = !flyMode;
		cout << "Fly mode " << (flyMode ? "on " : "off ") << endl;
	}
	if (tolower(key) == 'w') {
		// move forward
		if (flyMode) {
			flyZ = ((flyZ -= speed) < -1) ? -1 : flyZ - speed;
		}
		else {
			selectorZ = ((selectorZ -= speed) < -1) ? -1 : selectorZ - speed;
		}
		glutPostRedisplay();
	}
	else if (tolower(key) == 'a') {
		// move left
		if (flyMode) {
			flyX = ((flyX -= speed) < -1) ? -1 : flyX - speed;
		}
		else {
			selectorX = ((selectorX -= speed) < -1) ? -1 : selectorX - speed;
		}
		glutPostRedisplay();
	}
	else if (tolower(key) == 's') {
		// move back
		if (flyMode) {
			flyZ = ((flyZ += speed) > 1) ? 1 : flyZ + speed;
		}
		else {
			selectorZ = ((selectorZ += speed) > 1) ? 1 : selectorZ + speed;
		}
		glutPostRedisplay();
	}
	else if (tolower(key) == 'd') {
		if (flyMode) {
			flyX = ((flyX += speed) > 1) ? 1 : flyX + speed;
		}
		else {
			// move right
			selectorX = ((selectorX += speed) > 1) ? 1 : selectorX + speed;
		}
		glutPostRedisplay();
	}
	else if (key == 'r') {
		angle = (angle + 5) % 360;
		glutPostRedisplay();
	}
	else if (key == 'R') {
		angle = (angle - 5) % 360;
		glutPostRedisplay();
	}
	// reset view
	else if (tolower(key) == 27) { //escape key
		angle = 0;
		glutPostRedisplay();
	}
	else if (key == ' ') {
		cubes.push_back(Coordinate(selectorX, selectorY, selectorZ));
		glutPostRedisplay();
	}
	else if (key == 'u') {
		if (flyMode) {
			flyY = ((flyY += speed) > 1) ? 1 : flyY + speed;
		}
		else {
			selectorY = ((selectorY += speed) > 1) ? 1 : selectorY + speed;
		}
		glutPostRedisplay();
	}
	else if (key == 'U') {
		if (flyMode) {
			flyY = ((flyY -= speed) < -1) ? -1 : flyY - speed;
		}
		else {
			selectorY = ((selectorY -= speed) < -1) ? -1 : selectorY - speed;
		}
		glutPostRedisplay();
	}
}

void mouseFunction(int button, int state, int x, int y) {
	gluLookAt(-1, 1, -1, x, y, 0, 0, 1, 0);
}
//---------------------------------------
// Init function for OpenGL
//---------------------------------------
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

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
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

	cube(selectorX, selectorY, selectorZ, .125, colorSelectorR, colorSelectorG, colorSelectorB);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply new rotations (if required)
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

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
	cout << "Press \"f\" to toggle fly mode (lets you move around)" << endl;
	cout << "Press \"w\" to go forward." << endl;
	cout << "Press \"a\" to go left" << endl;
	cout << "Press \"s\" to go back" << endl;
	cout << "Press \"d\" to go right." << endl;
	cout << "Press \"u\" to go up." << endl;
	cout << "Press \"U\" to go down" << endl;
	cout << "Press space to place a block" << endl;
	cout << "Press \"esc\" key to return to the original view position" << endl;
	cout << "Press \"r\" to rotate" << endl;
	cout << "Press \"R\" to rotate back" << endl;
	glutMainLoop();
	return 0;
}
