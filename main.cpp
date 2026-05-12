#include <iostream>
#include <ostream>
#include <unistd.h>
#include "TerminalGuard.h"

int main()
{
    TerminalGuard guard;
    std::cout << "hello world!" << "\r\n" << std::flush;
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1)
    {
        if (c == 'q') break;
    }
    return 0;
}
