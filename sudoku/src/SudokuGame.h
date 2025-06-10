#ifndef SUDOKUGAME_H  
#define SUDOKUGAME_H  
#include <array>
#include "constants.h"

class SudokuGame  
{  
public:  
  SudokuGame(int difficulty);
  ~SudokuGame();  
  // Initializes the game with a given puzzle  
  void initializePuzzle();  
  // Checks if the current state of the board is valid  
  bool isValid() const;  
  // Solves the Sudoku puzzle  
  bool solve();  

  // ������w��m���Ʀr
  int getCell(int row, int col) const;

  // �ˬd���w��m���Ʀr�O�_���D�ةT�w��
  bool isCellFixed(int row, int col) const;

  bool isSolved();

  bool setCell(int row, int col, int num);

private:  
  std::array<std::array<int, SUDOKU_SIZE>, SUDOKU_SIZE> board; // 2D array to represent the Sudoku board 
  std::array<std::array<bool, SUDOKU_SIZE>, SUDOKU_SIZE> isFixed; // Flags for rows
  int holes = 0; // Number of holes in the puzzle
  // �C���޿�禡
  void generatePuzzle(int difficulty);
  bool isValidMove(int row, int col, int num);


  void handleInput();
  std::array<int, SUDOKU_SIZE> shuffle(int n);
  int fill_board(int pos);
  
};  

#endif // SUDOKUGAME_H
