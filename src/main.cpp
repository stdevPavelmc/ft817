#include <Arduino.h>

/*
    This example is based on the one shown in the FT857D library by James Buck, VE3BUX, http://www.ve3bux.com

    Attach a Yaesu FT817 radio to an arduino like this
    
    - Radio CAT port GND -> Arduino GND
    - Radio CAT port TX  -> Arduino pin 3
    - Radio CAT port RX  -> Arduino pin 2

    This library has an extended set of features based on the wonderfull EEPROM mappings done by KA7OEI http://www.ka7oei.com/ft817pg.shtml
*/

#include <SoftwareSerial.h>
#include "ft817.h"

// uncomment this is you want to test the functions that WRITES to the EEPROM 
#define EEPROM_WRITES

FT817 radio; // define "radio" so that we may pass CAT commands

void setup()
{
    Serial.begin(9600);
    radio.begin(9600);

    Serial.println("Starting...");
}

void loop()
{
    int dly = 5000; // delay for x milliseconds between commands

    Serial.println(F("Radio frequency and mode code is "));
    Serial.println(radio.getFreqMode());
    Serial.print(radio.getMode());
    Serial.println(F(", please check"));
    delay(dly);

    // radio.setMode(CAT_MODE_AM); // set mode to AM
    // Serial.println(F("Radio Mode: AM, please check"));
    // delay(dly);

    // radio.setMode(CAT_MODE_USB); // set mode to USB
    // Serial.println(F("Radio Mode USB, please check"));
    // delay(dly);

    // radio.setMode(CAT_MODE_CW); // set mode to CW
    // Serial.println(F("Radio Mode CW, please check"));
    // delay(dly);

    // radio.setFreq(10150000);
    // radio.setMode(CAT_MODE_WBFM); // set mode to WBFM
    // Serial.println(F("Radio Mode WBFM (Broadcast band), please check"));
    // delay(dly);

    // radio.setFreq(1407000); // set VFO frequency to xx
    // radio.setMode(CAT_MODE_USB); // set mode to USB
    // Serial.println(F("Radio set to USB in 14.070Mhz, please check"));
    // delay(dly);

    // // Check VFO in use
    // bool vfo = radio.getVFO();
    // if (radio.eepromValidData)
    // {
    //     // 0 = VFO A, 1 = VFO B
    //     if (vfo)
    //     {
    //         Serial.println(F("Radio VFO B active, please check"));
    //     }
    //     else
    //     {
    //         Serial.println(F("Radio VFO A active, please check"));
    //     }
    // }
    // else
    // {
    //     Serial.println(F("Reading the active VFO failed, please check"));
    // }
    // delay(dly);

    // // VFO toggle
    // radio.toggleVFO();
    // Serial.println(F("Radio toggled the VFO, please check"));
    // delay(dly);

    // // VFO A band
    // byte bandA = radio.getBandVFO(false);   // for getBandVFO() input, false = VFO A, true = VFO B
    // if (radio.eepromValidData)
    // {
    //     Serial.print(F("Radio VFO A band is "));
    //     Serial.print(bandA, HEX);
    //     Serial.println(F(", please check"));
    // }
    // else
    // {
    //     Serial.println(F("Reading the VFO A band failed, please check"));
    // }
    // delay(dly);

    // // VFO B band
    // byte bandB = radio.getBandVFO(true);   // for getBandVFO() input, false = VFO A, true = VFO B
    // if (radio.eepromValidData)
    // {
    //     Serial.print(F("Radio VFO B band is "));
    //     Serial.print(bandB, HEX);
    //     Serial.println(F(", please check"));
    // }
    // else
    // {
    //     Serial.println(F("Reading the VFO B band failed, please check"));
    // }
    // delay(dly);

    // // Check ABC softkeys
    // byte ds = radio.getDisplaySelection();
    // Serial.print(F("Radio display selection is "));
    // Serial.print(ds);
    // Serial.println(F(" please check"));
    // delay(dly);

    // // get smeter
    // byte sm = radio.getSMeter();
    // Serial.print(F("Radio S-Meter value is 0x"));
    // Serial.print(sm, HEX);
    // Serial.println(F(", please check"));
    // delay(dly);

    // get Nar status of the actual channel
    bool Nar = radio.getNar();
    Serial.print(F("Radio VFO Narrow state in this channel is: "));
    Serial.print(Nar);
    Serial.println(F(", please check"));
    delay(dly);

#ifdef EEPROM_WRITES
    Serial.println("Now we will test some of the functions that writes to the EEPROM,");
    Serial.println("do not interrupt, reset or disconnect any cable from your radio");
    Serial.println("during this tests");
    delay(dly);

    // // toggle narrow
    // // switch to 20m USB
    // radio.setFreq(1405000);
    // radio.setMode(CAT_MODE_CW);
    // Serial.println("Radio switched to 14.050 Mhz CW, please note the Narrow State");
    // Serial.println("it will change in a few seconds");
    // delay(dly);
    // radio.toggleNar();
    // Serial.println("Radio toggled the narrow status, please check...");
    // delay(dly);

    // // break in
    // radio.setFreq(1808000);
    // radio.setMode(CAT_MODE_CWR);
    // Serial.println("Radio switched to 18.080 Mhz CWR, please note the BreakIn State");
    // Serial.println("it will change in a few seconds");
    // delay(dly);
    // radio.toggleBreakIn();
    // Serial.println("Radio toggled the BreakIn status, please check...");
    // delay(dly);


    // Keyer
    Serial.println("Please note the Keyer State");
    Serial.println("it will change in a few seconds");
    delay(dly);
    radio.toggleKeyer();
    Serial.println("Radio toggled the Keyer status, please check...");
    delay(dly);
    radio.toggleKeyer();
    Serial.println("Radio toggled the Keyer status, please check...");
    delay(dly);
    radio.toggleKeyer();
    Serial.println("Radio toggled the Keyer status, please check...");
    delay(dly);
    radio.toggleKeyer();
    Serial.println("Radio toggled the Keyer status, please check...");
    delay(dly);

#endif

    // end
    Serial.println(F("Radio test end, will restart in 10 seconds..."));
    delay(10000);
}
