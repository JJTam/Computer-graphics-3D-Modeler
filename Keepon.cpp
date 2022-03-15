#include <FL/gl.h>
#include "modelerglobals.h"
#include "Keepon.h"
#include <math.h>


void drawTorso()
{
	setDiffuseColor(VAL(INDIVIDUAL_LOOKING_TORSO_COLOR_RED) / 255, VAL(INDIVIDUAL_LOOKING_TORSO_COLOR_GREEN) /255, VAL(INDIVIDUAL_LOOKING_TORSO_COLOR_BLUE) / 255);
	drawSphere(2);
	setDiffuseColor(COLOR_GREEN);
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
			drawSphere(VAL(INDIVIDUAL_LOOKING_EYE_SIZE));
		}
		glPopMatrix();

		glPushMatrix();
		glRotated(-eye_angle, 0, 1, 0);
		glTranslated(0, 0, 1);
		if (VAL(LEVEL_OF_DETAILS) > 4)
		{
			// draw right eye
			drawSphere(VAL(INDIVIDUAL_LOOKING_EYE_SIZE));
		}
		glPopMatrix();

		glPushMatrix();
		// draw nose
		glTranslated(0, -0.3, 1);
		drawCylinder(VAL(INDIVIDUAL_LOOKING_NOSE_LENGTH), 0.1, 0.1);
		glPopMatrix();

		glPushMatrix();
		// draw neck
		glTranslated(0, -1, 0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(HEADHEIGHT), 0.1, 0.1);
		glPopMatrix();

	glPopMatrix();
}

// Build a complex shape as a set of polygonal faces, using the "triangle" primitive to render them.
void drawDiamond()
{
	// point A (1, 0, 0)
	// point B (0, 0, 1)
	// point C (-1, 0, 0)
	// point D (0, 0, -1)
	// point E (0, -1, 0)
	// point F (0, 1, 0)

	// triangle ABE
	setDiffuseColor(COLOR_RED);
	drawTriangle(1, 0, 0, 0, 0, 1, 0, -1, 0);
	// triangle BCE
	setDiffuseColor(COLOR_BLUE);
	drawTriangle(0, 0, 1, -1, 0, 0, 0, -1, 0);
	// triangle DCE
	setDiffuseColor(COLOR_RED);
	drawTriangle(0, 0, -1, -1, 0, 0, 0, -1, 0);
	// triangle ADE
	setDiffuseColor(COLOR_GREEN);
	drawTriangle(1, 0, 0, 0, 0, -1, 0, -1, 0);

	// triangle AFB
	setDiffuseColor(COLOR_GREEN);
	drawTriangle(1, 0, 0, 0, 1, 0, 0, 0, 1);
	// triangle BFC
	setDiffuseColor(COLOR_RED);
	drawTriangle(0, 0, 1, 0, 1, 0, -1, 0, 0);
	// triangle DFC
	setDiffuseColor(COLOR_BLUE);
	drawTriangle(0, 0, -1, 0, 1, 0, -1, 0, 0);
	//triangle DFA
	setDiffuseColor(COLOR_RED);
	drawTriangle(0, 0, -1, 0, 1, 0, 1, 0, 0);
	setDiffuseColor(COLOR_GREEN);
}

void drawHat()
{
	glPushMatrix();
	drawCylinder(0.03, 1.5, 1.5);
	glTranslated(0.0, 0.03, 0.0);
	drawCylinder(1.0, 0.5, 0.5);
	glRotated(90, 1, 0, 0);
	glTranslated(0.0, 2.0, 0.0);
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


void drawHammer()
{
	// const double palmThickness = 0.2;
	const double hammerThick = 0.2;
	const double hammerLength = 0.5;

	glPushMatrix();

		glTranslated(-1, 0, -0.5);
		drawBox(2, 1, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 1, 0);
		glPushMatrix();
		glTranslated(-VAL(HAMMER_WIDTH) - hammerThick / 2, 0, -0.5);
		drawBox(hammerThick, hammerLength, 1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(VAL(HAMMER_WIDTH), 0, -0.5);
		drawBox(hammerThick, hammerLength, 1);
		glPopMatrix();

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
	glTranslated(0.15, 0.0, 0.15);
	glScaled(1, 1.3, 1);
	if (VAL(LEVEL_OF_DETAILS) > 2)
	{
		// draw the upper part of the weapon
		if (VAL(INDIVIDUAL_LOOKING_CHOICE_OF_WEAPON) == 1)
		{
			drawHammer();
		}
		else if (VAL(INDIVIDUAL_LOOKING_CHOICE_OF_WEAPON) == 2)
		{
			drawSphere(0.3);
		}
		else
		{
			glTranslated(0.0, 0.76, 0.0);
			drawDiamond();
		}
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

void drawLeftLeg()
{
	drawBox(0.5, -1.7, 0.5);
}

void drawRightLeg()
{
	drawBox(0.5, -1.7, 0.5);
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
		circleIndex += 2;
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
	glTranslated(VAL(XPOS) + baseAnimatedX, VAL(YPOS) + baseAnimatedY, VAL(ZPOS) + baseAnimatedZ);

		// draw the bottom sphere
		glPushMatrix();
		glRotated(VAL(TORSO_ROTATE_X) + baseAnimatedRotateX, 1, 0, 0);
		glRotated(VAL(TORSO_ROTATE_Y) + baseAnimatedRotateY, 0, 1, 0);
		glRotated(VAL(TORSO_ROTATE_Z) + baseAnimatedRotateZ, 0, 0, 1);
		glTranslated(0.0, 2.0 + 1.5, 0.0);				// radius of torso + length of leg 
		drawTorso();

			// draw the left leg
			glPushMatrix();
			glTranslated(0.3, -1.8, -.3);
			glRotated(VAL(LEFT_LEG_ROTATE_X), 1, 0, 0);
			glRotated(VAL(LEFT_LEG_ROTATE_Y), 0, 1, 0);
			glRotated(VAL(LEFT_LEG_ROTATE_Z), 0, 0, 1);
			drawLeftLeg();
			glPopMatrix();

			// draw the right leg
			glPushMatrix();
			glTranslated(-(0.3 + 0.5), -1.8, -0.3);
			glRotated(VAL(RIGHT_LEG_ROTATE_X), 1, 0, 0);
			glRotated(VAL(RIGHT_LEG_ROTATE_Y), 0, 1, 0);
			glRotated(VAL(RIGHT_LEG_ROTATE_Z), 0, 0,1);
			drawRightLeg();
			glPopMatrix();

			// draw the right upper arm
			glPushMatrix();
			glTranslated(-1.8, 0.2, 0.0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_X) + RUArmAnimatedX, 1, 0, 0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_Y) + RUArmAnimatedY, 0, 1, 0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_Z) + RUArmAnimatedZ, 0, 0, 1);
			drawUpperRightArm();
			
				// draw the right lower arm
				glPushMatrix();
				glTranslated(-2.7, 0, 0);
				glRotated(VAL(RIGHT_LOWER_ARM_ROTATE_X) + RLArmAnimatedX, 1, 0, 0);
				glRotated(VAL(RIGHT_LOWER_ARM_ROTATE_Y) + RLArmAnimatedY, 0, 1, 0);
				glRotated(VAL(RIGHT_LOWER_ARM_ROTATE_Z) + RLArmAnimatedZ, 0, 0, 1);
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
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_X) + LUArmAnimatedX, 1, 0, 0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_Y) + LUArmAnimatedY, 0, 1, 0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_Z) + LUArmAnimatedZ, 0, 0, 1);
			drawUpperLeftArm();

				glPushMatrix();
				glTranslated(2.7, 0, 0);
				glRotated(VAL(LEFT_LOWER_ARM_ROTATE_X) + LLArmAnimatedX, 1, 0, 0);
				glRotated(VAL(LEFT_LOWER_ARM_ROTATE_Y) + LLArmAnimatedY, 0, 1, 0);
				glRotated(VAL(LEFT_LOWER_ARM_ROTATE_Z) + LLArmAnimatedZ, 0, 0, 1);
				glTranslated(0.3, 0, 0);
				// draw the left lower arm
				drawLowerLeftArm();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix();
			glTranslated(0.0, 3.0 + VAL(HEADHEIGHT), 0.0);
			glRotated(VAL(HEAD_ROTATE_X) + headAnimatedX, 1, 0, 0);
			glRotated(VAL(HEAD_ROTATE_Y) + headAnimatedY, 0, 1, 0);
			glRotated(VAL(HEAD_ROTATE_Z) + headAnimatedZ, 0, 0, 1);

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
				glRotated(90, 1.0, 0.0, 0.0);
				glRotated(diamondAnimated, 0.0, 1.0, 0.0);
				glTranslated(0.0, 2.0, 0.0);
				drawDiamond();
				glPopMatrix();

			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

ModelerView* createKeeponModel(int x, int y, int w, int h, char* label)
{
	return new Keepon(x, y, w, h, label);
}



void Keepon::calAnimatedValue(double& value, int min, int max, bool& toMax, bool& toMin) {
	
	if (toMax) {
		value += 0.5;
		if (value == max) {
			toMax = false;
			toMin = true;
		}
	}
	else if (toMin) {
		value -= 0.5;
		if (value == min) {
			toMax = true;
			toMin = false;
		}
	}

}


void Keepon::startAnimation() {

	// Base and whole body
	float theta = circleIndex * M_PI / 180;
	float radius = 2.5;
	baseAnimatedX = cos(theta) * 2;
	baseAnimatedZ = sin(theta) * radius;
	calAnimatedValue(baseAnimatedRotateX , -5, 5, baseToMax, baseToMin);
	baseAnimatedRotateY += 0.5;
	calAnimatedValue(baseAnimatedRotateZ , -5, 5, baseToMax, baseToMin);

	// Head
	diamondAnimated += 10;
	//calAnimatedValue(headAnimatedY, -50, 50, headToMax, headToMin);
	calAnimatedValue(headAnimatedZ, -7, 7, headToMax, headToMin);

	// Left Upper Arm
	LUArmAnimatedX = 15;
	LUArmAnimatedZ = 17;
	calAnimatedValue(LUArmAnimatedY, -90, 0, luHandToMax, luHandToMin);

	// Left Lower Arm
	LLArmAnimatedX = -90;
	calAnimatedValue(LLArmAnimatedZ, -90, 0, llHandToMax, llHandToMin);

	// Right Upper Arm
	RUArmAnimatedX = 90;
	RUArmAnimatedY = 14;
	calAnimatedValue(RUArmAnimatedZ, -90, 0, ruHandToMax, ruHandToMin);

	// Right Lower Arm
	RLArmAnimatedX += 10.5;
	//calAnimatedValue(RLArmAnimatedZ, 10, 90, ruHandToMax, ruHandToMin);


}

// Reset all animated values
void Keepon::endAnimation() {

	baseAnimatedX = 0.0;
	baseAnimatedY = 0.0;
	baseAnimatedZ = 0.0;
	baseAnimatedRotateX = 0.0;
	baseAnimatedRotateY = 0.0;
	baseAnimatedRotateZ = 0.0;
	circleIndex = 0;

	diamondAnimated = 0.0;
	headAnimatedX = 0.0;
	headAnimatedY = 0.0;
	headAnimatedZ = 0.0;

	LUArmAnimatedX = 0.0;
	LUArmAnimatedY = 0.0;
	LUArmAnimatedZ = 0.0;

	LLArmAnimatedX = 0.0;
	LLArmAnimatedY = 0.0;
	LLArmAnimatedZ = 0.0;

	RUArmAnimatedX = 0.0;
	RUArmAnimatedY = 0.0;
	RUArmAnimatedZ = 0.0;

	RLArmAnimatedX = 0.0;
	RLArmAnimatedY = 0.0;
	RLArmAnimatedZ = 0.0;

	baseToMax = true;
	baseToMin = false;

	headToMax = true;
	headToMin = false;

	luHandToMax = false;
	luHandToMin = true;

	llHandToMax = false;
	llHandToMin = true;

	ruHandToMax = false;
	ruHandToMin = true;

	rlHandToMax = false;
	rlHandToMin = true;

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

	controls[HAMMER_WIDTH] = ModelerControl("Hammer Width", 0, 2.5, 0.1f, 0);

	controls[RIGHT_UPPER_ARM_ROTATE_X] = ModelerControl("Right Upper Arm X", -90, 90, 1, 0);
	controls[RIGHT_UPPER_ARM_ROTATE_Y] = ModelerControl("Right Upper Arm Y", -90, 90, 1, 0);
	controls[RIGHT_UPPER_ARM_ROTATE_Z] = ModelerControl("Right Upper Arm Z", -90, 90, 1, 0);

	controls[RIGHT_LOWER_ARM_ROTATE_X] = ModelerControl("Right Lower Arm X", -90, 90, 1, 0);
	controls[RIGHT_LOWER_ARM_ROTATE_Y] = ModelerControl("Right Lower Arm Y", -90, 90, 1, 0);
	controls[RIGHT_LOWER_ARM_ROTATE_Z] = ModelerControl("Right Lower Arm Z", -90, 90, 1, 0);

	controls[LEFT_LEG_ROTATE_X] = ModelerControl("Left Leg X", -90, 90, 1, 0);
	controls[LEFT_LEG_ROTATE_Y] = ModelerControl("Left Leg Y", -90, 90, 1, 0);
	controls[LEFT_LEG_ROTATE_Z] = ModelerControl("Left Leg Z", -90, 90, 1, 0);

	controls[RIGHT_LEG_ROTATE_X] = ModelerControl("Right Leg X", -90, 90, 1, 0);
	controls[RIGHT_LEG_ROTATE_Y] = ModelerControl("Right Leg Y", -90, 90, 1, 0);
	controls[RIGHT_LEG_ROTATE_Z] = ModelerControl("Right Leg Z", -90, 90, 1, 0);

	controls[HEADHEIGHT] = ModelerControl("Head Height", 0, 2.5, 0.1f, 0);

	controls[XLIGHT] = ModelerControl("Default Light X Position", -30, 30, 0.1f, 8);
	controls[YLIGHT] = ModelerControl("Default Light Y Position", -30, 30, 0.1f, 12);
	controls[ZLIGHT] = ModelerControl("Default Light Z Position", -30, 30, 0.1f, 9);
	controls[INTENSITY] = ModelerControl("Default Light Intensity", 0, 5, 0.1f, 1.3);

	controls[INDIVIDUAL_LOOKING_NOSE_LENGTH] = ModelerControl("Individual Looking Nose Length", 0.1, 2, 0.1, 0.1);
	controls[INDIVIDUAL_LOOKING_CHOICE_OF_WEAPON] = ModelerControl("Individual Looking Choice of Weapon", 1, 3, 1, 1);
	controls[INDIVIDUAL_LOOKING_EYE_SIZE] = ModelerControl("Individual Looking Eye Size", 0.1, 0.3, 0.02, 0.1);
	controls[INDIVIDUAL_LOOKING_TORSO_COLOR_RED] = ModelerControl("Individual Looking Torso Color Red", 0, 255, 1, 0);
	controls[INDIVIDUAL_LOOKING_TORSO_COLOR_GREEN] = ModelerControl("Individual Looking Torso Color Green", 0, 255, 1, 255);
	controls[INDIVIDUAL_LOOKING_TORSO_COLOR_BLUE] = ModelerControl("Individual Looking Torso Color Blue", 0, 255, 1, 0);

	controls[LEVEL_OF_DETAILS] = ModelerControl("Level of Details", 0, 5, 1, 5);

	ModelerApplication::Instance()->Init(&createKeeponModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}