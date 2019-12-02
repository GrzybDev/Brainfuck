#include "main.h"

int main(int argc, char** argv)
{
    if (argc == 1) // Only executable path is provided, no arguments
        fatalError(ERROR_NO_ARGUMENTS, "No arguments provided!");

    while (true) {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (opt == -1)
            break;

        switch (opt) {
            case 'h':
                break;
            case 'v':
                break;
            case 'i':
                break;
            default:
                fatalError(ERROR_INVALID_ARGUMENT, "Invalid argument provided!");
        }
    }

    return 0;
}
