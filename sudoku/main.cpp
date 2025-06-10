#include<iostream>
#include "SudokuGame.h"
#include "ui.h"
#include "constants.h"
using namespace std;

int main()
{
	ui::displayWelcomeMessage();
	int difficulty = ui::promptDifficulty();
	SudokuGame game(difficulty);
	ui::runGame(game);
	return 0;
}