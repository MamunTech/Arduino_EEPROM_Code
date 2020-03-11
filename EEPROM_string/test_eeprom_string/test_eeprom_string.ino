#include <EEPROM.h>
int address = 0;                                     // the variable which holds the address in the eeprom
int read_value = 0;                                  // the variable which holds the data which is read from the eeprom
char serial_in_data;  

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);   
  Serial.println("PREVIOUS TEXT IN EEPROM :-");
  for(address = 0; address < 1024; address ++)        // read the entire EEPROM memory
  {  
    read_value = EEPROM.read(address);
    Serial.write(read_value);
  }
}


void loop() {
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
