#include <ncurses.h>
#include <stdint.h>

int main(int argc, char const *argv[]) {
    // Initialize
    initscr();

    int32_t row, col;
    row = 1;
    col = 1;
    // Moves the cursor to the specified location
    move(row, col);

    // Prints to window
    printw("Hello, World!");

    // Refreshes the screen
    refresh();

    // Waits for user input, returns int value of that key
    int32_t c = getch();

    printw("%d", c);

    getch();

    endwin();

    return 0;
}
