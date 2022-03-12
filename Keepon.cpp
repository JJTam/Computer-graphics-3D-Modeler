#include <FL/gl.h>
#include "modelerglobals.h"
#include "Keepon.h"
#include "Keepon.h"

void drawTorso()
{
	drawSphere(2);
}

void drawHead()
{
	drawSphere(1.0);
}

void drawHat()
{
	glPushMatrix();
	drawCylinder(0.03, 1.5, 1.5);
	glTranslated(0.0, 0.03, 0.0);
	drawCylinder(1.0, 0.5, 0.5);
	glRotated(90, 1, 0, 0);
	glTranslated(0.0, 1.0, 0.0);
	drawTriangle(0.5, 0.0, 0.0, 0.0, 0.7, 0.0, -0.5, 0.0, 0.0);
	glRotated(90, 0, 1, 0);
	drawTriangle(0.5, 0.0, 0.0, 0.0, 0.7, 0.0, -0.5, 0.0, 0.0);
	glPopMatrix();

}

void drawUpperLeftArm()
{
	glPushMatrix();
	glTranslated(0, 0.25, -0.25);
	glScaled(-2.7, -0.5, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
}

void drawUpperRightArm()
{
	glPushMatrix();
	glTranslated(0, 0.25, -0.25);
	glScaled(2.7, -0.5, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
}

void drawLowerLeftArm()
{
	glPushMatrix();
	glScaled(1.5, 1, 1);
	drawSphere(0.3);
	glPopMatrix();
}

void drawLowerRightArm()
{
	glPushMatrix();
	glScaled(1.5, 1, 1);
	drawSphere(0.3);
	glPopMatrix();
}

void drawWeapon()
{
	glPushMatrix();
	glTranslated(-0.15, 0, -0.15);
	glScaled(0.3, 3, 0.3);
	// draw the lower part of the weapon
	drawBox(1, 1, 1);
	// go to the top of the lower part
	glTranslated(0, 1, 0);
	// scale back to normal
	glScaled(3.33, 0.33, 3.33);
	glTranslated(0.15, 0.3, 0.15);
	glScaled(1, 1.3, 1);
	drawSphere(0.3);
	glPopMatrix();
}

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
		drawTorso();

			// draw the left upper arm
			glPushMatrix();
			glTranslated(-1.8, 0.2, 0.0);
			drawUpperLeftArm();
			
				// draw the left lower arm
				glPushMatrix();
				glTranslated(-(2.7 + 0.3), 0, 0);
				drawLowerLeftArm();

					// draw the left weapon
					glPushMatrix();
					drawWeapon();
					glPopMatrix();

				glPopMatrix();
			glPopMatrix();

			// draw the right upper arm
			glPushMatrix();
			glTranslated(1.8, 0.2, 0.0);
			drawUpperRightArm();

				glPushMatrix();
				glTranslated(2.7 + 0.3, 0, 0);
				drawLowerRightArm();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix();
			glTranslated(0.0, 3.0, 0.0);
			// draw the upper sphere
			drawHead();

				glPushMatrix();
				glTranslated(0.0, 1.0, 0.0);
				glRotated(-90.0, 1.0, 0.0, 0.0);
				// draw the hat
				drawHat();
				glPopMatrix();

			glPopMatrix();
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