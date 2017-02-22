#include <iostream>

using namespace std;

class GridMirror
{
public:
	GridMirror(int size1, int size2);
	~GridMirror();
	void makeRandom();
	void makeNextGeneration();
	//void copyLastGen();
	void switchGenerations();
	void displayGrid();
	void makeReflectionGrid();

	bool** currentGen;
	bool** lastGen;
	bool** reflectionGrid;

	int rows;
	int columns;
	int genNum;
	bool alive;

};