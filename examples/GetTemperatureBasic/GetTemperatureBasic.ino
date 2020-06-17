#include <Wire.h>
#include <TimeLib.h>
#include <MT_DS1307RTC.h>

void setup() {
  bool parse=false;
  bool config=false;

  // get the date and time the compiler was run
  if (RTC.getDate(__DATE__) && RTC.getTime(__TIME__)) {
    parse = true;
    // and configure the RTC with this info
    if (RTC.write(tm)) {
      config = true;
    }
  }

  Serial.begin(9600);
  while (!Serial) ; // wait for Arduino Serial Monitor
  delay(200);
  if (parse && config) {
    Serial.print("DS1307 configured Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
	int16_t t = getTemperatureBasic();
	Serial.print(", Temperature=");
	Serial.println(t);
  } else if (parse) {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check your circuitry");
  } else {
    Serial.print("Could not parse info from the compiler, Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }
}

void loop() {

}
