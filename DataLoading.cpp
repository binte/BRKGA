/*
 * DataLoading.cpp
 *
 *  Created on: May 11, 2015
 *      Author: Celso
 */

#include "DataLoading.h"

namespace DataLoading {

	/* Ler a string contendo o número de vértices, o número de viajantes (Travellers) ou o tempo máximo de cada viagem

	Exemplo:

	n 21
	m 2
	tmax 7.5
	4.600	7.100	0
	(...)

	número de vértices/linhas = 21
	número de viajantes = 2
	tempo máximo = 7.5

	*/
	char *readParam(std::ifstream &data) /*throws FileNotFoundException*/ {

		char* buffer = NULL, *pch = NULL;
		std::string line;

		std::getline(data, line); // read a line from the given stream

		buffer = (char *) line.c_str(); // convert the stream into a C string (char *)
		
		pch = strtok(buffer, " "); // initialise strtok
		
		pch = strtok(NULL, " "); // discard identifier
		
		return strdup(pch); // return the param converted to an integer
	}

	/* Fill the structure with the vertices by parsing the given stream */
	void readVertices(std::ifstream &data, std::vector<Vertice> &vertices) {

		int numLine = 0;
		std::string line;

 		// ler linha a linha do ficheiro, para a string 'line', e em cada iteração do ciclo processar essa linha
		while ( std::getline(data, line) ) {

 			update(vertices, numLine, line);  // atualiza o vector de Vértices
			numLine++;
 		}
	}
	
	/* Updates the vector of vertices with a new vertice, coming from a line read from the stream */
	void update(std::vector<Vertice> &vertices, int numLine, std::string line) {

		Vertice novo;
		char* buffer = NULL, *pch = NULL;
		
		buffer = (char *) line.c_str(); // convert the stream into a C string (char *)

		pch = strtok(buffer, "	"); // initialise strtok
		
		novo.setID(numLine);

		novo.setX(atof(pch));
		
		pch = strtok(NULL, "	"); // next parameter
		
		novo.setY(atof(pch));

		pch = strtok(NULL, "	"); // next parameter

		novo.setScore(atoi(pch));

		vertices.push_back(novo);
	}
}
