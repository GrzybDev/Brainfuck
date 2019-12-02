#include "help.h"

void printVersion() {
    cout << "Brainfuck " << APP_VERSION << " by Marek Grzyb (GrzybDev)" << endl;
    cout << "This project is licensed under the terms of the MIT license" << endl;
    cout << "https://github.com/GrzybDev/Brainfuck" << endl << endl;
}

void printHelp() {
    cout << "Usage: Brainfuck [-h|-v][-i <input file>]" << endl << endl;
    cout << "-h | --help - Displays this message" << endl;
    cout << "-v | --version - Displays application version" << endl << endl;
    cout << "-i <file path> | --input <file path> - Executes program located at file path" << endl << endl;
}
