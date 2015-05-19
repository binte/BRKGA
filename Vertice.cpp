#include "Vertice.h"
	
Vertice::Vertice() {
	
	this->id		= -1;
	this->x 		= std::numeric_limits<int>::max();
	this->y 		= std::numeric_limits<int>::max();
	this->score = std::numeric_limits<int>::max();
}

Vertice::Vertice(int id, float x, float y, float score) {
	
	this->id		= id;
	this->x			= x;
	this->y			= y;
	this->score = score;
}


/************************************************/
/********************* SETS *********************/
/************************************************/
void Vertice::setID(int id) {
	
	this->id = id;
}

void Vertice::setX(float x) {
	
	this->x = x;
}

void Vertice::setY(float y) {
	
	this->y = y;
}

void Vertice::setScore(float score) {
	
	this->score = score;
}


/************************************************/
/********************* GETS *********************/
/************************************************/
int Vertice::getID() {
	
	return this->id;
}

float Vertice::getX() {
	
	return this->x;
}

float Vertice::getY() {
	
	return this->y;
}

float Vertice::getScore() {
	
	return this->score;
}


/************************************************/
/******************* Methods ********************/
/************************************************/

/* Retorna uma string representativa do Vértice que invocou este método */
std::string Vertice::toString() {
  
	std::string s;

	s.append(std::to_string(this->id) + ":	");
	s.append("(");
	s.append(std::to_string(this->x));
	s.append(",	");
  s.append(std::to_string(this->y));
  s.append(",	");
  s.append(std::to_string(this->score));
  s.append(")");

	return s;
}
