#include <FL/gl.h>
#include "modelerglobals.h"
#include "Keepon.h"
#include "Keepon.h"

void Keepon::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();

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
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));

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

	ModelerApplication::Instance()->Init(&createKeeponModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}