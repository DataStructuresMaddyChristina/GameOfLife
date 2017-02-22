#include <iostream>
#include <fstream>
#include <string>
#include "GridClassic.h"
#include "GridMirror.h"

using namespace std;

int main(int argc, char** argv)
{
	bool wantContinue = true;
	while(wantContinue)
	{

		int choiceGen;
		int choiceMode;
		int choiceHappen;
		cout << "Welcome to The Game Of Life" << endl;

		cout << "What Theme would you like?" << endl;
		cout << "1. Classic Mode" << endl;
		cout << "2. Mirror Mode" << endl;
		cout << "3. Donut Mode" << endl;
		cin >> choiceMode;

		cout << "Would you like: " << endl;
		cout << "1. Random Assignment " << endl;
		cout << "2. Provide A MapFile " << endl;

		cout << "Choice: ";

		cin >> choiceGen;

		cout << "Would you like to happen between generations?" << endl;
		cout << "1. Breif Pause " << endl;
		cout << "2. Press Enter " << endl;
		cout << "3. All at Once " << endl;
		cin >> choiceHappen;

		if(!(choiceGen == 1) || !(choiceGen == 2))
		{
			if(choiceMode == 1)
			{
				GridClassic cg(choiceGen);
				wantContinue = false;
			}
			else if(choiceMode == 2)
			{
				//GridMirror mg(choiceGen);
				wantContinue = false;
			
			}
			else if(choiceMode == 3)
			{
				//make donut grid
				wantContinue = false;
			}


		}

	}





	return 0;
}