int latchPin = 4;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 3;  // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 2;   // Data pin of 74HC595 is connected to Digital pin 4
byte leds = 0;  // Variable to hold the pattern of which LEDs are currently turned on or off

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() {
  delay(1000);
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

/*
 * loop() - this function runs over and over again
 */
void loop() {
  leds = 0;  // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  char alphabet[] = {'a','b','c','d','e','f','g', 'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '1'};
  updateShiftRegister();
  for (int i = 0; i < 27; i++) {
    setChar(leds, alphabet[i]);
    delay(250);
  }
}

/*
 * updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
 */
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setChar(byte& braille, char x) {
  braille = 0;
  updateShiftRegister();
  switch (x) {
    case 'a':
      bitSet(braille, 0);
      break;
    case 'b':
      bitSet(braille, 0);
      bitSet(braille, 1);
      break;
    case 'c':
      bitSet(braille, 0);
      bitSet(braille, 3);
      break;
    case 'd':
      bitSet(braille, 0);
      bitSet(braille, 3);
      bitSet(braille, 4);
      break;
    case 'e':
      bitSet(braille, 0);
      bitSet(braille, 4);
      break;
    case 'f':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 3);
      break;
    case 'g':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 3);
      bitSet(braille, 4);
      break;
    case 'h':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 4);
      break;
    case 'i':
      bitSet(braille, 1);
      bitSet(braille, 3);
      break;
    case 'j':
      bitSet(braille, 1);
      bitSet(braille, 3);
      bitSet(braille, 4);
      break;
    case 'k':
      bitSet(braille, 0);
      bitSet(braille, 2);
      break;
    case 'l':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 2);
      break;
    case 'm':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 3);
      break;
    case 'n':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 3);
      bitSet(braille, 4);
      break;
    case 'o':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 4);
      break;
    case 'p':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 2);
      bitSet(braille, 3);
      break;
    case 'q':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 2);
      bitSet(braille, 3);
      bitSet(braille, 4);
      break;
    case 'r':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 2);
      bitSet(braille, 4);
      break;
    case 's':
      bitSet(braille, 1);
      bitSet(braille, 2);
      bitSet(braille, 3);
      break;
    case 't':
      bitSet(braille, 1);
      bitSet(braille, 2);
      bitSet(braille, 3);
      bitSet(braille, 4);
      break;
    case 'u':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 5);
      break;
    case 'v':
      bitSet(braille, 0);
      bitSet(braille, 1);
      bitSet(braille, 2);
      bitSet(braille, 5);
      break;
    case 'w':
      bitSet(braille, 1);
      bitSet(braille, 3);
      bitSet(braille, 4);
      bitSet(braille, 5);
      break;
    case 'x':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 3);
      bitSet(braille, 5);
      break;
    case 'y':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 3);
      bitSet(braille, 4);
      bitSet(braille, 5);
      break;
    case 'z':
      bitSet(braille, 0);
      bitSet(braille, 2);
      bitSet(braille, 4);
      bitSet(braille, 5);
      break;
    default:
      braille = 0;
      break;
  }
  updateShiftRegister();


}