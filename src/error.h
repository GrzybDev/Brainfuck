#ifndef ERROR_H
#define ERROR_H

#include <iostream>

using namespace std;

[[noreturn]] void fatalError(int errorCode, string errorMessage);

#endif // ERROR_H
