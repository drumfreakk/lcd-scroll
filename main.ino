#include <LiquidCrystal.h>

#define DISPLAY_LEN 16
#define SPLIT_LEN 4

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

char* toDisplay = NULL;
int len;
int stp = 0;

const char* input = "Hello my name is Kieran";

unsigned long previousMillis = 0;
const long interval = 500;

void setup() {
  lcd.begin(16, 2);

  toDisplay = init(input);
  len = getLen(toDisplay);
}

void loop() {


	unsigned long currentMillis = millis();
	if(currentMillis - previousMillis >= interval){
		previousMillis = currentMillis;
		
		stepThrough(toDisplay, stp);
		stp++;
		if(stp >= len){
			stp = 0;
		}
	}
}


void stepThrough(const char* toDisplay, int stp) {
  char text[DISPLAY_LEN];
  getStep(text, toDisplay, stp);
  lcd.setCursor(0, 0);
  lcd.print(text);
}

int getLen(const char* str) {
  int len = 0;
  bool done = false;
  while (!done) {
    if (str[len] == '\0') {
      done = true;
    }
    len++;
  }
  return len;
}

void getStep(char* text, const char* toDisplay, int stp) {
  const char* first = &toDisplay[stp];
  bool done = false;
  int count = 0;
  int countb;

  while (!done) {
    if (first[count] == '\0' || count >= DISPLAY_LEN) {
      done = true;
      continue;
    }
    text[count] = first[count];
    count++;
  }
  done = false;
  countb = count;

  while (!done) {
    if (countb >= DISPLAY_LEN - 1) {
      done = true;
    }
    text[countb] = toDisplay[countb - count];
    countb++;
  }
  text[16] = '\0';
}

char* init(const char* input) {
  int len = getLen(input);

  char* toDisplay = new char[len + SPLIT_LEN];

  for (int i = 0; i < len + SPLIT_LEN - 1; i++) {
    if (i < len - 1) {
      toDisplay[i] = input[i];
    } else {
      toDisplay[i] = ' ';
    }
  }
  toDisplay[len + SPLIT_LEN - 1] = '\0';

  return toDisplay;
}
