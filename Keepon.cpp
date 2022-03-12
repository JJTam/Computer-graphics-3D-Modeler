#include <FL/gl.h>
#include "modelerglobals.h"
#include "Keepon.h"
#include <math.h>


void Keepon::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();

	// Start animation
	if (ModelerApplication::Instance()->GetAnimating()) {
		startAnimation();
		i += 2;
	}
	else {
		endAnimation();
	}

	setDefaultLight();

	// draw the floor
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5, 0, -5);
	drawBox(10, 0.01f, 10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS) + animatedX, VAL(YPOS) + animatedY, VAL(ZPOS) + animatedZ);

		// draw the bottom sphere
		glPushMatrix();
		glTranslated(0.0, 2.0, 0.0);
		drawSphere(2);
		glPopMatrix();

		// draw a cylinder connecting bottom and upper sphere
		glPushMatrix();
		glRotated(-90, 1.0, 0.0, 0.0);
		//drawCylinder(4.0 + 4.0, 0.1, 0.1);
		glPopMatrix();

		// draw the upper sphere
		glPushMatrix();
		glTranslated(0.0, 5.0, 0.0);
		drawSphere(1.0);
		glPopMatrix();

		// draw the hat
		glPushMatrix();
		glTranslated(0.0, 6.0, 0.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		drawCylinder(0.03, 1.5, 1.5);
		glTranslated(0.0, 0.03, 0.0);
		drawCylinder(1.0, 0.5, 0.5);
		glPopMatrix();


	glPopMatrix();
}

ModelerView* createKeeponModel(int x, int y, int w, int h, char* label)
{
	return new Keepon(x, y, w, h, label);
}


void Keepon::startAnimation() {

	float theta = i * M_PI / 180;
	float radius = 2.5;
	animatedX = cos(theta) * 2;
	animatedZ = sin(theta) * radius;

}

// Reset all animated values
void Keepon::endAnimation() {
	animatedX = 0.0; 
	animatedY = 0.0; 
	animatedZ = 0.0; 
	animatedAngle = 0.0;
	i = 0;

}


void Keepon::setDefaultLight() {

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	
	GLfloat lightPosition[] = { VAL(XLIGHT), VAL(YLIGHT), VAL(ZLIGHT), 0 };
	GLfloat lightDiffuse[] = { VAL(INTENSITY), VAL(INTENSITY), VAL(INTENSITY), VAL(INTENSITY) };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);


	// Add Specular Reflection
	GLfloat white[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat cyan[] = { 0.f, .8f, .8f, 1.f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

}


int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS];
	controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
	controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
	controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
	controls[XLIGHT] = ModelerControl("Default Light X Position", -30, 30, 0.1f, 8);
	controls[YLIGHT] = ModelerControl("Default Light Y Position", -30, 30, 0.1f, 12);
	controls[ZLIGHT] = ModelerControl("Default Light Z Position", -30, 30, 0.1f, 9);
	controls[INTENSITY] = ModelerControl("Default Light Intensity", 0, 5, 0.1f, 1.3);

	ModelerApplication::Instance()->Init(&createKeeponModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}