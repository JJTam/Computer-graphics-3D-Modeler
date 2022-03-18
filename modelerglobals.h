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

	LEVEL_OF_DETAILS,

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

	LEFT_LEG_ROTATE_X,
	LEFT_LEG_ROTATE_Y,
	LEFT_LEG_ROTATE_Z,

	RIGHT_LEG_ROTATE_X,
	RIGHT_LEG_ROTATE_Y,
	RIGHT_LEG_ROTATE_Z,

	HAMMER_WIDTH,

	ANIMATION_HAPPY_MOOD,
	ANIMATION_ANGRY_MOOD,

	INDIVIDUAL_LOOKING_NOSE_LENGTH,
	INDIVIDUAL_LOOKING_CHOICE_OF_WEAPON,
	INDIVIDUAL_LOOKING_CHOICE_OF_DIAMOND,
	INDIVIDUAL_LOOKING_EYE_SIZE,
	INDIVIDUAL_LOOKING_WINGS,
	INDIVIDUAL_LOOKING_LEFT_WING_ROTATE,
	INDIVIDUAL_LOOKING_RIGHT_WING_ROTATE,
	INDIVIDUAL_LOOKING_WINGS_SIZE,
	INDIVIDUAL_LOOKING_TORSO_COLOR_RED,
	INDIVIDUAL_LOOKING_TORSO_COLOR_GREEN,
	INDIVIDUAL_LOOKING_TORSO_COLOR_BLUE,

	L_SYSTEM_TREE_ON,
	L_SYSTEM_TREE_LENGTH,
	L_SYSTEM_TREE_THICKNESS,
	L_SYSTEM_TREE_ANGLE,
	L_SYSTEM_TREE_LEVEL,

	XLIGHT,
	YLIGHT,
	ZLIGHT,
	INTENSITY,

	METABALL_RADIUS,
	METABALL_DISTANCE_DIFFERENCE,


	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_YELLOW	1.0f, 1.0f, 0.0f
#define COLOR_BLACK		0.0f, 0.0f, 0.0f
#define COLOR_ROSE		255.0f, 219.0f, 232.0f 
#define COLOR_PURPLE	100.0f, 0.0f, 100.0f 

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#define SVAL(x, v) (ModelerApplication::Instance()->SetControlValue(x, v))

#endif