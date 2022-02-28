#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/color.h"

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

void cex::Color::clear() {
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

void cex::Color::clear() {
    std::cout << "\033[0m";
}
#endif

cex::Log::Log() {}

std::string cex::Log::info_msg = "Info";
std::string cex::Log::warning_msg = "Warning";
std::string cex::Log::error_msg = "Error";

void cex::Log::black(std::string _str) {
    cex::Color::set(cex::Color::Black);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::red(std::string _str) {
    cex::Color::set(cex::Color::Red);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::green(std::string _str) {
    cex::Color::set(cex::Color::Green);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::yellow(std::string _str) {
    cex::Color::set(cex::Color::Yellow);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::blue(std::string _str) {
    cex::Color::set(cex::Color::Blue);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::magenta(std::string _str) {
    cex::Color::set(cex::Color::Magenta);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::cyan(std::string _str) {
    cex::Color::set(cex::Color::Cyan);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::white(std::string _str) {
    cex::Color::set(cex::Color::White);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgBlack(std::string _str) {
    cex::Color::set(cex::Color::BG_Black);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgRed(std::string _str) {
    cex::Color::set(cex::Color::BG_Red);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgGreen(std::string _str) {
    cex::Color::set(cex::Color::BG_Green);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgYellow(std::string _str) {
    cex::Color::set(cex::Color::BG_Yellow);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgBlue(std::string _str) {
    cex::Color::set(cex::Color::BG_Blue);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgMagenta(std::string _str) {
    cex::Color::set(cex::Color::BG_Magenta);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgCyan(std::string _str) {
    cex::Color::set(cex::Color::BG_Cyan);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::bgWhite(std::string _str) {
    cex::Color::set(cex::Color::BG_White);
    std::cout << _str;
    cex::Color::clear();
}

void cex::Log::info(std::string _str) {
    std::cout << "[";
    cex::Color::set(cex::Color::Blue);
    std::cout << info_msg;
    cex::Color::clear();
    std::cout << "] " << _str;
}

void cex::Log::warning(std::string _str) {
    std::cout << "[";
    cex::Color::set(cex::Color::Yellow);
    std::cout << warning_msg;
    cex::Color::clear();
    std::cout << "] " << _str;
}

void cex::Log::error(std::string _str) {
    std::cout << "[";
    cex::Color::set(cex::Color::Red);
    std::cout << error_msg;
    cex::Color::clear();
    std::cout << "] " << _str;
}
