#pragma once
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"
#include "bitmap.h"
#include "LSystemTree.h"

class Keepon: public ModelerView
{
public:
	Keepon(int x, int y, int w, int h, char* label)
		:ModelerView(x, y, w, h, label)
	{}

	
	virtual void draw();

	void startAnimation();
	void endAnimation();

	void setDefaultLight();
	void calAnimatedValue(double& value, int min, int max, bool& toMax, bool& toMin);

private:

	// For animations
	double
		// Base
		baseAnimatedX = 0.0,
		baseAnimatedY = 0.0,
		baseAnimatedZ = 0.0,
		baseAnimatedRotateX = 0.0,
		baseAnimatedRotateY = 0.0,
		baseAnimatedRotateZ = 0.0,

		// Head
		headAnimatedX = 0.0,
		headAnimatedY = 0.0,
		headAnimatedZ = 0.0,

		diamondAnimated = 0.0,

		// Left Upper Arm
		LUArmAnimatedX = 0.0,
		LUArmAnimatedY = 0.0,
		LUArmAnimatedZ = 0.0,

		// Left Lower Arm
		LLArmAnimatedX = 0.0,
		LLArmAnimatedY = 0.0,
		LLArmAnimatedZ = 0.0,

		// Right Upper Arm
		RUArmAnimatedX = 0.0,
		RUArmAnimatedY = 0.0,
		RUArmAnimatedZ = 0.0,

		// Right Lower Arm
		RLArmAnimatedX = 0.0,
		RLArmAnimatedY = 0.0,
		RLArmAnimatedZ = 0.0,

		// Left Leg
		LLegAnimatedX = 0.0,

		// Right Leg
		RLegAnimatedX = 0.0;

		int circleIndex = 0;

		bool
			baseToMax = true,
			baseToMin = false,

			headToMax = true,
			headToMin = false,

			luHandToMax = false,
			luHandToMin = true,

			llHandToMax = false,
			llHandToMin = true,

			ruHandToMax = false,
			ruHandToMin = true,

			rlHandToMax = false,
			rlHandToMin = true,

			lLegToMax = false,
			lLegToMin = true,

			rlegToMax = true,
			rlegToMin = false;

	// add others here

};

