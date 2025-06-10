#include<iostream>
#include "SudokuGame.h"
#include "ui.h"
#include "constants.h"
#include <conio.h>
#include <ctime>   // <-- 新增：為了使用 time()
#include <cstdlib> // <-- 新增：為了使用 srand() 和 rand()
using namespace std;

int main()
{
	// 初始化隨機數生成器
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
			key = -1; // 重置 key 以便再次顯示主菜單
			continue;
		}
		ui::displayMainMenu();
		key = _getch();
	}
	
	return 0;
}