#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* reverseWords(const char* text) {

    if (text == NULL) return NULL; // 

    int len = strlen(text);
    char* result = (char*)malloc(len + 1);
    if (!result) return NULL; // 

    strcpy(result, text); // 

    char* start = NULL; // START
    for (int i = 0; i <= len; i++) {
        if (!isspace(result[i]) && start == NULL) {
            start = &result[i]; // END
        }
        if ((isspace(result[i]) || result[i] == '\0') && start) {
            // NOW reverse 
            char* end = &result[i - 1];
            while (start < end) {
                char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
            }
            start = NULL; // init 
        }
    }

    return result; // free 
}


#include <stdio.h>

int main() {
    const char* str = "This is  an example!";
    char* reversed = reverseWords(str);
    if (reversed) {
        printf("%s\n", reversed); // expected output : "sihT si  na !elpmaxe"
        free(reversed); // 
    }

    return 0;
}

