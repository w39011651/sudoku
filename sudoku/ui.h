#ifndef UI_H
#define UI_H

#include <string>
#include <utility> // For std::pair

// Forward declaration to avoid including the full SudokuGame.h here
// This can help reduce compile times and unnecessary dependencies.
class SudokuGame;

namespace ui 
{

    // �M�Ų׺ݾ��e��
    void clearScreen();

    // ����w��T��
    void displayWelcomeMessage();

	void displayCompletionMessage();

    // ��ܾ�ӼƿW�ѽL
    // �`�N�G�ڭ̶ǤJ const SudokuGame& ��Ū���C�����A
    void displayBoard(const SudokuGame& game);

    // �V�ϥΪ���ܤ@���T���]�Ҧp���~�Ϊ��A��s�^
    void displayMessage(const std::string& message);

    // ���ܨϥΪ̿�J�A�æ^�ǥL�̪����
    // �^�Ǥ@�ӥ]�t <row, col, num> �����c�Τ���
    struct Move {
        int row;
        int col;
        int num;
    };
    Move promptMove();

    // ���ܨϥΪ̿������
    int promptDifficulty();

} // namespace ui

#endif