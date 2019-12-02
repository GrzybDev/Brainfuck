#include "main.h"

string readFile(string path) {
    ifstream fileContext(path, ios::in);
    stringstream strStream;
    string fileContent;

    if (fileContext.good() && fileContext.is_open()) {
        fileContext.seekg(0, ios::end);
        strStream << fileContext.rdbuf();
        fileContent = strStream.str();
    } else {
        fatalError(ERROR_FAILED_TO_READ_FILE, "Failed to read file located at path: " + path);
    }

    fileContext.close();
    return fileContent;
}

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
                printHelp();
                break;
            case 'v':
                printVersion();
                break;
            case 'i': {
                string fileData = readFile(optarg);
                Interpreter(fileData).run();

                break;
            }
            default:
                fatalError(ERROR_INVALID_ARGUMENT, "Invalid argument provided!");
        }
    }

    return 0;
}
