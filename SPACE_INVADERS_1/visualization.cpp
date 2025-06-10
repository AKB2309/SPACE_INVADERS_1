#include <windows.h>
#include "visualization.h"
#include <iostream>
using namespace std;


HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);

void draw_char(char ch, int y, int x, COLORS foreground_color, COLORS background_color) {
    CHAR_INFO ch_info;
    ch_info.Char.UnicodeChar = ch;
    ch_info.Attributes = foreground_color | (background_color << 4);

    COORD buf_size = { 1, 1 };
    COORD buf_coord = { 0, 0 };
    SMALL_RECT screen_pos = { x, y, x + 1, y + 1 };
    ::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);
}

void draw_text(const std::string& text, int x, int y, COLORS color)
{
    for (int i = 0; i < text.length(); i++)
    {
        draw_char(text[i], y, x + i, color, BLACK);
    }
}

void LockConsoleSize(int width, int height) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

    SMALL_RECT windowRect = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    SetConsoleWindowInfo(hConsoleOutput, TRUE, &windowRect);

    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_SIZEBOX);

}
