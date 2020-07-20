#pragma once

#include <iostream>
#include <cstdio>
#include <cstdarg>

using namespace std;

class Console {

public:
    static void println(const char *format, ...) {
        va_list args;
                va_start(args, format);
        vprintf(format, args);
                va_end(args);
        printf("\n");
    }

public:
    static int askIntegerNumber() {
        int number;
        cin >> number;
        return number;
    }

public:
    static int askIntegerNumberBetween(int minimum, int maximum) {
        int number = askIntegerNumber();

        if (number < minimum || number > maximum) {
            println("Please provide a number between '%d' and '%d'.", minimum, maximum);
            return askIntegerNumberBetween(minimum, maximum);
        }

        return number;
    }

};
