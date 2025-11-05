// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>
// #include <Servo.h>

// RF24 radio(9,10);
// const byte address[6] = "00001";



// struct Data_Packet{
  
//   int speed;
// int steering;
// };
// Data_Packet data;
// Servo esc;
// Servo myServo;

// void setup(){
//   Serial.begin(9600);
//   radio.begin();
//   radio.openReadingPipe(0,address);
//   radio.setPALevel(RF24_PA_LOW);
//   radio.startListening();
//   myServo.attach(5);
//   esc.attach(6);
//   radio.setDataRate(RF24_250KBPS);  // Use slower data rate for better range
// radio.setChannel(100);  // Change the channel to avoid interference
// radio.setRetries(3, 5);  // Retry sending if failure


// }


// void loop(){
//   if(radio.available()){
//     radio.read(&data, sizeof(Data_Packet));
//     Serial.print("Speed: ");
//     Serial.println(data.speed);
//     Serial.print("angle:");
//     Serial.println(data.steering);

//   }else{
//     Serial.println("No Signal");
//   }
//   int throttle = map(data.speed,0,1023,1000,2000);
//   int servoAngle = map(data.steering,0,1023,0,180);
//   esc.writeMicroseconds(throttle);
//   myServo.write(servoAngle);

// }
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>
// #include <Servo.h>

// RF24 radio(9, 10);  // CE, CSN pins
// const byte address[6] = "00001";  // Address for communication

// struct Data_Packet {
//     int speed;
//     int direction;
//     int steering;
// };

// Data_Packet data;

// Servo esc;    // ESC for motor
// Servo servo;  // Servo for steering

// void setup() {
//     Serial.begin(9600);
//     radio.begin();
//     radio.openReadingPipe(0, address);
//     radio.setPALevel(RF24_PA_LOW);
//     radio.startListening();  // Set as receiver

//     esc.attach(5);   // ESC connected to PWM pin 5
//     servo.attach(6); // Servo connected to PWM pin 6
// }

// void loop() {
//     if (radio.available()) {
//         radio.read(&data, sizeof(Data_Packet));  // Read incoming data

//         // Process speed and direction
//         int throttle = map(data.speed, 0, 1023, 1000, 2000); // Convert speed to ESC signal
//         if (data.direction < 512) {  // Reverse
//             throttle = map(data.speed, 0, 1023, 1500, 1000);
//         } else {  // Forward
//             throttle = map(data.speed, 0, 1023, 1500, 2000);
//         }

//         int servoPos = map(data.steering, 0, 1023, 0, 180);  // Convert to servo angle

//         esc.writeMicroseconds(throttle);  // Control ESC
//         servo.write(servoPos);            // Control Servo

//         Serial.print("Throttle: ");
//         Serial.print(throttle);
//         Serial.print(" | Steering: ");
//         Serial.println(servoPos);
//     }
// }
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>
// #include <Servo.h>

// RF24 radio(9, 10);
// const byte address[6] = "00001";

// struct Data_Packet {
//   int speed;
//   int steering;
// };
// Data_Packet data;

// Servo esc;
// Servo myServo;

// void setup() {
//   Serial.begin(9600);
//   radio.begin();
//   radio.openReadingPipe(0, address);
//   radio.setPALevel(RF24_PA_HIGH); // Use HIGH power mode for better range
//   radio.setDataRate(RF24_250KBPS);
//   radio.setChannel(100);
//   radio.startListening();

//   myServo.attach(5);
//   esc.attach(6);
// }

// void loop() {
//   if (radio.available()) {
//     radio.read(&data, sizeof(Data_Packet));

//     Serial.print("Speed: ");
//     Serial.println(data.speed);
//     Serial.print("Steering: ");
//     Serial.println(data.steering);

//     // Map values only if valid data is received
//     int throttle = map(data.speed, 0, 1023, 1000, 2000); // Adjust for ESC
//     int servoAngle = map(data.steering, 0, 1023, 0, 180);

//     esc.writeMicroseconds(throttle);
//     myServo.write(servoAngle);
//   } else {
//     Serial.println("No Signal");
//   }

//   delay(100);  // Small delay to avoid flooding Serial Monitor
// }
 
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// RF24 radio(9, 10); // CE, CSN pins
// const byte address[6] = "00001";

// void setup() {
//   Serial.begin(9600);
//   radio.begin();
//   radio.openReadingPipe(0, address);
//   radio.setPALevel(RF24_PA_HIGH); // Use high power level
//   radio.startListening();         // Set module as receiver
// }

// void loop() {
//   if (radio.available()) {
//     char text[32] = "";
//     radio.read(&text, sizeof(text));
//     Serial.print("Received: ");
//     Serial.println(text);
//   }
// }
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int receivedValue;
    radio.read(&receivedValue, sizeof(receivedValue));
    Serial.print("Received: ");
    Serial.println(receivedValue);
  } else {
    Serial.println("No Signal...");
  }
  delay(500);
}
