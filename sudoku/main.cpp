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
	while (!game.isSolved())
	{
		ui::displayBoard(game);
		ui::displayMessage("Please enter your move (row, col, num):\n");
		ui::Move move = ui::promptMove();

		if (game.isCellFixed(move.row, move.col)) {
			ui::displayMessage("This cell is fixed and cannot be changed.\n");
			continue;
		}
		if (game.setCell(move.row, move.col, move.num))
		{

		}
		else 
		{
			ui::displayMessage("Invalid move! Please try again.\n");
			continue;
		}
	}
	ui::displayBoard(game);
	ui::displayCompletionMessage();
}