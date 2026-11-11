
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//P2
// #include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) 
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) 
        Serial.print("0");
      Serial.println(address, HEX);
    }    
  }
  
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);
}


//P3

// LiquidCrystal_I2C lcd(0x27, 20, 4); // set I2C address 0x27 for 20x4 LCD

// void setup() {
//   Wire.begin(D1, D2);
//   lcd.init();
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Selamat Belajar");
//   lcd.setCursor(0, 1);
//   lcd.print("Workshop Sistem Tertanam");
//   lcd.setCursor(0, 2);
//   lcd.print("Selamat Belajar");
//   lcd.setCursor(0, 3);
//   lcd.print("Workshop Sistem Tertanam");
//   delay(700);
// }

// void loop() {
// }

//Test
