#include<iostream>
#include "SudokuGame.h"
#include "ui.h"
#include "constants.h"
#include <conio.h>
using namespace std;

int main()
{
	int key = -1;
	while (true)
	{
		if (key == '3')
			break;
		else if (key == '2')
			ui::displayInstructions();
		else if (key == '1')
		{
			int difficulty = ui::promptDifficulty();
			SudokuGame game(difficulty);
			ui::runGame(game);
		}
		ui::displayMainMenu();
		key = _getch();
	}
	
	return 0;
}