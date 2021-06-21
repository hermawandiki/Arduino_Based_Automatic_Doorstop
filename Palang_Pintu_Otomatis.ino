/*
Nama projek = Palang Pintu Otomatis berbasis Arduino
Dibuat oleh = Diki Hermawan - Bojonegoro, Indonesia
*/

#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Ultrasonic sensor1(6, 7);
Ultrasonic sensor2(8, 9);
LiquidCrystal_I2C lcd (0x3f, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  myservo.attach(5);
  myservo.write(0);
  lcd.setCursor(0, 0);
  lcd.print("  PALANG PINTU  ");
  lcd.setCursor(0, 1);
  lcd.print("    OTOMATIS    ");
  delay(2000);
  lcd.clear();
  lcd.print(" DILARANG MASUK ");
}

void loop() {
  int masuk = sensor1.distanceRead();
  int keluar = sensor2.distanceRead();
  Serial.print("masuk = ");
  Serial.print(masuk);
  Serial.print("keluar = ");
  Serial.println(keluar);
  delay(200);

  if (masuk <= 10) {
    myservo.write(90);
    lcd.clear();
    lcd.print(" SILAHKAN MASUK ");
  }
  else if (keluar <= 10) {
    myservo.write(0);
    lcd.clear();
    lcd.print(" DILARANG MASUK ");
  }
}
