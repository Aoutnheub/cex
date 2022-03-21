#include "../include/color.h"

int main(int argc, char **argv) {
    cex::Color::set(cex::Color::BG_White);
    cex::Color::set(cex::Color::Black);
    std::cout << "Black\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Red);
    std::cout << "Red\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Green);
    std::cout << "Green\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Yellow);
    std::cout << "Yellow\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Blue);
    std::cout << "Blue\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Magenta);
    std::cout << "Magenta\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Cyan);
    std::cout << "Cyan\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::White);
    std::cout << "White\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::White);
    cex::Color::set(cex::Color::BG_Black);
    std::cout << "Bg Black\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::BG_Red);
    std::cout << "Bg Red\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::BG_Green);
    std::cout << "Bg Green\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::BG_Yellow);
    std::cout << "Bg Yellow\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::BG_Blue);
    std::cout << "Bg Blue\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::BG_Magenta);
    std::cout << "Bg Magenta\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::BG_Cyan);
    std::cout << "Bg Cyan\n";
    cex::Color::clear();

    cex::Color::set(cex::Color::Black);
    cex::Color::set(cex::Color::BG_White);
    std::cout << "Bg White\n";
    cex::Color::clear();
}
