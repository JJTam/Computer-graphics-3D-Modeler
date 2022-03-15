#pragma once
#include <string>
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"
#include "bitmap.h"
#include <iostream>

class LSystemTree
{
public:
	LSystemTree(double lineLength, double thickness, int angle, int numRecursion);
	void		draw();							// draw the L-System Tree
	std::string	generateSentence();				// generate the requred sequence for the L-System Tree
	std::string getSymbolRule(char symbol);		// every symbol in m_sentence represent one action

public:
	std::string		m_sentence;					// sentence for the L-System Tree
	double			m_nLineLength;				// line length for one sector of the tree
	double			m_nThickness;				// line thickness of one sector of the tree
	int				m_nAngle;					// angle between main branch and sub-branches
	int				m_nNumRecursion;			// level of L-system sequence
};

