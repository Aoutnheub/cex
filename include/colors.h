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
            static void set(std::ostream &_stream, cex::Color::ColorCode _color);
            static void clear();
            static void clear(std::ostream &_stream);
    };

};
