#include <iostream>

#include "SampleDecoder.h"
#include "MTRand.h"
#include "BRKGA.h"
#include "DataLoading.h"
#include "Vertice.h"


int main(int argc, char* argv[]) {
	
	const unsigned n = 100;		// size of chromosomes
	const unsigned p = 1000;	// size of population
	const double pe = 0.20;		// fraction of population to be the elite-set
	const double pm = 0.10;		// fraction of population to be replaced by mutants
	const double rhoe = 0.70;	// probability that offspring inherit an allele from elite parent
	const unsigned K = 3;		// number of independent populations
	const unsigned MAXT = 2;	// number of threads for parallel decoding	

	std::vector<Vertice> vertices;  // vector that will contain the Vertices
	
	if(argc != 2) {

		std::cerr << "\nWrong parameter number\n" << std::endl;

		return EXIT_FAILURE;
	}
		
	std::ifstream data (argv[1]);  // create a new stream and open the file in argv[1]
	
	if( !data.is_open() ) {
		
		std::cerr << "\nError while opening file " << argv[1] << std::endl;
		
		return EXIT_FAILURE;
	}
	
	/* Read all the data from the data file */
	const int F = atoi(DataLoading::readParam(data));
	const int T = atoi(DataLoading::readParam(data));
	float deadline = atof(DataLoading::readParam(data));

	DataLoading::readVertices(data, vertices);
	
	// DEBUG 	std::cout << T << std::endl;  std::cout << F << std::endl; std::cout << deadline << std::endl; 
	// DEBUG  for(int i=0; i < vertices.size() ; i++)	std::cout << vertices[i].toString() << std::endl;
	
	SampleDecoder decoder;			// initialize the decoder
	
	const long unsigned rngSeed = 0;	// seed to the random number generator
	MTRand rng(rngSeed);				// initialize the random number generator
	
	// initialize the BRKGA-based heuristic
	BRKGA< SampleDecoder, MTRand > algorithm(n, p, pe, pm, rhoe, decoder, rng, K, MAXT);
	
	unsigned generation = 0;		// current generation
	const unsigned X_INTVL = 100;	// exchange best individuals at every 100 generations
	const unsigned X_NUMBER = 2;	// exchange top 2 best
	const unsigned MAX_GENS = 1000;	// run for 1000 gens
	
	do {
		
		algorithm.evolve();	// evolve the population for one generation
		
		if((++generation) % X_INTVL == 0)
			algorithm.exchangeElite(X_NUMBER);	// exchange top individuals
	} 
	while (generation < MAX_GENS);
	
	std::cout << "Best solution found has objective value = "
	 		<< algorithm.getBestFitness() << std::endl;
	
	return EXIT_SUCCESS;
}

/** 
 * Inicializar as variáveis através da leitura do ficheiro de dados
 */
//void init(char *fileName) {
    		
	// calcular a soma dos pesos de todas as tarefas antes da execução do filtro
/*	for (int i = 0; i <= this.F - 1; i++)
		this.totalScore += vertices.get(i).getScore();
			
	this.collected = 0;
				
		this.filter();
		this.buildMatrix(); // construir a matriz de distâncias
	}
    		
	input.close();
    		
	this.bestFitness = 0.0;
	this.bestTrip = new ArrayList[this.T];
    		
	for(int i=0 ; i<this.T ; i++)
		this.bestTrip[i] = new ArrayList<Integer>();
*/
//}
/*    	catch (FileNotFoundException ex) {
    		System.err.println("Unable to open file: " + ex);
    		ex.printStackTrace();
    		
    		System.	(-1);
    	}
    	catch (NumberFormatException ex) {
    		System.err.println("Unable to read number: " + ex);
    		ex.printStackTrace();
    		
    		System.exit(-1);    		
    	}
    	catch (Exception ex) {
    		System.err.println("Error: " + ex);
    		ex.printStackTrace();
    		
    		System.exit(-1);
    	}*/
//}
