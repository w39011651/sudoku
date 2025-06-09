#include "SudokuGame.h"
#include <iostream>
#include <ctime>
#include <array>
#include "constants.h"
// Initializes the game with a given puzzle  

SudokuGame::SudokuGame(int difficulty = 0)
{
	initializePuzzle();
	solve();
	generatePuzzle(difficulty);
}

SudokuGame::~SudokuGame()
{
	delete this;
}

void SudokuGame::initializePuzzle()
{
	for (int i = 0; i < SUDOKU_SIZE; ++i)
		for (int j = 0; j < SUDOKU_SIZE; ++j)
		{
			(*this).board[i][j] = EMPTY_CELL; // Initialize the board with zeros
			(*this).isFixed[i][j] = true; // Initialize the fixed flags
		}
}
// Checks if the current state of the board is valid  
bool SudokuGame::isValid() const
{
	return true;
}
// Solves the Sudoku puzzle  
bool SudokuGame::solve()
{
	return fill_board(0); // Start filling the board from position 0
}

// 獲取指定位置的數字
int SudokuGame::getCell(int row, int col) const
{
	if (row < 0 || row >= 9 || col < 0 || col >= 9)
	{
		std::cerr << "Invalid cell position!" << std::endl;
		return -1; // Return an invalid value
	}
	return board[row][col]; // Return the number at the specified cell
}

// 檢查指定位置的數字是否為題目固定的
bool SudokuGame::isCellFixed(int row, int col) const
{
	if (row < 0 || row >= 9 || col < 0 || col >= 9)
	{
		std::cerr << "Invalid cell position!" << std::endl;
		return false; // Return false for invalid positions
	}
	return isFixed[row][col]; // Return whether the cell is fixed
}

bool SudokuGame::setCell(int row, int col, int num)
{
	if (!isValidMove(row, col, num))
	{
		std::cerr << "Invalid move!" << std::endl;
		return false; // Return false if the move is invalid
	}
	board[row][col] = num; // Set the number in the specified cell
	return true;
}

std::array<int, SUDOKU_SIZE> SudokuGame::shuffle(int n) 
{
	std::array<int, SUDOKU_SIZE> array = {};
	for (int i = 0; i < SUDOKU_SIZE; i++) array[i] = i + 1;
	for (int i = n - 1; i > 0; i--) 
	{
		int j = rand() % (i + 1); // 0 ~ i: random pick index in the array
		int t = array[i]; // swap the elements at index i and j
		array[i] = array[j];
		array[j] = t;
	}
	return array;
}

int SudokuGame::fill_board(int pos)
{
	if (pos == 81) return 1;
	int row = pos / SUDOKU_SIZE, col = pos % SUDOKU_SIZE;
	std::array<int, SUDOKU_SIZE> nums = shuffle(SUDOKU_SIZE); // Shuffle numbers 1-SUDOKU_SIZE
	for (int i = 0; i < SUDOKU_SIZE; i++) 
	{
		if (this->isValidMove(row, col, nums[i]))
		{
			board[row][col] = nums[i];
			if (fill_board(pos + 1)) return 1;
			board[row][col] = 0;
		}
	}
	return 0;
}


// 遊戲邏輯函式
void SudokuGame::generatePuzzle(int difficulty)
{
	if (difficulty == 0)
		holes = 10;
	else if (difficulty == 1)
		holes = 30;
	else if (difficulty == 2)
		holes = 45;

	int count = 0;
	while (count < holes) {
		int i = rand() % SUDOKU_SIZE;
		int j = rand() % SUDOKU_SIZE;
		if (this->board[i][j] != 0) 
		{
			this->board[i][j] = 0;
			this->isFixed[i][j] = false;
			count++;
		}
	}
}

bool SudokuGame::isValidMove(int row, int col, int num)
{
	//check row
	for (int i = 0; i < SUDOKU_SIZE; ++i)
	{
		if ((*this).board[row][i] == num)
			return false;
	}
	//check column
	for (int i = 0; i < SUDOKU_SIZE; ++i)
	{
		if ((*this).board[i][col] == num)
			return false;
	}
	//check 3x3 box
	int boxRowStart = (row / 3) * 3;
	int boxColStart = (col / 3) * 3;
	for (int i = boxRowStart; i < boxRowStart + 3; ++i)
	{
		for (int j = boxColStart; j < boxColStart + 3; ++j)
		{
			if ((*this).board[i][j] == num)
				return false;
		}
	}

	// If all checks passed, the move is valid
	(*this).board[row][col] = num; // Place the number temporarily
	(*this).isFixed[row][col] = true; // Mark the cell as fixed
	(*this).holes--; // Decrease the number of holes

	return true;
}

bool SudokuGame::isSolved()
{
	return this->holes == 0;
}

void SudokuGame::handleInput()
{
	return;
}


