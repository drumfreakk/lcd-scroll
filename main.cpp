#include <iostream>
#include <stdio.h>
#include <string.h>

#define DISPLAY_LEN 16
#define SPLIT_LEN 2

void dump(const char *data_buffer, const unsigned int length) {
    unsigned char byte;
    unsigned int i, j;
    for(i=0; i < length; i++) {
        byte = data_buffer[i];
        printf("%02x ", data_buffer[i]);  // display byte in hex
        if(((i%17)==16) || (i==length-1)) {
            for(j=0; j < 16-(i%17); j++)
                printf("   ");
            printf("| ");
            for(j=(i-(i%17)); j <= i; j++) {  // display printable bytes from line
                byte = data_buffer[j];
                if((byte > 31) && (byte < 127)) // outside printable char range
                    printf("%c", byte);
                else
                    printf(".");
            }
            printf("\n"); // end of the dump line (each line 16 bytes)
        } // end if
    } // end for
    printf("\n");
}

int getLen(char* str);

int main() {

    char* input = "Hello my name is Kieran";


    int len = getLen(input);

    char* toDisplay = new char[len + SPLIT_LEN];

    for(int i = 0; i < len+SPLIT_LEN-1; i++){
        if(i < len-1) {
            toDisplay[i] = input[i];
        } else {
            toDisplay[i] = ' ';
        }
    }
    toDisplay[len+SPLIT_LEN-1] = '\0';

    len = getLen(toDisplay);
    dump(toDisplay, len+5);

    std::cout << len << std::endl;

    char text[DISPLAY_LEN];
    int step = 0;
    char* first = NULL;
    bool done = false;
    int count = 0;
    int countb;

    while(step < len){
        first = &toDisplay[step];
        done = false;
        count = 0;
        while(!done){
            if(first[count] == '\0') {
                done = true;
//                text[count] = '\0';
                continue;
            }
            text[count] = first[count];
            count++;
        }
        done = false;
        countb = count;
        while(!done){
            if(countb >= DISPLAY_LEN-1){
                done = true;
            }
            text[countb] = toDisplay[countb - count];
            countb++;
        }
        text[16] = '\0';

        std::cout << "[" << step << "]:\t" << text << std::endl;
//        dump(text, 17);
        step++;
    }
    std::cout << "end" << std::endl;


    delete[] toDisplay;
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

