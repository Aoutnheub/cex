## Index

  - ArgParser
    - ArgParser()
    - addFlag()
    - addOption()
    - addCommand()
    - help()
    - max_line_length
    - command_required

## ArgParser

### Constructor

`ArgParser(const std::string &_name = "", const std::string &_description = "")`

  - `_name` : Name of the application; used for the `help` function
  - `_description` : Description of the application; used for the `help` function

### Functions

**`void addFlag(const std::string &_name, const std::string &_help = "", const char &_abbr = '\0')`**

  - `_name` : Flag name; throws a `cex::duplicate_argument` exception if the name already exists
  - `_help` : Flag description; used for the `help` function
  - `_abbr` : Flag abbreviation; throws a `cex::duplicate_argument` exception if the abbreviation already exists

**Example**

```c++
ArgParser parser;
parser.addFlag("test", "This is a test flag", 't');
```

Can be used like this:

  - `--test`
  - `-t`
  - `-atbc` (with other flags: a, b, c)

Can be accessed from `ArgResults` with `.flag["test"]`

**`void addOption(const std::string &_name, const std::string &_help = "", const char &_abbr = '\0', const std::string &_defaults_to = "", const std::vector<std::string> &_allowed = {})`**

  - `_name` : Option name; throws a `cex::duplicate_argument` exception if the name already exists
  - `_help` : Option description; used for the `help` function
  - `_abbr` : Option abbreviation; throws a `cex::duplicate_argument` exception if the abbreviation already exists
  - `_defaults_to` : Default value; can be different from the allowed values
  - `_allowed` : Allowed values; if it's not empty throws a `cex::invalid_value` if the option value doesn't match any of the allowed values

**Example**

```c++
ArgParser parser;
parser.addOption("test", "This is a test option", 't', "option1", {"option1", "option2", "option3"});
```

Can be used like this:

  - `--test option1` or `--test option2` etc.
  - `-t option1` or `-t option2` etc.
  - `-abct option1` or `-bact option2` etc. (with other flags: a, b, c; MUST BE POSITIONED AT THE END)

Can be accessed from `ArgResults` with `.option["test"]`

**`void addCommand(const std::string &_name, const std::string &_help = "")`**

  - `_name` : Command name; throws a `cex::duplicate_argument` exception if the name already exists
  - `_help` : Command description; used for the `help` function

**Example**

```c++
ArgParser parser;
parser.addCommand("test", "This is a test command");
```

Can be used like this:

  - `./app.exe test <other arguments>` (MUST BE THE FIRST ARGUMENT)

Can be accessed from `ArgResults` with `.command`

**`ArgResults parse(const std::vector<std::string> &_args)`**

**`ArgResults parse(char **_args, const std::size_t _size)`**

  - `_args` : vector or array of arguments to be parsed
  - `_size` : size of the array if `_args` is an array

**Example**

```c++
int main(int argc, char **argv) {
    ArgParser parser;
    // Add flags, options and commands
    ArgResults results = parser.parse(argv + 1, argc - 1);
}
```

**`std::string help()`**

Returns a formated string with the help for all the flags, options and commands.

**Format**

```
<app name> - <app description>

COMMANDS

    <name>
        <help>

FLAGS

    <name>, <abbreviation>
        <help>

OPTIONS

    <name>, <abbreviation> <allowed values>
        <help>

```

### Variables

  - `unsigned max_line_length = 80` : Restrict the formated help text to X columns
  - `bool command_required = false` : Throw a `cex::missing_value` if no command is given
