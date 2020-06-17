/*
 * MT_DS1307RTC.h - library for DS1307 RTC
 * This library is intended to be uses with Arduino Time library functions
 * 
 * Edited by Thurstan to add temperature.
 */

#ifndef MT_DS1307RTC_h
#define MT_DS1307RTC_h

#include <TimeLib.h>

// library interface description
class MT_DS1307RTC
{
  // user-accessible "public" interface
  public:
    MT_DS1307RTC();
    static time_t get();
    static bool set(time_t t);
    static bool read(tmElements_t &tm);
    static bool write(tmElements_t &tm);
    static bool chipPresent() { return exists; }
    static unsigned char isRunning();
    static void setCalibration(char calValue);
    static char getCalibration();
	static int16_t getTemperatureBasic();

  private:
    static bool exists;
    static uint8_t dec2bcd(uint8_t num);
    static uint8_t bcd2dec(uint8_t num);
};

#ifdef RTC
#undef RTC // workaround for Arduino Due, which defines "RTC"...
#endif

extern MT_DS1307RTC RTC;

#endif
 

