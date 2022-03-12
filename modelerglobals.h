#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{
	XPOS,
	YPOS,
	ZPOS,

	TORSO_ROTATE_X,
	TORSO_ROTATE_Y,
	TORSO_ROTATE_Z,
	
	HEAD_ROTATE_X,
	HEAD_ROTATE_Y,
	HEAD_ROTATE_Z,
	
	HEADHEIGHT,

	LEFT_UPPER_ARM_ROTATE_X,
	LEFT_UPPER_ARM_ROTATE_Y,
	LEFT_UPPER_ARM_ROTATE_Z,
	
	LEFT_LOWER_ARM_ROTATE_X,
	LEFT_LOWER_ARM_ROTATE_Y,
	LEFT_LOWER_ARM_ROTATE_Z,
	
	RIGHT_UPPER_ARM_ROTATE_X,
	RIGHT_UPPER_ARM_ROTATE_Y,
	RIGHT_UPPER_ARM_ROTATE_Z,
	
	RIGHT_LOWER_ARM_ROTATE_X,
	RIGHT_LOWER_ARM_ROTATE_Y,
	RIGHT_LOWER_ARM_ROTATE_Z,
	
	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif