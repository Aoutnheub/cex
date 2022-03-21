#include <iostream>
#include "../include/args.h"

int main(int argc, char **argv) {
    cex::ArgParser parser("Test", "Test program");
    parser.addCommand("test", "Test command");
    parser.addFlag("one-file", "Test flag", 'S');
    parser.addFlag("quit", "Test flag", '\0');
    parser.addFlag("recursive", "Test flag", 'R');
    parser.addFlag("help", "Print this message", 'h');
    parser.addOption("output", "Test option", 'o', "", {});
    parser.addOption("type", "Test option", 't', "type1", {"type1", "type2"});
    parser.addOption("count", "Test option", '\0', "1", {});

    // parser.commands_help_msg = "";
    // parser.flags_help_msg = "";
    // parser.options_help_msg = "";
    // parser.colors = true;
    parser.description_color = cex::Color::Yellow;
    parser.header_color = cex::Color::Red;
    parser.commands_description_color = cex::Color::Yellow;
    parser.flags_description_color = cex::Color::Yellow;
    parser.options_description_color = cex::Color::Yellow;

    // parser.command_required = true;
    cex::ArgResults results = parser.parse(argv + 1, argc - 1);

    if(results.flag["help"]) {
        // std::cout << parser.helpString();
        parser.help();
    }else {
        std::cout << "command: " << results.command << "\n\n";
        std::cout << "flags\n-----------\n";
        for(auto i : results.flag) {
            std::cout << i.first << " : " << i.second << '\n';
        }
        std::cout << "\noptions\n-----------\n";
        for(auto i : results.option) {
            std::cout << i.first << " : " << i.second << '\n';
        }
        std::cout << "\npositional\n-----------\n";
        for(auto i : results.positional) {
            std::cout << i << '\n';
        }
    }
}
