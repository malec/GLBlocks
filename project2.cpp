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

bool flyMode = false;
float x = 0;
float y = 0;
float z = 0;
float speed = .1;
void keyPressed(unsigned char key, int x, int y) {
	key = tolower(key);
	if (key == 'x') {
		cout << "Now we're " << (flyMode == true ? "" : "not ") << "in fly mode" << endl;
		flyMode = !flyMode;
	}
	else if (key == 'w') {
		// move forward
		z -= speed;
		cout << "w" << endl;
	}
	else if (key == 'a') {
		// move left
		y -= speed;
		cout << "a" << endl;
	}
	else if (key == 's') {
		// move back
		z += speed;
		cout << "s" << endl;
	}
	else if (key == 'd') {
		// move right
		y += speed;
		cout << "d" << endl;
	}
	else if (key == 'r') {
		angle = (angle + 5) % 360;
	}
	glutPostRedisplay();
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

	// Define surface
	// define_vase();
	// define_donut();
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
	// Incrementally rotate objects
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cube(0.0, 0.0, 0.0, 1);
	cube(x, y, z, .25);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

	//// Draw object surface
	glColor3f(1.0, 1.0, 1.0);
	//for (int i = 0; i <= SIZE; i++)
	//{
	//	glBegin(GL_LINE_STRIP);
	//	for (int j = 0; j <= SIZE; j++)
	//		glVertex3f(Px[i][j], Py[i][j], Pz[i][j]);
	//	glEnd();
	//}
	//for (int j = 0; j <= SIZE; j++)
	//{
	//	glBegin(GL_LINE_STRIP);
	//	for (int i = 0; i <= SIZE; i++)
	//		glVertex3f(Px[i][j], Py[i][j], Pz[i][j]);
	//	glEnd();
	//}
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
	glutMainLoop();
	return 0;
}
