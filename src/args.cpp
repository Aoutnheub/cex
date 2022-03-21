#include "../include/args.h"

// +------------+
// | Exceptions |
// +------------+

// Invalid argument
cex::invalid_argument::invalid_argument(const std::string &_arg) : arg_(_arg) {
    err_ = "argument \"" + arg_ + "\" does not exist";
}

cex::invalid_argument::invalid_argument(const std::string &_arg, const std::string &_err)
    : arg_(_arg), err_(_err) {}

const char* cex::invalid_argument::what() const throw() {
    return err_.c_str();
}

const char* cex::invalid_argument::which() const throw() {
    return arg_.c_str();
}

// Invalid value
cex::invalid_value::invalid_value(const std::string &_arg, const std::string &_val)
    : arg_(_arg), val_(_val) {
    err_ = "\"" + _val + "\" is not an allowed value for argument \"" + _arg + "\"";
}

cex::invalid_value::invalid_value(
    const std::string &_arg, const std::string &_val, const std::string &_err
) : arg_(_arg), val_(_val), err_(_err) {}

const char* cex::invalid_value::what() const throw() {
    return err_.c_str();
}

const char* cex::invalid_value::which() const throw() {
    return arg_.c_str();
}

const char* cex::invalid_value::with() const throw() {
    return val_.c_str();
}

// Missing value
cex::missing_value::missing_value(const std::string &_arg) : arg_(_arg) {
    err_ = "no value provided for argument \"" + arg_ + "\"";
}

cex::missing_value::missing_value(const std::string &_arg, const std::string &_err)
    : arg_(_arg), err_(_err) {}

const char* cex::missing_value::what() const throw() {
    return err_.c_str();
}

const char* cex::missing_value::which() const throw() {
    return arg_.c_str();
}

// Duplicate argument
cex::duplicate_argument::duplicate_argument(const std::string &_arg) : arg_(_arg) {
    err_ = "argument \"" + arg_ + "\" already exists";
}

cex::duplicate_argument::duplicate_argument(const std::string &_arg, const std::string &_err)
    : arg_(_arg), err_(_err) {}

const char* cex::duplicate_argument::what() const throw() {
    return err_.c_str();
}

const char* cex::duplicate_argument::which() const throw() {
    return arg_.c_str();
}

// +------+
// | Args |
// +------+

// Option
cex::ArgParser::ArgOption::ArgOption(
    const std::string &_help,
    const std::string &_defaults_to,
    const std::vector<std::string> &_allowed
) : defaults_to(_defaults_to), allowed(_allowed) {
    help = _help;
}

// Parser
cex::ArgParser::ArgParser(const std::string &_name, const std::string &_description)
    : name_(_name), description_(_description) {}

cex::ArgParser::~ArgParser() {}

std::unordered_map<std::string, char> cex::ArgParser::getFlagsAbbr() {
    std::unordered_map<std::string, char> abbr;
    for(auto i = flags_abbr_.begin(); i != flags_abbr_.end(); ++i) {
        abbr.insert({i->second, i->first});
    }

    return abbr;
}

std::unordered_map<std::string, char> cex::ArgParser::getOptionsAbbr() {
    std::unordered_map<std::string, char> abbr;
    for(auto i = options_abbr_.begin(); i != options_abbr_.end(); ++i) {
        abbr.insert({i->second, i->first});
    }

    return abbr;
}

bool cex::ArgParser::isAllowedOptionValue(const std::string &_opt, const std::string &_val) {
    auto op = options_.at(_opt);
    unsigned al_len = options_.at(_opt).allowed.size();
    bool allowed = false;
    if(al_len != 0) {
        for(unsigned i = 0; i < al_len; ++i) {
            if(op.allowed[i] == _val) {
                allowed = true;
                break;
            }
        }
    }else {
        allowed = true;
    }

    return allowed;
}

void cex::ArgParser::splitDesc(std::string &_help, std::string &_desc) {
    std::size_t desc_length = _desc.length();
    std::size_t last = 0;
    int line_length = max_line_length-8;
    std::string indent = "        ";
    while(desc_length > line_length) {
        std::size_t token;
        if(last+line_length >= last+desc_length) {
            _help += indent + _desc.substr(last) + '\n';
            break;
        }else {
            token = _desc.rfind(" ", last+line_length);
        }
        if(token != std::string::npos && token > last) {
            _help += indent + _desc.substr(last, token-last) + '\n';
            desc_length -= token-last-1;
            last = token+1;
        }else {
            _help += indent + _desc.substr(last) + '\n';
            break;
        }
    }
    _help += indent + _desc.substr(last) + '\n';
}

// Adding
void cex::ArgParser::addFlag(const std::string &_name, const std::string &_help, const char &_abbr) {
    if(flags_.find(_name) == flags_.end() && options_.find(_name) == options_.end()) {
        flags_.insert({_name, _help});
        if(_abbr != '\0') {
            if(
                flags_abbr_.find(_abbr) == flags_abbr_.end() &&
                options_abbr_.find(_abbr) == options_abbr_.end()
            ) {
                flags_abbr_.insert({_abbr, _name});
            }else {
                std::string temp;
                temp = _abbr;
                throw cex::duplicate_argument(temp);
            }
        }
    }else {
        throw cex::duplicate_argument(_name);
    }
}

void cex::ArgParser::addOption(
    const std::string &_name,
    const std::string &_help,
    const char &_abbr,
    const std::string &_defaults_to,
    const std::vector<std::string> &_allowed
) {
    if(options_.find(_name) == options_.end() && flags_.find(_name) == flags_.end()) {
        ArgOption argo(_help, _defaults_to, _allowed);
        options_.insert({_name, argo});
        if(_abbr != '\0') {
            if(
                flags_abbr_.find(_abbr) == flags_abbr_.end() &&
                options_abbr_.find(_abbr) == options_abbr_.end()
            ) {
                options_abbr_.insert({_abbr, _name});
            }else {
                std::string temp;
                temp = _abbr;
                throw cex::duplicate_argument(temp);
            }
        }
    }else {
        throw cex::duplicate_argument(_name);
    }
}

void cex::ArgParser::addCommand(const std::string &_name, const std::string &_help) {
    if(commands_.find(_name) == commands_.end()) {
        commands_.insert({_name, _help});
    }else {
        throw cex::duplicate_argument(_name);
    }
}

void cex::ArgParser::help() {
    if(!name_.empty()) {
        if(colors) {
            Color::set(title_color);
            std::cout << name_;
            Color::clear();
        }else {
            std::cout << name_;
        }
    }
    if(!description_.empty()) {
        if(colors) Color::set(description_color);
        std::cout << " - ";
        if(max_line_length != 0) {
            std::size_t desc_len = description_.length();
            std::size_t line_len = max_line_length - name_.length() - 3;
            if(description_.length() > max_line_length - name_.length() - 3) {
                std::string indent;
                for(std::size_t i = 0; i < name_.length() + 3; ++i) {
                    indent += " ";
                }
                std::cout << indent << description_.substr(0, line_len) << '\n';
                unsigned cuts = 1;
                while(true) {
                    if(cuts * line_len + line_len > desc_len) {
                        std::cout << indent << description_.substr(cuts * line_len) << '\n';
                        break;
                    }else {
                        std::cout << indent << description_.substr(cuts * line_len, line_len);
                    }
                }
            }else {
                std::cout << description_ << '\n';
            }
        }
        if(colors) Color::clear();
    }
    std::cout << "\n";

    if(!commands_.empty()) {
        if(!commands_help_msg.empty())
            if(colors) {
                Color::set(header_color);
                std::cout << commands_help_msg << "\n\n";
                Color::clear();
            }else {
                std::cout << commands_help_msg << "\n\n";
            }
        for(auto i = commands_.begin(); i != commands_.end(); ++i) {
            if(colors) Color::set(commands_color);
            std::cout << "    " << i->first << '\n';
            std::string indent = "        ";
            if(colors) {
                Color::clear();
                Color::set(commands_description_color);
            }
            if(i->second.length() > max_line_length - 8) {
                std::string tmp;
                splitDesc(tmp, i->second);
                std::cout << tmp;
            }else {
                std::cout << indent << i->second << '\n';
            }
            if(colors) Color::clear();
            std::cout << '\n';
        }
    }

    if(!flags_.empty()) {
        std::unordered_map<std::string, char> abbr = getFlagsAbbr();
        if(!flags_help_msg.empty())
            if(colors) {
                Color::set(header_color);
                std::cout << flags_help_msg << "\n\n";
                Color::clear();
            }else {
                std::cout << flags_help_msg << "\n\n";
            }
        for(auto i = flags_.begin(); i != flags_.end(); ++i) {
            if(colors) Color::set(flags_color);
            std::cout << "    --" + i->first;
            auto tmp = abbr.find(i->first);
            if(tmp != abbr.end()) {
                std::cout << ", -" << tmp->second;
            }
            std::cout << '\n';
            std::string indent = "        ";
            if(colors) {
                Color::clear();
                Color::set(flags_description_color);
            }
            if(i->second.length() > max_line_length - 8) {
                std::string tmp;
                splitDesc(tmp, i->second);
                std::cout << tmp;
            }else {
                std::cout << indent + i->second + '\n';
            }
            if(colors) Color::clear();
            std::cout << '\n';
        }
    }

    if(!options_.empty()) {
        std::unordered_map<std::string, char> abbr = getOptionsAbbr();
        if(!options_help_msg.empty())
            if(colors) {
                Color::set(header_color);
                std::cout << options_help_msg << "\n\n";
                Color::clear();
            }else {
                std::cout << options_help_msg << "\n\n";
            }
        for(auto i = options_.begin(); i != options_.end(); ++i) {
            if(colors) Color::set(options_color);
            std::cout << "    --" + i->first;
            auto tmp = abbr.find(i->first);
            if(tmp != abbr.end()) {
                std::cout << ", -" << tmp->second;
            }
            if(!i->second.allowed.empty()) {
                std::cout << " ";
                for(std::size_t ii = 0; ii < i->second.allowed.size(); ++ii) {
                    if(ii != i->second.allowed.size() - 1) {
                        std::cout << i->second.allowed[ii] + "|";
                    }else {
                        std::cout << i->second.allowed[ii];
                    }
                }
            }
            std::cout << '\n';
            std::string indent = "        ";
            if(colors) {
                Color::clear();
                Color::set(options_description_color);
            }
            if(i->second.help.length() > max_line_length - 8) {
                std::string tmp;
                splitDesc(tmp, i->second.help);
                std::cout << tmp;
            }else {
                std::cout << indent + i->second.help + '\n';
            }
            if(colors) Color::clear();
            std::cout << '\n';
        }
    }
}

std::string cex::ArgParser::helpString() {
    if(!cached_help.empty()) {
        return cached_help;
    }
    if(!name_.empty()) {
        cached_help += name_;
    }
    if(!description_.empty()) {
        cached_help += " - ";
        if(max_line_length != 0) {
            std::size_t desc_len = description_.length();
            std::size_t line_len = max_line_length - name_.length() - 3;
            if(description_.length() > max_line_length - name_.length() - 3) {
                std::string indent;
                for(std::size_t i = 0; i < name_.length() + 3; ++i) {
                    indent += " ";
                }
                cached_help += indent + description_.substr(0, line_len) + '\n';
                unsigned cuts = 1;
                while(true) {
                    if(cuts * line_len + line_len > desc_len) {
                        cached_help += indent + description_.substr(cuts * line_len) + '\n';
                        break;
                    }else {
                        cached_help += indent + description_.substr(cuts * line_len, line_len);
                    }
                }
            }else {
                cached_help += description_ + '\n';
            }
        }
    }
    cached_help += "\n";

    if(!commands_.empty()) {
        if(!commands_help_msg.empty())
            cached_help += commands_help_msg + "\n\n";
        for(auto i = commands_.begin(); i != commands_.end(); ++i) {
            cached_help += "    "+i->first+'\n';
            std::string indent = "        ";
            if(i->second.length() > max_line_length - 8) {
                splitDesc(cached_help, i->second);
            }else {
                cached_help += indent + i->second + '\n';
            }
            cached_help += '\n';
        }
    }

    if(!flags_.empty()) {
        std::unordered_map<std::string, char> abbr = getFlagsAbbr();
        if(!flags_help_msg.empty())
            cached_help += flags_help_msg + "\n\n";
        for(auto i = flags_.begin(); i != flags_.end(); ++i) {
            cached_help += "    --" + i->first;
            auto tmp = abbr.find(i->first);
            if(tmp != abbr.end()) {
                cached_help += ", -";
                cached_help += tmp->second;
            }
            cached_help += '\n';
            std::string indent = "        ";
            if(i->second.length() > max_line_length - 8) {
                splitDesc(cached_help, i->second);
            }else {
                cached_help += indent + i->second + '\n';
            }
            cached_help += '\n';
        }
    }

    if(!options_.empty()) {
        std::unordered_map<std::string, char> abbr = getOptionsAbbr();
        if(!options_help_msg.empty())
            cached_help += options_help_msg + "\n\n";
        for(auto i = options_.begin(); i != options_.end(); ++i) {
            cached_help += "    --" + i->first;
            auto tmp = abbr.find(i->first);
            if(tmp != abbr.end()) {
                cached_help += ", -";
                cached_help += tmp->second;
            }
            if(!i->second.allowed.empty()) {
                cached_help += " ";
                for(std::size_t ii = 0; ii < i->second.allowed.size(); ++ii) {
                    if(ii != i->second.allowed.size() - 1) {
                        cached_help += i->second.allowed[ii] + "|";
                    }else {
                        cached_help += i->second.allowed[ii];
                    }
                }
            }
            cached_help += '\n';
            std::string indent = "        ";
            if(i->second.help.length() > max_line_length - 8) {
                splitDesc(cached_help, i->second.help);
            }else {
                cached_help += indent + i->second.help + '\n';
            }
            cached_help += '\n';
        }
    }

    return cached_help;
}

cex::ArgResults cex::ArgParser::parse(const std::vector<std::string> &_args) {
    ArgResults results;

    for(auto i = flags_.begin(); i != flags_.end(); ++i) {
        results.flag.insert({i->first, false});
    }
    for(auto i = options_.begin(); i != options_.end(); ++i) {
        results.option.insert({i->first, i->second.defaults_to});
    }

    std::size_t i = 0;
    bool skip_command_check = false;
    while(i < _args.size()) {
        std::size_t args_len = _args[i].length();
        if(!skip_command_check && i == 0 && !commands_.empty()) {
            if(commands_.find(_args[i]) != commands_.end()) {
                results.command = _args[i];
                ++i;
            }else {
                if(command_required) {
                    throw cex::invalid_argument(
                        _args[i], "\"" + _args[i] + "\" is not a command"
                    );
                }
            }
            skip_command_check = true;
        }else {
            if(_args[i] == "--") {
                for(std::size_t ii = i + 1; ii < _args.size(); ++ii) {
                    results.positional.push_back(_args[ii]);
                }
                i = _args.size();
            }else {
                if(args_len > 2) {
                    if(_args[i][0] == '-' && _args[i][1] != '-') {
                        std::size_t equals = _args[i].find('=');
                        if(equals != std::string::npos) {
                            if(equals == 2) { // option
                                auto fl = options_abbr_.find(_args[i][1]);
                                if(fl != options_abbr_.end()) {
                                    if(args_len > 3) {
                                        std::string temp = _args[i].substr(3);
                                        if(isAllowedOptionValue(fl->second, temp)) {
                                            results.option.at(fl->second) = temp;
                                            ++i;
                                        }else {
                                            std::string temp2;
                                            temp2 += _args[i][1];
                                            throw cex::invalid_value(temp2, temp);
                                        }
                                    }else {
                                        std::string temp;
                                        temp += _args[i][1];
                                        throw cex::missing_value(temp);
                                    }
                                }
                            }else { // multiple flags and one option
                                for(std::size_t ii = 1; ii < equals - 1; ++ii) {
                                    auto fl = flags_abbr_.find(_args[i][ii]);
                                    if(fl != flags_abbr_.end()) {
                                        results.flag.at(fl->second) = true;
                                    }else {
                                        std::string temp;
                                        temp += _args[i][ii];
                                        throw cex::invalid_argument(
                                            temp, "flag \""+temp+"\" does not exist"
                                        );
                                    }
                                }
                                if(equals + 1 < args_len) {
                                    auto fl = options_abbr_.find(_args[i][equals - 1]);
                                    if(fl != options_abbr_.end()) {
                                        std::string temp = _args[i].substr(equals + 1);
                                        if(isAllowedOptionValue(fl->second, temp)) {
                                            results.option.at(fl->second) = temp;
                                        }else {
                                            temp = "";
                                            temp += _args[i][1];
                                            throw cex::missing_value(temp);
                                        }
                                    }
                                }else {
                                    std::string temp;
                                    temp += _args[i][1];
                                    throw cex::missing_value(temp);
                                }
                                ++i;
                            }
                        }else { // option and value with no space
                            auto op = options_abbr_.find(_args[i][1]);
                            if(op != options_abbr_.end()) {
                                std::string temp = _args[i].substr(2);
                                if(isAllowedOptionValue(op->second, temp)) {
                                    results.option.at(op->second) = temp;
                                }else {
                                    temp = "";
                                    temp += _args[i][1];
                                    throw cex::missing_value(temp);
                                }
                            }else { // multiple flags
                                for(std::size_t ii = 1; ii < _args[i].length(); ++ii) {
                                    auto fl = flags_abbr_.find(_args[i][ii]);
                                    if(fl != flags_abbr_.end()) {
                                        results.flag.at(fl->second) = true;
                                    }else {
                                        std::string temp;
                                        temp += _args[i][ii];
                                        throw cex::invalid_argument(
                                            temp, "flag \"" + temp + "\" does not exist"
                                        );
                                    }
                                }
                            }
                            ++i;
                        }
                    }else if(_args[i][0] == '-' && _args[i][1] == '-') {
                        std::size_t equals = _args[i].find('=');
                        if(equals != std::string::npos) {
                            std::string op = _args[i].substr(2, equals - 2);
                            std::string val;
                            if(equals + 1 < args_len) {
                                val = _args[i].substr(equals + 1);
                            }else {
                                throw cex::missing_value(op);
                            }
                            if(isAllowedOptionValue(op, val)) {
                                results.option.at(op) = val;
                            }else {
                                throw cex::invalid_value(op, val);
                            }
                            ++i;
                        }else {
                            std::string arg = _args[i].substr(2);
                            auto fl = flags_.find(arg);
                            if(fl != flags_.end()) {
                                results.flag.at(arg) = true;
                                ++i;
                            }else {
                                auto op = options_.find(arg);
                                if(op != options_.end()) {
                                    if(i + 1 < _args.size()) {
                                        if(_args[i+1].length() == 0) {
                                            results.option.at(arg) = _args[i+1];
                                        }else {
                                            if(_args[i+1][0] != '-') {
                                                if(isAllowedOptionValue(arg, _args[i+1])) {
                                                    results.option.at(arg) = _args[i+1];
                                                }else {
                                                    throw cex::invalid_value(arg, _args[i+1]);
                                                }
                                            }else {
                                                throw cex::missing_value(_args[i].substr(2));
                                            }
                                        }
                                    }else {
                                        throw cex::missing_value(_args[i].substr(2));
                                    }
                                    i += 2;
                                }else {
                                    throw cex::invalid_argument(arg);
                                }
                            }
                        }
                    }else {
                        results.positional.push_back(_args[i]);
                        ++i;
                    }
                }else if(args_len == 2) {
                    if(_args[i][0] == '-') {
                        auto fl = flags_abbr_.find(_args[i][1]);
                        if(fl != flags_abbr_.end()) {
                            results.flag.at(fl->second) = true;
                            ++i;
                        }else {
                            auto op = options_abbr_.find(_args[i][1]);
                            if(op != options_abbr_.end()) {
                                if(i + 1 < _args.size()) {
                                    if(_args[i+1].length() == 0) {
                                        results.option.at(op->second) = _args[i+1];
                                    }else {
                                        if(_args[i+1][0] != '-') {
                                            results.option.at(op->second) = _args[i+1];
                                        }else {
                                            throw cex::missing_value(_args[i]);
                                        }
                                    }
                                }else {
                                    throw cex::missing_value(_args[i]);
                                }
                                i += 2;
                            }else {
                                std::string temp;
                                temp += _args[i][1];
                                throw cex::invalid_argument(temp);
                            }
                        }
                    }else {
                        results.positional.push_back(_args[i]);
                        ++i;
                    }
                }else {
                    results.positional.push_back(_args[i]);
                    ++i;
                }
            }
        }
    }

    return results;
}

cex::ArgResults cex::ArgParser::parse(char **_args, const std::size_t _size) {
    std::vector<std::string> v;
    for(std::size_t i = 0; i < _size; ++i) {
        std::string s = _args[i];
        v.push_back(s);
    }

    return parse(v);
}
