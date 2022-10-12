// program_options.cpp: method implementations for the ProgramOptions class


#include <iostream>

#include "program_options.h"



bool ProgramOptions::operator ! ()
{
    // !(*this) is true, if the options are NOT ok.
    return !options_ok;
}




ProgramOptions::ProgramOptions(int argc, char* argv[])
    : options_ok(false), a_flag(false)
{
    int opt;

    // iterate through every option passed to the program
    while((opt = getopt_long(argc, argv, optstring, longopts, NULL)) != -1)
    {
        switch(opt)
        {
            case 's':
                some_option = optarg;
                break;
            case 'a':
                another_option = optarg;
                break;
            case 'f':
                a_flag = true;
                break;
            case '?':
                // Do nothing, let options_ok at false and return
                return;
            default:
                // we shouldn't get here
                break;
        }
    }

    if (optind < argc-1)
    {
        // if there are more than one nonoption arguments, display an error
        // message
        std::cerr<<"Extranous Arguments\n";
        return;
    }
    else if (optind >= argc)
    {
        // if we are at the end of all arguments
        // (or past the end, which really shouldn't happen)
        // then we are missing our filename
        std::cerr<<"Missing filename\n";
        return;
    }
    else
    {
        // if we have exactly one argument left, we have our filename
        filename = argv[optind];
    }


    options_ok = true;
}

// option string for this program, will be passed to getopts_long
// see http://www.gnu.org/s/libc/manual/html_node/Getopt.html for details
const char* ProgramOptions::optstring =
    "s:m:f";


// option struct array for this program, will be passed to getopts_long
// see http://www.gnu.org/s/libc/manual/html_node/Getopt.html for details
const option ProgramOptions::longopts[] = {
    {"some-option",  required_argument, NULL, 's'}
    ,{"another-option",  required_argument, NULL, 'a'}
    ,{"a-flag", no_argument, NULL, 'f'}
};
