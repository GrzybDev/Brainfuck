#include "main.h"

int main(int argc, char** argv)
{
    if (argc == 0) ;

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
                break;
        }
    }

    return 0;
}
