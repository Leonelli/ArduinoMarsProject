#include <Servo.h>

//string for the final word
String parola;
int index_parola=0;
char value_for_rotation_1;
char value_for_rotation_2;
//////SERVO
int servoPin = 5;
int angle=0;
char c;
Servo servo;
////


unsigned long signal_len,t1,t2;   //time for which button is pressed
int inputPin = 2;                 //input pin for push button
int ledPin = 4;                   //outpu pin for LED
String code = "";                 //string in which one alphabet is stored

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); //internal pullup resistor is used to simplify the circuit
  pinMode(ledPin,OUTPUT);


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




String ascii_to_hex_convert(char c){
  String hex_value;
  if(c=='A'){
        Serial.println("41");
        hex_value="41";

  }

 else if(c=='B'){
        Serial.println("42");
        hex_value="42";
  }

else if(c=='C'){
        Serial.println("43");
        hex_value="43";
  }

else if(c=='D'){
        Serial.println("44");
        hex_value="44";
  }

else if(c=='E'){
        Serial.println("45");
        hex_value="45";
}
else if(c=='F'){
        Serial.println("46");
        hex_value="46";
  }

else if(c=='G'){
        Serial.println("47");
        hex_value="47";
  }

else if(c=='H'){
        Serial.println("48");
        hex_value="48";
  }

else if(c=='I'){
        Serial.println("49");
        hex_value="49";
  }

else if(c=='J'){
        Serial.println("4A");
        hex_value="4A";
  }

else if(c=='K'){
        Serial.println("4B");
        hex_value="4B";
}

else if(c=='L'){
        Serial.println("4C");
        hex_value="4C";
  }

else if(c=='M'){
        Serial.println("4D");
        hex_value="4D";
  }

else if(c=='N'){
        Serial.println("4E");
        hex_value="4E";
  }

else if(c=='O'){
        Serial.println("4F");
        hex_value="4F";
  }

else if(c=='P'){
        Serial.println("50");
        hex_value="50";
  }

else if(c=='Q'){
        Serial.println("51");
        hex_value="51";
  }
else if(c=='R'){
        Serial.println("52");
        hex_value="52";
  }

 else if(c=='S'){
        Serial.println("53");
        hex_value="53";
  }

 else if(c=='T'){
        Serial.println("54");
        hex_value="54";
  }

 else if(c=='U'){
        Serial.println("55");
        hex_value="55";
  }

 else if(c=='V'){
        Serial.println("56");
        hex_value="56";
  }

 else if(c=='W'){
        Serial.println("57");
        hex_value="57";
  }

 else if(c=='X'){
        Serial.println("58");
        hex_value="58";
  }

 else if(c=='Y'){
        Serial.println("59");
        hex_value="59";
  }

 else if(c=='Z'){
        Serial.println("5A");
        hex_value="5A";
  }

  //rotateServo(hex_value);
}   


void ResetPosition(int angle){
  for(int servoAngle = angle; servoAngle >= 0; servoAngle--)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);              
    delay(10);                  
  }
}

void rotateServo(String hex_value_returned){
    Serial.println("hex_value_returned:"+hex_value_returned);

    for (int n = 0; n <= 1; n++) {
      value_for_rotation_1 = hex_value_returned.charAt(n);
      Serial.println(value_for_rotation_1);   

       if(value_for_rotation_1=='F'){
          servo.write(11.5);  
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='E'){
          servo.write(23); 
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='D'){
          servo.write(34.5);  
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='C'){
          servo.write(46);  
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='B'){
          servo.write(57.5); 
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='A'){
          servo.write(69);   
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='9'){
          servo.write(80.5); 
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='8'){
          servo.write(92);   
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='7'){
          servo.write(103.5); 
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='6'){
          servo.write(115);  
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='5'){
          servo.write(126.5);  
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='4'){
          servo.write(138);   
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='3'){
          servo.write(149.5);   
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='2'){
          servo.write(161);   
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='1'){
          servo.write(172.5); 
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
         else if(value_for_rotation_1=='0'){
          servo.write(180); 
          delay(1000); 
          ResetPosition(value_for_rotation_1);              
       }
     
    }

}


char readio()
{
  if (signal_len < 600 && signal_len > 50)
  {
    return '.';                        //if button press less than 0.6sec, it is a dot
  }
  else if (signal_len > 600)
  {
    return '-';                        //if button press more than 0.6sec, it is a dash
  }
}

void convertor()
{
  static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
                            };
  int i = 0;
  if (code == ".-.-.-")
  {
    Serial.print(".");        //for break
  }
  else
  {
    while (letters[i] != "E")  //loop for comparing input code with letters array
    {
      if (letters[i] == code)
      {
        char c = char('A' + i);
        Serial.println(c);
        if(isAscii(c)){
          ascii_to_hex_convert(c);
          break;
        }
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
