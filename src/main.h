#include "Arduino.h"
#include <SPI.h>
#include "ILI9341_due.h"

// #include "Adafruit_GFX.h"    // Core graphics library by Adafruit
// #include "Adafruit_ST7789.h" // Hardware-specific library for ST7789 (with or without CS pin)

#define DELAY 3000

#define PIN_POWER 25

#define PIN_BUTTON_ONOFF_LED_WHITE 37
#define PIN_BUTTON_ONOFF_LED_RED 49

#define BUTTON_RIGHT_UP 30
#define BUTTON_RIGHT_DOWN 32
#define BUTTON_LEFT_UP 31
#define BUTTON_LEFT_DOWN 33

#define TFT_RST 51
#define TFT_DC 11
#define TFT_CS 10

// Adafruit_ST7789 tft = Adafruit_ST7789(TFT_DC, TFT_RST, TFT_CS);
ILI9341_due tft = ILI9341_due(TFT_CS, TFT_DC, TFT_RST);