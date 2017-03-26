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

const int greenLEDpin = 17;
const int redLEDpin = 18;
const int blueLEDpin = 19;


void setup() {
  
  pinMode(AudioInPin, INPUT);   //Mic is a input
  pinMode(DigAudioPin, INPUT);
  lcd1.begin(16, 2);    //set the screen sizes of the LCD's
  lcd2.begin(16, 2);
  Serial.begin(9600);

 pinMode(greenLEDpin,OUTPUT); 
 pinMode(redLEDpin,OUTPUT);  
 pinMode(blueLEDpin,OUTPUT); 
}

void loop() {
  audioVal = analogRead(AudioInPin);   //reads Mic input and sets it as = to audioval 
  digtialAudVal =  digitalRead(DigAudioPin);

  Serial.println(audioVal);
  Serial.println(digtialAudVal);

  if (audioVal > 450 && audioVal < 500) //checks if audio input is less than lowest threshold but more than a ambient setting
  {
    lcd1.print(":( :( :( :( :( :(");
    lcd2.print(":( :( :( :( :( :(");
   digitalWrite(blueLEDpin, HIGH);
   digitalWrite(redLEDpin, LOW);
   digitalWrite(greenLEDpin, LOW);
    delay(2000);    //should keep it on screen for one second 
    lcd1.clear();
    lcd2.clear();


  }

  //rinise and repeat with diffrent check for audio levels
  if (audioVal > 500 && audioVal < 505)
  {
    lcd1.print(":) :) :) :) :) :)");
    lcd2.print(":) :) :) :) :) :)");
    digitalWrite(greenLEDpin, HIGH);
    digitalWrite(redLEDpin, LOW);
    digitalWrite(blueLEDpin, LOW);
    delay(2000);
    lcd1.clear();
    lcd2.clear();


  }
  if (audioVal > 505)
  {
    lcd1.print(":D :D :D :D :D :D");
    lcd2.print(":D :D :D :D :D :D");
   digitalWrite(redLEDpin, HIGH);
   digitalWrite(blueLEDpin, LOW);
   digitalWrite(greenLEDpin, LOW);
    delay(2000);
    lcd1.clear();
    lcd2.clear();


  }

  lcd1.print(":/ :/ :/ ");
  lcd2.print(":/ :/ :/ ");
  lcd1.clear();
  lcd2.clear();



}

