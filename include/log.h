#pragma once
#include <string>

namespace cex {
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
}
