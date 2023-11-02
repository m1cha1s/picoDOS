#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <pico/stdlib.h>
#include <string.h>

#define programLoadPoint ((uint8_t*)0x21003000)

uint8_t prog[] = {
    0x47,
    0x70,
};

typedef int (*prog_t)(int, char**);

int loadProgram() {
    printf("Please enter the size of the program in bytes\n>");
    uint32_t progSize = 0;
    scanf("%d", &progSize);
    printf("%d\n", progSize);
    
    size_t bytesRead = 0;
    for (; bytesRead < progSize; bytesRead++) {
        uint32_t byte = 0;
        scanf("0x%02X", &byte);
        printf("0x%02X\n", byte);
        programLoadPoint[bytesRead] = (uint8_t)byte;
    }

    return bytesRead+1;
}

int main() {
    stdio_init_all();

    getchar(); // Wait for terminal

    printf("Copying...");
    memcpy((void*)programLoadPoint, (void*)prog, sizeof(prog));
    printf("DONE\n");

    for (int i = 0;i < sizeof(prog);i++)
        printf("0x%02X\n", programLoadPoint[i]);

    sleep_ms(10);

    while(1) {
        printf("Running program...\n");
        //size_t bytesRead = loadProgram();
        //printf("Successfuly loaded %u bytes\n", bytesRead);
        sleep_ms(10);
        prog_t app = (prog_t)programLoadPoint;
        int exitCode = app(69, NULL);
        printf("Program exited with code %d\n", exitCode);
        sleep_ms(1000);
    }

    return 0; // Unreachable
}
