 /*
    AVR processors EEPROM sizes,
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb or eeprom_size bytes EEPROM storage.
    - Arduino Mega:       4kb or 4096 bytes EEPROM storage.
 */
 
#include <EEPROM.h>
int eeprom_Memory_address = 0;                       //  holds the eeprom memory address 
int read_eepromDATA = 0;                             // holds the data which is read from the eeprom
char serialDATA_to_write;                            //holds serial input data to write in the eeprom
int write_memoryLED = 13;                            //LED to indicate writing in the EEPROM memory which is connected in digital pin 13
int end_memoryLED=12 ;                               //LED to indicate eeprom memory is full which is connected in digital pin 12
int eeprom_size=1024;                                //holds the eeprom memory size or memory length

void setup()
{
  pinMode(write_memoryLED, OUTPUT);                              
  pinMode( end_memoryLED, OUTPUT);  
  Serial.begin(9600);                                                                                 // initialize the serial baud rate 9600
  Serial.println();
  Serial.println("The previous text saves in the EEPROM was :");
  Serial.println();
  for(eeprom_Memory_address = 0; eeprom_Memory_address < eeprom_size; eeprom_Memory_address ++)        // read all the EEPROM memory data
  {  
   read_eepromDATA = EEPROM.read(eeprom_Memory_address);
    Serial.write(read_eepromDATA);
  }
  
  Serial.println();
  Serial.println();
  
   
  for(eeprom_Memory_address = 0; eeprom_Memory_address < eeprom_size; eeprom_Memory_address ++)        // erase the entire eeprom memory using white spaces
   {
    EEPROM.write(eeprom_Memory_address, ' ');
   }   
   Serial.println("EEPROM memory is erased.");
   Serial.println();              
   Serial.println("Write your new text :");
    Serial.println();
  for(eeprom_Memory_address = 0; eeprom_Memory_address < eeprom_size; )                               // write the incoming serial string to the EEPROM
  {
    if(Serial.available())
    {
      serialDATA_to_write = Serial.read();  
      Serial.write(serialDATA_to_write); 
      EEPROM.write(eeprom_Memory_address, serialDATA_to_write); 
      eeprom_Memory_address ++;
      digitalWrite(write_memoryLED, HIGH);       
      delay(50);
      digitalWrite(write_memoryLED, LOW);
    }
  }
}
 
void loop()
{
  digitalWrite(end_memoryLED, HIGH);                                                                  //indicate the eeprom memorys is full
}
 
