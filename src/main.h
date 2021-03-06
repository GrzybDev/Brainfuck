#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include <sstream>
#include <getopt.h>
#include "error.h"
#include "help.h"
#include "interpreter.h"

const static char* short_opts = "hvi:";
const static option long_opts[] = {
    {"help", no_argument, nullptr, 'h'},
    {"version", no_argument, nullptr, 'v'},
    {"input", required_argument, nullptr, 'i'},
    {nullptr, no_argument, nullptr, 0}
};

#endif // MAIN_H
