# sudoku

Environment:

- OS: Windows 11
- Compiler: MSVC
- IDE: Microsoft Studio 2022

---

# 使用C/C++打造的命令列數獨遊戲

使用 `w`, `a`, `s`, `d`上下左右移動

在對應的格子輸入數字

使用 `0`, `backspace`或者空格鍵移除數字

使用 `q` 結束遊戲

---

# 文件結構

```
├── .gitattributes
├── .gitignore
├── LICENSE.txt
├── README.md
├── sudoku.sln
├──sudoku
    ├── sudoku.vcxproj // visual studio file
    ├── sudoku.vcxproj.filters //visual studio file
    ├──src
        ├── SudokuGame.cpp // 遊戲核心邏輯
        ├── SudokuGame.h //Class定義
        ├── constants.h //枚舉常數
        ├── main.cpp // 程式進入點以及遊戲程式主邏輯
        ├── ui.cpp // 使用者介面邏輯
        ├── ui.h // 使用者介面定義
```
