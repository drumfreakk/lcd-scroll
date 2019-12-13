#include <iostream>
#include <stdio.h>
#include <string.h>

#define DISPLAY_LEN 16

int getLen(char* str);

int main() {

    char* toDisplay = "Hello my name is Kieran";
    int len = getLen(toDisplay);

    std::cout << len << std::endl;

    int count = 0;
    char text[DISPLAY_LEN];
    int step = 0;

    while(count < 7){
        for(int i = 0; i < DISPLAY_LEN + 1; i++){
            text[i] = toDisplay[i + step];
        }

        std::cout << text << std::endl;
        step++;
        count++;
    }

    return 0;
}

int getLen(char* str){
    int len = 0;
    bool done = false;
    while(!done) {
        if (str[len] == '\0') {
            done = true;
        }
        len++;
    }
    return len;
}

