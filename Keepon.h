#pragma once
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

class Keepon: public ModelerView
{
public:
	Keepon(int x, int y, int w, int h, char* label)
		:ModelerView(x, y, w, h, label)
	{}

	
	virtual void draw();

	void startAnimation();
	void endAnimation();


private:

	double animatedX = 0.0, animatedY = 0.0, animatedZ = 0.0, animatedAngle = 0.0;
	int i = 0;

};

