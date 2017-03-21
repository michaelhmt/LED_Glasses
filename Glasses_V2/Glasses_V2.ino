#include <LiquidCrystal.h>

// Right(Blue) LCD
LiquidCrystal lcd1(8, 9, 10, 11, 12, 13);
// Left(Green) LCD
LiquidCrystal lcd2(2, 3, 4, 5, 6, 7);

const int AudioInPin = A0; //sets the Mic as an input 
const int DigAudioPin = 15; //reads digtial as well
int audioVal;  // is the varablie for Mic input
int digtialAudVal;
const int Low = 20;  //used for lowest threshold
const int High = 300; //used for high threshold
int LockSwitch;


void setup() {
  
  pinMode(AudioInPin, INPUT);   //Mic is a input
  pinMode(DigAudioPin, INPUT);
  lcd1.begin(16, 2);    //set the screen sizes of the LCD's
  lcd2.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  audioVal = analogRead(AudioInPin);   //reads Mic input and sets it as = to audioval 
  digtialAudVal =  digitalRead(DigAudioPin);

  Serial.println(audioVal);
  Serial.println(digtialAudVal);

  if (audioVal > 400 && audioVal < 484) //checks if audio input is less than lowest threshold but more than a ambient setting
  {
    lcd1.print(":( :( :( :( :( :(");
    lcd2.print(":( :( :( :( :( :(");
    delay(2000);    //should keep it on screen for one second 
    lcd1.clear();
    lcd2.clear();
  }

  //rinise and repeat with diffrent check for audio levels
  if (audioVal > 484 && audioVal < 495)
  {
    lcd1.print(":) :) :) :) :) :)");
    lcd2.print(":) :) :) :) :) :)");
    delay(2000);
    lcd1.clear();
    lcd2.clear();
  }
  if (audioVal > 495)
  {
    lcd1.print(":D :D :D :D :D :D");
    lcd2.print(":D :D :D :D :D :D");
    delay(2000);
    lcd1.clear();
    lcd2.clear();
  }

  lcd1.print(":/ :/ :/ ");
  lcd2.print(":/ :/ :/ ");
  lcd1.clear();
  lcd2.clear();


}

