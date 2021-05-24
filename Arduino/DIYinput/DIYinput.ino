#include <Servo.h>

//string for the final word
String parola;
int index_parola = 0;
char value_for_rotation_1;
char value_for_rotation_2;
//////SERVO
int servoPin = 4;
int angle = 0;
char c;
Servo servo;
////

const int ldrPin = A0;

unsigned long signal_len, t1, t2; //time for which button is pressed
int inputPin = 5; //input pin for push button
int ledPin = 2; //outpu pin for LED
String code = ""; //string in which one alphabet is stored

boolean lightOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); //internal pullup resistor is used to simplify the circuit
  pinMode(ledPin, OUTPUT);

  ///////servo setup
  servo.attach(servoPin);
  servo.write(angle);
  ///////////

}

void loop() {
NextDotDash:
  int ldrStatus = analogRead(ldrPin);
  //Serial.println(ldrStatus);
  signal_len=0;
  
  if(!lightOn){
    if (ldrStatus <= 230) {
      t1 = millis(); //time at button press
      digitalWrite(ledPin, HIGH); //LED on while button pressed
      lightOn = true;
    }
  }
  else{
    if (ldrStatus >= 230) {
      t2 = millis(); //time at button release
      digitalWrite(ledPin, LOW); //LED off on button release
      signal_len = t2 - t1; //time for which button is pressed
      lightOn = false;
    }
  }
  
    
   if (signal_len > 100)                      //to account for switch debouncing
  {
    code += readio();                       //function to read dot or dash
    Serial.println("code:" + code);
  }
  if ((millis() - t2) < 1000)           //if time between button press greater than 0.5sec, skip loop and go to next alphabet
  {     
    if (ldrStatus >= 230)
    {
      goto NextDotDash;
    }
  }
  else{                          //function to decipher code into alphabet
  if(code!="")
  {
    //Serial.println(code);
    convertor();    
  }
  code="";
  signal_len=0;
  }
   
    
}

void rotateServo(String hex_value_returned) {
  Serial.println("hex_value_returned:" + hex_value_returned);

  for (int n = 0; n <= 1; n++) {
    value_for_rotation_1 = hex_value_returned.charAt(n);
    Serial.println(value_for_rotation_1);

    if (value_for_rotation_1 == 'F') {
      servo.write(11.5);
      delay(1000);
      ResetPosition(11.5);
    } else if (value_for_rotation_1 == 'E') {
      servo.write(23);
      delay(1000);
      ResetPosition(23);
    } else if (value_for_rotation_1 == 'D') {
      servo.write(34.5);
      delay(1000);
      ResetPosition(34.5);
    } else if (value_for_rotation_1 == 'C') {
      servo.write(46);
      delay(1000);
      ResetPosition(46);
    } else if (value_for_rotation_1 == 'B') {
      servo.write(57.5);
      delay(1000);
      ResetPosition(57.5);
    } else if (value_for_rotation_1 == 'A') {
      servo.write(69);
      delay(1000);
      ResetPosition(69);
    } else if (value_for_rotation_1 == '9') {
      servo.write(80.5);
      delay(1000);
      ResetPosition(80.5);
    } else if (value_for_rotation_1 == '8') {
      servo.write(92);
      delay(1000);
      ResetPosition(92);
    } else if (value_for_rotation_1 == '7') {
      servo.write(103.5);
      delay(1000);
      ResetPosition(103.5);
    } else if (value_for_rotation_1 == '6') {
      servo.write(115);
      delay(1000);
      ResetPosition(115);
    } else if (value_for_rotation_1 == '5') {
      servo.write(126.5);
      delay(1000);
      ResetPosition(126.5);
    } else if (value_for_rotation_1 == '4') {
      servo.write(138);
      delay(1000);
      ResetPosition(138);
    } else if (value_for_rotation_1 == '3') {
      servo.write(149.5);
      delay(1000);
      ResetPosition(149.5);
    } else if (value_for_rotation_1 == '2') {
      servo.write(161);
      delay(1000);
      ResetPosition(161);
    } else if (value_for_rotation_1 == '1') {
      servo.write(172.5);
      delay(1000);
      ResetPosition(172.5);
    } else if (value_for_rotation_1 == '0') {
      servo.write(180);
      delay(1000);
      ResetPosition(180);
    }

  }
}

void ascii_to_hex_convert(char c) {
  Serial.println(c);
  if (c == 'A') {

    Serial.println("41");
    rotateServo("41");
  }

  if (c == 'B') {
    Serial.println("42");
    rotateServo("42");

  }

  if (c == 'C') {
    Serial.println("43");
    rotateServo("43");

  }

  if (c == 'D') {
    Serial.println("44");
    rotateServo("44");
  }

  if (c == 'E') {
    Serial.println("45");
    rotateServo("45");

  }
  if (c == 'F') {
    Serial.println("46");
    rotateServo("46");
  }

  if (c == 'G') {
    Serial.println("47");
    rotateServo("47");
  }

  if (c == 'H') {
    Serial.println("48");
    rotateServo("48");
  }

  if (c == 'I') {
    Serial.println("49");
    rotateServo("49");
  }

  if (c == 'J') {
    Serial.println("4A");
    rotateServo("4A");
  }

  if (c == 'K') {
    Serial.println("4B");
    rotateServo("4B");
  }

  if (c == 'L') {
    Serial.println("4C");
    rotateServo("4C");
  }

  if (c == 'M') {
    Serial.println("4D");
    rotateServo("4D");
  }

  if (c == 'N') {
    Serial.println("4E");
    rotateServo("4E");
  }

  if (c == 'O') {
    Serial.println("4F");
    rotateServo("4F");
  }

  if (c == 'P') {
    Serial.println("50");
    rotateServo("50");
  }

  if (c == 'Q') {
    Serial.println("51");
    rotateServo("51");

  }
  if (c == 'R') {
    Serial.println("52");
    rotateServo("52");

  }

  if (c == 'S') {
    Serial.println("53");
    rotateServo("53");
  }

  if (c == 'T') {
    Serial.println("54");
    rotateServo("54");
  }

  if (c == 'U') {
    Serial.println("55");
    rotateServo("55");
  }

  if (c == 'V') {
    Serial.println("56");
    rotateServo("56");
  }

  if (c == 'W') {
    Serial.println("57");
    rotateServo("57");
  }

  if (c == 'X') {
    Serial.println("58");
    rotateServo("58");
  }

  if (c == 'Y') {
    Serial.println("59");
    rotateServo("59");
  }

  if (c == 'Z') {
    Serial.println("5A");
    rotateServo("5A");
  }

}

void ResetPosition(int angle) {
  for (int servoAngle = angle; servoAngle >= 0; servoAngle--) //move the micro servo from 0 degrees to 180 degrees
  {
    servo.write(servoAngle);
    delay(10);
  }
}

char readio() {
  if (signal_len < 600 && signal_len > 50) {
    return '.'; //if button press less than 0.6 sec, it is a dot
  } else if (signal_len > 600) {
    return '-'; //if button press more than 0.6 sec, it is a dash
  }
}

void convertor() {
  static String letters[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
    "E"
  };
  int i = 0;
  /*if (code == ".-.-.-")
  {
    Serial.print(".");        //for break
  }
  else*/
  {
    while (letters[i] != "E") //loop for comparing input code with letters array
    {
      if (letters[i] == code) {
        Serial.println(char('A' + i));
        ascii_to_hex_convert(char('A' + i));
        break;

      }
      i++;
    }
    if (letters[i] == "E") {
      Serial.println("<Wrong input>"); //if input code doesn't match any letter, error
    }
  }
  code = ""; //reset code to blank string
}
