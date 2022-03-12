#include <FL/gl.h>
#include "modelerglobals.h"
#include "Keepon.h"
#include <math.h>

void drawTorso()
{
	drawSphere(2);
}

void drawHead()
{
	glPushMatrix();
	// draw head
	drawSphere(1.0);
	
		int eye_angle = 20;
		glPushMatrix();
		glRotated(eye_angle, 0, 1, 0);
		glTranslated(0, 0, 1);
		if (VAL(LEVEL_OF_DETAILS) > 4)
		{
			// draw left eye
			drawSphere(0.1);
		}
		glPopMatrix();

		glPushMatrix();
		glRotated(-eye_angle, 0, 1, 0);
		glTranslated(0, 0, 1);
		if (VAL(LEVEL_OF_DETAILS) > 4)
		{
			// draw right eye
			drawSphere(0.1);
		}
		glPopMatrix();

	glPopMatrix();
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

void drawUpperRightArm()
{
	glPushMatrix();
	glTranslated(0, 0.25, -0.25);
	glScaled(-2.7, -0.5, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
}

void drawUpperLeftArm()
{
	glPushMatrix();
	glTranslated(0, 0.25, -0.25);
	glScaled(2.7, -0.5, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();
}

void drawLowerRightArm()
{
	glPushMatrix();
	glScaled(1.5, 1, 1);
	drawSphere(0.3);
	glPopMatrix();
}

void drawLowerLeftArm()
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
	if (VAL(LEVEL_OF_DETAILS) > 1)
	{
		// draw the lower part of the weapon
		drawBox(1, 1, 1);
	}
	// go to the top of the lower part
	glTranslated(0, 1, 0);
	// scale back to normal
	glScaled(3.33, 0.33, 3.33);
	glTranslated(0.15, 0.3, 0.15);
	glScaled(1, 1.3, 1);
	if (VAL(LEVEL_OF_DETAILS) > 2)
	{
		// draw the upper part of the weapon
		drawSphere(0.3);
	}
	glPopMatrix();
}

void drawHatWithTexture()
{
	int width, height, nrChannels;
	unsigned char* data = readBMP("wildf.bmp", width, height);

	unsigned int texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);

	drawHat();

	glDisable(GL_TEXTURE_2D);

}

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
		glRotated(VAL(TORSO_ROTATE_X), 1, 0, 0);
		glRotated(VAL(TORSO_ROTATE_Y), 0, 1, 0);
		glRotated(VAL(TORSO_ROTATE_Z), 0, 0, 1);
		glTranslated(0.0, 2.0, 0.0);
		drawTorso();

			// draw the right upper arm
			glPushMatrix();
			glTranslated(-1.8, 0.2, 0.0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_X), 1, 0, 0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_Y), 0, 1, 0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_Z), 0, 0, 1);
			drawUpperRightArm();
			
				// draw the right lower arm
				glPushMatrix();
				glTranslated(-2.7, 0, 0);
				glRotated(VAL(RIGHT_LOWER_ARM_ROTATE_X), 1, 0, 0);
				glRotated(VAL(RIGHT_LOWER_ARM_ROTATE_Y), 0, 1, 0);
				glRotated(VAL(RIGHT_LOWER_ARM_ROTATE_Z), 0, 0, 1);
				glTranslated(-0.3, 0, 0);
				drawLowerRightArm();

					// draw the right weapon
					glPushMatrix();
					drawWeapon();
					glPopMatrix();

				glPopMatrix();
			glPopMatrix();

			// draw the left upper arm
			glPushMatrix();
			glTranslated(1.8, 0.2, 0.0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_X), 1, 0, 0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_Y), 0, 1, 0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_Z), 0, 0, 1);
			drawUpperLeftArm();

				glPushMatrix();
				glTranslated(2.7, 0, 0);
				glRotated(VAL(LEFT_LOWER_ARM_ROTATE_X), 1, 0, 0);
				glRotated(VAL(LEFT_LOWER_ARM_ROTATE_Y), 0, 1, 0);
				glRotated(VAL(LEFT_LOWER_ARM_ROTATE_Z), 0, 0, 1);
				glTranslated(0.3, 0, 0);
				// draw the left lower arm
				drawLowerLeftArm();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix();
			glTranslated(0.0, 3.0 + VAL(HEADHEIGHT), 0.0);
			glRotated(VAL(HEAD_ROTATE_X), 1, 0, 0);
			glRotated(VAL(HEAD_ROTATE_Y), 0, 1, 0);
			glRotated(VAL(HEAD_ROTATE_Z), 0, 0, 1);
			// draw the head
			drawHead();

				glPushMatrix();
				glTranslated(0.0, 1.0, 0.0);
				glRotated(-90.0, 1.0, 0.0, 0.0);
				if (VAL(LEVEL_OF_DETAILS) > 3)
				{
					// draw the hat
					//drawHat();
					drawHatWithTexture();
				}
				glPopMatrix();

			glPopMatrix();
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
	controls[XPOS] = ModelerControl("Base X Position", -5, 5, 0.1f, 0);
	controls[YPOS] = ModelerControl("Base Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Base Z Position", -5, 5, 0.1f, 0);

	controls[TORSO_ROTATE_X] = ModelerControl("Base Rotate X", -45, 45, 1, 0);
	controls[TORSO_ROTATE_Y] = ModelerControl("Base Rotate Y", -180, 180, 1, 0);
	controls[TORSO_ROTATE_Z] = ModelerControl("Base Rotate Z", -45, 45, 1, 0);


	controls[HEAD_ROTATE_X] = ModelerControl("Head Rotate X", -90, 90, 1, 0);
	controls[HEAD_ROTATE_Y] = ModelerControl("Head Rotate Y", -180, 180, 1, 0);
	controls[HEAD_ROTATE_Z] = ModelerControl("Head Rotate Z", -90, 90, 1, 0);

	controls[LEFT_UPPER_ARM_ROTATE_X] = ModelerControl("Left Upper Arm X", -90, 90, 1, 0);
	controls[LEFT_UPPER_ARM_ROTATE_Y] = ModelerControl("Left Upper Arm Y", -90, 90, 1, 0);
	controls[LEFT_UPPER_ARM_ROTATE_Z] = ModelerControl("Left Upper Arm Z", -90, 90, 1, 0);

	controls[LEFT_LOWER_ARM_ROTATE_X] = ModelerControl("Left Lower Arm X", -90, 90, 1, 0);
	controls[LEFT_LOWER_ARM_ROTATE_Y] = ModelerControl("Left Lower Arm Y", -90, 90, 1, 0);
	controls[LEFT_LOWER_ARM_ROTATE_Z] = ModelerControl("Left Lower Arm Z", -90, 90, 1, 0);

	controls[RIGHT_UPPER_ARM_ROTATE_X] = ModelerControl("Right Upper Arm X", -90, 90, 1, 0);
	controls[RIGHT_UPPER_ARM_ROTATE_Y] = ModelerControl("Right Upper Arm Y", -90, 90, 1, 0);
	controls[RIGHT_UPPER_ARM_ROTATE_Z] = ModelerControl("Right Upper Arm Z", -90, 90, 1, 0);

	controls[RIGHT_LOWER_ARM_ROTATE_X] = ModelerControl("Right Lower Arm X", -90, 90, 1, 0);
	controls[RIGHT_LOWER_ARM_ROTATE_Y] = ModelerControl("Right Lower Arm X", -90, 90, 1, 0);
	controls[RIGHT_LOWER_ARM_ROTATE_Z] = ModelerControl("Right Lower Arm X", -90, 90, 1, 0);

	controls[HEADHEIGHT] = ModelerControl("Head Height", 0, 2.5, 0.1f, 0);

	controls[XLIGHT] = ModelerControl("Default Light X Position", -30, 30, 0.1f, 8);
	controls[YLIGHT] = ModelerControl("Default Light Y Position", -30, 30, 0.1f, 12);
	controls[ZLIGHT] = ModelerControl("Default Light Z Position", -30, 30, 0.1f, 9);
	controls[INTENSITY] = ModelerControl("Default Light Intensity", 0, 5, 0.1f, 1.3);

	controls[LEVEL_OF_DETAILS] = ModelerControl("Level of Details", 0, 5, 1, 5);

	ModelerApplication::Instance()->Init(&createKeeponModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}