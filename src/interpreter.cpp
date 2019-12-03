#include "interpreter.h"

Interpreter::Interpreter(string fileData)
{
    code = fileData; // Save fileData as code

    memory.clear(); // Clear memory
    memory.push_back(0); // Add null byte in memory

    dataPointer = memory.begin(); // Set memory pointer to beginning
    instructionPointer = code.begin(); // Set instruction pointer to beginning
}

void Interpreter::run() {
    stack<string::const_iterator> loopStack;

    while (instructionPointer != code.end()) {
        switch(*instructionPointer) {
            case BRAINFUCK_TOKEN_INCREMENT:
                (*dataPointer)++; // Increase (by one) the byte at the data pointer
                break;
            case BRAINFUCK_TOKEN_DECREMENT:
                (*dataPointer)--; // Decrease (by one) the byte at the data pointer
                break;
            case BRAINFUCK_TOKEN_PREVIOUS:
                if (dataPointer != memory.begin()) // If it's not first memory entry
                    dataPointer--; // Move data pointer backwards
                break;
            case BRAINFUCK_TOKEN_NEXT:
                if ((dataPointer + 1) == memory.end()) { // If data pointer is at memory ending
                    memory.push_back(0); // Add null byte in memory
                    dataPointer = memory.end() - 1; // Set data pointer to newly created null byte
                } else
                    dataPointer++; // Move data pointer forwards
                break;
            case BRAINFUCK_TOKEN_OUTPUT:
                cout << *dataPointer; // Output byte at data pointer
                break;
            case BRAINFUCK_TOKEN_INPUT:
                char userInput; // byte for userInput
                cin >> userInput; // Get user input (unfortunately, it requires ENTERing every char)

                (*dataPointer) = userInput; // Store user input at memory pointer
                break;
            case BRAINFUCK_TOKEN_LOOP_START:
                loopStack.push(instructionPointer); // Save loop beginning

                if (*dataPointer == 0) { // If the byte at dataPointer is 0...
                    auto startingInstructionPointer = instructionPointer; // Save starting intruction pointer

                    while(++instructionPointer != code.end()) { // Loop ends when code ends.
                        if (*instructionPointer == BRAINFUCK_TOKEN_LOOP_START) // If there's loop inside loop...
                            loopStack.push(instructionPointer); // Save that loop too
                        else if (*instructionPointer == BRAINFUCK_TOKEN_LOOP_END) { // If there's loop ending...
                            if (loopStack.empty()) // If there's no loop started...
                                fatalError(ERROR_LOOP_DOES_NOT_HAVE_BEGINNING, "Found loop that does not have beginning!");

                            auto tempIntructionPointer = loopStack.top(); // Save temporary instruction pointer (last started loop)
                            loopStack.pop(); // Remove current loop from loopStack

                            if (startingInstructionPointer == tempIntructionPointer) // If newest loop is starting loop
                                break; // Finish this loop
                        }
                    }
                }
                break;
            case BRAINFUCK_TOKEN_LOOP_END:
                if (loopStack.empty()) // If there's no loop started...
                    fatalError(ERROR_LOOP_DOES_NOT_HAVE_BEGINNING, "Found loop that does not have beginning!");

                if (*dataPointer != 0) // If the byte at dataPointer is not 0...
                    instructionPointer = loopStack.top(); // Jump back to loop beginning (last started loop)
                else // ...if it is 0
                    loopStack.pop(); // Loop ended, remove loop from loopStack
                break;
            default: // Non-brainfuck character
                break; // Do nothing...
        }

        instructionPointer++; // Increment instruction pointer (Next instruction)
    }

    if (!loopStack.empty()) // loopStack should be empty here, if it's not something went wrong...
        fatalError(ERROR_LOOP_DOES_NOT_HAVE_ENDING, "Found loop that does not have ending!"); // It usually means that loop doesn't have ending, so crash program with that message.
}
