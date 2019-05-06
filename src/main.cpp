#include "main.h"

#define PIN_BUTTON_ONOFF_LED_WHITE 37
#define PIN_BUTTON_ONOFF_LED_RED 49

void setup()
{
    pinMode(PIN_POWER, OUTPUT);
    digitalWrite(PIN_POWER, HIGH);

    Serial.begin(9600);
    Serial.println("Starting ...");

    pinMode(BUTTON_LEFT_DOWN, INPUT);

    // activate backlight
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    Serial.println("Initizalizing TFT");
    // tft.init(240, 320);
    tft.begin();
    Serial.println("Initizalizing TFT finished");

    pinMode(BUTTON_LEFT_UP, INPUT);
    pinMode(BUTTON_RIGHT_UP, INPUT);
    pinMode(BUTTON_RIGHT_DOWN, INPUT);

    pinMode(PIN_BUTTON_ONOFF_LED_WHITE, OUTPUT);
    pinMode(PIN_BUTTON_ONOFF_LED_RED, OUTPUT);
    digitalWrite(PIN_BUTTON_ONOFF_LED_RED, LOW);
    digitalWrite(PIN_BUTTON_ONOFF_LED_WHITE, HIGH);

    Serial.println("Drawing rect");
    tft.fillScreen(ILI9341_WHITE);
    tft.fillRect(10, 10, 100, 100, ILI9341_RED);
    tft.fillRect(10, 110, 100, 100, ILI9341_YELLOW);
    tft.fillScreen(ILI9341_WHITE);
    Serial.println("Drawing rect finished");
    // tft.fillScreen(ST77XX_WHITE);
    // tft.drawRect(10, 10, 100, 100, ST77XX_RED);
}

void loop(void)
{
    // uint8_t btLeftUp = digitalRead(BUTTON_LEFT_UP); // not needed for now
    uint8_t btLeftDown = digitalRead(BUTTON_LEFT_DOWN);
    uint8_t btRightUp = digitalRead(BUTTON_RIGHT_UP);
    uint8_t btRightDown = digitalRead(BUTTON_RIGHT_DOWN);

    if(btRightUp == HIGH)
    {
        Serial.println("Button RightUp");
        // tft.fillScreen(ST77XX_WHITE);
        tft.fillScreen(ILI9341_WHITE);
        delay(1000);
        // tft.fillScreen(ST77XX_BLACK);
        tft.fillScreen(ILI9341_BLACK);
        delay(1000);
        // tft.fillScreen(ST77XX_WHITE);
        tft.fillScreen(ILI9341_WHITE);
        delay(1000);
        // tft.fillScreen(ST77XX_BLACK);
        tft.fillScreen(ILI9341_BLACK);
        delay(1000);
    }
    // reset tft
    else if(btRightDown == HIGH)
    {
        Serial.println("Button RightDown");
        tft.begin();
        // tft.init(240, 320);
    }
    else if(btLeftDown == HIGH)
    {
        Serial.println("Button LeftDown");
        digitalWrite(PIN_POWER, LOW);
        digitalWrite(PIN_BUTTON_ONOFF_LED_WHITE, LOW);
        delay(5000);
    }
}