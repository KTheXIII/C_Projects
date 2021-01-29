#include <stdio.h>

#define BUFFER_SIZE 256

int main(int argc, char const *argv[]) {
    char const message[] = "───────────────────────────────";
    char input_buffer[BUFFER_SIZE];

    printf("%s\n", message);
    printf("Enter your name: ");
    gets_s(input_buffer, BUFFER_SIZE);
    printf("Hello %s\n", input_buffer);
    gets_s(input_buffer, BUFFER_SIZE);

    return 0;
}
