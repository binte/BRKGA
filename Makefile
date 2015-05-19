# Macros:
CPP= g++
CFLAGS= -Wall -Wextra -pedantic -O3 -g -fopenmp -std=c++11
OBJECTS= main.o SampleDecoder.o DataLoading.o Vertice.o
TARGET= sample


# Targets:
main: $(OBJECTS)
	$(CPP) $(CFLAGS) -o $(TARGET) $(OBJECTS)
        
main.o: main.cpp MTRand.h BRKGA.h
	$(CPP) $(CFLAGS) -c main.cpp

SampleDecoder.o: SampleDecoder.cpp SampleDecoder.h BRKGA.h
	$(CPP) $(CFLAGS) -c sampleDecoder.cpp

DataLoading.o: DataLoading.cpp DataLoading.h
	$(CPP) $(CFLAGS) -c DataLoading.cpp

Vertice.o : Vertice.cpp Vertice.h
	$(CPP) $(CFLAGS) -c Vertice.cpp


# Remove:
clean:
	rm -f $(OBJECTS) *~

run:
	./$(TARGET) data.txt
