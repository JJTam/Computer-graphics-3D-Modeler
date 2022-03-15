#include "LSystemTree.h"

LSystemTree::LSystemTree(double lineLength, double thickness, int angle, int numRecursion)
	:	m_nLineLength(lineLength), 
		m_nThickness(thickness),
		m_nAngle(angle), 
		m_nNumRecursion(numRecursion)
{
	m_sentence = generateSentence();
}

void LSystemTree::draw()
{
	setDiffuseColor(COLOR_GREEN);
	// loop throush every symbol in the sentence
	for (int i = 0; i < m_sentence.length(); i++)
	{
		switch (m_sentence[i])
		{
		case 'l':
			//std::cout << "line length: " << m_nLineLength << '\n';
			//std::cout << "thickness: " << m_nThickness << '\n';

			// draw the a sector of branch
			glRotated(-90.0, 1.0, 0.0, 0.0);
			setDiffuseColor(153/255, 51/255, 51/255);
			drawCylinder(m_nLineLength, m_nThickness, m_nThickness);
			glRotated(90, 1.0, 0.0, 0.0);

			// draw the leaf
			setDiffuseColor(COLOR_GREEN);
			glTranslated(0, m_nLineLength + m_nThickness, 0.0);
			drawSphere(m_nThickness);
			break;

		case 'd':
			// draw aa sector of branch only, no leaf
			glRotated(-90.0, 1.0, 0.0, 0.0);
			setDiffuseColor(153 / 255, 51 / 255, 51 / 255);
			drawCylinder(m_nLineLength, m_nThickness, m_nThickness);
			glRotated(90.0, 1.0, 0.0, 0.0);
			glTranslated(0, m_nLineLength, 0.0);
			break;

		case '[':
			glPushMatrix();
			break;

		case ']':
			glPopMatrix();
			break;

		case '%':	// first sub-branch
			glRotated(m_nAngle, 0.0, 0.0, 1.0);
			break;

		case '^':	// second sub-branch
			glRotated(120.0, 0.0, 1.0, 0.0);
			glRotated(m_nAngle, 0.0, 0.0, 1.0);
			break;

		case '&':	// third sub-branch
			glRotated(240.0, 0.0, 1.0, 0.0);
			glRotated(m_nAngle, 0.0, 0.0, 1.0);
			break;

		default:	// shoud not enter normally
			std::cout << "default" << '\n';
			break;
		}
	}

}

std::string LSystemTree::generateSentence()
{
	std::string sentence = "l";			// initial axiom
	std::string nextSentence;
	
	for (int i = 0; i < m_nNumRecursion; i++)
	{
		for (int j = 0; j < sentence.length(); j++)
		{
			nextSentence += getSymbolRule(sentence[j]);
		}
		sentence = nextSentence;
		nextSentence = "";
	}
	std::cout << sentence << '\n';
	return sentence;
}

std::string LSystemTree::getSymbolRule(char symbol)
{
	std::string str{ symbol };
	switch (symbol)
	{
	case 'l':
		return std::string("d[%l][^l][&l]");
	case 'd':
		return std::string("dd");
	default:
		return str;
	}
}
