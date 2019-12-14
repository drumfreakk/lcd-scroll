#include <iostream>

#define DISPLAY_LEN 16
#define SPLIT_LEN 4

int getLen(const char* str);
void getStep(char* text, const char* toDisplay, int step);
char* init(const char* input);

int main() {

	const char* input = "Hello my name is Kieran";

	char* toDisplay = NULL;
	int len;
	char text[DISPLAY_LEN];
	int step = 0;

	toDisplay = init(input);
    len = getLen(toDisplay);

	while(step < len){
		getStep(text, toDisplay, step);
		std::cout << "[" << step << "]:\t" << text << std::endl;
		step++;
	}

	delete[] toDisplay;
	return 0;
}

int getLen(const char* str){
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

void getStep(char* text, const char* toDisplay, int step){
	const char* first = &toDisplay[step];
	bool done = false;
	int count = 0;
	int countb;

	while(!done){
		if(first[count] == '\0' || count >= DISPLAY_LEN) {
			done = true;
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
}

char* init(const char* input){
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

	return toDisplay;
}