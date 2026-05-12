#ifndef TERMINALGUARD_H
#define TERMINALGUARD_H

#include <termios.h>
#include <unistd.h>
#include <iostream>

class TerminalGuard
{
private:
    struct termios orig_termios;

public:
    TerminalGuard()
    {
        std::cout << "\x1B[?1049h\x1B[H" << std::flush;
        tcgetattr(STDIN_FILENO, &orig_termios);
        struct termios raw = orig_termios;
        raw.c_lflag &= ~(ECHO | ICANON);

        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    ~TerminalGuard()
    {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
        std::cout << "\x1B[?1049l" << std::flush;
    }

    TerminalGuard(const TerminalGuard&) = delete;
    TerminalGuard& operator=(const TerminalGuard&) = delete;
};

#endif // TERMINALGUARD_H
