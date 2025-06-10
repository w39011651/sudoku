#ifndef UI_H
#define UI_H

#include <string>
#include <utility> // For std::pair

// Forward declaration to avoid including the full SudokuGame.h here
// This can help reduce compile times and unnecessary dependencies.
class SudokuGame;

namespace ui 
{
	// ===== 遊戲介面相關函式宣告 =====
    // 清空終端機畫面
    void clearScreen();

    // 顯示歡迎訊息
    void displayWelcomeMessage();

	void displayCompletionMessage();

    // 顯示整個數獨棋盤
    // 注意：我們傳入 const SudokuGame& 來讀取遊戲狀態
    void displayBoard(const SudokuGame& game, int x, int y);

    // 向使用者顯示一條訊息（例如錯誤或狀態更新）
    void displayMessage(const std::string& message);

    // 提示使用者輸入，並回傳他們的選擇
    // 回傳一個包含 <row, col, num> 的結構或元組
	void runGame(SudokuGame& game);

    // 提示使用者選擇難度
    int promptDifficulty();
    // ===== 遊戲介面相關函式宣告 =====
    // 
    // 
    // ===== 新增的函式宣告 =====
    void displayMainMenu();
    void displayInstructions();
    void displaySeed();
    // ===========================
} // namespace ui

#endif