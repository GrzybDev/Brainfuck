#ifndef MAIN_H
#define MAIN_H

#include <getopt.h>

const static char* short_opts = "hvi:";
const static option long_opts[] = {
    {"help", no_argument, nullptr, 'h'},
    {"version", no_argument, nullptr, 'v'},
    {"input", required_argument, nullptr, 'i'},
    {nullptr, no_argument, nullptr, 0}
};

#endif // MAIN_H
