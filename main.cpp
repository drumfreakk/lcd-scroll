#include <iostream>
#include <stdio.h>
#include <string.h>

#define DISPLAY_LEN 16

int getLen(char* str);

int main() {

    char* toDisplay = "Hello my name is Kieran";
    int len = getLen(toDisplay);

    std::cout << len << std::endl;

    char text[DISPLAY_LEN];
    int step = 0;

    char* first = NULL;

    while(step < 24){
//        for(int i = 0; i < DISPLAY_LEN + 1; i++){
//            if(i+step < len){
//                text[i] = toDisplay[i + step];
//                std::cout << "a";
//            }else if(i+step > len+2){
//                text[i] = 'x';//toDisplay[1];
//                std::cout << "b";
//            }/*else if(i+step >= len){
//                text[i] = ' ';
//                std::cout << "c";
//            }*/
//        }
//        text[DISPLAY_LEN + 1] = '\0';
first = &toDisplay[step];

        bool done = false;
        int count = 0;
        while(!done){
            if(first[count] == '\0') {
                done = true;
                continue;
            }
            text[count] = first[count];
            count++;
        }
        done = false;
        int countb = count;
        while(!done){
            if(countb >= 15){
                done = true;
            }
            text[countb] = toDisplay[countb - count];
            countb++;
        }

        std::cout << "[" << step << "]:\t" << text << std::endl;
        step++;
    }
    std::cout << "end" << std::endl;

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

