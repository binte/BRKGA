/*
 * DataLoading.h
 *
 * Auxiliar class, used for parsing the data file
 *
 *  Created on: May 11, 2015
 *      Author: Celso
 */

#ifndef DATALOADING_H
#define DATALOADING_H

#include "Vertice.h"

#include <cstring>
#include <iostream>
#include <sstream>  
#include <fstream>
#include <vector>


namespace DataLoading {
	
	char *readParam(std::ifstream &data);
	void readVertices(std::ifstream &data, std::vector<Vertice> &vertices);
	void update(std::vector<Vertice> &vertices, int numLine, std::string line);
}

#endif
