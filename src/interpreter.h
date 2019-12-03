#ifndef INTERPRETER_H
#define INTERPRETER_H

#define BRAINFUCK_TOKEN_INCREMENT '+'
#define BRAINFUCK_TOKEN_DECREMENT '-'
#define BRAINFUCK_TOKEN_PREVIOUS '<'
#define BRAINFUCK_TOKEN_NEXT '>'
#define BRAINFUCK_TOKEN_OUTPUT '.'
#define BRAINFUCK_TOKEN_INPUT ','
#define BRAINFUCK_TOKEN_LOOP_START '['
#define BRAINFUCK_TOKEN_LOOP_END ']'

#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
#include "error.h"

using namespace std;

class Interpreter
{
public:
    Interpreter(string fileData);
    void run();
};

#endif // INTERPRETER_H
