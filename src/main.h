#ifndef MAIN_H
#define MAIN_H

#define APP_VERSION "v1.0"

#include <getopt.h>
#include "error.h"

const static char* short_opts = "hvi:";
const static option long_opts[] = {
    {"help", no_argument, nullptr, 'h'},
    {"version", no_argument, nullptr, 'v'},
    {"input", required_argument, nullptr, 'i'},
    {nullptr, no_argument, nullptr, 0}
};

#endif // MAIN_H
