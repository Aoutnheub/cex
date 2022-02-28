#include "../include/color.h"

int main(int argc, char **argv) {
    cex::Color::set(cex::Color::BG_White);
    cex::Log::black("Black\n");

    cex::Log::red("Red\n");

    cex::Log::green("Green\n");

    cex::Log::yellow("Yellow\n");

    cex::Log::blue("Blue\n");

    cex::Log::magenta("Magenta\n");

    cex::Log::cyan("Cyan\n");

    cex::Log::white("White\n");

    cex::Color::set(cex::Color::White);
    cex::Log::bgBlack("Bg Black\n");

    cex::Log::bgRed("Bg Red\n");

    cex::Log::bgGreen("Bg Green\n");

    cex::Log::bgYellow("Bg Yellow\n");

    cex::Log::bgBlue("Bg Blue\n");

    cex::Log::bgMagenta("Bg Magenta\n");

    cex::Log::bgCyan("Bg Cyan\n");

    cex::Color::set(cex::Color::Black);
    cex::Log::bgWhite("Bg White\n");

    cex::Log::info("This is some info!\n");
    cex::Log::warning("This is a warning!\n");
    cex::Log::error("This is an error!\n");
}
