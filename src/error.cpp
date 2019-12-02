#include "error.h"

[[noreturn]] void fatalError(int errorCode, string errorMessage) {
    cout << "Fatal Error!" << endl << errorMessage << endl << endl;
    exit(errorCode);
}
