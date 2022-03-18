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
			setDiffuseColor(COLOR_BLACK);
			drawSphere(VAL(INDIVIDUAL_LOOKING_EYE_SIZE));
		}
		glPopMatrix();


		if (VAL(LEVEL_OF_DETAILS) > 4) {
			glPushMatrix();
			glRotated(-eye_angle, 0, 1, 0);
			glTranslated(0, 0, 1);
			// draw right eye
			setDiffuseColor(COLOR_BLACK);
			drawSphere(VAL(INDIVIDUAL_LOOKING_EYE_SIZE));
			glPopMatrix();

			glPushMatrix();
			// draw nose
			glTranslated(0, -0.3, 1);
			setDiffuseColor(COLOR_YELLOW);
			drawCylinder(VAL(INDIVIDUAL_LOOKING_NOSE_LENGTH), 0.1, 0.1);
			glPopMatrix();

			glPushMatrix();
			// draw neck
			glTranslated(0, -1, 0);
			glRotated(90, 1.0, 0.0, 0.0);
			drawCylinder(VAL(HEADHEIGHT), 0.1, 0.1);
			glPopMatrix();
		}

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
	setDiffuseColor(COLOR_YELLOW);
	drawTriangle(0, 0, -1, -1, 0, 0, 0, -1, 0);
	// triangle ADE
	setDiffuseColor(COLOR_GREEN);
	drawTriangle(1, 0, 0, 0, 0, -1, 0, -1, 0);

	// triangle AFB
	setDiffuseColor(COLOR_GREEN);
	drawTriangle(1, 0, 0, 0, 1, 0, 0, 0, 1);
	// triangle BFC
	setDiffuseColor(COLOR_YELLOW);
	drawTriangle(0, 0, 1, 0, 1, 0, -1, 0, 0);
	// triangle DFC
	setDiffuseColor(COLOR_BLUE);
	drawTriangle(0, 0, -1, 0, 1, 0, -1, 0, 0);
	//triangle DFA
	setDiffuseColor(COLOR_RED);
	drawTriangle(0, 0, -1, 0, 1, 0, 1, 0, 0);
	setDiffuseColor(COLOR_GREEN);
}


// Build a complex shape as a set of polygonal faces, using the "triangle" primitive to render them.
void drawTriangularPyramid(double r) 
{
	double x1 = 0, y1 = 0, z1 = 0, x2 = r / 2, y2 = 0, z2 = r * sqrt(3) / 2,
		x3 = r, y3 = 0, z3 = 0, x4 = r / 2, y4 = r * sqrt(6) / 3, z4 = r * sqrt(3) / 6;

	drawTriangle(x1, y1, z1, x2, y2, z2, x3, y3, z3);
	drawTriangle(x1, y1, z1, x2, y2, z2, x4, y4, z4);
	drawTriangle(x1, y1, z1, x3, y3, z3, x4, y4, z4);
	drawTriangle(x2, y2, z2, x3, y3, z3, x4, y4, z4);
}


// Build a complex shape as a set of polygonal faces, using the "triangle" primitive to render them.
void drawRectangularPyramid(double r, double h) 
{
	drawTriangle(0, 0, 0, 0, 0, r, r, 0, r);
	drawTriangle(0, 0, 0, r, 0, r, r, 0, 0);
	drawTriangle(r / 2, h, r / 2, 0, 0, 0, 0, 0, r);
	drawTriangle(r / 2, h, r / 2, 0, 0, r, r, 0, r);
	drawTriangle(r / 2, h, r / 2, r, 0, r, r, 0, 0);
	drawTriangle(r / 2, h, r / 2, r, 0, 0, 0, 0, 0);
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


void drawWing(bool drawLeft) 
{
	double a = 5 + VAL(INDIVIDUAL_LOOKING_WINGS_SIZE), 
		   b = 0.75,
		   h = 1.75,
		   theta = 90;

	double sinTheta = sin(theta * M_PI / 180);
	double cosTheta = cos(theta * M_PI / 180);

	if (drawLeft) {
		// Big backlight
		drawTriangle(a, 0, 0, 0, h, 0, a, h * VAL(INDIVIDUAL_LOOKING_WINGS_SIZE), 0);
		// Big tolight
		drawTriangle(a, 0, 0, a, h * VAL(INDIVIDUAL_LOOKING_WINGS_SIZE), 0, b * cosTheta, h, b * sinTheta);
	}
	
	else {  // draw right
		// Big backlight
		a += 0.55;
		drawTriangle(a, h * VAL(INDIVIDUAL_LOOKING_WINGS_SIZE), 0, a, 0, 0, b * cosTheta, h, b * sinTheta);
		// Big tolight
		drawTriangle(0, h, 0, a, 0, 0, a, h * VAL(INDIVIDUAL_LOOKING_WINGS_SIZE), 0);
	}

	// Small backlight
	drawTriangle(0, h, 0, a, 0, 0, b * cosTheta, h, b * sinTheta);
	// Small tolight
	drawTriangle(0, h, 0, b * cosTheta, h, b * sinTheta, a, h * VAL(INDIVIDUAL_LOOKING_WINGS_SIZE), 0);


	/* Not use these
	*
	drawTriangle(0, 0, 0, 0, h, 0, a, 0, 0);
	drawTriangle(b * cosTheta, 0, b * sinTheta, a, 0, 0, b * cosTheta, h, b * sinTheta);

	drawTriangle(0, 0, 0, b * cosTheta, 0, b * sinTheta, 0, h, 0);
	drawTriangle(b * cosTheta, 0, b * sinTheta, b * cosTheta, h, b * sinTheta, 0, h, 0);
	*/

}


void drawHammer()
{
	// const double palmThickness = 0.2;
	const double hammerThick = 0.2;
	const double hammerLength = 0.5;

	setDiffuseColor(COLOR_BLUE);

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
	setDiffuseColor(COLOR_GREEN);
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
			glTranslated(-0.75, 0.0, -0.75);
			setDiffuseColor(COLOR_PURPLE);
			drawRectangularPyramid(1.5, 2.0);
			//drawSphere(0.85);
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

//reference:	https://en.wikipedia.org/wiki/Torus
//				http://glprogramming.com/red/chapter07.html

// draw a torus in the xz-plane
// x = ( R + r * cos(angle1) ) * cos(angle2)
// y = ( R + r * cos(angle1) ) * sin(angle2)
// z = r * sin(angle1)
// angle 1 and angle 2 are angles which make a full circle, so their values start and end at the same point,
// R is the distance from the center of the tube to the center of the torus,
// r is the radius of the tube.
void drawTorus(int numc, int numt, double R, double r)
{
	int i, j, k;
	double s, t, x, y, z, twopi;
	
	setDiffuseColor(COLOR_ROSE);

	for (i = 0; i < numc; i++) {
		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= numt; j++) {
			for (k = 1; k >= 0; k--) {
				s = (i + k) % numc + 0.5;
				t = j % numt;

				x = (R + r * cos(s * 2 * M_PI / numc)) * cos(t * 2 * M_PI / numt);
				y = (R + r * cos(s * 2 * M_PI / numc)) * sin(t * 2 * M_PI / numt);
				z = r * sin(s * 2 * M_PI / numc);
				glVertex3f(x, y, z);
			}
		}
		glEnd();
	}
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
		
		if (VAL(ANIMATION_HAPPY_MOOD) == 1) {
			circleSpeed += 3.0;
		}
		else if (VAL(ANIMATION_ANGRY_MOOD) == 1) {
			circleSpeed += 2.25;
		}
		else {
			circleSpeed += 1.25;
		}
	}
	else {
		endAnimation();
	}

	setDefaultLight();

	// draw the floor
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-8, 0, -8);
	drawBox(16, 0.1f, 16);
	glPopMatrix();


		if (VAL(L_SYSTEM_TREE_ON))
		{
			setDiffuseColor(COLOR_GREEN);
			LSystemTree tree(VAL(L_SYSTEM_TREE_LENGTH), VAL(L_SYSTEM_TREE_THICKNESS), VAL(L_SYSTEM_TREE_ANGLE), VAL(L_SYSTEM_TREE_LEVEL));
			glPushMatrix();
			glTranslated(VAL(XPOS) + baseAnimatedX, VAL(YPOS) + baseAnimatedY, VAL(ZPOS) + baseAnimatedZ);
			tree.draw();
			glPopMatrix();
		}
		else
		{
			// draw the original model

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

				if (VAL(INDIVIDUAL_LOOKING_WINGS) && VAL(LEVEL_OF_DETAILS) > 4) {
					// draw the left wing
					setDiffuseColor(COLOR_YELLOW);

					glPushMatrix();
					glTranslated(0.3, -1.0, -1.7);
					glRotated(70 - VAL(INDIVIDUAL_LOOKING_LEFT_WING_ROTATE) - LWingAnimated, 0, 1, 0);
					drawWing(true);
					glPopMatrix();

					// draw the right wing
					glPushMatrix();
					glTranslated(-1.23, -1.0, -1.23);
					glRotated(100 + VAL(INDIVIDUAL_LOOKING_RIGHT_WING_ROTATE) + RWingAnimated, 0, 1, 0);
					drawWing(false);
					glPopMatrix();
				}

				setDiffuseColor(COLOR_YELLOW);

				// draw the left leg
				glPushMatrix();
				glTranslated(0.3, -1.8, -0.3);
				glRotated(VAL(LEFT_LEG_ROTATE_X) + LLegAnimatedX, 1, 0, 0);
				glRotated(VAL(LEFT_LEG_ROTATE_Y), 0, 1, 0);
				glRotated(VAL(LEFT_LEG_ROTATE_Z), 0, 0, 1);
				drawLeftLeg();
				glPopMatrix();

				// draw the right leg
				glPushMatrix();
				glTranslated(-(0.3 + 0.5), -1.8, -0.3);
				glRotated(VAL(RIGHT_LEG_ROTATE_X) + RLegAnimatedX, 1, 0, 0);
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

					setDiffuseColor(COLOR_YELLOW);
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

						if (VAL(LEVEL_OF_DETAILS) > 5) {
			
							// draw the meta ball
							glPushMatrix();
							//glRotated(90, 0.0, 1.0, 0.0);
							glTranslated(0.0, 1.5, 0.0);
							glScaled(VAL(METABALL_RADIUS), VAL(METABALL_RADIUS), VAL(METABALL_RADIUS));
							glTranslated(-VAL(METABALL_RADIUS) * 2, 0, -VAL(METABALL_RADIUS) * 2);
							MetaBall metaball(VAL(METABALL_DISTANCE_DIFFERENCE));
							metaball.drawMetaBall();
							glPopMatrix();

							if (VAL(INDIVIDUAL_LOOKING_CHOICE_OF_DIAMOND) == 1) {
								glRotated(diamondAnimated, 0.0, 1.0, 0.0);
								glTranslated(0.0, 2.0, 0.0);
								drawDiamond();
							}
							else if (VAL(INDIVIDUAL_LOOKING_CHOICE_OF_DIAMOND) == 2) {
								glRotated(diamondAnimated, 2.0, 0.0, 0.0);
								glTranslated(-1.0, 1.0, -1.0);
								setDiffuseColor(COLOR_BLUE);
								drawTriangularPyramid(2.0);
							}
							else {
								glRotated(diamondAnimated, 0.0, 2.0, 1.0);
								glTranslated(-1.0, 1.0, -1.0);
								drawRectangularPyramid(2.0, 2.5);
							}
						}
						glPopMatrix();
					glPopMatrix();

					setDiffuseColor(COLOR_YELLOW);
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
						//if (VAL(LEVEL_OF_DETAILS)>5)
						//{
						//	glRotated(diamondAnimated, 0.0, 1.0, 0.0);
						//	glTranslated(0.0, 2.0, 0.0);
						//	drawDiamond();
						//}

						if (VAL(LEVEL_OF_DETAILS)>6)
						{
							glPushMatrix();
							glTranslated(0.0, 1.5, 0);
							glRotated(-90, 1, 0, 0);
							drawTorus(50, 50, 1, 0.2);
							glPopMatrix();
						}

						glPopMatrix();

					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		}
}

ModelerView* createKeeponModel(int x, int y, int w, int h, char* label)
{
	return new Keepon(x, y, w, h, label);
}



void Keepon::setAnimatedValue(double& value, double step, double min, double max, bool& toMax, bool& toMin) {
	
	if (toMax) {
		value += step;
		if (value >= max) {
			toMax = false;
			toMin = true;
		}
	}
	else if (toMin) {
		value -= step;
		if (value <= min) {
			toMax = true;
			toMin = false;
		}
	}

}


void Keepon::startAnimation() {

	// Base and whole body
	float theta = circleSpeed * M_PI / 180;
	float radius = 5.5;
	baseAnimatedX = (GLdouble)cos(theta) * 2;
	baseAnimatedZ = (GLdouble)sin(theta) * radius;

	if (VAL(ANIMATION_HAPPY_MOOD) == 1) {
		// Base and whole body
		setAnimatedValue(baseAnimatedY, 0.2, 0, 5, baseToMax, baseToMin);

		// Head
		headAnimatedY = 0;

		if (baseAnimatedY > 3.5) {
			SVAL(INDIVIDUAL_LOOKING_NOSE_LENGTH, 2.0);
		}
		else {
			SVAL(INDIVIDUAL_LOOKING_NOSE_LENGTH, 0.1);
		}
		setAnimatedValue(headAnimatedZ, 0.55, -13.0, 13.0, headToMax, headToMin);

		// Wings
		setAnimatedValue(LWingAnimated, 5.05, -10.0, 50.0, lWingToMax, lWingToMin);
		setAnimatedValue(RWingAnimated, 5.05, -10.0, 50.0, rWingToMax, rWingToMin);

		// Left upper arm 
		setAnimatedValue(LUArmAnimatedY, 0.75, -80.0, 0.0, luHandToMax, luHandToMin);

		// Right Upper Arm
		// Right Lower Arm (weapon)
		RUArmAnimatedX = 90;
		RUArmAnimatedY = 14;
		RLArmAnimatedX += 10.5;
		setAnimatedValue(RUArmAnimatedZ, 0.55, -90, 0, ruHandToMax, ruHandToMin);
	}
	else if (VAL(ANIMATION_ANGRY_MOOD) == 1) {
		// Base
		setAnimatedValue(baseAnimatedRotateX , 0.4, -5.0, 5.0, baseToMax, baseToMin);
		baseAnimatedRotateY += 0.5;
		setAnimatedValue(baseAnimatedRotateZ , 0.3, -5.0, 5.0, baseToMax, baseToMin);

		// Head
		setAnimatedValue(headAnimatedY, 0.6, -17.0, 17.0, headToMax, headToMin);

		// Wings
		setAnimatedValue(LWingAnimated, 0.45, 0.0, 25.0, lWingToMax, lWingToMin);
		setAnimatedValue(RWingAnimated, 0.45, 0.0, 25.0, rWingToMax, rWingToMin);

		// Right Upper Arm
		// Right Lower Arm (weapon)
		RUArmAnimatedZ = -90;
		RUArmAnimatedY = 90;
		setAnimatedValue(RUArmAnimatedX, 3.5, 10.0, 90.0, ruHandToMax, ruHandToMin);
	}
	else {
		// Head
		setAnimatedValue(headAnimatedY, 0.6, -90.0, 0.0, headToMax, headToMin);

		// Wings
		LWingAnimated = 0.0;
		RWingAnimated = 0.0;

		// Right Upper Arm
		// Right Lower Arm (weapon)
		RUArmAnimatedX = 90;
		RUArmAnimatedY = 14;
		setAnimatedValue(RUArmAnimatedZ, 0.55, -90, 0, ruHandToMax, ruHandToMin);
	}

	// Left upper arm
	LUArmAnimatedZ = 45.0;
	diamondAnimated += 8.0;

	// Left Lower Arm
	setAnimatedValue(LLArmAnimatedZ, 0.55, -45.0, 0.0, llHandToMax, llHandToMin);

	// Left Leg
	setAnimatedValue(LLegAnimatedX, 0.55, -45, 45, lLegToMax, lLegToMin);

	// Right Leg
	setAnimatedValue(RLegAnimatedX, 0.55, -45, 45, rlegToMax, rlegToMin);

}


// Reset all animated values
void Keepon::endAnimation() {

	happyMood = false;
	angryMood = false;

	baseAnimatedX = 0.0;
	baseAnimatedY = 0.0;
	baseAnimatedZ = 0.0;
	baseAnimatedRotateX = 0.0;
	baseAnimatedRotateY = 0.0;
	baseAnimatedRotateZ = 0.0;
	circleSpeed = 0.0f;

	headAnimatedX = 0.0;
	headAnimatedY = 0.0;
	headAnimatedZ = 0.0;

	noseAnimated = 0.0,

	LWingAnimated = 0.0;
	RWingAnimated = 0.0;

	LUArmAnimatedX = 0.0;
	LUArmAnimatedY = 0.0;
	LUArmAnimatedZ = 0.0;

	diamondAnimated = 0.0;

	LLArmAnimatedX = 0.0;
	LLArmAnimatedY = 0.0;
	LLArmAnimatedZ = 0.0;

	RUArmAnimatedX = 0.0;
	RUArmAnimatedY = 0.0;
	RUArmAnimatedZ = 0.0;

	RLArmAnimatedX = 0.0;
	RLArmAnimatedY = 0.0;
	RLArmAnimatedZ = 0.0;

	LLegAnimatedX = 0.0;
	RLegAnimatedX = 0.0;

	baseToMax = true;
	baseToMin = false;

	headToMax = false;
	headToMin = true;

	lWingToMax = true;
	lWingToMin = false;

	rWingToMax = true;
	rWingToMin = false;

	luHandToMax = false;
	luHandToMin = true;

	llHandToMax = false;
	llHandToMin = true;

	ruHandToMax = false;
	ruHandToMin = true;

	rlHandToMax = false;
	rlHandToMin = true;

	lLegToMax = false;
	lLegToMin = true;

	rlegToMax = true;
	rlegToMin = false;

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

	controls[LEVEL_OF_DETAILS] = ModelerControl("Level of Details", 0, 7, 1, 7);

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
	controls[LEFT_UPPER_ARM_ROTATE_Z] = ModelerControl("Left Upper Arm Z", -90, 45, 1, 0);

	controls[LEFT_LOWER_ARM_ROTATE_X] = ModelerControl("Left Lower Arm X", -90, 90, 1, 0);
	controls[LEFT_LOWER_ARM_ROTATE_Y] = ModelerControl("Left Lower Arm Y", -90, 90, 1, 0);
	controls[LEFT_LOWER_ARM_ROTATE_Z] = ModelerControl("Left Lower Arm Z", -90, 45, 1, 0);

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

	controls[ANIMATION_HAPPY_MOOD] = ModelerControl("Happy Mood", 0, 1, 1, 0);
	controls[ANIMATION_ANGRY_MOOD] = ModelerControl("Angry Mood", 0, 1, 1, 0);

	controls[INDIVIDUAL_LOOKING_NOSE_LENGTH] = ModelerControl("Individual Looking Nose Length", 0.1, 2, 0.1, 0.1);
	controls[INDIVIDUAL_LOOKING_CHOICE_OF_WEAPON] = ModelerControl("Individual Looking Choice of Weapon", 1, 3, 1, 1);
	controls[INDIVIDUAL_LOOKING_CHOICE_OF_DIAMOND] = ModelerControl("Individual Looking Choice of Diamond", 1, 3, 1, 1);
	controls[INDIVIDUAL_LOOKING_EYE_SIZE] = ModelerControl("Individual Looking Eye Size", 0.1, 0.3, 0.02, 0.1);
	controls[INDIVIDUAL_LOOKING_WINGS] = ModelerControl("Individual Looking Wings", 0, 1, 1, 1);
	controls[INDIVIDUAL_LOOKING_WINGS_SIZE] = ModelerControl("Individual Looking Wings Size", 1, 4, 0.1f, 1);
	controls[INDIVIDUAL_LOOKING_LEFT_WING_ROTATE] = ModelerControl("Individual Looking Left Wing Rotate", -20, 35, 0.1f, 0);
	controls[INDIVIDUAL_LOOKING_RIGHT_WING_ROTATE] = ModelerControl("Individual Looking Right Wing Rotate", -20, 35, 0.1f, 0);
	controls[INDIVIDUAL_LOOKING_TORSO_COLOR_RED] = ModelerControl("Individual Looking Torso Color Red", 0, 255, 1, 0);
	controls[INDIVIDUAL_LOOKING_TORSO_COLOR_GREEN] = ModelerControl("Individual Looking Torso Color Green", 0, 255, 1, 255);
	controls[INDIVIDUAL_LOOKING_TORSO_COLOR_BLUE] = ModelerControl("Individual Looking Torso Color Blue", 0, 255, 1, 0);

	controls[L_SYSTEM_TREE_ON] = ModelerControl("L-system ON", 0, 1, 1, 0);
	controls[L_SYSTEM_TREE_LENGTH] = ModelerControl("L-system Tree Length", 1, 2.0, 0.1, 1);
	controls[L_SYSTEM_TREE_THICKNESS] = ModelerControl("L-system Tree Thickness", 0.2, 0.5, 0.1, 0.2);
	controls[L_SYSTEM_TREE_ANGLE] = ModelerControl("L-system Tree Angle", 30, 60, 1, 30);
	controls[L_SYSTEM_TREE_LEVEL] = ModelerControl("L-system Tree Level", 0, 5, 1, 3);

	controls[METABALL_RADIUS] = ModelerControl("MetaBall Radius", 0.2, 2, 0.1, 1.0);
	controls[METABALL_DISTANCE_DIFFERENCE] = ModelerControl("MetaBall distance difference", 0.5, 2, 0.1, 1);

	controls[LEVEL_OF_DETAILS] = ModelerControl("Level of Details", 0, 7, 1, 7);

	ModelerApplication::Instance()->Init(&createKeeponModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}