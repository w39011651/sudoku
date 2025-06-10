#ifndef UI_H
#define UI_H

#include <string>
#include <utility> // For std::pair

// Forward declaration to avoid including the full SudokuGame.h here
// This can help reduce compile times and unnecessary dependencies.
class SudokuGame;

namespace ui 
{
	// ===== �C�����������禡�ŧi =====
    // �M�Ų׺ݾ��e��
    void clearScreen();

    // ����w��T��
    void displayWelcomeMessage();

	void displayCompletionMessage();

    // ��ܾ�ӼƿW�ѽL
    // �`�N�G�ڭ̶ǤJ const SudokuGame& ��Ū���C�����A
    void displayBoard(const SudokuGame& game, int x, int y);

    // �V�ϥΪ���ܤ@���T���]�Ҧp���~�Ϊ��A��s�^
    void displayMessage(const std::string& message);

    // ���ܨϥΪ̿�J�A�æ^�ǥL�̪����
    // �^�Ǥ@�ӥ]�t <row, col, num> �����c�Τ���
	void runGame(SudokuGame& game);

    // ���ܨϥΪ̿������
    int promptDifficulty();
    // ===== �C�����������禡�ŧi =====
    // 
    // 
    // ===== �s�W���禡�ŧi =====
    void displayMainMenu();
    void displayInstructions();
    void displaySeed();
    // ===========================
} // namespace ui

#endif