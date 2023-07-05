// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int initialDelay = 2000;
char *welcomeMessage = "Welcome";

float oneSec = initialDelay;
float twoSec = initialDelay;
float threeSec = initialDelay;
int num = 0;

byte loading_a[] = {
  B00100,
  B00100,
  B00100,
  B00000,
  B00000,
  B00100,
  B01110,
  B11111
};
byte loading_b[8] = {
  B00100,
  B00000,
  B00000,
  B00100,
  B01110,
  B11111,
  B00100,
  B00100
};
byte loading_c[8] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100
};
byte loading_d[8] = {
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};
byte loading_e[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000,
  B00100,
  B01110
};

void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, loading_a);
  lcd.createChar(1, loading_b);
  lcd.createChar(2, loading_c);
  lcd.createChar(3, loading_d);
  lcd.createChar(4, loading_e);
  lcd.setCursor((16 - strlen(welcomeMessage)) / 2, 0);
  lcd.print(welcomeMessage);
  delay(1000);
  lcd.clear();
}

void loop()
{
  if (oneSec <= millis())
  {
    lcd.setCursor(0, 0);
    lcd.print(oneSec);
    oneSec = millis() + 1000;
  }

  if (twoSec <= millis())
  {
    lcd.setCursor(0, 1);
    lcd.print(twoSec);
    twoSec = millis() + 1000;
  }

  if (threeSec <= millis())
  {
    if (num == 5)
    {
      num = 0;
    }
    // for (int i = 0; i < 2; i++)
    // {
    //   for (int j = 0; j < 7; j++)
    //   {
    //     lcd.setCursor(15 - j, 0 - i);
    //   }
    // }
    lcd.setCursor(15, 0);
    lcd.write(num);
    num++;
    threeSec = millis() + 300;
  }
}