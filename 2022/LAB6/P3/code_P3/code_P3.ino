// When numReadings goes up the plot smooths out but the signal
// is delayed.  When numReadings goes down the plot is jagged but
// the signal is closer to real time.
const int numReadings = 100;

// Potentiometer
float ewmaAlphaP = 0.1;
double ewmaP = 0;
int readP = 0;

int actualNumReadingsM = 0;
int readingsM[numReadings]; // the readings from the analog input
int readIndexM = 0;         // the index of the current reading
int totalM = 0;             // the running total
int averageM = 0;           // the average
const int potentiometerPin = A0;

// Photoresistor
float ewmaAlphaR = 0.1;
double ewmaR = 0;
int readR = 0;

int actualNumReadingsR = 0;
int readingsR[numReadings]; // the readings from the analog input
int readIndexR = 0;         // the index of the current reading
int totalR = 0;             // the running total
int averageR = 0;           // the average
const int photoresistorPin = A1;

int moving_average(int pin, int readings[], int &readIndex, int &total, int &average, int &actualNumReadings)
{
    total = total - readings[readIndex];
    readings[readIndex] = analogRead(pin);
    total = total + readings[readIndex];
    readIndex = readIndex + 1;
    if (readIndex >= numReadings)
    {
        readIndex = 0;
    }
    if (actualNumReadings < numReadings)
    {
        actualNumReadings++;
    }
    average = total / actualNumReadings;
    return average;
}


void exponential_smoothing(double &ewma, float &ewmaAlpha, int &sensorValue)
{
    ewma = (ewmaAlpha * sensorValue) + (1 - ewmaAlpha) * ewma;
}


void setup()
{
    Serial.begin(9600);

    for (int thisReading = 0; thisReading < numReadings; thisReading++)
    {
        readingsM[thisReading] = 0;
        readingsR[thisReading] = 0;
    }
}

void loop()
{
    readP = analogRead(potentiometerPin);
    exponential_smoothing(ewmaP, ewmaAlphaP, readP);
    Serial.print(ewmaP);

    Serial.print(',');

    readR = analogRead(photoresistorPin);
    exponential_smoothing(ewmaR, ewmaAlphaR, readR);
    Serial.println(ewmaR);

    delay(1);
}
