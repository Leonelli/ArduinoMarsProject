#include <Servo.h>
#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

//string for the final word
String parola;
int index_parola=0;
char value_for_rotation_1;
char value_for_rotation_2;
//////SERVO
int servoPin = 4;
int angle=0;
char c;
Servo servo;
////


unsigned long signal_len,t1,t2;   //time for which button is pressed
int inputPin = 5;                 //input pin for push button
int ledPin = 2;                   //outpu pin for LED
String code = "";                 //string in which one alphabet is stored

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); //internal pullup resistor is used to simplify the circuit
  pinMode(ledPin,OUTPUT);
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);


  ///////servo setup
  servo.attach(servoPin);
  servo.write(angle);
  ///////////
  
}

void loop()
{
NextDotDash:
  while (digitalRead(inputPin) == HIGH) {}
  t1 = millis();                            //time at button press
  digitalWrite(ledPin, HIGH);               //LED on while button pressed
  while (digitalRead(inputPin) == LOW) {}
  t2 = millis();                            //time at button release
  digitalWrite(ledPin, LOW);                //LED off on button release
  signal_len = t2 - t1;                     //time for which button is pressed
  if (signal_len > 50)                      //to account for switch debouncing
  {
    code += readio();                       //function to read dot or dash
  }
  while ((millis() - t2) < 500)           //if time between button press greater than 0.5sec, skip loop and go to next alphabet
  {     
    if (digitalRead(inputPin) == LOW)
    {
      goto NextDotDash;
    }
  }
  convertor();                          //function to decipher code into alphabet
}



void rotateServo(String hex_value_returned){
    Serial.println("hex_value_returned:"+hex_value_returned);

    for (int n = 0; n <= 1; n++) {
      value_for_rotation_1 = hex_value_returned.charAt(n);
      Serial.println(value_for_rotation_1);   

       if(value_for_rotation_1=='F'){
          servo.write(11.5);  
          delay(1000); 
          ResetPosition(11.5);              
       }
         else if(value_for_rotation_1=='E'){
          servo.write(23); 
          delay(1000); 
          ResetPosition(23);              
       }
         else if(value_for_rotation_1=='D'){
          servo.write(34.5);  
          delay(1000); 
          ResetPosition(34.5);              
       }
         else if(value_for_rotation_1=='C'){
          servo.write(46);  
          delay(1000); 
          ResetPosition(46);              
       }
         else if(value_for_rotation_1=='B'){
          servo.write(57.5); 
          delay(1000); 
          ResetPosition(57.5);              
       }
         else if(value_for_rotation_1=='A'){
          servo.write(69);   
          delay(1000); 
          ResetPosition(69);              
       }
         else if(value_for_rotation_1=='9'){
          servo.write(80.5); 
          delay(1000); 
          ResetPosition(80.5);              
       }
         else if(value_for_rotation_1=='8'){
          servo.write(92);   
          delay(1000); 
          ResetPosition(92);              
       }
         else if(value_for_rotation_1=='7'){
          servo.write(103.5); 
          delay(1000); 
          ResetPosition(103.5);              
       }
         else if(value_for_rotation_1=='6'){
          servo.write(115);  
          delay(1000); 
          ResetPosition(115);              
       }
         else if(value_for_rotation_1=='5'){
          servo.write(126.5);  
          delay(1000); 
          ResetPosition(126.5);              
       }
         else if(value_for_rotation_1=='4'){
          servo.write(138);   
          delay(1000); 
          ResetPosition(138);              
       }
         else if(value_for_rotation_1=='3'){
          servo.write(149.5);   
          delay(1000); 
          ResetPosition(149.5);              
       }
         else if(value_for_rotation_1=='2'){
          servo.write(161);   
          delay(1000); 
          ResetPosition(161);              
       }
         else if(value_for_rotation_1=='1'){
          servo.write(172.5); 
          delay(1000); 
          ResetPosition(172.5);              
       }
         else if(value_for_rotation_1=='0'){
          servo.write(180); 
          delay(1000); 
          ResetPosition(180);              
       }
     
    }
}


void show_led(char c){     


     FastLED.clear();;

    switch (c) {
      case 'A':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;
    break;

     case 'B':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;

 case 'C':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
     
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;


case 'D':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

     

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;


     case 'E':
    // Turn the first led red for 1 second
      


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;


 case 'F':
    // Turn the first led red for 1 second
      


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

     
    break;

case 'G':
    // Turn the first led red for 1 second
      


      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
     
     

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;

     
    break;



case 'H':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

     

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

     
    break;


case 'I':
    // Turn the first led red for 1 second
     


      leds[3] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      leds[19] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[51] = CRGB::Blue;
      leds[59] = CRGB::Blue;

      leds[57] = CRGB::Blue;
      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

     
      leds[1] = CRGB::Blue;
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;




case 'J':
    // Turn the first led red for 1 second
     


      leds[3] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      leds[19] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[51] = CRGB::Blue;
      leds[59] = CRGB::Blue;

      leds[57] = CRGB::Blue;
      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

     
     
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[13] = CRGB::Blue;
    break;


  case 'K':
    // Turn the first led red for 1 second
     


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

  

     
      leds[29] = CRGB::Blue;
      leds[36] = CRGB::Blue;
      leds[20] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      leds[2] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[50] = CRGB::Blue;


     
    break;


  case 'L':
    // Turn the first led red for 1 second
     


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;


      leds[1] = CRGB::Blue;
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;

  case 'M':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[50] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[44] = CRGB::Blue;
      leds[53] = CRGB::Blue;

     

    
    break;


case 'N':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;


      leds[46] = CRGB::Blue;
      leds[37] = CRGB::Blue;
      leds[28] = CRGB::Blue;    
      leds[19] = CRGB::Blue;    
      leds[10] = CRGB::Blue;    

    break;


  case 'O':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;

  case 'P':
    // Turn the first led red for 1 second
     
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

     
    break;


  case 'Q':
    // Turn the first led red for 1 second
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;


      leds[0] = CRGB::Blue;
      leds[18] = CRGB::Blue;
      leds[27] = CRGB::Blue;

    

      leds[10] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      leds[12] = CRGB::Blue;
      leds[13] = CRGB::Blue;
    break;


      case 'R':
    // Turn the first led red for 1 second
    
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

      leds[21] = CRGB::Blue;
      leds[12] = CRGB::Blue;
      leds[3] = CRGB::Blue;
    
    break;


  case 'S':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
    
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

      leds[26] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;

      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;
case 'T':
    // Turn the first led red for 1 second
     


      leds[3] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      leds[19] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[51] = CRGB::Blue;
      leds[59] = CRGB::Blue;

      leds[57] = CRGB::Blue;
      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

    break;


  case 'U':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      leds[9]= CRGB::Blue;
      leds[17] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      leds[62] = CRGB::Blue;


      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;


    case 'V':
    // Turn the first led red for 1 second
     
      leds[33] = CRGB::Blue;
      leds[41] = CRGB::Blue;
      leds[48] = CRGB::Blue;
      leds[56] = CRGB::Blue;


     
     
      leds[38] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[55] = CRGB::Blue;
      leds[63] = CRGB::Blue;


      leds[11] = CRGB::Blue;
      leds[12] = CRGB::Blue;

      leds[21] = CRGB::Blue;
      leds[18] = CRGB::Blue;

      leds[29] = CRGB::Blue;
      leds[26] = CRGB::Blue;

      
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
    break;

 

case 'W':
    // Turn the first led red for 1 second
     



      leds[11] = CRGB::Blue;
      leds[20] = CRGB::Blue;
      leds[18] = CRGB::Blue;
      leds[9] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[38] = CRGB::Blue;

      leds[16] = CRGB::Blue;
      leds[24] = CRGB::Blue;
      leds[32] = CRGB::Blue;




     
      leds[13] = CRGB::Blue;

      leds[2] = CRGB::Blue;
      leds[4] = CRGB::Blue;


    break;


 case 'X':
    // Turn the first led red for 1 second
     


   leds[1]= CRGB::Blue;
   leds[10]= CRGB::Blue;
   leds[19]= CRGB::Blue;
   leds[28]= CRGB::Blue;
   leds[37]= CRGB::Blue;
   leds[46]= CRGB::Blue;

      leds[6] = CRGB::Blue;
      leds[13] = CRGB::Blue;
      leds[20] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[34] = CRGB::Blue; 
      leds[41] = CRGB::Blue;



   

    break;


 case 'Y':
    // Turn the first led red for 1 second
     


      leds[3] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      leds[19] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[43] = CRGB::Blue;
    

      leds[57] = CRGB::Blue;
      leds[50] = CRGB::Blue;
      leds[52] = CRGB::Blue;
      leds[61] = CRGB::Blue;

    break; 

 case 'Z':
    // Turn the first led red for 1 second
      leds[1]= CRGB::Blue;
      
      leds[57] = CRGB::Blue;


      leds[6] = CRGB::Blue;
      
      leds[62] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[50] = CRGB::Blue;
      leds[42] = CRGB::Blue;

      leds[13] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[21] = CRGB::Blue;
      leds[20] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[34] = CRGB::Blue;

      leds[58] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[61] = CRGB::Blue;

    
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Blue;
    break;

    
    default:
      for(int a = 0; a < 64; a = a++ ){
         leds[a] = CRGB::Black;
      }
      break;

      
      
      
      }


      FastLED.show();
      delay(1000);

}

void ascii_to_hex_convert(char c){     
  Serial.println(c);

  show_led(c);
  if(c =='A'){ 
 
        Serial.println("41");
        rotateServo("41");
        Serial.println("function running");

  }

  if(c=='B'){
        Serial.println("42");
        rotateServo("42");
                Serial.println("function running");

  }

 if(c=='C'){
        Serial.println("43");
        rotateServo("43");
                Serial.println("function running");

  }

 if(c=='D'){
        Serial.println("44");
        rotateServo("44");
  }

 if(c=='E'){
        Serial.println("45");
        rotateServo("45");
                Serial.println("function running");

}
 if(c=='F'){
        Serial.println("46");
        rotateServo("46");
  }

 if(c=='G'){
        Serial.println("47");
        rotateServo("47");
  }

 if(c=='H'){
        Serial.println("48");
        rotateServo("48");
  }

 if(c=='I'){
        Serial.println("49");
        rotateServo("49");
  }

 if(c=='J'){
        Serial.println("4A");
        rotateServo("4A");
  }

 if(c=='K'){
        Serial.println("4B"); 
        rotateServo("4B");
}

 if(c=='L'){
        Serial.println("4C");
        rotateServo("4C");
  }

 if(c=='M'){
        Serial.println("4D");
        rotateServo("4D");
  }

 if(c=='N'){
        Serial.println("4E");
        rotateServo("4E");
  }

 if(c=='O'){
        Serial.println("4F");
        rotateServo("4F");
  }

 if(c=='P'){
        Serial.println("50");
        rotateServo("50");
  }

 if(c=='Q'){
        Serial.println("51");
        rotateServo("51");
        Serial.println("function running");

  }
 if(c=='R'){
        Serial.println("52");
        rotateServo("52");
                Serial.println("function running");

  }

  if(c=='S'){
        Serial.println("53");
        rotateServo("53");
  }

  if(c=='T'){
        Serial.println("54");
        rotateServo("54");
  }

  if(c=='U'){
        Serial.println("55");
        rotateServo("55");
  }

  if(c=='V'){
        Serial.println("56");
        rotateServo("56");
  }

  if(c=='W'){
        Serial.println("57");
        rotateServo("57");
  }

  if(c=='X'){
        Serial.println("58");
        rotateServo("58");
  }

  if(c=='Y'){
        Serial.println("59");
        rotateServo("59");
  }

  if(c=='Z'){
        Serial.println("5A");
        rotateServo("5A");
  }

  
  
}   


void ResetPosition(int angle){
  for(int servoAngle = angle; servoAngle >= 0; servoAngle--)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);              
    delay(10);                  
  }
}

char readio()
{
  if (signal_len < 600 && signal_len > 50)
  {
    return '.';                        //if button press less than 0.6 sec, it is a dot
  }
  else if (signal_len > 600)
  {
    return '-';                        //if button press more than 0.6 sec, it is a dash
  }
}

void convertor()
{
  static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
                            };
  int i = 0;
  /*if (code == ".-.-.-")
  {
    Serial.print(".");        //for break
  }
  else*/
  {
    while (letters[i] != "E")  //loop for comparing input code with letters array
    {
      if (letters[i] == code)
      {
        Serial.println(char('A' + i));
        ascii_to_hex_convert(char('A' + i));
        break;
       
      }
      i++;
    }
    if (letters[i] == "E")
    {
      Serial.println("<Wrong input>");  //if input code doesn't match any letter, error
    }
  }
  code = "";                            //reset code to blank string
}
