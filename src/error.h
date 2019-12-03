#ifndef ERROR_H
#define ERROR_H

#define ERROR_NO_ARGUMENTS 1
#define ERROR_INVALID_ARGUMENT 2
#define ERROR_FAILED_TO_READ_FILE 3
#define ERROR_LOOP_DOES_NOT_HAVE_ENDING 4
#define ERROR_LOOP_DOES_NOT_HAVE_BEGINNING 5

#include <iostream>

using namespace std;

[[noreturn]] void fatalError(int errorCode, string errorMessage);

#endif // ERROR_H
