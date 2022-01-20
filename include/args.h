#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>
#include <cerrno>

namespace cex {
    class invalid_argument : public std::exception {
        private:
            std::string arg_;
            std::string err_;

        public:
            invalid_argument(const std::string &_arg);
            invalid_argument(const std::string &_arg, const std::string &_err);
            const char* what() const throw() override;
            const char* which() const throw();
    };

    class invalid_value : public std::exception {
        private:
            std::string arg_;
            std::string val_;
            std::string err_;

        public:
            invalid_value(const std::string &_arg, const std::string &_val);
            invalid_value(const std::string &_arg, const std::string &_val, const std::string &_err);
            const char* what() const throw() override;
            const char* which() const throw();
            const char* with() const throw();
    };

    class missing_value : public std::exception {
        private:
            std::string arg_;
            std::string err_;

        public:
            missing_value(const std::string &_arg);
            missing_value(const std::string &_arg, const std::string &_err);
            const char* what() const throw() override;
            const char* which() const throw();
    };

    class duplicate_argument : public std::exception {
        private:
            std::string arg_;
            std::string err_;

        public:
            duplicate_argument(const std::string &_arg);
            duplicate_argument(const std::string &_arg, const std::string &_err);
            const char* what() const throw() override;
            const char* which() const throw();
    };

    class ArgResults {
        public:
            std::unordered_map<std::string, bool> flag;
            std::unordered_map<std::string, std::string> option;
            std::vector<std::string> positional;
            std::string command;
    };

    class ArgParser {
        private:
            class ArgOption {
                public:
                    std::string help;
                    std::string defaults_to;
                    std::vector<std::string> allowed;

                    ArgOption(
                        const std::string &_help = "", const std::string &_defaults_to = "",
                        const std::vector<std::string> &_allowed = {}
                    );
            };
            std::unordered_map<std::string, std::string> flags_;
            std::unordered_map<char, std::string> flags_abbr_;
            std::unordered_map<std::string, ArgOption> options_;
            std::unordered_map<char, std::string> options_abbr_;
            std::unordered_map<std::string, std::string> commands_;
            std::vector<std::string> positional_;
            std::string name_;
            std::string description_;

            std::unordered_map<std::string, char> getFlagsAbbr();
            std::unordered_map<std::string, char> getOptionsAbbr();
            bool isAllowedOptionValue(const std::string &_opt, const std::string &_val);
            void splitDesc(std::string &_help, std::string &_desc);

        public:
            unsigned max_line_length = 80;
            bool command_required = false;

            ArgParser(const std::string &_name = "", const std::string &_description = "");
            ~ArgParser();

            void addFlag(
                const std::string &_name, const std::string &_help = "",
                const char &_abbr = '\0'
            );
            void addOption(
                const std::string &_name, const std::string &_help = "",
                const char &_abbr = '\0', const std::string &_defaults_to = "",
                const std::vector<std::string> &_allowed = {}
            );
            void addCommand(const std::string &_name, const std::string &_help = "");
            std::string help();
            ArgResults parse(const std::vector<std::string> &_args);
            ArgResults parse(char **_args, const std::size_t _size);
    };
}
