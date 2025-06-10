#include<iostream>
#include "SudokuGame.h"
#include "ui.h"
#include "constants.h"
#include <conio.h>
#include <ctime>   // <-- �s�W�G���F�ϥ� time()
#include <cstdlib> // <-- �s�W�G���F�ϥ� srand() �M rand()
using namespace std;

int main()
{
	// ��l���H���ƥͦ���
	srand(time(0));
	int key = -1;
	while (true)
	{
		if (key == '4')
			break;
		else if (key == '3')
			ui::displaySeed();
		else if (key == '2')
			ui::displayInstructions();
		else if (key == '1')
		{
			int difficulty = ui::promptDifficulty();
			SudokuGame game(difficulty);
			ui::runGame(game);
			key = -1; // ���m key �H�K�A����ܥD���
			continue;
		}
		ui::displayMainMenu();
		key = _getch();
	}
	
	return 0;
}