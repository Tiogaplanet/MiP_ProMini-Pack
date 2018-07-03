/* Copyright (C) 2018  Adam Green (https://github.com/adamgreen)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
/* Example used in following API documentation:
    sleep()
*/
#include <mip.h>

MiP     mip;

void setup()
{
    bool connectResult = mip.begin();
    if (!connectResult)
    {
        Serial.begin(115200);
        Serial.println(F("Failed connecting to MiP!"));
        return;
    }

    Serial.println(F("Sleep.ino - Shows begin()/end()/sleep() functionality."));
    Serial.println(F("Chest LED should be green to indicate UART connection."));
    
    delay(5000);
    Serial.println(F("Disconnecting from MiP. Chest LED should revert to blue."));
    mip.end();

    delay(5000);
    Serial.println(F("Attempting to reconnect to MiP. Chest LED should turn green again."));
    connectResult = mip.begin();
    if (!connectResult)
    {
        Serial.println(F("Failed reconnecting to MiP!"));
        return;
    }

    delay(5000);
    Serial.println(F("Putting MiP to sleep. Will require power cycle before it will accept UART connections again."));
    mip.sleep();
}

void loop()
{
}
