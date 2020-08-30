/*
serialRelayTest.ino
*/
// for this to work, the LC Technology board must be in Mode 2 with the Red Led d& lit up solid, and the green D6 led winking
// hold S1 down during a power up to get into this mode
//The default mode with a solid Blue LED WONT WORK>
 

byte rel1ON[] = {0xA0, 0x01, 0x01, 0xA2};  //Hex command to send to serial for open relay 1
byte rel1OFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay 1
byte rel2ON[] = {0xA0, 0x02, 0x01, 0xA3};  //Hex command to send to serial for open relay 2
byte rel2OFF[] = {0xA0, 0x02, 0x00, 0xA2}; //Hex command to send to serial for close relay 2

const int GPIO2 = 2;  // GPIO2 pin - on board LED of some of the ESP-01 variants.

void setup(void){

  pinMode(GPIO2, OUTPUT); 
  
  Serial.begin(115200);
    Serial.println("void setup starting ");
  Serial.println("Booting...");
  delay(2000);
  Serial.println("flashing LED on GPIO2...");
  //flash fast a few times to indicate CPU is booting
  digitalWrite(GPIO2, LOW);
  delay(100);
  digitalWrite(GPIO2, HIGH);
  delay(100);
  digitalWrite(GPIO2, LOW);
  delay(100);
  digitalWrite(GPIO2, HIGH);
  delay(100);
  digitalWrite(GPIO2, LOW);
  delay(100);
  digitalWrite(GPIO2, HIGH);

  Serial.println("Delaying a bit...");
  delay(2000);
 
  //make sure the relay is off before moving forward
  Serial.write(rel1OFF, sizeof(rel1OFF));
  Serial.println("relay 1 off - void setup init ");
  delay(100);
  Serial.write(rel2OFF, sizeof(rel2OFF));
  Serial.println("relay 2 off - void setup init ");
  delay(3000);
}


void loop(void){
   
  //turn the relay 1 on for 3 seconds
  Serial.write(rel1ON, sizeof(rel2ON));
  digitalWrite(GPIO2, LOW);
  delay(1000);
  //turn the relay 2 on for 3 seconds
  Serial.write(rel2ON, sizeof(rel2ON));
  digitalWrite(GPIO2, LOW);
  Serial.println("relay 1 on ");
  delay(3000);

  //turn the relay1 off for 3 seconds
  Serial.write(rel1OFF, sizeof(rel1OFF));
  digitalWrite(GPIO2, HIGH);
   Serial.println("relay 1 off ");
  delay(1000);
  
  //turn the relay2 off for 3 seconds
  Serial.write(rel2OFF, sizeof(rel2OFF));
  digitalWrite(GPIO2, HIGH);
  Serial.println("relay 2 off ");
  delay(3000);
}
