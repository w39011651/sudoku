#include "ui.h"
#include "SudokuGame.h"
#include <iostream>
#include "constants.h"

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
void ui::displayBoard(const SudokuGame& game)
{
    ui::clearScreen();
    std::cout << "+-------+-------+-------+" << std::endl;
    for (int i = 0; i < SUDOKU_SIZE; ++i) {
        std::cout << "| ";
        for (int j = 0; j < SUDOKU_SIZE; ++j) {
            // �ϥ� getter �禡�A�Ӥ��O�����s�� board
            int cellValue = game.getCell(i, j);
            bool isFixed = game.isCellFixed(i, j);

            if (cellValue == EMPTY_CELL) {
                std::cout << ". ";
            }
            else {
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

ui::Move ui::promptMove()
{
	ui::Move move;
	std::cout << "Enter your move (row, column, number): ";
	std::cin >> move.row >> move.col >> move.num;
	// �ˬd��J�O�_����
	while (move.row < 0 || move.row >= 9 || move.col < 0 || move.col >= 9 || move.num < 1 || move.num > 9) 
	{
		std::cout << "Invalid input. Please enter again (row, column, number): ";
		std::cin >> move.row >> move.col >> move.num;
	}
	return move;
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