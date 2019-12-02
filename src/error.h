#ifndef ERROR_H
#define ERROR_H

#define ERROR_NO_ARGUMENTS 1
#include <iostream>

using namespace std;

[[noreturn]] void fatalError(int errorCode, string errorMessage);

#endif // ERROR_H
