#include "../include/log.h"
#include "../include/color.h"

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
