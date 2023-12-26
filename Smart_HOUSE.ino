int Incoming_data = 0;

int led_1 = 13;
int led_2 = 12;
int led_3 = 8;
// Brightness led pins
int LED_1 = 6;
int LED_2 = 5;
int LED_3 = 3;
//RGB
int Red = 11;
int Blue =10;
int Green = 9;

//fan
int Fan_1 = 4;
//assigning pin in array

int ledPins[]={led_1,led_2,led_3};
int RGB_lights[]={Red,Blue,Green};
int BrightnessPins[]={LED_1,LED_2,LED_3}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i =0; i < 3; i++)
  {
    pinMode(ledPins[i],OUTPUT);
    pinMode(BrightnessPins[i],OUTPUT);
    pinMode(RGB_lights[i],OUTPUT);
    pinMode(Fan_1,OUTPUT);
  }
}

void loop() {

  while (Serial.available() > 0) {
  // Assuming Incoming_data is a string
  String command = Serial.readString('\n'); // Read the command until the newline character

  if (command == "Led") {
    // Call the Led_Lights function with the next piece of data received
    if (Serial.available() > 0) {
    int led_data = Serial.parsInt(); // Read the next byte as LED data
      Led_Lights(led_data);
    String motor_values = readString(); // Get the substring with the RGB values
      Fan_1(motor_values);
    }
  }
   else if (command == "brightness")) {
    // Extract the brightness value from the command
    int brightness_value = Serial.parsInt(); // Assuming the command is like "brightness128"
    brightness_control(brightness_value);
  }
   else if (command == "RGB") {
    // Extract the RGB values and call RGB_control
    // Assuming the command is in the format "RGB255,0,0"
    String rgb_values = readString(); // Get the substring with the RGB values
    RGB_control(rgb_values);
  }
}

// 3 leds , 1 fan , 3 leds with pwm brigthnes conteroll and 1 rgb with pws 
void Led_Lights(int Incoming_data) {
  switch (Incoming_data) {
    // Check the incoming data from MIT App Inventor which number is sending
    // LED 1
    case '1':
      digitalWrite(led_1, HIGH);
      Serial.println("Led 1 is On");
      break;
    case '2':
      digitalWrite(led_1, LOW);
      Serial.println("Led 1 is Off");
      break;
    // LED 2
    case '3':
      digitalWrite(led_2, HIGH);
      Serial.println("Led 2 is On");
      break;
    case '4':
      digitalWrite(led_2, LOW);
      Serial.println("Led 2 is Off");
      break;
    // LED 3
    case '5':
      digitalWrite(led_3, HIGH);
      Serial.println("Led 3 is On");
      break;
    case '6':
      digitalWrite(led_3, LOW);
      Serial.println("Led 3 is Off");
      break;
  }
}

void brightness_control(int value){
      analogWrite(LED_1,Incoming_data);
      analogWrite(LED_2,Incoming_data);
      analogWrite(LED_3,Incoming_data);
}

void RGB_control(char Incoming_data) {
  // This function needs to receive strings, but Arduino can't switch on strings directly
  // Use if-else statements to check the incoming data string against known commands
  String command = String(Incoming_data); // Convert char to String for comparison
  
  if (command == "Off") {
    setColor(0, 0, 0);
  } else if (command == "White") {
    setColor(255, 255, 255);
  } else if (command == "Blue") {
    setColor(0, 255, 0);
  } else if (command == "Red") {
    setColor(255, 0, 0);
  } else if (command == "Green") {
    setColor(0, 0, 255);
  } else if (command == "Orange") {
    setColor(255, 165, 0);
  } else if (command == "Purple") {
    setColor(128, 0, 128);
  } else if (command == "Cyan") {
    setColor(0, 255, 255);
  }else if (command == "Yellow") {
    setColor(255, 215, 0);
  }
  // Add more colors as needed
}
void Fan_1(string data)
{
  if(data == 'on')
     digitalWrite(Fan_1,HIGH);
  else if(data== 'off')
    digitalWrite(Fan_1,LOW);
}

void setColor(int red, int green, int blue) {
  analogWrite(Red, red);
  analogWrite(Green, green);
  analogWrite(Blue, blue);
}