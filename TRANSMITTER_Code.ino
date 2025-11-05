// //TRANSMITTER Code

// #include <SPI.h> //needed for NRF communication
// #include <nRF24L01.h>
// #include <RF24.h>




// RF24 radio(9,10);
// const byte address[6]="00001";

// struct Packet{
//   int steering;
// int speed;
// };
// Packet data;

// void setup(){
//   Serial.begin(9600);
//   radio.begin();
//   radio.openWritingPipe(address);
//   radio.setPALevel(RF24_PA_LOW);
//   radio.stopListening();
//   radio.setDataRate(RF24_250KBPS);  // Use slower data rate for better range
// radio.setChannel(100);  // Change the channel to avoid interference
// radio.setRetries(3, 5);  // Retry sending if failure

// }


// void loop(){
//   data.speed= analogRead(A0);
//   data.steering=analogRead(A1);
//   radio.write(&data,sizeof(Packet));

//   Serial.print("Speed: ");
//   Serial.println(data.speed);
//   Serial.print("Direction: ");
//   Serial.println(data.steering);
//   delay(1000);

// // }
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  int testValue = 123;  // Sending a constant value
  bool success = radio.write(&testValue, sizeof(testValue));

  if (success) {
    Serial.println("Data Sent!");
  } else {
    Serial.println("Send Failed...");
  }

  delay(1000);
}
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// RF24 radio(9, 10); // CE, CSN Pins
// const byte address[6] = "00001";

// struct Packet {
//   int speed;
//   int steering;
// };
// Packet data;

// void setup() {
//   Serial.begin(9600);
//   Serial.println("Transmitter Starting...");

//   if (!radio.begin()) {
//     Serial.println("NRF24 module not detected!");
//     while (1); // Stop execution
//   }

//   radio.openWritingPipe(address);
//   radio.setPALevel(RF24_PA_HIGH); // High power for better range
//   radio.setDataRate(RF24_250KBPS);
//   radio.setChannel(76); // Try a different channel
//   radio.stopListening();
// }

// void loop() {
//   data.speed = analogRead(A0);
//   data.steering = analogRead(A1);

//   Serial.println("Sending Data...");
//   if (radio.write(&data, sizeof(Packet))) {
//     Serial.println("✅ Transmission Successful!");
//   } else {
//     Serial.println("⚠️ Transmission Failed!");
//   }

//   delay(200);
// }

// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// RF24 radio(9, 10); // CE, CSN pins
// const byte address[6] = "00001";

// void setup() {
//   Serial.begin(9600);
//   radio.begin();
//   radio.openWritingPipe(address);
//   radio.setPALevel(RF24_PA_HIGH); // Use high power level
//   radio.stopListening();        // Set module as transmitter
//   radio.setDataRate(RF24_250KBPS);  // Use slower data rate for better range
// radio.setChannel(100);  // Change channel to avoid interference
// radio.setRetries(3, 5);  // Retries in case of failure

// }

// void loop() {
//   const char text[] = "Hello World";
//   Serial.print("Sending: ");
//   Serial.println(text);
  
//   bool ok = radio.write(&text, sizeof(text));
//   if (ok) {
//     Serial.println("Transmission successful!");
//   } else {
//     Serial.println("Transmission failed!");
//   }
  
//   delay(1000);
// }

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN
const byte address[6] = {'R','X','A','A','A'};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.setRetries(5, 15);
  radio.setChannel(100);
  radio.stopListening();
}

void loop() {
  int testValue = 123;  // Send a fixed number
  bool success = radio.write(&testValue, sizeof(testValue));

  if (success) {
    Serial.println("Data Sent!");
  } else {
    Serial.println("Send Failed...");
  }

  delay(1000);
}
// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// RF24 radio(9, 10);  // CE, CSN

// void setup() {
//   Serial.begin(9600);
//   Serial.println("Testing NRF24L01...");
  
//   if (!radio.begin()) {
//     Serial.println("NRF24L01 NOT DETECTED! Check Wiring.");
//   } else {
//     Serial.println("NRF24L01 DETECTED!");
//   }
// }

// void loop() {

// }

