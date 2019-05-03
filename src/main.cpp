#include "main.h"

#define PIN_BUTTON_ONOFF_LED_WHITE 37
#define PIN_BUTTON_ONOFF_LED_RED 49

void setup()
{
    pinMode(25, OUTPUT);
    digitalWrite(25, HIGH);

    // activate backlight
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    // tft.init(240, 320);
    tft.begin();

    pinMode(BUTTON_LEFT_UP, INPUT);
    pinMode(BUTTON_RIGHT_UP, INPUT);
    pinMode(BUTTON_RIGHT_DOWN, INPUT);

    pinMode(PIN_BUTTON_ONOFF_LED_WHITE, OUTPUT);
    pinMode(PIN_BUTTON_ONOFF_LED_RED, OUTPUT);
    digitalWrite(PIN_BUTTON_ONOFF_LED_RED, LOW);
    digitalWrite(PIN_BUTTON_ONOFF_LED_WHITE, HIGH);

    tft.fillScreen(ILI9341_WHITE);
    tft.drawRect(10, 10, 100, 100, ILI9341_RED);
    // tft.fillScreen(ST77XX_WHITE);
    // tft.drawRect(10, 10, 100, 100, ST77XX_RED);
}

String _serialString = "";
void serialEvent()
{
}

void loop(void)
{
    // uint8_t btLeftUp = digitalRead(BUTTON_LEFT_UP); // not needed for now
    uint8_t btRightUp = digitalRead(BUTTON_RIGHT_UP);
    uint8_t btRightDown = digitalRead(BUTTON_RIGHT_DOWN);

    if(btRightUp == HIGH)
    {
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
        tft.begin();
        // tft.init(240, 320);
    }
}