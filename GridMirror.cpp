#include <iostream>
#include <cstring>
#include "GridMirror.h"

using namespace std;

GridMirror::GridMirror(int size1, int size2)
{

	cout << "Grid mirror" << endl;

	rows = size1;
	columns = size2;
	alive = false;

	bool** currentGen = new bool*[rows];

	for(int i = 0; i < rows; ++i)
	{
  		currentGen[i] = new bool[columns];
	}

	for(int i = 0; i < rows; ++i)
	{

		for(int j = 0; j < columns; ++j)
		{
			int liveOrDead = (rand() % 2);

			if(liveOrDead == 0)
			{
				currentGen[i][j] = true;
			}
			
			else if(liveOrDead == 1)
			{
				currentGen[i][j] = false;
			}
		}
	}

	genNum = 0;
}

GridMirror::~GridMirror()
{
	cout << "Grid was destroyed." << endl;
}



void GridMirror:: makeNextGeneration()
{
	genNum++;

	//copy current grid to last grid
	bool** lastGen = new bool*[rows];
	for(int i = 0; i < rows; ++i)
  		lastGen[i] = new bool[columns];

  	memcpy(&currentGen, &lastGen, sizeof(lastGen));

	//use last grid to make new generation
	for(int i = 0; i < rows; ++i)
	{
		//first row
		if(i == 0)
		{
			cout << "first for loop" << endl;

			for(int j = columns-1; j >= 0; --j)
			{
				int numOfNeighbors = 0;

				cout << "second for loop" << endl;

				//if it is the left most slot
				if(j == 0)
				{
					cout << "First row " << endl;
					if (lastGen[i][j])
					{
						numOfNeighbors += 3;
						alive = true;
					}

					//check right
					if(lastGen[i][j+1])
						numOfNeighbors += 2;
					//check down 
					if(lastGen[i+1][j])
						numOfNeighbors += 2;
					//check down and right
					if(lastGen[i+1][j+1])
						numOfNeighbors++;

				}

				//if it is the right most slot
				else if(j == columns-1)
				{
					cout << "top right corner" << endl;
					cout << "i: " << i << "j: " << j << endl;
					cout << "columns - 1: " << columns-1 << endl;
					cout << "last gen [0][4]: " << lastGen[0][4] << endl;
					if (lastGen[i][j] == alive)
					{
						cout << "In first if statement" << endl;
						numOfNeighbors += 3;
						alive = true;
					}
					cout << "top right corner if statement " << endl;
					//check left
					if(lastGen[i][j-1])
						numOfNeighbors += 2;
					//check down 
					if(lastGen[i+1][j])
						numOfNeighbors += 2;
					//check down and left
					if(lastGen[i+1][j+1])
						numOfNeighbors++;
				}

				//internal column
				else
				{
					if (lastGen[i][j])
					{
						numOfNeighbors += 1;
						alive = true;
					}
					//check left
					if(lastGen[i][j-1])
						numOfNeighbors += 2;
					//check right
					if(lastGen[i][j+1])
						numOfNeighbors += 2;
					//check down and left
					if(lastGen[i+1][j-1])
						numOfNeighbors++;
					//check down 
					if(lastGen[i+1][j])
						numOfNeighbors++;
					//check down and right
					if(lastGen[i+1][j+1])
						numOfNeighbors++;


				}


			//Check if it lives or dies
				if(numOfNeighbors <= 1)
					currentGen[i][(columns-1) - j] = false;
				//else if(numOfNeighbors == 2 && alive = false)
				//	currentGen[i][j] = true;
				else if((numOfNeighbors == 3) && (alive = false))
					currentGen[i][(columns-1) - j] = true;
				else if(numOfNeighbors >= 4)
					currentGen[i][(columns-1) - j] = false;

			}
		}

		//last row
		else if(i == rows-1)
		{
			for(int j = columns-1; j >= 0; --j)
			{
				int numOfNeighbors = 0;

				//if it is the left most slot
				if(j == 0)
				{
					if (lastGen[i][j])
					{
						numOfNeighbors += 3;
						alive = true;
					}

					//check right
					if(lastGen[i][j+1])
						numOfNeighbors += 2;
					//check up
					if(lastGen[i-1][j])
						numOfNeighbors += 2;
					//check up and right
					if(lastGen[i-1][j+1])
						numOfNeighbors++;

				}
				//if it is the right most slot
				else if(j == columns-1)
				{
					if (lastGen[i][j])
					{
						numOfNeighbors += 3;
						alive = true;
					}

					//check left
					if(lastGen[i][j-1])
						numOfNeighbors += 2;
					//check up
					if(lastGen[i-1][j])
						numOfNeighbors += 2;
					//check up and left
					if(lastGen[i-1][j-1])
						numOfNeighbors++;
				}

				//internal column
				else
				{
					if (lastGen[i][j])
					{
						numOfNeighbors += 1;
						alive = true;
					}
					//check left
					if(lastGen[i][j+1])
						numOfNeighbors++;
					//check right
					if(lastGen[i][j-1])
						numOfNeighbors++;
					//check up and left
					if(lastGen[i-1][j-1])
						numOfNeighbors++;
					//check up
					if(lastGen[i-1][j])
						numOfNeighbors++;
					//check up and right
					if(lastGen[i-1][j+1])
						numOfNeighbors++;
					
				}

			//Check if it lives or dies
				if(numOfNeighbors <= 1)
					currentGen[i][(columns-1) - j] = false;
				//else if(numOfNeighbors == 2 && alive = false)
				//	currentGen[i][j] = true;
				else if((numOfNeighbors == 3) && (alive = false))
					currentGen[i][(columns-1) - j] = true;
				else if(numOfNeighbors >= 4)
					currentGen[i][(columns-1) - j] = false;
			}

		}
		//internal row
		else
		{
			for(int j = columns-1; j >= 0; --j)
			{
				int numOfNeighbors = 0;

				//if it is the left most row
				if(j == 0)
				{
					if (lastGen[i][j])
					{
						//one neighbor is reflected left
						numOfNeighbors += 1;
						alive = true;
					}

					//check right
					if(lastGen[i][j+1])
						numOfNeighbors++;
					//check up
					if(lastGen[i-1][j])
						numOfNeighbors += 2;
					//check up and right
					if(lastGen[i-1][j+1])
						numOfNeighbors++;
					//check down 
					if(lastGen[i+1][j])
						numOfNeighbors += 2;
					//check down and right
					if(lastGen[i+1][j+1])
						numOfNeighbors++;

				}
				//if it is the right most row
				else if(j == columns-1)
				{
					if (lastGen[i][j])
					{
						//one neighbor is reflected right
						numOfNeighbors += 1;
						alive = true;
					}

					//check left
					if(lastGen[i][j-1])
						numOfNeighbors++;
					//check up and left
					if(lastGen[i-1][j-1])
						numOfNeighbors++;
					//check up
					if(lastGen[i-1][j])
						numOfNeighbors += 2;
					//check down and left
					if(lastGen[i+1][j-1])
						numOfNeighbors++;
					//check down 
					if(lastGen[i-1][j])
						numOfNeighbors += 2;
				}
				//internal column
				else
				{
					if (lastGen[i][j])
						alive = true;

					//check left
					if(lastGen[i][j-1])
						numOfNeighbors++;
					//check right
					if(lastGen[i][j+1])
						numOfNeighbors++;
					//check up and left
					if(lastGen[i-1][j-1])
						numOfNeighbors++;
					//check up
					if(lastGen[i-1][j])
						numOfNeighbors++;
					//check up and right
					if(lastGen[i-1][j+1])
						numOfNeighbors++;
					//check down and left
					if(lastGen[i+1][j-1])
						numOfNeighbors++;
					//check down
					if(lastGen[i+1][j])
						numOfNeighbors++; 
					//check down and right
					if(lastGen[i+1][j+1])
						numOfNeighbors++;
				}


			//Check if it lives or dies
				if(numOfNeighbors <= 1)
					currentGen[i][(columns-1) - j] = false;
				//else if(numOfNeighbors == 2 && alive = false)
				//	currentGen[i][j] = true;
				else if((numOfNeighbors == 3) && (alive = false))
					currentGen[i][(columns-1) - j] = true;
				else if(numOfNeighbors >= 4)
					currentGen[i][(columns-1) - j] = false;
			}

		}
	}
	
	cout << "Generation " << genNum << endl;
	for (int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			cout << "generation [" << i << "]" << "[" << j << "]" << currentGen[i][j] << endl;
		}
	}
	displayGrid(); 

}

void GridMirror:: displayGrid()
{
	for (int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			if(currentGen[i][j] == false)
				cout << " [   ] " ;
			else if(currentGen[i][j] == true)
				cout << " [ X ] " ;
		}
		cout << endl;
	}
}
