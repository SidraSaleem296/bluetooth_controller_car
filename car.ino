// Motor Pins
int motor1A = 9;   // Motor 1: Positive terminal
int motor1B = 10;  // Motor 1: Negative terminal
int motor2A = 11;  // Motor 2: Positive terminal
int motor2B = 12;  // Motor 2: Negative terminal

char receivedData;  // Variable to store received data from Bluetooth

void setup() 
{  
  pinMode(motor1A, OUTPUT);  // Configure motor pins as outputs
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  
  Serial.begin(9600);  // Start serial communication
}

void loop()
{
  while (Serial.available() > 0)
  {
    receivedData = Serial.read();  // Read data from serial buffer
    Serial.println(receivedData);  // Print the received data
  }

  // Control based on received data
  
  if (receivedData == 'F')  // Move forward
  {
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);  
  }
  
  else if (receivedData == 'B')  // Move backward
  {
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH); 
  }
  
  // ... Repeat the same logic for other directions (Left, Right, Stop, Forward Right, Backward Right, Forward Left, Backward Left)
  
  else if (receivedData == 'S')  // Stop
  {
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW); 
  }
}
