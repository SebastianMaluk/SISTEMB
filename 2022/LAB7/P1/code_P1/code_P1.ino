#include <Arduino_FreeRTOS.h>

// define two tasks for Blink & AnalogRead
void TaskBlink(void *pvParameters);
void TaskBreath(void *pvParameters);
void TaskSerialWrite(void *pvParameters);


int i = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
    }

    // Now set up two tasks to run independently.
    xTaskCreate(
        TaskBlink,
        "Blink",  // A name just for humans
        128,      // This stack size can be checked & adjusted by reading the Stack Highwater
        NULL,
        3,        // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
        NULL );

     xTaskCreate(
         TaskBreath,
         "Breathe",  // A name just for humans
         128,      // This stack size can be checked & adjusted by reading the Stack Highwater
         NULL,
         2,
         NULL );

     xTaskCreate(
         TaskSerialWrite,
         "SerialWrite",
         128,  // Stack size
         NULL,
         1, // Priority
         NULL );

    // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
    vTaskStartScheduler();
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

/*
  Blink
  Turns on an LED on for 500ms, then off for 500ms, repeatedly.
*/

  // initialize digital pin 11 as an output.
  pinMode(11, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay(500 / portTICK_PERIOD_MS); // wait for 500ms
    digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(500 / portTICK_PERIOD_MS); // wait for 500ms
  }
}

void TaskSerialWrite(void *pvParameters)  // This is a task.
{
    (void) pvParameters;
  
/*
    SerialWrite
    Prints "Arduino" one character per second.
*/

    for (;;) // A Task shall never return or exit.
    {
        Serial.println("Arduino"[i]);
        vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
        i++;
        if (i == 7) {
            i = 0;
        }
    }
}

void TaskBreath(void *pvParameters)  // This is a task.
{
    (void) pvParameters;

/*
    Breathe
    Turns on an LED on from 0 to 255 and back down to 0 repeatedly over a period of 5 seconds.
    The LED is attached to digital pin 9.
*/

    // initialize digital pin 9 as an output.
    pinMode(9, OUTPUT);

    for (;;)
    {
        // fade in from min to max in increments of 5 points:
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
            // sets the value (range from 0 to 255):
            analogWrite(9, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }

        // fade out from max to min in increments of 5 points:
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
            // sets the value (range from 0 to 255):
            analogWrite(9, fadeValue);
            // wait for 30 milliseconds to see the dimming effect
            vTaskDelay(50 / portTICK_PERIOD_MS);
        }
    }
}
