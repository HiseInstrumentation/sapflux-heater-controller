/*
 * Written By Hise Scientific Instrumentation, LLC
 * https://hisescientific.com/
 * 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
    
#define HEATER_ON_DURATION_MILISECONDS 2500
#define HEATER_OFF_DURATION_MILISECONDS 600000
#define LED_IND 13

// Specify the pins for each heating element
int heater_map[] = {7};

void setup() {
  setup_lamp();
  setup_heaters();
}

void loop() 
{
  heaters_run();
}


/****/

/**
 * Turn the indicator LED on
 */
void lamp_on()
{
  digitalWrite(LED_IND, HIGH);
}

/**
 * Turn the indicator LED off
 */
void lamp_off()
{
  digitalWrite(LED_IND, LOW);
}

/**
 * Turn on all heaters for specified duration and turn off all heaters
 * for specified duration.
 */
void heaters_run()
{
  long runtime_on = HEATER_ON_DURATION_MILISECONDS;
  long runtime_off = HEATER_OFF_DURATION_MILISECONDS;

  Serial.println(runtime_off);
  
  lamp_on();
  for(int i = 0; i < sizeof(heater_map); i++) {
    heater_on(heater_map[i]);  
  }
  delay(runtime_on);
  lamp_off();
  
  for(int i = 0; i < sizeof(heater_map); i++) {
    heater_off(heater_map[i]);  
  }
  delay(runtime_off);
}

/**
 * Turn on an idividual heater
 */
void heater_on(int heater_id)
{
  digitalWrite(heater_id, HIGH);
}

/**
 * Turn off an individual heater
 */
void heater_off(int heater_id)
{
  digitalWrite(heater_id, LOW);
}

/**
 * Setup indidcator LED
 */
void setup_lamp()
{
  pinMode(LED_IND, OUTPUT);
  digitalWrite(LED_IND, LOW);
}

/**
 * Setup all heaters
 */
void setup_heaters()
{
  for(int i = 0; i < sizeof(heater_map); i++) {
    pinMode(heater_map[i], OUTPUT);
    digitalWrite(heater_map[i], LOW);
  }
}
