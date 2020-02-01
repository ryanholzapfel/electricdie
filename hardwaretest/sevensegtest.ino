nt latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() 
{
  //initialize SR pins
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  
  //serial debugging
  Serial.begin(9600);
  Serial.write("connected\n");
  
  //initialize random
  randomSeed(analogRead(0));
  
  //turn LEDs off
  leds = 0;
  updateShiftRegister(leds);
}

void loop() 
{
  delay(500);
  
  //generate new random number
  int dMax = getDMax();
  int rr = random(0,dMax);
  Serial.print(rr); //print to serial for debugging
  Serial.print("   ");
  byte rByte = intToSeven(rr);
  Serial.println(rByte);
  updateShiftRegister(rByte);
  delay(500);
}

void updateShiftRegister(byte bits)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, bits);
   digitalWrite(latchPin, HIGH);
}

int getDMax(){
  //**todo** check digital inputs (switch positions) to determine die size (dmax)
  return 9; //set to 9 for testing
}

byte intToSeven(int num) { 
  //convert integer to bytes corresponding to LEDs on 7 segment display
  switch (num) {
    case 0:
      return B11111100;
      break;
    case 1:
      return B01100000;
      break;
    case 2:
      return B11011010;
      break;
    case 3:
      return B11110010;
      break;
    case 4:
      return B01100110;
      break;
    case 5:
      return B10110110;
      break;
    case 6:
      return B10111110;
      break;
    case 7:
      return B11100000;
      break;
    case 8:
      return B11111110;
      break;
    case 9:
      return B11110110;
      break;
    case 10:
      return B11101110; // Hexidecimal A
      break;
    case 11:
      return B00111110; // Hexidecimal B
      break;
    case 12:
      return B10011100; // Hexidecimal C or use for Centigrade
      break;
    case 13:
      return B01111010; // Hexidecimal D
      break;
    case 14:
      return B10011110; // Hexidecimal E
      break;
    case 15:
      return B10001110; // Hexidecimal F or use for Fahrenheit
      break;  
    default:
      return B10010010; // Error condition, displays three vertical bars
      break;   
  }
}
