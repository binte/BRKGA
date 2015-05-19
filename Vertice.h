#ifndef _VERTICE
#define _VERTICE

#include <string>
#include <limits>

class Vertice {
	
private:
	int id;				// vertice ID, according to its original number
	float x;  		// abscissa
	float y;			// ordinate
	float score;	// score obtained by passing through this vertice

public:
	
	Vertice();
	Vertice(int id, float x, float y, float score);

	void setID(int id);
	void setX(float x);
	void setY(float y);
	void setScore(float score);
	int getID();
	float getX();
	float getY();
	float getScore();
	std::string toString();
};

#endif
