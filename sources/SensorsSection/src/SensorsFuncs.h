#include "header.h"



float *readDHT()
{
    static float dhtSensorsInfo[2];
    dhtSensorsInfo[1] = dht.readHumidity();
    dhtSensorsInfo[0] = dht.readTemperature();
    return dhtSensorsInfo;
}

float *readDS18Temp()
{
    float *temps = new float[ds18Amount];
    for (unsigned int i = 0; i < ds18Amount; i++)
    {
        if (dsSensors[i].readTemp())
        {
            temps[i] = dsSensors[i].getTemp();
        }
    }
    return temps;
}

void requestDS18Temp()
{
    for (unsigned int i = 0; i < ds18Amount; i++)
    {
        dsSensors[i].requestTemp();
    }
}
