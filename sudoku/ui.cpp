#include "ui.h"
#include "SudokuGame.h"
#include <iostream>
#include "constants.h"
#include <conio.h>
#include <string>

// �M�Ų׺ݾ��e��
void ui::clearScreen()
{
	system("cls");
}

// ����w��T��
void ui::displayWelcomeMessage()
{
	std::cout << "Welcome to Sudoku!\n";
}

void ui::displayCompletionMessage()
{
	std::cout << "Congratulations! You have completed the Sudoku puzzle!\n";
}

// ��ܾ�ӼƿW�ѽL
// �`�N�G�ڭ̶ǤJ const SudokuGame& ��Ū���C�����A
void ui::displayBoard(const SudokuGame& game, int x = 0, int y = 0)
{
    ui::clearScreen();
    std::cout << "+-------+-------+-------+" << std::endl;
    for (int i = 0; i < SUDOKU_SIZE; ++i) {
        std::cout << "| ";
        for (int j = 0; j < SUDOKU_SIZE; ++j) {
            // �ϥ� getter �禡�A�Ӥ��O�����s�� board
            int cellValue = game.getCell(i, j);
            bool isFixed = game.isCellFixed(i, j);
			bool isCursorOn = (i == x && j == y);

            if (isCursorOn)
            {
                std::cout << "\033[47;30m";
            }

            if (cellValue == EMPTY_CELL) 
            {
                std::cout << ". ";
            }
            else 
            {
                // �i�H�ھ� isFixed �����C��
                // �Ҧp�A�T�w���Ʀr�Τ��P�C�⥴�L
                if (isFixed) {
                    // ANSI escape code for bold/different color
                    std::cout << "\033[1;34m" << cellValue << "\033[0m ";
                }
                else {
                    std::cout << cellValue << " ";
                }
            }

            if (isCursorOn) 
            {
                std::cout << "\033[0m";
            }

            if ((j + 1) % 3 == 0) {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0) {
            std::cout << "+-------+-------+-------+" << std::endl;
        }
    }
}

// �V�ϥΪ���ܤ@���T���]�Ҧp���~�Ϊ��A��s�^
void ui::displayMessage(const std::string& message)
{
	std::cout << message << std::endl;
}

void ui::runGame(SudokuGame& game)
{
    int cursorX = 0;
    int cursorY = 0;
    bool gamingRunning = true;
    while (gamingRunning)
    {
        ui::clearScreen();
		ui::displayBoard(game, cursorX, cursorY);
        ui::displayMessage("Use arrow keys to move, 1-9 to input, 'q' to quit.");

		int key = _getch(); // �ϥ� _getch() �������L��J

        switch (key)
        {
			printf("X:%d, Y:%d", cursorX, cursorY);
            case 'w':
                if (cursorX > MIN_NUM)
                    cursorX--;
            break;
            case 'a':
                if (cursorY > MIN_NUM)
                    cursorY--;
            break;
            case 's':
                if (cursorX < MAX_NUM)
                    cursorX++;
            break;
            case 'd':
				if (cursorY < MAX_NUM)
					cursorY++;
            break;

            case '1':case '2':case '3':
            case '4':case '5':case '6':
            case '7':case '8':case '9':
            {
                int num = key - '0';
                game.setCell(cursorX, cursorY, num);
                break;
            }

            case '0':case ' ':case 127:
            {
				game.setCell(cursorX, cursorY, EMPTY_CELL); // �M����e��l
                break;
            }

            case 'q':
            {
				gamingRunning = false; // �����C���`��
                ui::displayMessage("Game Over.");
                break;
            }
        }
        if (game.isSolved())
        {
            gamingRunning = false;
            ui::clearScreen();
            ui::displayBoard(game, cursorX, cursorY);
            ui::displayMessage("Congratulations! You have completed the Sudoku puzzle!");
        }
    }
}

// ���ܨϥΪ̿������
int ui::promptDifficulty()
{
	int difficulty;
	std::cout << "Select difficulty (0: Easy, 1: Medium, 2: Hard):\n> ";
	std::cin >> difficulty;
	while (difficulty < 0 || difficulty > 2) 
	{
		std::cout << "Invalid choice. Please select again (0: Easy, 1: Medium, 2: Hard):\n> ";
		std::cin >> difficulty;
	}
	return difficulty;
}