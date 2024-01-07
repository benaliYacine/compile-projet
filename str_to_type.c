#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isInteger(const char *str) {
    char *end;
    strtol(str, &end, 10);
    return *end == '\0';
}

bool isFloat(const char *str) {
    char *end;
    strtof(str, &end);
    return *end == '\0';
}

bool isBoolean(const char *str) {
    return strcmp(str, "true") == 0 || strcmp(str, "false") == 0;
}

int main12() {
    char str[] = "5.4226"; // Example input

    if (isInteger(str)) {
        int val = strtol(str, NULL, 10);
        printf("Integer: %d\n", val);
        // Convert back to string
        char backToStr[20];
        sprintf(backToStr, "%d", val);
        printf("Back to String: %s\n", backToStr);
    }
    else if (isFloat(str)) {
        float val = strtof(str, NULL);
        printf("Float: %f\n", val);
        // Convert back to string
        char backToStr[20];
        sprintf(backToStr, "%f", val);
        printf("Back to String: %s\n", backToStr);
    }
    else if (isBoolean(str)) {
        bool val = strcmp(str, "true") == 0;
        printf("Boolean: %s\n", val ? "true" : "false");
        // Conversion back to string is trivial here
        char *backToStr = val ? "true" : "false";
        printf("Back to String: %s\n", backToStr);
    }
    else {
        printf("Unknown format\n");
    }

    return 0;
}

