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
    continuousDrive()
*/
#include <mip.h>

MiP     mip;

void setup()
{
    mip.begin();

    PRINTLN(F("ContinuousDrive.ino - Use continuousDrive() function.\n"
              "Drive forward with right turn and then backward with left turn."));

    for (int i = 0 ; i < 40 ; i++)
    {
        // Drive forward at half-speed and turn right at quarter rate.
        int result = mip.continuousDrive(16, 8);
        // Pace out the continuous drive commands by 50 msec.
        delay(50);
    }
    for (int i = 0 ; i < 40 ; i++)
    {
        // Drive backward at half-speed and turn left at quarter rate.
        int result = mip.continuousDrive(-16, -8);
        // Pace out the continuous drive commands by 50 msec.
        delay(50);
    }

    mip.end();
}

void loop()
{
}
