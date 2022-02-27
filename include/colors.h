#pragma once
#include <iostream>

namespace cex {
    class Color {
        private:
            #ifdef _WIN32
            static void *console_handle_;
            static int initial_color_;
            static int last_color_;
            static const int colors_[16];
            #else
            static const char colors_[16][6];
            #endif

            Color();

        public:
            enum ColorCode {
                Black = 0,
                Red = 1,
                Green = 2,
                Yellow = 3,
                Blue = 4,
                Magenta = 5,
                Cyan = 6,
                White = 7,
                BG_Black = 8,
                BG_Red = 9,
                BG_Green = 10,
                BG_Yellow = 11,
                BG_Blue = 12,
                BG_Magenta = 13,
                BG_Cyan = 14,
                BG_White = 15,
            };

            #ifdef _WIN32
            static void init();
            #endif
            static void set(cex::Color::ColorCode _color);
            static void clear();
    };

    class Log {
        private:
            Log();

        public:
            static std::string info_msg;
            static std::string warning_msg;
            static std::string error_msg;

            static void black(std::string _str);
            static void red(std::string _str);
            static void green(std::string _str);
            static void yellow(std::string _str);
            static void blue(std::string _str);
            static void magenta(std::string _str);
            static void cyan(std::string _str);
            static void white(std::string _str);
            static void bgBlack(std::string _str);
            static void bgRed(std::string _str);
            static void bgGreen(std::string _str);
            static void bgYellow(std::string _str);
            static void bgBlue(std::string _str);
            static void bgMagenta(std::string _str);
            static void bgCyan(std::string _str);
            static void bgWhite(std::string _str);

            static void info(std::string _str);
            static void warning(std::string _str);
            static void error(std::string _str);
    };
};
