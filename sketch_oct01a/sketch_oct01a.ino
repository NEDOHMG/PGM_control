//Arduino基板ピン配置設定  Board pin arrangement setting
//evaluate solenoid pwm switching
//int yamahasensor = 0;
//int pressuresensor = 5;
//int pwm = 11;
//int onoff = 2;
//int off = 2;
//int INTERVAL = 5000;
int ledPin = 9; // output pin supporting PWM
//int inPin = 3; // voltage connected to analog pin 3, e.g. a potentiometer
//int val = 0; // variable to store the read value
//float volt = 0; // variable to hold the voltage read
const int analogPin_read = A3;
int sensorvalue = 0;
int outputvalue = 0;

void setup()
{
  Serial.begin(9600);
  //pinMode(ledPin, OUTPUT); // sets the pin as output
}

void loop()
{
  sensorvalue = analogRead(analogPin_read);
  outputvalue = map(sensorvalue, 0, 1023, 0, 500);
  Serial.println(sensorvalue);
  Serial.println("　");
  if (Serial.available()) {
  char ser = Serial.read(); //read serial as a character

  //NOTE because the serial is read as “char” and not “int”, the read value must be compared to character numbers
  //hence the quotes around the numbers in the case statement
  //analogWrite(ledPin, ser);
  switch (ser)
  {
    case '0':
    analogWrite(ledPin, 0);
    break;

    case '1':
    analogWrite(ledPin, 8);
    break;

    case '2':
    analogWrite(ledPin, 20);
    break;
    case '3':
    analogWrite(ledPin, 32);
    break;

    case '4':
    analogWrite(ledPin, 46);
    break;
    case '5':
    analogWrite(ledPin, 55);
    break;

    case '6':
    analogWrite(ledPin, 68);
    break;
    case '7':
    analogWrite(ledPin, 79);
    break;

    case '8':
    analogWrite(ledPin, 90);
    break;

    case '9':
    analogWrite(ledPin, 100);
    break;

    case 'a':
    analogWrite(ledPin, 117);
    break;
    case 'b':
    analogWrite(ledPin, 128);
    break;

    case 'c':
    analogWrite(ledPin, 140);
    break;
    case 'd':
    analogWrite(ledPin, 152);
    break;

    case 'e':
    analogWrite(ledPin, 163);
    break;
    case 'f':
    analogWrite(ledPin, 175);
    break;

    case 'g':
    analogWrite(ledPin, 192);
    break;
    /*case 'h':
    analogWrite(ledPin, 193);
    break;

    case 'i':
    analogWrite(ledPin, 194);
    break;
    case 'j':
    analogWrite(ledPin, 195);
    break;

    case 'k':
    analogWrite(ledPin, 196);
    break;
    case 'l':
    analogWrite(ledPin, 197);
    break;

    case 'm':
    analogWrite(ledPin, 198);
    break;
    case 'n':
    analogWrite(ledPin, 199);
    break;

    case 'o':
    analogWrite(ledPin, 200);
    break;
    case 'p':
    analogWrite(ledPin, 201);
    break;

    case 'q':
    analogWrite(ledPin, 202);
    break;
    case 'r':
    analogWrite(ledPin, 203);
    break;

    case 's':
    analogWrite(ledPin, 204);
    break;

    case 't':
    analogWrite(ledPin, 205);
    break;

    case 'u':
    analogWrite(ledPin, 206);
    break;

    case 'v':
    analogWrite(ledPin, 207);
    break;

    case 'x':
    analogWrite(ledPin, 208);
    break;

    case 'y':
    analogWrite(ledPin, 209);
    break;

    case 'z':
    analogWrite(ledPin, 210);
    break;*/
    //default:
    
    //Serial.println("Invalid entry");

   }
}
}
  /*val = analogRead(inPin); // read the input pin
  volt =(5.0 * val) / 1023;
  val = 255 * (volt / 5);
  analogWrite(pwmPin, val);*/
