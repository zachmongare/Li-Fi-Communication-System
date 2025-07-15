//Set system global variables
const int ledPin = 2;
const int period = 5;
String prompt = "Enter Message: ";
String message;

void setup() {
  pinMode(ledPin, OUTPUT); //Initialize the transmitting GPIO pin
  Serial.begin(9600); //Initialize serial monitor for GUI
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println(prompt);
  while (Serial.available() == 0){
    //Wait for user input
  }
  message = Serial.readString();
  for(int i = 0; i < message.length(); i++){
    sendByte(message[i]);
  }
  Serial.print("Message sent: ");
  Serial.println(message);
}

void sendByte(char myByte){
  digitalWrite(ledPin, LOW);
  delay(period);
  
  for(int i = 0; i < 8; i++){
    int ledState = bitRead(myByte, i);
    digitalWrite(ledPin, ledState != 0);
    delay(period);
  }
  digitalWrite(ledPin, HIGH);
  delay(period);
}