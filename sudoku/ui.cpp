#include "ui.h"
#include "SudokuGame.h"
#include <iostream>
#include "constants.h"

// 清空終端機畫面
void ui::clearScreen()
{
	system("cls");
}

// 顯示歡迎訊息
void ui::displayWelcomeMessage()
{
	std::cout << "Welcome to Sudoku!\n";
}

void ui::displayCompletionMessage()
{
	std::cout << "Congratulations! You have completed the Sudoku puzzle!\n";
}

// 顯示整個數獨棋盤
// 注意：我們傳入 const SudokuGame& 來讀取遊戲狀態
void ui::displayBoard(const SudokuGame& game)
{
    ui::clearScreen();
    std::cout << "+-------+-------+-------+" << std::endl;
    for (int i = 0; i < SUDOKU_SIZE; ++i) {
        std::cout << "| ";
        for (int j = 0; j < SUDOKU_SIZE; ++j) {
            // 使用 getter 函式，而不是直接存取 board
            int cellValue = game.getCell(i, j);
            bool isFixed = game.isCellFixed(i, j);

            if (cellValue == EMPTY_CELL) {
                std::cout << ". ";
            }
            else {
                // 可以根據 isFixed 改變顏色
                // 例如，固定的數字用不同顏色打印
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

// 向使用者顯示一條訊息（例如錯誤或狀態更新）
void ui::displayMessage(const std::string& message)
{
	std::cout << message << std::endl;
}

ui::Move ui::promptMove()
{
	ui::Move move;
	std::cout << "Enter your move (row, column, number): ";
	std::cin >> move.row >> move.col >> move.num;
	// 檢查輸入是否有效
	while (move.row < 0 || move.row >= 9 || move.col < 0 || move.col >= 9 || move.num < 1 || move.num > 9) 
	{
		std::cout << "Invalid input. Please enter again (row, column, number): ";
		std::cin >> move.row >> move.col >> move.num;
	}
	return move;
}

// 提示使用者選擇難度
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