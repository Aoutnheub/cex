#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/colors.h"

cex::Color::Color() {}

#ifdef _WIN32
void *cex::Color::console_handle_ = nullptr;
int cex::Color::initial_color_ = 0;
int cex::Color::last_color_ = 0;

const int cex::Color::colors_[16] = {
    0,
    FOREGROUND_RED,
    FOREGROUND_GREEN,
    FOREGROUND_RED | FOREGROUND_GREEN,
    FOREGROUND_BLUE,
    FOREGROUND_RED | FOREGROUND_BLUE,
    FOREGROUND_GREEN | FOREGROUND_BLUE,
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    0,
    BACKGROUND_RED,
    BACKGROUND_GREEN,
    BACKGROUND_RED | BACKGROUND_GREEN,
    BACKGROUND_BLUE,
    BACKGROUND_RED | BACKGROUND_BLUE,
    BACKGROUND_GREEN | BACKGROUND_BLUE,
    BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
}

void cex::Color::init() {
    *((Handle*)console_handle_) = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(*((Handle*)console_handle_), &csbi);
    initial_color_ = csbi.wAttributes;
}

void cex::Color::set(cex::Color::ColorCode _color) {
    int color = last_color_ | colors_[_color];
    SetConsoleTextAttribute(*((Handle*)console_handle_), color);
    last_color_ = color;
}

void cex::Color::set(std::ostream &_stream, cex::Color::ColorCode _color) {
    int color = last_color_ | colors_[_color];
    SetConsoleTextAttribute(*((Handle*)console_handle_), color);
    last_color_ = color;
}

void cex::Color::clear() {
    SetConsoleTextAttribute(*((Handle*)console_handle_), initial_color_);
    last_color_ = 0;
}

void cex::Color::clear(std::ostream &_stream) {
    SetConsoleTextAttribute(*((Handle*)console_handle_), initial_color_);
    last_color_ = 0;
}
#else
const char cex::Color::colors_[16][6] = {
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
    "\033[40m",
    "\033[41m",
    "\033[42m",
    "\033[43m",
    "\033[44m",
    "\033[45m",
    "\033[46m",
    "\033[47m"
};

void cex::Color::set(cex::Color::ColorCode _color) {
    std::cout << colors_[_color];
}

void cex::Color::set(std::ostream &_stream, cex::Color::ColorCode _color) {
    _stream << colors_[_color];
}

void cex::Color::clear() {
    std::cout << "\033[0m";
}

void cex::Color::clear(std::ostream &_stream) {
    std::cout << "\033[0m";
}
#endif
