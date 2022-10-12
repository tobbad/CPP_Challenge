// program_options.h: Class declaration file for the ProgramOptions Class


#ifndef PROGRAM_OPTIONS_H_
#define PROGRAM_OPTIONS_H_

#include <string>
#include "getopt.h"


struct ProgramOptions
{
    /// Some option. If this option is not set the string is empty.
    std::string some_option;

    /// A different option. If this option is not set the string is empty.
    std::string another_option;

    /// name of the a file
    std::string filename;

    bool a_flag;

    /** Constructor
    *
    * Construct program options struct. When passed the arguments of main(),
    * this constructor fills the struct with all options set on the command line.
    * If all options were valid, operator ! returns false. You can use
    * something like this to check for validity: @verbatim
ProgramOptions po(argc, argv);
if (!po)
{
    display_usage();
    exit(EXIT_FAILURE);
}@endverbatim
    *
    * @param argc Number of arguments, pass along the first argument of main()
    * here
    * @param argv Arguments vector, pass along the second argument of main()
    * here
    */
    ProgramOptions(int argc, char* argv[]);

    /** Check if all options were valid.
    * @return If all options entered on the command line were vealid, the operator returns false.
    * Otherwise, returns true.
    */
    bool operator ! ();

private:
    bool options_ok;
    static const char* optstring;
    static const option longopts[];
};


#endif // ifndef PROGRAM_OPTIONS_H_
